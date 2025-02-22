﻿#include "Log.h"

#include <process.h>

using std::string;
using std::fstream;
using namespace logg;
//-------------------------------------------------------------------------------------------------

// Functie care verifica daca exista fisierul, daca nu il creaza
void LogF::ensureLogFileExists()
{
	std::filesystem::path logPath = std::filesystem::current_path() / baseFilePathToLog;

	// Creează directoarele necesare
	std::error_code ec;
	if (!std::filesystem::exists(logPath.parent_path())) {
		if (!std::filesystem::create_directories(logPath.parent_path(), ec)) {
			std::cerr << "Error: Unable to create directory: " << logPath.parent_path()
				<< " - " << ec.message() << std::endl;
			return;
		}
	}

	// creaza fisierul daca nu exista
	if (!std::filesystem::exists(logPath)) {
		std::ofstream createFile(logPath);
		if (!createFile) {
			std::cerr << "Error: Unable to create log file: " << logPath << std::endl;
			return;
		}

		// antetul in fisier
		createFile << "|=========================================================================================================================|\n";
		createFile << "|       Ora         |   PID  |    Level Info    |         Functia         |      Error     |            Message           |\n";
		createFile << "|===================|========|==================|=========================|================|==============================|\n";
		createFile.close();
	}
}

std::string LogF::addSpaces(std::string str, size_t len)
{
	string strLocal;																							// Variabila in care se va formata sirul de caractere
	strLocal.assign(" ");																						// Initializeaza sirul cu un sptiu gol
	strLocal.append(str);																						// Adauga sirul de caractere
	while (strLocal.length() < len)																				// Daca lungimea sirului este mai mica decat lungimea necesara
		strLocal.append(" ");																					// Adauga spatii goale la finalul sirului
	return strLocal;																							// Returneaza sirul formatat
}

// returnare PID curent
std::string LogF::GetPID()
{
	return std::to_string(getpid());
}

// setare directoriu fisier
void LogF::setFilePath(const char *file_path, const char *file_name)
{
	if (!file_path || !file_name) {
		std::cerr << "Invalid file path or file name!" << std::endl;
		return;
	}

	// calea salvare log
	baseFilePathToLog = file_path;
	if (baseFilePathToLog.back() != '/' && baseFilePathToLog.back() != '\\') {
		baseFilePathToLog += '/';
	}
	baseFilePathToLog += file_name;

	// daca fisierul si folderul exista
	ensureLogFileExists();

	// Deschide fișierul pentru verificare
	fpLog.open(baseFilePathToLog, std::fstream::out | std::fstream::app);
	if (!fpLog) {
		std::cerr << "Failed to open log file: " << baseFilePathToLog << std::endl;
	}
}

// setare nivel log
void LogF::setLevelLog(unsigned short logLevel) {
	_isLevelNone = false;
	_isLevelException = false;
	_isLevelWarning = false;
	_isLevelInfo = false;
	_isLevelDebug = false;
	_isLevelTrace = false;

	switch (logLevel) {
	case 1: _isLevelException = true; msgLevel = EXCEPTION; break;																						// nivel exception
	case 2: _isLevelException = true; _isLevelWarning = true; msgLevel = WARNING; break;																// nivel exception + warning
	case 3: _isLevelException = true; _isLevelInfo = true; _isLevelWarning = true; msgLevel = INFO; break;												// nivel exception + warning + info
	case 4: _isLevelException = true; _isLevelDebug = true; _isLevelWarning = true; _isLevelInfo = true; msgLevel = DEBUG; break;						// nivel exception + warning + info + debug
	case 5: _isLevelException = true; _isLevelDebug = true; _isLevelWarning = true; _isLevelInfo = true; _isLevelTrace = true; msgLevel = TRACE; break; // nivel exception + warning + info + debug + trace
	default:
		_isLevelNone = true;
		msgLevel = NONE;
		if (fpLog.is_open()) {
			fpLog.close(); // inchidere fisier daca era deschis
		}
		return;
	}

	// daca nivelul nu este NONE, deschide fisierul
	ensureLogFileExists();
	if (!fpLog.is_open())
	{
		fpLog.open(baseFilePathToLog, std::fstream::out | std::fstream::app);
		if (!fpLog) {
			std::cerr << "Error: Could not open log file: " << baseFilePathToLog << std::endl;
		}
	}
}

//-------------------------------------------------------------------------------------------------

unsigned short LogF::getLevelLog()
{
	return msgLevel;
}

//-------------------------------------------------------------------------------------------------

std::string LogF::levelToString(level_log level)
{
	switch (level)
	{
		case NONE: return "NONE";
		case INFO: return "INFO";
		case DEBUG: return "DEBUG";
		case WARNING: return "WARNING";
		case EXCEPTION: return "EXCEPTION";
		case TRACE: return "TRACE";
		default: return "UNKNOWN";
	}
}

// obtine timpul curent
std::string LogF::getCurrentTime()
{
	// timpul curent
	time_t now = time(0);
	tm* timeinfo = localtime(&now);
	char timestamp[20];
	strftime(timestamp, sizeof(timestamp),
		"%Y-%m-%d %H:%M:%S", timeinfo);
	string temp = timestamp;
	return temp;
}

//-------------------------------------------------------------------------------------------------

void LogF::info(const char* functionName, const char* format, ...)
{
	if (!_isLevelInfo || _isLevelNone || !fpLog.is_open()) return;

	this->functionName = functionName;

	va_list args;
	va_start(args, format);
	char buffer[1024];
	vsnprintf(buffer, sizeof(buffer), format, args);
	va_end(args);

	// construire mesajul de log
	std::string formatMessage = addSpaces(getCurrentTime(), 21)
		+ addSpaces(GetPID(), 13)
		+ addSpaces("Info", 21)
		+ addSpaces(functionName, 23)
		+ addSpaces("", 15)
		+ buffer + "\n";

	fpLog << formatMessage;
	fpLog.flush();
}

void LogF::debug(const char* functionName, const char* format, ...)
{
	if (!_isLevelDebug || _isLevelNone || !fpLog.is_open()) return;
	
	this->functionName = functionName;

	va_list args;
	va_start(args, format);
	char buffer[1024];
	vsnprintf(buffer, sizeof(buffer), format, args);
	va_end(args);

	// construire mesajul de log
	std::string formatMessage = addSpaces(getCurrentTime(), 21)
		+ addSpaces(GetPID(), 13)
		+ addSpaces("Debug", 21)
		+ addSpaces(functionName, 23)
		+ addSpaces("", 15)
		+ buffer + "\n";

	fpLog << formatMessage;
	fpLog.flush();

}

void LogF::exception(int lineNumber, const char* functionName, const char* format, ...)
{
	if (!_isLevelException || _isLevelNone || !fpLog.is_open()) return;
	
	
	this->functionName = functionName;

	va_list args;
	va_start(args, format);
	char buffer[1024];
	vsnprintf(buffer, sizeof(buffer), format, args);
	va_end(args);

	// construire mesajul de log
	std::string formatMessage = addSpaces(getCurrentTime(), 21)
		+ addSpaces(GetPID(), 13)
		+ addSpaces("Exception", 21)
		+ addSpaces(functionName, 23)
		+ addSpaces("L" + std::to_string(lineNumber), 15)
		+ buffer + "\n";

	fpLog << formatMessage;
	fpLog.flush();
}

int LogF::warning(int warningCode, const char* functionName, const char * format, ...)
{
	if (!_isLevelWarning || _isLevelNone || !fpLog.is_open()) return 0;

	this->functionName = functionName;

	va_list args;
	va_start(args, format);
	char buffer[1024];
	vsnprintf(buffer, sizeof(buffer), format, args);
	va_end(args);

	// construire mesajul de log
	std::string formatMessage = addSpaces(getCurrentTime(), 21)
		+ addSpaces(GetPID(), 13)
		+ addSpaces("Warning", 21)
		+ addSpaces(functionName, 23)
		+ addSpaces(std::to_string(warningCode), 15)
		+ buffer + "\n";

	fpLog << formatMessage;
	fpLog.flush();

	return warningCode;
}

void LogF::trace(const char* functionName, const char * format, ...)
{
	if (!_isLevelTrace || _isLevelNone || !fpLog.is_open()) return;

	this->functionName = functionName;

	va_list args;
	va_start(args, format);
	char buffer[1024];
	vsnprintf(buffer, sizeof(buffer), format, args);
	va_end(args);

	// construire mesajul de log
	std::string formatMessage = addSpaces(getCurrentTime(), 21)
		+ addSpaces(GetPID(), 13)
		+ addSpaces("Trace", 21)
		+ addSpaces(functionName, 23)
		+ addSpaces("", 15)
		+ buffer + "\n";

	fpLog << formatMessage;
	fpLog.flush();

}
//-------------------------------------------------------------------------------------------------

// verificare daca este zi noua, atunci se adauga header-ul din nou in fisier log
void LogF::checkAndWriteHeader()
{
	std::string lastDate = getLastLogDate();
	std::string currentDate = getCurrentTime().substr(0, 10); // Extrage doar "YYYY-MM-DD"
	if(lastDate.size() >= 9)
	{
		lastDate = lastDate.substr(1, lastDate.size() - 1);
    }

	// daca este aceasi zi, sa se inchida functia de adaugare a unui antet nou
	if (lastDate == currentDate) {
		return;
	}
	// antetul in fisier
	fpLog << "\n|================================================ Log Date: " << currentDate << " ===============================================|\n";
	fpLog << "|=========================================================================================================================|\n";
	fpLog << "|       Ora         |   PID  |    Level Info    |         Functia         |      Error     |            Message           |\n";
	fpLog << "|===================|========|==================|=========================|================|==============================|\n";
	fpLog.flush();
}
//--------------------------------------------------------------------------------------------------

// obtine data curenta
std::string LogF::getCurrentDate()
{
	time_t now = time(0);
	tm* timeinfo = localtime(&now);
	char date[11]; // YYYY-MM-DD
	strftime(date, sizeof(date), "%Y-%m-%d", timeinfo);
	return std::string(date);
}

//--------------------------------------------------------------------------------------------------

// obtinere data facuta la ultimul log scris in fisier
std::string LogF::getLastLogDate()
{
	std::ifstream file(baseFilePathToLog);
	if (!file.is_open()) return "";

	std::string lastLine, currentLine;
	while (std::getline(file, currentLine)) {
		if (!currentLine.empty()) {
			lastLine = currentLine;
		}
	}
	file.close();

	if (lastLine.empty()) return "";

	// Data este la începutul fiecărei linii, de forma "YYYY-MM-DD HH:MM:SS"
	return lastLine.substr(0, 11); // Extrage doar "YYYY-MM-DD"
}

