/*==============================================================================================================//
* SUB - FDE LOG																									//
* --------------------------------------------------------------------------------------------------------------//
* AUTORE: Ticau Vasile																							//
* --------------------------------------------------------------------------------------------------------------//
* FUNZIONI SVOLTE: - Funzioni per la scrittura di LOG															//
* --------------------------------------------------------------------------------------------------------------//
* HFUNZ: Sono definiti 5 livelli per la scrittura di informazioni sul processo di esecuzione nel file LOG		//
*								exception	- Errori gravi che causano l'interruzione prematura dell'attivita	//
*								warning		- Errori che non interrompono l'esecuzione, ma che avvertono		//
*								info		- Eventi interessanti durante l'esecuzione (avvio/arresto)			//
*								debug		- Informazioni dettagliate sul flusso di esecuzione					//
*								trace		- Informazioni molto piu dettagliate sul flusso di esecuzione		//
* --------------------------------------------------------------------------------------------------------------//
* REVISIONI:																									//
* --------------------------------------------------------------------------------------------------------------//
* BUGS CONOSCIUTI:																								//
* --------------------------------------------------------------------------------------------------------------//
* TIPOLOGIA: LOG																								//
* ==============================================================================================================*/
//----- INCLUDE DIVISION  --------------------------------------------------------------------------------------// 
#include "fd_define.h"																							// Firma Digitale definitions macros
#include "fd_error.h"																							// Firma Digitale error macros
#include "fd_log.h"																								// Firma Digitale EXE log header
#include "fd_versione.h"																						// Firma Digitale version header
#include "fd_log.h"																								// Firma Digitale EXE  log header

#include <Windows.h>																							// Include file for Windows applications.
#include <shlwapi.h>																							// Pentru lucrul cu PATH-urile
#include <time.h>																								// Pentru lucrul cu timpul
#include <psapi.h>																								// Pentru accesarea memoriei

//----- NAMESPACE DIVISION -------------------------------------------------------------------------------------// 
using namespace std;

//----- GLOBAL DIVISION ----------------------------------------------------------------------------------------// 
static bool flagInitTMP = 0;																					// Flag that show if TMP DIR was initialized
static bool flagInitFDELog = false;																				// Flag that show if log was initialized

//==============================================================================================================// 
//	Clasa LOG																									//
//==============================================================================================================// 

#pragma region GENERAL FUNTIONS
//--------------------------------------------------------------------------------------------------------------// 
// METODO: FDELog																								//
//--------------------------------------------------------------------------------------------------------------// 
// METODO SVOLTE: Construieste obiectul FDELog 																	//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 19-10-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------// 
// ARGOMENTI:																									//
//	logLevel		int		(I)	- nivelul de scriere a LOG-ului													//
//								0 - None																		//
//								1 - Exception(Erori grave care cauzeaza o terminare prematura)					//
//								2 - Warning(Erori ce nu perturbeaza executia, insa instiinteaza)				//
//								3 - Info(Evenimente interesante in timpul executiei(pornire / oprire))			//
//								4 - Debug(Informatii detaliate privind fluxul executiei)						//
//								5 - Trace(Informatii detaliate.)												//
//	endsLogOn		string	(I)	- Indica data pana cand se face LOG-ul											//
//	strHfirmaDir	string	(I)	- Calea completa catre folderul 'HFIRMA'										//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO:																										//
//--------------------------------------------------------------------------------------------------------------//
//	Obiectul FDELog initializat																					//
//--------------------------------------------------------------------------------------------------------------// 
FDELog::FDELog(int logLevel, std::string endsLogOn, std::string strHfirmaDir) {									// Declararea metodei
	/*----- Initializari preliminare ---------------------------------------------------------------------------*/
	_writeError = false;																						// Flag: Indica ca NU se scriu log-urile de tip EXCEPTIE
	_writeWarning = false;																						// Flag: Indica ca NU se scriu log-urile de tip WARNING
	_writeInfo = false;																							// Flag: Indica ca NU se scriu log-urile de tip INFO
	_writeDebug = false;																						// Flag: Indica ca NU se scriu log-urile de tip DEBUG
	_writeTrace = false;																						// Flag: Indica ca NU se scriu log-urile de tip TRACE
	//==========================================================================================================// 
	if (allowsWritingLOG(endsLogOn) || endsLogOn.find("00000000") != std::string::npos) {						// Daca este permisa scrierea LOG-ului conform datei limita
		setLogLevel(logLevel);																					// Seteaza var. locala cu nivelul de scrierea a LOG-ului
		if (_isLogActive) {																						// Daca este activata scrierea LOG-ului
			setHfirmaDir(strHfirmaDir);																			// Seteaza var. locala cu calea compleeta cate 'HFIRMA'
			logInitialization();																				// Porneste initializarea fisierului de LOG
			_strPID = FDEL_GetPID();																			// Seteaza PID-ul curent
		}																										//
	}																											//
	else {																										//
		_isLogActive = false;																					// Indica ca loagarea nu este activa
		setLogLevel(0);																							// Seteaza var. locala cu nivelul de scrierea a LOG-ului = 0
	}																											//
}																												//

//--------------------------------------------------------------------------------------------------------------// 
// METODO: ~FDELog																								//
//--------------------------------------------------------------------------------------------------------------// 
// METODO SVOLTE: Distruge obiectul FDELog 																		//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 19-10-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
FDELog::~FDELog() {																								// Declararea metodei 
}																												//

//--------------------------------------------------------------------------------------------------------------// 
// METODO: logInitialization																					//
//--------------------------------------------------------------------------------------------------------------// 
// METODO SVOLTE: Initializeaza fisierul LOG																	//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 19-10-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------//
void FDELog::logInitialization() {																				//
	/*----- Dichiarazione di variabili -------------------------------------------------------------------------*/
	FILE* fpLog = NULL;																							//
	FILE* fpInfOS = NULL;																						//
	string userName;																							// UserName din OS
	string computerName;																						// ComputerName din OS
	string osName;																								// Numele OS
	string osVersion;																							// Vesriunea OS
	string osLang;																								// Limba OS
	string inLang;																								// Limba de input in OS (keyboard)
	string osUTC;																								// Zona UTC din OS
	string sysDir;																								// System directory din OS
																												//
	string versFD;																								//
	string versPDF;																								//
	string versSBB;																								//
																												//
	char buffCHAR[MAX_256] = "";																				//
	char osInfoFile[_MAX_PATH] = "";																			//
	char cmd[MAX_512] = "";																						//
	//==========================================================================================================// 
	SPRINTF(buffCHAR, "%sfd-%s.log", FDEL_GetTemporaryDirectoryPath().c_str(), FDEL_GetLocalDateNow().c_str());	// Formeaza calea catre fisierul 'fd-zz-mm-yy.log'
	setFdPathLog(buffCHAR);																						// Seteaza calea catre fisierul 'fd-zz-mm-yy.log' in clasa

	if (!FDEL_CheckFileExists((char*)_fdPathLog.c_str())) {														// Daca fisierul 'fd-zz-mm-yy.log' exista
#ifndef __GNUC__																								//
#pragma region Init Header																						
#endif 																											//
		//----- Get User name ----------------------------------------------------------------------------------//
		TCHAR user_name[257];																					//
		DWORD user_nameSize = 257;																				//
		GetUserName(user_name, &user_nameSize);																	//
																												//
		//----- Get Computer name from NetBIOS -----------------------------------------------------------------//
		TCHAR computer_name[257];																				//
		DWORD computer_nameSize = 257;																			//
		GetComputerName(computer_name, &computer_nameSize);														//
																												//
		//-----  Get and display the system directory ----------------------------------------------------------//
		TCHAR sys_dir[257];																						//
		DWORD sys_dirSize = 257;																				//
		GetSystemDirectory(sys_dir, sys_dirSize);																//
																												//
		//-----  Get information Operating system --------------------------------------------------------------//
		SYSTEM_INFO System;																						//
		std::string buff, os_architecture, os_name, os_build, os_lang, in_lang, os_utc;							//
		size_t pos, posf;																						//
																												//
		GetNativeSystemInfo(&System);																			//
		if (System.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)										//
		{																										//
			os_architecture = "(64 bit)";																		//
		}																										//
		else if (System.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_INTEL)									//
		{																										//
			os_architecture = "(32 bit)";																		//
		}																										//
																												//
		//----- Get System Info --------------------------------------------------------------------------------//
		sprintf_s(osInfoFile, "%sosInfo", _strHfirmaDir.c_str());												//
		if (!FDEL_CheckFileExists(osInfoFile))																	//
		{																										//
			sprintf_s(cmd, "/MIN /WAIT CMD.EXE /C \"SYSTEMINFO > \"%s\"\"", osInfoFile);						//
			if (FDEL_RunCmdInSilentMode((char*)"start", cmd))													//
			{																									//
				sprintf_s(cmd, "\"systeminfo > \"%s\"\"", osInfoFile);											//
				system(cmd);																					//
			}																									//
		}																										//
																												//
		//----- Parseaza fisierul cu informatii despre SO ------------------------------------------------------//
		fopen_s(&fpInfOS, osInfoFile, "r");																		//
		while (!feof(fpInfOS)) {																				//
			fgets(buffCHAR, sizeof(buffCHAR), fpInfOS);															//
			buff = buffCHAR;																					//
			pos = 0;																							//
			while ((pos = buff.find("\n", pos)) != std::string::npos)											//
			{																									//
				buff.erase(pos, 2);																				//
			}																									//
			//----- Get Operating System Name ------------------------------------------------------------------//
			if (((buff.find("OS Name") != std::string::npos) || (buff.find("Nome SO") != std::string::npos)) && os_name.length() == 0) {
				pos = buff.find(':');																			// position of ":" in str							
				if (pos) {																						//
					os_name = buff.substr(pos + 1);																//
					os_name.erase(0, os_name.find_first_not_of(' '));											//
					os_name = os_name.substr(10);																//
					os_name += " " + os_architecture;															//
				}																								//
			}																									//
			//----- Get Operating Sytem Version(Build) ---------------------------------------------------------//
			if (((buff.find("OS Version:") != std::string::npos) || (buff.find("Versione SO:") != std::string::npos)) && os_build.length() == 0) {
				pos = buff.find(':');																			// position of ":" in str
				if (pos) {																						//
					os_build = buff.substr(pos + 1);															//
					os_build.erase(0, os_build.find_first_not_of(' '));											//
					posf = os_build.find_first_of(' ');															//
					os_build = os_build.substr(0, posf);														//
				}																								//
			}																									//
			//----- Get System Locale language -----------------------------------------------------------------//
			if (((buff.find("System Locale:") != std::string::npos) || (buff.find("Impostazioni locali sistema:") != std::string::npos)) && os_lang.length() == 0) {
				pos = buff.find(':');																			// position of ":" in str
				if (pos) {																						//
					os_lang = buff.substr(pos + 1);																//
					os_lang.erase(0, os_lang.find_first_not_of(' '));											//
					posf = os_lang.find_first_of(';');															//
					os_lang = os_lang.substr(0, posf);															//
				}																								//
			}																									//
			//----- Get Input Locale language ------------------------------------------------------------------//
			if (((buff.find("Input Locale:") != std::string::npos) || (buff.find("Impostazioni locali di input:") != std::string::npos)) && in_lang.length() == 0) {
				pos = buff.find(':');																			// position of ":" in str
				if (pos) {																						//
					in_lang = buff.substr(pos + 1);																//
					in_lang.erase(0, in_lang.find_first_not_of(' '));											//
					posf = in_lang.find_first_of(';');															//
					in_lang = in_lang.substr(0, posf);															//
				}																								//
			}																									//
			//----- Get Time Zone ------------------------------------------------------------------------------//
			if (((buff.find("Time Zone:") != std::string::npos) || buff.find("Fuso orario:") != std::string::npos) && os_utc.length() == 0) {
				pos = buff.find(':');																			// position of ":" in str
				if (pos) {																						//
					os_utc = buff.substr(pos + 1);																//
					os_utc.erase(0, os_utc.find_first_not_of(' '));												//
					posf = os_utc.find_first_of(')');															//
					os_utc = os_utc.substr(5, 5);																//
				}																								//
				break;																							//
			}																									//
		}																										//
		if (fpInfOS) fclose(fpInfOS);																			// Inchide fisierul 'osInfo' daca este deschis

		osName = os_name;																						// Stocheaza numele OS pentru scrierea in LOG
		osVersion = os_build;																					// Stocheaza versiunea OS pentru scrierea in LOG
		osLang = os_lang;																						// Stocheaza limba OS pentru scrierea in LOG
		inLang = in_lang;																						// Stocheaza limba de input OS pentru scrierea in LOG
		osUTC = os_utc;																							// Stocheaza zona de timp OS pentru scrierea in LOG

		versFD = FD_VERSION_STR;																				// Stocheaza versiunea librariei Firma Digitale
		versPDF = FDEL_GetPdfNetCVersionNumber();																// Stocheaza versiunea librariei PDFNetC
		versSBB = SBB_VERSION;																					// Stocheaza versiunea librariei SBB

#ifndef __GNUC__
#pragma endregion 
#endif 
		fpLog = fopen(_fdPathLog.c_str(), "a+");																// Deschide fisierul 'fd-zz-mm-yy.log' pentru adaugari
		if (!fpLog) return;																						// Daca sunt erori la deschidere, paraseste functia
		fprintf(fpLog, "| Utenti               | Computer        | SO Nome                                              | SO Versione   |  Lingua  | In lingua | UTC   | SO Dir              | Vers. FD | Vers. PDFNetC | Versione SB |\n");
		fprintf(fpLog, "|----------------------|-----------------|------------------------------------------------------|---------------|----------|-----------|-------|---------------------|----------|---------------|-------------|\n");
		fprintf(fpLog, "|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|\n", addSpaces(userName, 22).c_str(), addSpaces(computerName, 17).c_str(), addSpaces(osName, 54).c_str(), addSpaces(osVersion, 15).c_str(), addSpaces(osLang, 10).c_str(), addSpaces(inLang, 11).c_str(), addSpaces(osUTC, 7).c_str(), addSpaces(sysDir, 21).c_str(), addSpaces(versFD, 10).c_str(), addSpaces(versPDF, 15).c_str(), addSpaces(versSBB, 13).c_str());
		fprintf(fpLog, "|==========================================================================================================================================================================================================================|\n");
		fprintf(fpLog, "| Ora      |   PID   | Livello info | Funzione              | Sub-Funzione                      | Err | Messaggio\n");
		fclose(fpLog);																							// Inchide fisierul dupa adaugare
	}

	if (!flagInitFDELog) {																						// Daca fisierul LOG nu a fost initializat
		fopen_s(&fpLog, _fdPathLog.c_str(), "a+");																// Deschide fisierul 'fd-zz-mm-yy.log' pentru adaugari
		if (!fpLog) return;																						// Daca sunt erori la deschidere, paraseste functia
		fprintf(fpLog, "|==========|=========|==============|=======================|===================================|=====|==============================================================================================================================\n");
		fclose(fpLog);																							// Inchide fisierul dupa adaugare
		flagInitFDELog = true;																					// Activeaza flag-ul ca fisierul a fost initializat
	}																											//
}																												//

//--------------------------------------------------------------------------------------------------------------// 
// METODO: setLogLevel																							//
//--------------------------------------------------------------------------------------------------------------// 
// METODO SVOLTE: Seteaza nivelul de LOG																		//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 20-10-2022 : Prima stesura																	//
//	- Ticau Vasile - 01-10-2022 : Adaugarea nivelelor de LOG													//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------//
// ARGOMENTI:																									//
//	logLevel		int		(I)	- nivelul de scriere a LOG-ului													//
//								0 - None																		//
//								1 - Exception(Erori grave care cauzeaza o terminare prematura)					//
//								2 - Warning(Erori ce nu perturbeaza executia, insa instiinteaza)				//
//								3 - Info(Evenimente interesante in timpul executiei(pornire / oprire))			//
//								4 - Debug(Informatii detaliate privind fluxul executiei)						//
//								5 - Trace(Informatii detaliate.)												//
//--------------------------------------------------------------------------------------------------------------//
void FDELog::setLogLevel(int logLevel) {																		//
	_logLevel = logLevel;																						// Seteaza var. locala cu nivelul de LOG
	_isLogActive = (_logLevel > LOG_LEVEL_NONE && _logLevel <= LOG_LEVEL_TRACE_MEMORY) ? true : false;			// Seteaza ACTIV/INACTIV scrierea LOG-ului pentru [0 > 'logLevel' <= 5]

	_writeError = false;																						// Flag: Indica ca NU se scriu log-urile de tip EXCEPTIE
	_writeWarning = false;																						// Flag: Indica ca NU se scriu log-urile de tip WARNING
	_writeInfo = false;																							// Flag: Indica ca NU se scriu log-urile de tip INFO
	_writeDebug = false;																						// Flag: Indica ca NU se scriu log-urile de tip DEBUG
	_writeTrace = false;																						// Flag: Indica ca NU se scriu log-urile de tip TRACE
	_writeTraceMem = false;																						// Flag: Indica ca NU se scriu log-urile de tip TRACE MEMORY

	if (logLevel == LOG_LEVEL_ERROR) {																			// Daca nivelul de scriere a LOG-ului este EXCEPTION
		_writeError = true;																						// Flag: Indica ca se scriu log-urile de tip EXCEPTIE
	}
	else if (logLevel == LOG_LEVEL_WARNING) {																	// Daca nivelul de scriere a LOG-ului este WARNING
		_writeError = true;																						// Flag: Indica ca se scriu log-urile de tip EXCEPTIE
		_writeWarning = true;																					// Flag: Indica ca se scriu log-urile de tip WARNING
	}
	else if (logLevel == LOG_LEVEL_INFO) {																		// Daca nivelul de scriere a LOG-ului este INFO
		_writeError = true;																						// Flag: Indica ca se scriu log-urile de tip EXCEPTIE
		_writeWarning = true;																					// Flag: Indica ca se scriu log-urile de tip WARNING
		_writeInfo = true;																						// Flag: Indica ca se scriu log-urile de tip INFO
	}
	else if (logLevel == LOG_LEVEL_DEBUG) {																		// Daca nivelul de scriere a LOG-ului este DEBUG
		_writeError = true;																						// Flag: Indica ca se scriu log-urile de tip EXCEPTIE
		_writeWarning = true;																					// Flag: Indica ca se scriu log-urile de tip WARNING
		_writeInfo = true;																						// Flag: Indica ca se scriu log-urile de tip INFO
		_writeDebug = true;																						// Flag: Indica ca se scriu log-urile de tip DEBUG
	}
	else if (logLevel == LOG_LEVEL_TRACE) {																		// Daca nivelul de scriere a LOG-ului este TRACE
		_writeError = true;																						// Flag: Indica ca se scriu log-urile de tip EXCEPTIE
		_writeWarning = true;																					// Flag: Indica ca se scriu log-urile de tip WARNING
		_writeInfo = true;																						// Flag: Indica ca se scriu log-urile de tip INFO
		_writeDebug = true;																						// Flag: Indica ca se scriu log-urile de tip DEBUG
		_writeTrace = true;																						// Flag: Indica ca se scriu log-urile de tip TRACE
	}
	else if (logLevel == LOG_LEVEL_TRACE_MEMORY) {																// Daca nivelul de scriere a LOG-ului este TRACE MEMORY
		_writeError = true;																						// Flag: Indica ca se scriu log-urile de tip EXCEPTIE
		_writeWarning = true;																					// Flag: Indica ca se scriu log-urile de tip WARNING
		_writeInfo = true;																						// Flag: Indica ca se scriu log-urile de tip INFO
		_writeDebug = true;																						// Flag: Indica ca se scriu log-urile de tip DEBUG
		_writeTrace = true;																						// Flag: Indica ca se scriu log-urile de tip TRACE
		_writeTraceMem = true;																					// Flag: Indica ca se scriu log-urile de tip TRACE MEMORY
	}
}																												//

//--------------------------------------------------------------------------------------------------------------// 
// METODO: setHfirmaDir																							//
//--------------------------------------------------------------------------------------------------------------// 
// METODO SVOLTE: Seteaza folderul HFIRMA																		//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 20-10-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------//
// ARGOMENTI:																									//
//	setHfirmaDir	string		(I)	- path-ul catre folderul HFIRMA												//
//--------------------------------------------------------------------------------------------------------------//
void FDELog::setHfirmaDir(std::string strHfirmaDir) {															//
	_strHfirmaDir = strHfirmaDir;																				// Seteaza var. locala cu calea completa catre 'HFIRMA'
}

//--------------------------------------------------------------------------------------------------------------// 
// METODO: setFdPathLog																							//
//--------------------------------------------------------------------------------------------------------------// 
// METODO SVOLTE: Seteaza calea catre fisierul fd-zz-mm-yy.log													//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 17-01-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------//
// ARGOMENTI:																									//
//	fdPathLog	string		(I)	- path-ul catre fisierul fd-zz-mm-yy.log										//
//--------------------------------------------------------------------------------------------------------------//
void FDELog::setFdPathLog(std::string fdPathLog) {																//
	_fdPathLog = fdPathLog;																						// Seteaza var. locala cu calea completa catre fisierul fd-zz-mm-yy.log
}

//--------------------------------------------------------------------------------------------------------------// 
// METODO: setFunction																							//
//--------------------------------------------------------------------------------------------------------------// 
// METODO SVOLTE: Seteaza numele Functiei	in LOG si reseteaza vectorul de sub-functii							//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 20-10-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------//
// ARGOMENTI:																									//
//	FunctionName	const char*	(I)	- numele Functiei 															//
//--------------------------------------------------------------------------------------------------------------//
void FDELog::setFunction(const char* FunctionName) {															//
	if (_isLogActive) {																							// Daca este activata scrierea LOG-ului
		_function = FunctionName;																				// Seteaza var. locala cu numele functiei ce se executa
		vSFunctions.clear();																					// Curata vectorul de sub-functii
	}
}																												//

//--------------------------------------------------------------------------------------------------------------// 
// METODO: setSFunction																							//
//--------------------------------------------------------------------------------------------------------------// 
// METODO SVOLTE: Seteaza numele sub-Functiei in LOG si seteaza vectorul de sub-functii							//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 20-10-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------//
// ARGOMENTI:																									//
//	subFunctionName	const char*	(I)	- numele sub-Functiei 														//
//--------------------------------------------------------------------------------------------------------------//
void FDELog::setSFunction(const char* subFunctionName) {														//
	if (_isLogActive) {																							// Daca este activata scrierea LOG-ului
		vSFunctions.push_back(subFunctionName);																	// Adauga la finalul vectorului de sub-functii, numele sub-funtieii ce se executa
	}
}																												//

//--------------------------------------------------------------------------------------------------------------// 
// METODO: unsetSFunction																						//
//--------------------------------------------------------------------------------------------------------------// 
// METODO SVOLTE: Reseteaza vectorul de sub-functii																//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 20-10-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------//
void FDELog::unsetSFunction() {																					//
	if (_isLogActive) {																							// Daca este activata scrierea LOG-ului
		if (!vSFunctions.empty())																				// Daca vectorul nu are elemente
			vSFunctions.pop_back();																				// Elimina ultimul element din vectorul de sub-functii
	}
}																												//

//--------------------------------------------------------------------------------------------------------------// 
// METODO: getErrorDesc																							//
//--------------------------------------------------------------------------------------------------------------// 
// METODO SVOLTE: Formeaza si returneaza descrierea erorii in baza codului										//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 20-10-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------//
// ARGOMENTI:																									//
//	warningCode		int		(I)	- codul de Warning 																//
//	msg				char*	(I)	- mesaj aditional la descrierea prestabilita erorii								//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO:																										//
//				char*	- descrierea warning-ului																//
//--------------------------------------------------------------------------------------------------------------//
std::string FDELog::getErrorDesc(int warningCode, char* msg) {													// Declararea metodei
	/*----- Dichiarazione di variabili -------------------------------------------------------------------------*/
	string	warCode;																							// Codului warning-ului 
	string	warName;																							// Numele prestabili warning-ului
	string	warMsg;																								// Mesajul prestabili warning-ului
	string	warDesc;																							// Descrierea ce se retuneaza pentru codul warning-ului
	bool flagErrExist = true;																					// Flag - indica daca a fost identificata descriere pentru codul de warning
	//==========================================================================================================// 
#ifndef __GNUC__																								//
#pragma region Prelucrarea alertelor																			
#endif 																											//
	switch (warningCode) {																						// Mergi catre cazul necesar
	//----- 350 ------------------------------------------------------------------------------------------------//
	case FD_WAR_CFG_LOAD_FAILED: {																				//
		warName = "FD_WAR_CFG_LOAD_FAILED";																		//
		warMsg = "Impossibile caricare il file di configurazione";												//
	}; break;																									//
	//----- 352 ------------------------------------------------------------------------------------------------//
	case FD_WAR_TSL_OPEN_FAILED: {																				//
		warName = "FD_WAR_TSL_OPEN_FAILED";																		//
		warMsg = "Il file TSL non puo essere aperto";															//
	}; break;																									//
	//----- 353 ------------------------------------------------------------------------------------------------//
	case FD_WAR_TSL_CLOSE_FAILED: {																				//
		warName = "FD_WAR_TSL_CLOSE_FAILED";																	//
		warMsg = "Il file TSL non puo essere chiuso";															//
	}; break;																									//
	//----- 354 ------------------------------------------------------------------------------------------------//
	case FD_WAR_CRT_CA_LOAD_FAILED: {																			//
		warName = "FD_WAR_CRT_CA_LOAD_FAILED";																	//
		warMsg = "Impossibile caricare il certificato della CA di fiducia";										//
	}; break;																									//
	//----- 355 ------------------------------------------------------------------------------------------------//
	case FD_WAR_LOG_OPEN_FAILED: {																				//
		warName = "FD_WAR_LOG_OPEN_FAILED";																		//
		warMsg = "Il file LOG non puo essere aperto";															//
	}; break;																									//
	//----- 356 ------------------------------------------------------------------------------------------------//
	case FD_WAR_CERT_DOES_NOT_EXIST: {																			//
		warName = "FD_WAR_CERT_DOES_NOT_EXIST";																	//
		warMsg = "Il certificato utente e NULL";																//
	}; break;																									//
	//----- 357 ------------------------------------------------------------------------------------------------//
	case FD_WAR_TOK_MORE_THAT_ONE: {																			//
		warName = "FD_WAR_TOK_MORE_THAT_ONE";																	//
		warMsg = "Viene rilevato piu di un dispositivo rimovibile, questo puo portare all'identificazione del percorso errato del file DLL.";//
	}; break;																									//
	//----- 358 ------------------------------------------------------------------------------------------------//
	case FD_WAR_COPY_FAILED: {																					//
		warName = "FD_WAR_COPY_FAILED";																			//
		warMsg = "Impossibile copiare il file nella destinazione.";												//
	}; break;																									//
	//----- 359 ------------------------------------------------------------------------------------------------//
	case FD_WAR_OVERWRITE_FILE: {																				//
		warName = "FD_WAR_OVERWRITE_FILE";																		//
		warMsg = "Il file verra sovrascritto.";																	//
	}; break;																									//
	//----- 360 ------------------------------------------------------------------------------------------------//
	case FD_WAR_VALIDATION_FAILED: {																			//
		warName = "FD_WAR_VALIDATION_FAILED";																	//
		warMsg = "Errori durante la convalida del certificato.";												//
	}; break;																									//
	//----- 361 ------------------------------------------------------------------------------------------------//
	case FD_WAR_VALIDATION_OFFLINE: {																			//
		warName = "FD_WAR_VALIDATION_OFFLINE";																	//
		warMsg = "La convalida del certificato viene eseguita OFFLINE.";										//
	}; break;																									//
	//----- 362 ------------------------------------------------------------------------------------------------//
	case FD_WAR_VALIDATION_CUSTOM: {																			//
		warName = "FD_WAR_VALIDATION_CUSTOM";																	//
		warMsg = "E stato specificato un elenco TSL personalizzato.";											//
	}; break;																									//
	//----- 363 ------------------------------------------------------------------------------------------------//
	case FD_WAR_VALIDATION_SKIPPED: {																			//
		warName = "FD_WAR_VALIDATION_SKIPPED";																	//
		warMsg = "La convalida del cert. e stata omessa. Il cert. assegnato potrebbe essere non valido (scaduto, revocato).";	//
	}; break;																									//
	//----- 364 ------------------------------------------------------------------------------------------------//
	case FD_WAR_ASSIGN_UNKNOWN_CA: {																			//
		warName = "FD_WAR_ASSIGN_UNKNOWN_CA";																	//
		warMsg = "Un cert. [NonRepudiation] e stato assegnato forzatamente senza conoscere la CA.";				//
	}; break;																									//
	//----- 365 ------------------------------------------------------------------------------------------------//
	case FD_WAR_FILE_SIGN_FAILED: {																				//
		warName = "FD_WAR_FILE_SIGN_FAILED";																	//
		warMsg = "Errore durante la firma di un file nell'elenco delle firma massiva";							//
	}; break;																									//
	//----- 366 ------------------------------------------------------------------------------------------------//
	case FD_WAR_WGT_SIGN_FAILED: {																				//
		warName = "FD_WAR_WGT_SIGN_FAILED";																		//
		warMsg = "Errore durante la firma con il timbro";														//
	}; break;																									//
	//----- 367 ------------------------------------------------------------------------------------------------//
	case FD_WAR_PDF_INFO_FAILED: {																				//
		warName = "FD_WAR_PDF_INFO_FAILED";																		//
		warMsg = "Impossibile ottenere informazioni sul file PDF";												//
	}; break;																									//
	//----- 368 ------------------------------------------------------------------------------------------------//
	case FD_WAR_SIGN_MASS_PART_FAIL: {																			//
		warName = "FD_WAR_SIGN_MASS_PART_FAIL";																	//
		warMsg = "Uno o piu file nell'elenco dei file non sono stati firmati";									//
	}; break;																									//
	//----- 369 ------------------------------------------------------------------------------------------------//
	case FD_WAR_PDF_OVER_TOT_PAG: {																				//
		warName = "FD_WAR_PDF_OVER_TOT_PAG";																	//
		warMsg = "Il numero di pagina specificato supera il numero totale di pagine del file PDF, la firma viene apposta su tutte le pagine";//
	}; break;																									//
	//----- 370 ------------------------------------------------------------------------------------------------//
	case FD_WAR_CER_BAD_DATA: {																					//
		warName = "FD_WAR_CER_BAD_DATA";																		//
		warMsg = "Formato certificato o certificato non valido sia danneggiato";								//
	}; break;																									//
	//----- 371 ------------------------------------------------------------------------------------------------//
	case FD_WAR_CER_REVOKED: {																					//
		warName = "FD_WAR_CER_REVOKED";																			//
		warMsg = "Il certificato sia revocato dall'emittente";													//
	}; break;																									//
	//----- 372 ------------------------------------------------------------------------------------------------//
	case FD_WAR_CER_NOT_YET_VALID: {																			//
		warName = "FD_WAR_CER_NOT_YET_VALID";																	//
		warMsg = "Il certificato non sia ancora valido";														//
	}; break;																									//
	//----- 373 ------------------------------------------------------------------------------------------------//
	case FD_WAR_CER_EXPIRED: {																					//
		warName = "FD_WAR_CER_EXPIRED";																			//
		warMsg = "Il certificato sia scaduto";																	//
	}; break;																									//
	//----- 374 ------------------------------------------------------------------------------------------------//
	case FD_WAR_CER_INVALID_SIGNATURE: {																		//
		warName = "FD_WAR_CER_INVALID_SIGNATURE";																//
		warMsg = "Il certificato contiene una firma digitale non valida, potrebbe essere danneggiato";			//
	}; break;																									//
	//----- 375 ------------------------------------------------------------------------------------------------//
	case FD_WAR_CER_UNKNOWN_CA: {																				//
		warName = "FD_WAR_CER_UNKNOWN_CA";																		//
		warMsg = "Il certificato dell'emittente (CA) non sia stato trovato";									//
	}; break;																									//
	//----- 376 ------------------------------------------------------------------------------------------------//
	case FD_WAR_CER_CA_UNAUTHORIZED: {																			//
		warName = "FD_WAR_CER_CA_UNAUTHORIZED";																	//
		warMsg = "Uno dei certificati CA non e autorizzato a fungere da CA";									//
	}; break;																									//
	//----- 377 ------------------------------------------------------------------------------------------------//
	case FD_WAR_CER_CRL_NOT_VERIFIED: {																			//
		warName = "FD_WAR_CER_CRL_NOT_VERIFIED";																//
		warMsg = "Non e stato possibile verificare uno o piu CRL";												//
	}; break;																									//
	//----- 378 ------------------------------------------------------------------------------------------------//
	case FD_WAR_CER_OCSP_NOT_VERIFIED: {																		//
		warName = "FD_WAR_CER_OCSP_NOT_VERIFIED";																//
		warMsg = "Non e stato possibile verificare uno o piu risposte OCSP";									//
	}; break;																									//
	//----- 379 ------------------------------------------------------------------------------------------------//
	case FD_WAR_CER_IDENTITY_MISMATCH: {																		//
		warName = "FD_WAR_CER_IDENTITY_MISMATCH";																//
		warMsg = "L'identita protetta dal certificato non corrisponde a quella registrata nel certificato";		//
	}; break;																									//
	//----- 380 ------------------------------------------------------------------------------------------------//
	case FD_WAR_CER_NO_KEY_USAGE: {																				//
		warName = "FD_WAR_CER_NO_KEY_USAGE";																	//
		warMsg = "L'utilizzo obbligatorio della chiave non e abilitato in uno dei certificati della catena";	//
	}; break;																									//
	//----- 381 ------------------------------------------------------------------------------------------------//
	case FD_WAR_CER_BLOKED: {																					//
		warName = "FD_CER_ERR_BLOKED";																			//
		warMsg = "Il certificato fornito sia stato trovato nell'elenco dei certificati bloccati";				//
	}; break;																									//
	//----- 382 ------------------------------------------------------------------------------------------------//
	case FD_WAR_CER_GENERAL_FAILURE: {																			//
		warName = "FD_WAR_CER_GENERAL_FAILURE";																	//
		warMsg = "Errore di convalida generale";																//
	}; break;																									//
	//----- 383 ------------------------------------------------------------------------------------------------//
	case FD_WAR_CER_CHAIN_LOOP: {																				//
		warName = "FD_WAR_CER_CHAIN_LOOP";																		//
		warMsg = "Ciclo a catena: uno dei certificati CA firma ricorsivamente se stesso";						//
	}; break;																									//
	//----- 384 ------------------------------------------------------------------------------------------------//
	case FD_WAR_CER_WEAK_ALGORITHM: {																			//
		warName = "FD_WAR_CER_WEAK_ALGORITHM";																	//
		warMsg = "Un algoritmo debole e utilizzato in uno dei certificati o degli elementi di revoca";			//
	}; break;																									//
	//----- 385 ------------------------------------------------------------------------------------------------//
	case FD_WAR_CER_USER_ENFORCED: {																			//
		warName = "FD_WAR_CER_USER_ENFORCED";																	//
		warMsg = "La catena e stata considerata non valida in seguito all'intervento di un codice utente";		//
	}; break;																									//
	//----- 386 ------------------------------------------------------------------------------------------------//
	case FD_WAR_TOK_WINDOWS_HELLO: {																			//
		warName = "FD_WAR_TOK_WINDOWS_HELLO";																	//
		warMsg = "E stato identificato / escluso un dispositivo 'Windows Hello'.";								//
	}; break;																									//

	//----- 390 ------------------------------------------------------------------------------------------------//
	case FD_WGT_WAR_USER_ABORT_SEL_IMG: {																		//
		warName = "FD_WGT_WAR_USER_ABORT_SEL_IMG";																//
		warMsg = "WIDGET: L'utente ha cancellato la selezione dell'immagine";									//
	}; break;																									//

	//----- 752 ------------------------------------------------------------------------------------------------//
	case FD_WGT_WAR_PDF_MASK_NOT_FOUND: {																		//
		warName = "FD_WGT_WAR_PDF_MASK_NOT_FOUND";																//
		warMsg = "WIDGET: Immagine MASK per widget personalizzato non trovata";									//
	}; break;																									//
	//----- 753 ------------------------------------------------------------------------------------------------//
	case FD_WGT_WAR_PDF_MASK_MUST_BE: {																			//
		warName = "FD_WGT_WAR_PDF_MASK_MUST_BE";																//
		warMsg = "WIDGET: Manca il file MASK";																	//
	}; break;																									//
	//----- 754 ------------------------------------------------------------------------------------------------//
	case FD_WGT_WAR_PDF_IMG_NOT_LOAD: {																			//
		warName = "FD_WGT_WAR_PDF_IMG_NOT_LOAD";																//
		warMsg = "WIDGET: L'immagine del timbro non e supportata o e corrotta.";								//
	}; break;																									//
	//----- Default --------------------------------------------------------------------------------------------//
	default:																									// Mesaj predefiniti pentru codul de warning nu a fost gasit
		flagErrExist = false;																					// Deinitializeaza flagul indicand ca lipseste mesaj prestabilit
		break;																									//
	}																											//
#ifndef __GNUC__																								//
#pragma endregion 																								
#endif 																											//
																												//
	warDesc.append(warMsg);																						// Adauga mesajul prestabilit
	if (flagErrExist) {																							// Daca exista mesaj prestabilit codului de warning
		warCode = FDEL_ConvertDecIntToString(warningCode);														// Converteste codul warning-ului in string
		warDesc.append(" | ");																					// Adauga la descrierea warning-ului
	}																											//
	warDesc.append(msg);																						// Adauga mesajul aditional la descrierea warning-ului
	return warDesc;																								// Returneaza descrierea warning-ului
}																												//

//--------------------------------------------------------------------------------------------------------------// 
// METODO: getErrorDesc																							//
//--------------------------------------------------------------------------------------------------------------// 
// METODO SVOLTE: Formeaza si returneaza descrierea erorii in baza codului de eroare, adaugand numarul liniei 	//
//					de cod in care s-a produs eroarea															//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 20-10-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------//
// ARGOMENTI:																									//
//	line		int		(I)	- linia curenta in cod																//
//	error		int		(I)	- codul erorii																		//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO:																										//
//				char*	- descrierea erorii																		//
//--------------------------------------------------------------------------------------------------------------//
std::string FDELog::getErrorDesc(int line, int error) {															// Declararea metodei
	/*----- Dichiarazione di variabili -------------------------------------------------------------------------*/
	string errorName;																							//
	string errorMsg;																							//
	string errorDesc;																							//
	//==========================================================================================================// 
	errorDesc.assign(FDEL_ConvertDecIntToString(line));															// Initializeaza descrierea erorii cu numarul liniei de cod curenta
	if (!FDELog::inFile.empty())																				// Daca este specificat fisierul de INPUT
		errorDesc.append(" | [" + FDELog::inFile + "]");														// Adauga in descriere numele fisierului de INPUT
#ifndef __GNUC__																								//
#pragma region Prelucrarea erorilor																				
#endif 																											//
	switch (error) {																							// Mergi catre cazul necesar
		//----- 7 --------------------------------------------------------------------------------------------------//
	case HBL_ERR_WRT_CLOSE_OUT_FILE: {
		errorName = "HBL_ERR_WRT_CLOSE_OUT_FILE";
		errorMsg = "Si stato verificato un errore quando si tenta di aprire / chiudere il file di output per HBL";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 51 --------------------------------------------------------------------------------------------------//
	case FD_WRONG_ARG_HBL1: {
		errorName = "FD_WRONG_ARG_HBL1";
		errorMsg = "Il parametro nella posizione 1  e errato nel wrapper HBL"; errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 52 --------------------------------------------------------------------------------------------------//
	case FD_WRONG_ARG_HBL2: {
		errorName = "FD_WRONG_ARG_HBL2";
		errorMsg = "Il parametro nella posizione 2  e errato nel wrapper HBL"; errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 53 --------------------------------------------------------------------------------------------------//
	case FD_WRONG_ARG_HBL3: {
		errorName = "FD_WRONG_ARG_HBL3";
		errorMsg = "Il parametro nella posizione 3  e errato nel wrapper HBL"; errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 54 --------------------------------------------------------------------------------------------------//
	case FD_WRONG_ARG_HBL4: {
		errorName = "FD_WRONG_ARG_HBL4";
		errorMsg = "Il parametro nella posizione 4  e errato nel wrapper HBL"; errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 55 --------------------------------------------------------------------------------------------------//
	case FD_WRONG_ARG_HBL5: {
		errorName = "FD_WRONG_ARG_HBL5";
		errorMsg = "Il parametro nella posizione 5  e errato nel wrapper HBL"; errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 56 --------------------------------------------------------------------------------------------------//
	case FD_WRONG_ARG_HBL6: {
		errorName = "FD_WRONG_ARG_HBL6";
		errorMsg = "Il parametro nella posizione 6  e errato nel wrapper HBL"; errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 57 --------------------------------------------------------------------------------------------------//
	case FD_WRONG_ARG_HBL7: {
		errorName = "FD_WRONG_ARG_HBL7";
		errorMsg = "Il parametro nella posizione 7  e errato nel wrapper HBL"; errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 58 --------------------------------------------------------------------------------------------------//
	case FD_WRONG_ARG_HBL8: {
		errorName = "FD_WRONG_ARG_HBL8";
		errorMsg = "Il parametro nella posizione 8  e errato nel wrapper HBL"; errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 59 --------------------------------------------------------------------------------------------------//
	case FD_WRONG_ARG_HBL9: {
		errorName = "FD_WRONG_ARG_HBL9";
		errorMsg = "Il parametro nella posizione 9  e errato nel wrapper HBL"; errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 60 --------------------------------------------------------------------------------------------------//
	case FD_WRONG_ARG_HBL10: {
		errorName = "FD_WRONG_ARG_HBL10";
		errorMsg = "Il parametro nella posizione 10 e errato nel wrapper HBL"; errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 61 --------------------------------------------------------------------------------------------------//
	case FD_WRONG_ARG_HBL11: {
		errorName = "FD_WRONG_ARG_HBL11";
		errorMsg = "Il parametro nella posizione 11 e errato nel wrapper HBL"; errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 62 --------------------------------------------------------------------------------------------------//
	case FD_WRONG_ARG_HBL12: {
		errorName = "FD_WRONG_ARG_HBL12";
		errorMsg = "Il parametro nella posizione 12 e errato nel wrapper HBL"; errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 63 --------------------------------------------------------------------------------------------------//
	case FD_WRONG_ARG_HBL13: {
		errorName = "FD_WRONG_ARG_HBL13";
		errorMsg = "Il parametro nella posizione 13 e errato nel wrapper HBL"; errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 64 --------------------------------------------------------------------------------------------------//
	case FD_WRONG_ARG_HBL14: {
		errorName = "FD_WRONG_ARG_HBL14";
		errorMsg = "Il parametro nella posizione 14 e errato nel wrapper HBL"; errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 65 --------------------------------------------------------------------------------------------------//
	case FD_WRONG_ARG_HBL15: {
		errorName = "FD_WRONG_ARG_HBL15";
		errorMsg = "Il parametro nella posizione 15 e errato nel wrapper HBL"; errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 66 --------------------------------------------------------------------------------------------------//
	case FD_WRONG_ARG_HBL16: {
		errorName = "FD_WRONG_ARG_HBL16";
		errorMsg = "Il parametro nella posizione 16 e errato nel wrapper HBL"; errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 67 --------------------------------------------------------------------------------------------------//
	case FD_WRONG_ARG_HBL17: {
		errorName = "FD_WRONG_ARG_HBL17";
		errorMsg = "Il parametro nella posizione 17 e errato nel wrapper HBL"; errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 68 --------------------------------------------------------------------------------------------------//
	case FD_WRONG_ARG_HBL18: {
		errorName = "FD_WRONG_ARG_HBL18";
		errorMsg = "Il parametro nella posizione 18 e errato nel wrapper HBL"; errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 69 --------------------------------------------------------------------------------------------------//
	case FD_WRONG_ARG_HBL19: {
		errorName = "FD_WRONG_ARG_HBL19";
		errorMsg = "Il parametro nella posizione 19 e errato nel wrapper HBL"; errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 70 --------------------------------------------------------------------------------------------------//
	case FD_WRONG_ARG_HBL20: {
		errorName = "FD_WRONG_ARG_HBL20";
		errorMsg = "Il parametro nella posizione 20 e errato nel wrapper HBL"; errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 98 -------------------------------------------------------------------------------------------------//
	case EXE_ERR_MISSING_PARAMS: {
		errorName = "EXE_ERR_MISSING_PARAMS";
		errorMsg = "Parametri mancanti nel agento di firma digitale";
		errorDesc.append(" | Eccezione nella eseguibile FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 99 -------------------------------------------------------------------------------------------------//
	case HBL_ERR_MISSING_PARAMS: {
		errorName = "HBL_ERR_MISSING_PARAMS";
		errorMsg = "Parametri mancanti nel wrapper HBL";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 100 ------------------------------------------------------------------------------------------------//
	case FD_ERR_INVALID_TYPE: {
		errorName = "FD_ERR_INVALID_TYPE";
		errorMsg = "Tipo di file non valido";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 101 ------------------------------------------------------------------------------------------------//
	case FD_ERR_NOT_SIGNED_TYPE: {
		errorName = "FD_ERR_NOT_SIGNED_TYPE";
		errorMsg = "Il file non sia un tipo firmato";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 102 ------------------------------------------------------------------------------------------------//
	case FD_ERR_NO_SIGNATURE: {
		errorName = "FD_ERR_NO_SIGNATURE";
		errorMsg = "Il file non ha firma";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 103 ------------------------------------------------------------------------------------------------//
	case FD_ERR_TIMESTAMP_NOT_SET: {
		errorName = "FD_ERR_TIMESTAMP_NOT_SET";
		errorMsg = "URL Timestamp non sia impostato o e erroneamente indicato (Non inizia con 'HTTP').";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 104 ------------------------------------------------------------------------------------------------//
	case FD_ERR_LOAD_FAILED: {
		errorName = "FD_ERR_LOAD_FAILED";
		errorMsg = "Impossibile caricare il file";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 105 ------------------------------------------------------------------------------------------------//
	case FD_ERR_COPY_FAILED: {
		errorName = "FD_ERR_COPY_FAILED";
		errorMsg = "Impossibile copiare il file";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 106 ------------------------------------------------------------------------------------------------//
	case FD_ERR_SIGN_FAILED: {
		errorName = "FD_ERR_SIGN_FAILED";
		errorMsg = "Impossibile firmare il file";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 107 ------------------------------------------------------------------------------------------------//
	case FD_ERR_KEY_NOT_LOAD: {
		errorName = "FD_ERR_KEY_NOT_LOAD";
		errorMsg = "Impossibile caricare la chiave del certificato";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 108 ------------------------------------------------------------------------------------------------//
	case FD_ERR_UNSUPPORTED_SIGNATURE: {
		errorName = "FD_ERR_UNSUPPORTED_SIGNATURE";
		errorMsg = "Firma non supportata";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 109 ------------------------------------------------------------------------------------------------//
	case FD_ERR_SAVE_FAILED: {
		errorName = "FD_ERR_SAVE_FAILED";
		errorMsg = "Impossibile salvare il file";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 110 ------------------------------------------------------------------------------------------------//
	case FD_ERR_SIGN_INVALID: {
		errorName = "FD_ERR_SIGN_INVALID";
		errorMsg = "Firma non valida";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 111 ------------------------------------------------------------------------------------------------//
	case FD_ERR_SIGN_WAS_CANCELED: {
		errorName = "FD_ERR_SIGN_WAS_CANCELED";
		errorMsg = "La firma nel documento PDF e stata annullata";
		errorDesc.append(" | Eccezione nella libreria PDFNetC: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 112 ------------------------------------------------------------------------------------------------//
	case FD_ERR_FORCE_EXIT: {
		errorName = "FD_ERR_FORCE_EXIT";
		errorMsg = "L'utente e uscito forzatamente dall'applicazione EXE con il tasto [X].";
		errorDesc.append(" | Eccezione nella FIRMA_DIGITALE.EXE: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 113 ------------------------------------------------------------------------------------------------//
	case FD_ERR_OPEN_MASS_FAIL: {
		errorName = "FD_ERR_OPEN_MASS_FAIL";
		errorMsg = "Il file con percorsi di file non puo essere aperto per la lettura, probabilmente manca il file o il suo percorso e sbagliato";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 114 ------------------------------------------------------------------------------------------------//
	case FD_ERR_BAD_CHARACTER: {
		errorName = "FD_ERR_BAD_CHARACTER";
		errorMsg = "Impossibile caricare il file PDF perche contiene un errore come \"Carattere imprevisto\" e non e possibile ripararlo, probabilmente il file e corrotto";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 115 ------------------------------------------------------------------------------------------------//
	case FD_ERR_BAD_CONTENT: {
		errorName = "FD_ERR_BAD_CONTENT";
		errorMsg = "Impossibile caricare il file perche contiene meno di 1 Kb o contenuto mancante, probabilmente il file e corrotto";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 116 ------------------------------------------------------------------------------------------------//
	case FD_ERR_UNSUPPORTED_TYPE: {
		errorName = "FD_ERR_UNSUPPORTED_TYPE";
		errorMsg = "Il tipo di file specificato non e supportato";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 117 ------------------------------------------------------------------------------------------------//
	case FD_ERR_NOT_TIMESTAMPED: {
		errorName = "FD_ERR_NOT_TIMESTAMPED";
		errorMsg = "Il file non ha il timestamp";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 118 ------------------------------------------------------------------------------------------------//
	case FD_ERR_NO_SEAL: {
		errorName = "FD_ERR_NO_SEAL";
		errorMsg = "Il file non ha sigilli";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 119 ------------------------------------------------------------------------------------------------//
	case FD_ERR_COUNTERSIGN_FAILED: {
		errorName = "FD_ERR_COUNTERSIGN_FAILED";
		errorMsg = "Impossibile controfirmare il file";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 120 ------------------------------------------------------------------------------------------------//
	case FD_ERR_SIGN_MASS_FAIL: {
		errorName = "FD_ERR_SIGN_MASS_FAIL";
		errorMsg = "Errori durante la firma massiva";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 121 ------------------------------------------------------------------------------------------------//
	case FD_ERR_FILE_DOES_NOT_EXIST: {
		errorName = "FD_ERR_FILE_DOES_NOT_EXIST";
		errorMsg = "Il file non esiste";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 122 ------------------------------------------------------------------------------------------------//
	case FD_ERR_TIMESTAMP_FAILED: {
		errorName = "FD_ERR_TIMESTAMP_FAILED";
		errorMsg = "Impossibile applicare il timestamp al file";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 123 ------------------------------------------------------------------------------------------------//
	case FD_ERR_VERIFY_FAILED: {
		errorName = "FD_ERR_VERIFY_FAILED";
		errorMsg = "Impossibile verificare il file";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;

		//----- 130 ------------------------------------------------------------------------------------------------//
	case FD_ERR_FILE_IS_PROTECTED: {																				//
		errorName = "FD_ERR_FILE_IS_PROTECTED";																		//
		errorMsg = "Il file PDF e protetto da password/certificato, non si puo modificare";							//
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;																										//
		//----- 131 ------------------------------------------------------------------------------------------------//
	case FD_ERR_REMOVE_PROTECTION: {																				//
		errorName = "FD_ERR_REMOVE_PROTECTION";																		//
		errorMsg = "Errore nella rimozione delle restrizioni protette da password/certificato";						//
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;																										//
		//----- 160 ------------------------------------------------------------------------------------------------//
	case FD_TOK_ERR_PIN_INCORRECT: {
		errorName = "FD_TOK_ERR_PIN_INCORRECT";
		errorMsg = "PIN: impossibile firmare il file, codice pin errato";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 163 ------------------------------------------------------------------------------------------------//
	case FD_TOK_ERR_PIN_EXPIRED: {
		errorName = "FD_TOK_ERR_PIN_EXPIRED";
		errorMsg = "PIN: impossibile firmare il file, codice pin scaduto";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 164 ------------------------------------------------------------------------------------------------//
	case FD_TOK_ERR_PIN_LOCKED: {
		errorName = "FD_TOK_ERR_PIN_LOCKED";
		errorMsg = "PIN: impossibile firmare il file, codice pin bloccato";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;

		//----- 221 ------------------------------------------------------------------------------------------------//
	case FD_TOK_ERR_CMD_IS_NOT_EXECUTED: {
		errorName = "FD_TOK_ERR_CMD_IS_NOT_EXECUTED";
		errorMsg = "TOKEN: impossibile eseguire il comando CMD per trovare il token";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 222 ------------------------------------------------------------------------------------------------//
	case FD_TOK_ERR_TOKEN_DLL_NOT_FOUND: {
		errorName = "FD_TOK_ERR_TOKEN_DLL_NOT_FOUND";
		errorMsg = "TOKEN: impossibile firmare il file, file dll token non trovato";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 223 ------------------------------------------------------------------------------------------------//
	case FD_TOK_ERR_TOKEN_NOT_FOUND: {
		errorName = "FD_TOK_ERR_TOKEN_NOT_FOUND";
		errorMsg = "TOKEN: impossibile firmare il file, token non trovato";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 224 ------------------------------------------------------------------------------------------------//
	case FD_TOK_ERR_TOKEN_NOT_PRESENT: {
		errorName = "FD_TOK_ERR_TOKEN_NOT_PRESENT";
		errorMsg = "TOKEN: impossibile firmare il file, token non presente o il driver non puo accedere completamente il token";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 225 ------------------------------------------------------------------------------------------------//
	case FD_TOK_ERR_USED_DLL_IS_WRONG: {
		errorName = "FD_TOK_ERR_USED_DLL_IS_WRONG";
		errorMsg = "TOKEN: Impossibile firmare file dll utilizzato sia sbagliato o danneggiato";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 226 ------------------------------------------------------------------------------------------------//
	case FD_TOK_ERR_OPEN_FAILED: {
		errorName = "FD_TOK_ERR_OPEN_FAILED";
		errorMsg = "TOKEN: Impossibile aprire il token, si e verificato un errore.";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 227 ------------------------------------------------------------------------------------------------//
	case FD_TOK_ERR_WRONG_LOCATION: {
		errorName = "FD_TOK_ERR_WRONG_LOCATION";
		errorMsg = "TOKEN: La posizione specificata e sbagliata";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;

		//----- 251 ------------------------------------------------------------------------------------------------//
	case FD_WGT_ERR_GET_IMG_ENC_FAIL: {
		errorName = "FD_WGT_ERR_GET_IMG_ENC_FAIL";
		errorMsg = "TIMBRO: Non e stato determinato il numero di codifica dell'immagine.";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 252 ------------------------------------------------------------------------------------------------//
	case FD_WGT_ERR_QR_TO_PNG_FAIL: {
		errorName = "FD_WGT_ERR_QR_TO_PNG_FAIL";
		errorMsg = "TIMBRO: Generazione QR in PNG non riuscita.";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 253 ------------------------------------------------------------------------------------------------//
	case FD_WGT_ERR_CONV_TO_JPG_FAIL: {
		errorName = "FD_WGT_ERR_CONV_TO_JPG_FAIL";
		errorMsg = "TIMBRO: Conversione dell'immagine in JPEG non riuscita.";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;

		//----- 420 ------------------------------------------------------------------------------------------------//
	case FD_CER_ERR_NOT_FOUND: {
		errorName = "FD_CER_ERR_NOT_FOUND";
		errorMsg = "Il certificato non sia stato trovato";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 421 ------------------------------------------------------------------------------------------------//
	case FD_CER_ERR_LOAD_PFX: {
		errorName = "FD_CER_ERR_LOAD_PFX";
		errorMsg = "Errore durante il caricamento del certificato di firma da PFX, probabilmente il codice PIN e errato";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 450 ------------------------------------------------------------------------------------------------//
	case FD_CER_ERR_NO_SIGN_CRT: {																					//
		errorName = "FD_CER_ERR_NO_SIGN_CRT";																		//
		errorMsg = "Non e stato trovato alcun certificato di firma valido.";		//
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;

		//----- 701 --------------------------------------------------------------------------------------------//
	case FD_WGT_ERR_DEF_WGT_NOT_LOAD: {																			//
		errorName = "FD_WGT_ERR_DEF_WGT_NOT_LOAD";																//
		errorMsg = "WIDGET: Il widget predefinito non caricato";
		errorDesc.append(" | Eccezione nella libreria PDFNetC: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 702 --------------------------------------------------------------------------------------------//
	case FD_WGT_ERR_USER_WGT_NOT_LOAD: {																		//
		errorName = "FD_WGT_ERR_USER_WGT_NOT_LOAD";																//
		errorMsg = "WIDGET: Il widget selezionato dall'utente non e stato caricato con successo";
		errorDesc.append(" | Eccezione nella libreria PDFNetC: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 703 --------------------------------------------------------------------------------------------//
	case FD_WGT_ERR_USER_WGT_NOT_SAVED: {																		//
		errorName = "FD_WGT_ERR_USER_WGT_NOT_SAVED";															//
		errorMsg = "WIDGET: Il widget selezionato dall'utente non e stato salvato";
		errorDesc.append(" | Eccezione nella libreria PDFNetC: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 704 --------------------------------------------------------------------------------------------//
	case FD_WGT_ERR_DEF_PFX_NOT_CREATED: {																		//
		errorName = "FD_WGT_ERR_DEF_PFX_NOT_CREATED";															//
		errorMsg = "WIDGET: Il file PFX non e stato creato";
		errorDesc.append(" | Eccezione nella libreria PDFNetC: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 705 --------------------------------------------------------------------------------------------//
	case FD_WGT_ERR_DEF_PFX_NOT_WRITED: {																		//
		errorName = "FD_WGT_ERR_DEF_PFX_NOT_WRITED";															//
		errorMsg = "WIDGET: Il file PFX non e stato scritto";
		errorDesc.append(" | Eccezione nella libreria PDFNetC: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;

		//----- 751 --------------------------------------------------------------------------------------------//
	case FD_WGT_ERR_PDF_JPEG_NOT_FOUND: {																		//
		errorName = "FD_WGT_ERR_PDF_JPEG_NOT_FOUND";															//
		errorMsg = "WIDGET: Immagine JPEG per widget personalizzato non trovata";
		errorDesc.append(" | Eccezione nella libreria PDFNetC: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;


		//----- 798 ------------------------------------------------------------------------------------------------//
	case FD_ERR_INVALID_PDF_KEY: {																				//
		errorName = "FD_ERR_INVALID_PDF_KEY";																	//
		errorMsg = "Codice di sblocco di libreria PDFNetC non valido, impossibile impostare la chiave di licenza";
		errorDesc.append(" | Eccezione nella libreria PDFNetC: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;

		//----- 897 ------------------------------------------------------------------------------------------------//
	case FD_ERR_NO_IMPLEMENTATION: {																			//
		errorName = "FD_ERR_NO_IMPLEMENTATION";																	//
		errorMsg = "Il funzionale non e ancora implementato";													//
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 898 ------------------------------------------------------------------------------------------------//
	case FD_ERR_INVALID_SBB_KEY: {																				//
		errorName = "FD_ERR_INVALID_SBB_KEY";																	//
		errorMsg = "Codice di sblocco non valido, impossibile impostare la chiave di licenza";					//
		errorDesc.append(" | Eccezione nella libreria SecureBlackbox: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 899 ------------------------------------------------------------------------------------------------//
	case FD_ERR_SBB_EXCEPTION: {																				//
		errorName = "FD_ERR_SBB_EXCEPTION";																		//
		errorMsg = "Si sia verificata l'eccezione SBB";															//
		errorDesc.append(" | Eccezione nella libreria SecureBlackbox: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 999 -------------------------------------------------------------------------------------------------//
	case UNKNOWN_ERROR: {
		errorName = "UNKNOWN_ERROR";
		errorMsg = "Si sia verificato un errore sconosciuto";
		errorDesc.append(" | Eccezione nella libreria FirmaDigitale: " + errorName + "(Messaggio: '" + errorMsg + "', errore: " + FDEL_ConvertDecIntToString(error) + ")");
	}; break;
		//----- 000 ------------------------------------------------------------------------------------------------//
	default:																									//
		break;																									//
	}																											//
#ifndef __GNUC__																								//
#pragma endregion 																								
#endif 																											//
	return errorDesc;																							// Returneaza descrierea erorii
}

//--------------------------------------------------------------------------------------------------------------// 
// METODO: getErrorDesc																							//
//--------------------------------------------------------------------------------------------------------------// 
// METODO SVOLTE: Formeaza si returneaza descrierea erorii in baza codului de eroare, adaugand numarul liniei 	//
//					de cod in care s-a produs eroarea si mesaj aditional										//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 20-10-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------//
// ARGOMENTI:																									//
//	line		int		(I)	- linia curenta in cod																//
//	error		int		(I)	- codul erorii																		//
//	msg			char*	(I)	- mesaj aditional la descrierea prestabilita erorii									//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO:																										//
//				char*	- descrierea erorii																		//
//--------------------------------------------------------------------------------------------------------------//
std::string FDELog::getErrorDesc(int line, int error, char* msg) {												//
	/*----- Dichiarazione di variabili -------------------------------------------------------------------------*/
	string	errorDesc;																							// Descrierea ce se retuneaza pentru codul erorii
	//==========================================================================================================// 
	errorDesc.assign(getErrorDesc(line, error));																// Initializeaza descrierea erorii cu descrierea retunata in baza codului
	errorDesc.append(" |> ");																					// Adauga separatorul pentru mesajul aditional
	errorDesc.append(msg);																						// Adauga in descrierea mesajul aditional
	return errorDesc;																							// Returneaza descrierea erorii
}																												//

//--------------------------------------------------------------------------------------------------------------// 
// METODO: file																									//
//--------------------------------------------------------------------------------------------------------------// 
// METODO SVOLTE: Scrie in fisier aparte LOG-ul	si salveaza in \HFIRMA\LOG\ValidationLOG.log					//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 24-10-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------//
// ARGOMENTI:																									//
//	fileName	const char*		(I)	- numele fisierului ce se va crea											//
//	msg			char*			(I)	- mesajul ce se va inscrie in fisier										//
//--------------------------------------------------------------------------------------------------------------//
void FDELog::file(const char* fileName, char* msg) {
	/*==========================================================================================================*/
	if (_isLogActive) {																							// Daca este activata scrierea LOG-ului
		/*----- Dichiarazione di variabili ---------------------------------------------------------------------*/
		char validationLogPath[PATH_SIZE] = "";																	// The Firma Digitale validation log file path
		//======================================================================================================// 
		SPRINTF(validationLogPath, "%sLOG\\%s.log", _strHfirmaDir.c_str(), fileName);							// Formeaza calea cate fisierul 'ValidationLOG.log'
		FILE* fpValidationLogPath = fopen(validationLogPath, "w");												// Deschide fisierul in mod creare
		if (!fpValidationLogPath) return;																		// Daca nu s-a putut deschide fisierul  atunci paraseste fucntia 
		fprintf(fpValidationLogPath, "%s", msg);																// Scrie mesajul in fisier
		fclose(fpValidationLogPath);																			// Daca fisierul este deschis, inchide-l
		FDELog::info("Il file LOG viene salvato in [%s]", validationLogPath);									// Scrie in LOG - INFO
		return;																									// Paraseste executia
	}
}

#pragma endregion

//==============================================================================================================// 
//	Nivelurile de scriere a LOG-ului																			//
//==============================================================================================================// 


#pragma region EXCEPTION LEVEL
//--------------------------------------------------------------------------------------------------------------// 
// METODO: exception																							//
//--------------------------------------------------------------------------------------------------------------// 
// METODO SVOLTE: Scrie in fisierul LOG in modul EXCEPTION 														//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 20-10-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------//
// ARGOMENTI:																									//
//	line		int		(I)	- linia curenta in cod																//
//	error		int		(I)	- codul exceptiei																	//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO:																										//
//				int		- codul la exceptie																		//
//--------------------------------------------------------------------------------------------------------------//
int FDELog::exception(int lineNumber, int errorCode) {
	/*==========================================================================================================*/
	if (_writeError) {																							// Daca este activata scrierea EXCEPTIILOR
		/*----- Dichiarazione di variabili ---------------------------------------------------------------------*/
		string vSFunction = "";																					// Numele sub-functiei
		//======================================================================================================// 
		if (!FDELog::vSFunctions.empty())																		// Daca vectorul de sub-functii are elemente
			vSFunction = FDELog::vSFunctions.back();															// Atribuie ultimul element ca nule sub-fuctiei
		FDELog::fpLog = fopen(_fdPathLog.c_str(), "a+");														// Deschide fisierul in mod adaugare
		if (!FDELog::fpLog) return FD_WAR_LOG_OPEN_FAILED;														// Daca nu s-a putut deschide fisierul  atunci paraseste fucntia 
		FDELog::level = "Eccezione";																			// Seteaza nivelul de informare - EXCEPTION
		fprintf(FDELog::fpLog, "|%s|%s|%s|%s|%s|%s| %s\n", addSpaces(FDEL_GetLocalTimeNow(), 10).c_str(), addSpaces(_strPID, 9).c_str(), addSpaces(FDELog::level, 14).c_str(), addSpaces(FDELog::_function, 23).c_str(), addSpaces(vSFunction, 35).c_str(), addSpaces(FDEL_ConvertDecIntToString(errorCode), 5).c_str(), getErrorDesc(lineNumber, errorCode).c_str());
		fclose(FDELog::fpLog);																					// Inchide fisierul FD
	}
	return errorCode;																							// Returneaza codul la eroare
}																												//

//--------------------------------------------------------------------------------------------------------------// 
// METODO: exception																							//
//--------------------------------------------------------------------------------------------------------------// 
// METODO SVOLTE: Scrie in fisierul LOG in modul EXCEPTION cu adaugarea unui mesaj de descriere					//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 20-10-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------//
// ARGOMENTI:																									//
//	line		int				(I)	- linia curenta in cod														//
//	error		int				(I)	- codul exceptiei															//
//	format		const char*		(I)	- formatul mesajului														//
//	...			void			(I)	- argumentii in baza formatarii												//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO:																										//
//				int		- codul la exceptie																		//
//--------------------------------------------------------------------------------------------------------------//
int FDELog::exception(int lineNumber, int errorCode, const char* format, ...) {									//
	/*==========================================================================================================*/
	if (_writeError) {																							// Daca este activata scrierea EXCEPTIILOR
		/*----- Dichiarazione di variabili ---------------------------------------------------------------------*/
		string vSFunction = "";																					// Numele sub-functiei
		//======================================================================================================// 
		if (!FDELog::vSFunctions.empty())																		// Daca vectorul de sub-functii are elemente
			vSFunction = FDELog::vSFunctions.back();															// Atribuie ultimul element ca nule sub-fuctiei
		FDELog::fpLog = fopen(_fdPathLog.c_str(), "a+");														// Deschide fisierul in mod adaugare
		if (!FDELog::fpLog) return FD_WAR_LOG_OPEN_FAILED;														// Daca nu s-a putut deschide fisierul  atunci paraseste fucntia 
		FDELog::level = "Eccezione";																			// Seteaza nivelul de informare - EXCEPTION
		va_list args;																							// lista de argumenti pentru formatare
		va_start(args, format);																					// Incepe parsarea listei de argumenti conform formatarii
		int mesLen = vsnprintf(NULL, 0, format, args);															// Calculeaza lungimea necesara a buferului si adauga o unitate
		char* message = (char*)malloc(mesLen + 1);																// Alocarea memoriei pentru variabila + terminator
		if (!message) { fclose(FDELog::fpLog); return FD_ERR_MEM_ALLOC; };										// Se la variabile "message" e nulla, restituisce l'errore si inchide fisierul FD
		va_start(args, format);																					// Reinitializeaza lista de argumente si formateaza sirul
		vsprintf(message, format, args);																		// Inscrie in buffer sirul formatat cu valori
		va_end(args);																							// Incheie parsarea argumentilor
		fprintf(FDELog::fpLog, "|%s|%s|%s|%s|%s|%s| %s\n", addSpaces(FDEL_GetLocalTimeNow(), 10).c_str(), addSpaces(_strPID, 9).c_str(), addSpaces(FDELog::level, 14).c_str(), addSpaces(FDELog::_function, 23).c_str(), addSpaces(vSFunction, 35).c_str(), addSpaces(FDEL_ConvertDecIntToString(errorCode), 5).c_str(), getErrorDesc(lineNumber, errorCode, message).c_str());
		free(message);																							// Libera la memoria del puntatore
		fclose(FDELog::fpLog);																					// Inchide fisierul FD
	}
	return errorCode;																							// Returneaza codul la eroare
}																												//

//--------------------------------------------------------------------------------------------------------------// 
// METODO: exception																							//
//--------------------------------------------------------------------------------------------------------------// 
// METODO SVOLTE: Scrie in fisierul LOG in modul EXCEPTION 														//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 20-10-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------//
// ARGOMENTI:																									//
//	line		int			(I)	- linia curenta in cod															//
//	msg			const char*	(I)	- mesajul	aditional															//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO:																										//
//				int		- codul la exceptie																		//
//--------------------------------------------------------------------------------------------------------------//
int FDELog::exception(int lineNumber, const char* msg) {														//
	/*==========================================================================================================*/
	if (_writeError) {																							// Daca este activata scrierea EXCEPTIILOR
		/*----- Dichiarazione di variabili ---------------------------------------------------------------------*/
		string	errorDesc;																						// Descrierea ce se retuneaza pentru codul erorii
		string vSFunction = "";																					// Numele sub-functiei
		//======================================================================================================// 
		if (!vSFunctions.empty())																				// Daca vectorul de sub-functii are elemente
			vSFunction = vSFunctions.back();																	// Atribuie ultimul element ca nule sub-fuctiei
		FDELog::fpLog = fopen(_fdPathLog.c_str(), "a+");														// Deschide fisierul in mod adaugare
		if (!FDELog::fpLog) return FD_WAR_LOG_OPEN_FAILED;														// Daca nu s-a putut deschide fisierul  atunci paraseste fucntia 
		FDELog::level = "Eccezione";																			// Seteaza nivelul de informare - EXCEPTION
		errorDesc.assign(FDEL_ConvertDecIntToString(lineNumber));												// Initializeaza descrierea erorii cu numarul liniei de cod ce se executa
		errorDesc.append(" | ");																				// Adauga separatorul in descrierea erorii
		errorDesc.append(msg);																					// Adauga mesajul aditional in descrierea erorii
		fprintf(FDELog::fpLog, "|%s|%s|%s|%s|%s|%s| %s\n", addSpaces(FDEL_GetLocalTimeNow(), 10).c_str(), addSpaces(_strPID, 9).c_str(), addSpaces(FDELog::level, 14).c_str(), addSpaces(FDELog::_function, 23).c_str(), addSpaces(vSFunction, 35).c_str(), addSpaces(FDEL_ConvertDecIntToString(FD_ERR_SBB_EXCEPTION), 5).c_str(), errorDesc.c_str());
		fclose(FDELog::fpLog);																					// Inchide fisierul FD
	}
	return FD_ERR_SBB_EXCEPTION;																				// Returneaza eroarea generala 899 - SBB Exception
}


#pragma endregion

#pragma region WARNING LEVEL
//--------------------------------------------------------------------------------------------------------------// 
// METODO: warning																								//
//--------------------------------------------------------------------------------------------------------------// 
// METODO SVOLTE: Scrie in fisierul LOG in modul WARNING 														//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 20-10-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------//
// ARGOMENTI:																									//
//	warningCode		int				(I)	- codul warning															//
//	format			const char*		(I)	- formatul mesajului													//
//	...				void			(I)	- argumentii in baza formatarii											//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO:																										//
//				int		- codul la warning																		//
//--------------------------------------------------------------------------------------------------------------//
int FDELog::warning(int warningCode, const char* format, ...) {													// Declararea metodei
	/*==========================================================================================================*/
	if (_writeWarning) {																						// Daca este activata scrierea WARNING
		/*----- Dichiarazione di variabili ---------------------------------------------------------------------*/
		string vSFunction = "";																					// Numele sub-functiei
		//======================================================================================================// 
		if (!vSFunctions.empty())																				// Daca vectorul de sub-functii are elemente
			vSFunction = vSFunctions.back();																	// Atribuie ultimul element ca nule sub-fuctiei
		FDELog::fpLog = fopen(_fdPathLog.c_str(), "a+");														// Deschide fisierul in mod adaugare
		if (!FDELog::fpLog) return FD_WAR_LOG_OPEN_FAILED;														// Daca nu s-a putut deschide fisierul  atunci paraseste functia 
		FDELog::level = "Avvertimento";																			// Seteaza nivelul de informare - WARNING
		va_list args;																							// lista de argumenti pentru formatare
		va_start(args, format);																					// Incepe parsarea listei de argumenti conform formatarii
		int mesLen = vsnprintf(NULL, 0, format, args);															// Calculeaza lungimea necesara a buferului si adauga o unitate
		char* message = (char*)malloc(mesLen + 1);																// Alocarea memoriei pentru variabila + terminator
		if (!message) { fclose(FDELog::fpLog); return FD_ERR_MEM_ALLOC; };										// Se la variabile "message" e nulla, restituisce l'errore si inchide fisierul FD
		va_start(args, format);																					// Reinitializeaza lista de argumente si formateaza sirul
		vsprintf(message, format, args);																		// Inscrie in buffer sirul formatat cu valori
		va_end(args);																							// Incheie parsarea argumentilor
		if (warningCode)																						// Daca este specificat warning code
			fprintf(FDELog::fpLog, "|%s|%s|%s|%s|%s|%s| %s\n", addSpaces(FDEL_GetLocalTimeNow(), 10).c_str(), addSpaces(_strPID, 9).c_str(), addSpaces(FDELog::level, 14).c_str(), addSpaces(FDELog::_function, 23).c_str(), addSpaces(vSFunction, 35).c_str(), addSpaces(FDEL_ConvertDecIntToString(warningCode), 5).c_str(), getErrorDesc(warningCode, message).c_str());
		else																									// Daca NU este specificat warning code
			fprintf(FDELog::fpLog, "|%s|%s|%s|%s|%s|     | %s\n", addSpaces(FDEL_GetLocalTimeNow(), 10).c_str(), addSpaces(_strPID, 9).c_str(), addSpaces(FDELog::level, 14).c_str(), addSpaces(FDELog::_function, 23).c_str(), addSpaces(vSFunction, 35).c_str(), getErrorDesc(warningCode, message).c_str());
		free(message);																							// Libera la memoria del puntatore
		fclose(FDELog::fpLog);																					// Inchide fisierul FD
	}																											//
	return warningCode;																							// Returneaza codul la warning
}																												//

//--------------------------------------------------------------------------------------------------------------// 
// METODO: warning																								//
//--------------------------------------------------------------------------------------------------------------// 
// METODO SVOLTE: Scrie in fisierul LOG in modul WARNING 														//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 20-10-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------//
// ARGOMENTI:																									//
//	warningCode		short			(I)	- codul warning															//
//	msg				const char*		(I)	- mesajul aditional														//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO:																										//
//				int		- codul la warning																		//
//--------------------------------------------------------------------------------------------------------------//
int FDELog::warning(short warningCode, const char* msg) {														// Declararea metodei
	/*==========================================================================================================*/
	if (_writeWarning) {																						// Daca este activata scrierea WARNING
		/*----- Dichiarazione di variabili ---------------------------------------------------------------------*/
		string vSFunction = "";																					// Numele sub-functiei
		//======================================================================================================// 
		if (!vSFunctions.empty())																				// Daca vectorul de sub-functii are elemente
			vSFunction = vSFunctions.back();																	// Atribuie ultimul element ca nule sub-fuctiei
		FDELog::fpLog = fopen(_fdPathLog.c_str(), "a+");														// Deschide fisierul in mod adaugare
		if (!FDELog::fpLog) return FD_WAR_LOG_OPEN_FAILED;														// Daca nu s-a putut deschide fisierul  atunci paraseste functia 
		FDELog::level = "Avvertimento";																			// Seteaza nivelul de informare - WARNING
		fprintf(FDELog::fpLog, "|%s|%s|%s|%s|%s|%s| %s\n", addSpaces(FDEL_GetLocalTimeNow(), 10).c_str(), addSpaces(_strPID, 9).c_str(), addSpaces(FDELog::level, 14).c_str(), addSpaces(FDELog::_function, 23).c_str(), addSpaces(vSFunction, 35).c_str(), addSpaces(FDEL_ConvertDecIntToString(warningCode), 5).c_str(), msg);
		fclose(FDELog::fpLog);																					// Inchide fisierul FD
	}
	return warningCode;																							// Returneaza codul la warning
}																												//

#pragma endregion

#pragma region INFO LEVEL
//--------------------------------------------------------------------------------------------------------------// 
// METODO: info																									//
//--------------------------------------------------------------------------------------------------------------// 
// METODO SVOLTE: Scrie in fisierul LOG in modul INFO (inforamional)											//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 20-10-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------//
// ARGOMENTI:																									//
//	format		const char*		(I)	- formatul mesajului														//
//	...			void			(I)	- argumentii in baza formatarii												//
//--------------------------------------------------------------------------------------------------------------//
void FDELog::info(const char* format, ...) {																	// Declararea metodei
	/*==========================================================================================================*/
	if (_writeInfo) {																							// Daca este activata scrierea INFO
		/*----- Dichiarazione di variabili ---------------------------------------------------------------------*/
		string vSFunction = "";																					// Numele sub-functiei
		//======================================================================================================// 
		if (!vSFunctions.empty())																				// Daca vectorul de sub-functii are elemente
			vSFunction = vSFunctions.back();																	// Atribuie ultimul element ca nule sub-fuctiei
		FDELog::fpLog = fopen(_fdPathLog.c_str(), "a+");														// Deschide fisierul in mod adaugare
		if (!FDELog::fpLog) return;																				// Daca nu s-a putut deschide fisierul  atunci paraseste fucntia 
		FDELog::level = "Informazione";																			// Seteaza nivelul de informare - INFO
		va_list args;																							// lista de argumenti pentru formatare
		va_start(args, format);																					// Incepe parsarea listei de argumenti conform formatarii
		int mesLen = vsnprintf(NULL, 0, format, args);															// Calculeaza lungimea necesara a buferului si adauga o unitate
		char* message = (char*)malloc(mesLen + 1);																// Alocarea memoriei pentru variabila + terminator
		if (!message) { fclose(FDELog::fpLog); return; };														// Se la variabile "message" e nulla, restituisce l'errore si inchide fisierul FD
		va_start(args, format);																					// Reinitializeaza lista de argumente si formateaza sirul
		vsprintf(message, format, args);																		// Inscrie in buffer sirul formatat cu valori
		va_end(args);																							// Incheie parsarea argumentilor
		fprintf(FDELog::fpLog, "|%s|%s|%s|%s|%s|     | %s\n", addSpaces(FDEL_GetLocalTimeNow(), 10).c_str(), addSpaces(_strPID, 9).c_str(), addSpaces(FDELog::level, 14).c_str(), addSpaces(FDELog::_function, 23).c_str(), addSpaces(vSFunction, 35).c_str(), message);
		free(message);																							// Libera la memoria del puntatore
		fclose(FDELog::fpLog);																					// Inchide fisierul FD
	}																											//
	return;																										// Paraseste executia
}


#pragma endregion

#pragma region DEBUG LEVEL
//--------------------------------------------------------------------------------------------------------------// 
// METODO: debug																								//
//--------------------------------------------------------------------------------------------------------------// 
// METODO SVOLTE: Scrie in fisierul LOG in modul DEBUG  														//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 20-10-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------//
// ARGOMENTI:																									//
//	format		const char*		(I)	- formatul mesajului														//
//	...			void			(I)	- argumentii in baza formatarii												//
//--------------------------------------------------------------------------------------------------------------//
void FDELog::debug(const char* format, ...) {																	// Declararea metodei
	/*==========================================================================================================*/
	if (_writeDebug) {																							// Daca este activata scrierea DEBUG
		/*----- Dichiarazione di variabili ---------------------------------------------------------------------*/
		string vSFunction = "";																					// Numele sub-functiei
		//======================================================================================================// 
		if (!vSFunctions.empty())																				// Daca vectorul de sub-functii are elemente
			vSFunction = vSFunctions.back();																	// Atribuie ultimul element ca nule sub-fuctiei
		FDELog::fpLog = fopen(_fdPathLog.c_str(), "a+");														// Deschide fisierul in mod adaugare
		if (!FDELog::fpLog) return;																				// Daca nu s-a putut deschide fisierul  atunci paraseste fucntia 
		FDELog::level = "Debug";																				// Seteaza nivelul de informare - DEBUG
		va_list args;																							// lista de argumenti pentru formatare
		va_start(args, format);																					// Incepe parsarea listei de argumenti conform formatarii
		int mesLen = vsnprintf(NULL, 0, format, args);															// Calculeaza lungimea necesara a buferului si adauga o unitate
		char* message = (char*)malloc(mesLen + 1);																// Alocarea memoriei pentru variabila + terminator
		if (!message) { fclose(FDELog::fpLog); return; };														// Se la variabile "message" e nulla, restituisce l'errore si inchide fisierul FD
		va_start(args, format);																					// Reinitializeaza lista de argumente si formateaza sirul
		vsprintf(message, format, args);																		// Inscrie in buffer sirul formatat cu valori
		va_end(args);																							// Incheie parsarea argumentilor
		fprintf(FDELog::fpLog, "|%s|%s|%s|%s|%s|     | %s\n", addSpaces(FDEL_GetLocalTimeNow(), 10).c_str(), addSpaces(_strPID, 9).c_str(), addSpaces(FDELog::level, 14).c_str(), addSpaces(FDELog::_function, 23).c_str(), addSpaces(vSFunction, 35).c_str(), message);
		free(message);																							// Libera la memoria del puntatore
		fclose(FDELog::fpLog);																					// Inchide fisierul FD
	}																											//
	return;																										// Paraseste executia
}																												//

#pragma endregion

#pragma region TRACE LEVEL
//--------------------------------------------------------------------------------------------------------------// 
// METODO: trace																								//
//--------------------------------------------------------------------------------------------------------------// 
// METODO SVOLTE: Scrie in fisierul LOG in modul TRACE  														//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 01-12-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------//
// ARGOMENTI:																									//
//	format		const char*		(I)	- formatul mesajului														//
//	...			void			(I)	- argumentii in baza formatarii												//
//--------------------------------------------------------------------------------------------------------------//
void FDELog::trace(const char* format, ...) {																	// Declararea metodei
	/*==========================================================================================================*/
	if (_writeTrace) {																							// Daca este activata scrierea TRACE
		/*----- Dichiarazione di variabili ---------------------------------------------------------------------*/
		string vSFunction = "";																					// Numele sub-functiei
		//======================================================================================================// 
		if (!vSFunctions.empty())																				// Daca vectorul de sub-functii are elemente
			vSFunction = FDELog::vSFunctions.back();															// Atribuie ultimul element ca nule sub-fuctiei
		FDELog::fpLog = fopen(_fdPathLog.c_str(), "a+");														// Deschide fisierul in mod adaugare
		if (!FDELog::fpLog) return;																				// Daca nu s-a putut deschide fisierul  atunci paraseste fucntia 
		FDELog::level = "Trace";																				// Seteaza nivelul de informare - Trace
		va_list args;																							// lista de argumenti pentru formatare
		va_start(args, format);																					// Incepe parsarea listei de argumenti conform formatarii
		int mesLen = vsnprintf(NULL, 0, format, args);															// Calculeaza lungimea necesara a buferului si adauga o unitate
		char* message = (char*)malloc(mesLen + 1);																// Alocarea memoriei pentru variabila + terminator
		if (!message) { if (FDELog::fpLog) fclose(FDELog::fpLog); return; };									// Se la variabile "message" e nulla, restituisce l'errore si inchide fisierul FD
		va_start(args, format);																					// Reinitializeaza lista de argumente si formateaza sirul
		vsprintf(message, format, args);																		// Inscrie in buffer sirul formatat cu valori
		va_end(args);																							// Incheie parsarea argumentilor
		fprintf(FDELog::fpLog, "|%s|%s|%s|%s|%s|     | %s\n", addSpaces(FDEL_GetLocalTimeNow(), 10).c_str(), addSpaces(_strPID, 9).c_str(), addSpaces(FDELog::level, 14).c_str(), addSpaces(FDELog::_function, 23).c_str(), addSpaces(vSFunction, 35).c_str(), message);
		free(message);																							// Libera la memoria del puntatore
		fclose(FDELog::fpLog);																					// Inchide fisierul FD
	}																											//
	return;																										// Paraseste executia
}																												//


#pragma endregion

#pragma region TRACE MEMORY LEVEL
//--------------------------------------------------------------------------------------------------------------// 
// METODO: traceMemory																							//
//--------------------------------------------------------------------------------------------------------------// 
// METODO SVOLTE: Scrie in fisierul LOG in modul TRACE cu includerea informatiilor de memorie					//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 19-12-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------//
// ARGOMENTI:																									//
//	format		const char*		(I)	- formatul mesajului														//
//	...			void			(I)	- argumentii in baza formatarii												//
//--------------------------------------------------------------------------------------------------------------//
void FDELog::traceMemory(const char* format, ...) {																// Declararea metodei
	/*==========================================================================================================*/
	if (_writeTraceMem) {																						// Daca este activata scrierea TRACE
		/*----- Dichiarazione di variabili ---------------------------------------------------------------------*/
		long long memTotal = 0, memFree = 0, memUsage = 0;														// Variabile pentru valoarile de memorie
		char memMsg[80] = "";																					// Mesaj pentru valorile memoriei
		// Alocare de memorie pentru un proces
		HANDLE hProcess = GetCurrentProcess();																	// Obtine handler-ul procesului curent
		PROCESS_MEMORY_COUNTERS pmc;																			// Defineste o variabila de tip structura

		if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))													// Daca este obtinuta cu succes info despre memoria alocata procesului
			memUsage = pmc.WorkingSetSize / 1024;																// Stocheaza valoarea obtinuta convertita in Kb

		// Info despre memoria disponibila in sistem
		MEMORYSTATUSEX memoryStatus;																			// Defineste o variabila de tip structura
		memoryStatus.dwLength = sizeof(memoryStatus);															// Stabileste lungimea valorii

		if (GlobalMemoryStatusEx(&memoryStatus)) {																// Daca este obtinuta cu succes info despre memoria fizica a masinii
			memTotal = memoryStatus.ullTotalPhys / 1024;														// Stocheaza valoarea obtinuta convertind in Kb
			memFree = memoryStatus.ullAvailPhys / 1024;															// Stocheaza valoarea obtinuta convertind in Kb
		}
		SPRINTF(memMsg, "[Mem. use: %lld | Mem. free: %lld | Mem. total: %lld]", memUsage, memFree, memTotal);	// Creaza mesajul de afisare a memorie

		string vSFunction = "";																					// Numele sub-functiei
		//======================================================================================================// 
		if (!vSFunctions.empty())																				// Daca vectorul de sub-functii are elemente
			vSFunction = FDELog::vSFunctions.back();															// Atribuie ultimul element ca nule sub-fuctiei
		FDELog::fpLog = fopen(_fdPathLog.c_str(), "a+");														// Deschide fisierul in mod adaugare
		if (!FDELog::fpLog) return;																				// Daca nu s-a putut deschide fisierul  atunci paraseste fucntia 
		FDELog::level = "TraceMemory";																			// Seteaza nivelul de informare - Trace
		va_list args;																							// lista de argumenti pentru formatare
		va_start(args, format);																					// Incepe parsarea listei de argumenti conform formatarii
		int mesLen = vsnprintf(NULL, 0, format, args);															// Calculeaza lungimea necesara a buferului si adauga o unitate
		char* message = (char*)malloc(mesLen + 1);																// Alocarea memoriei pentru variabila + terminator
		if (!message) { fclose(FDELog::fpLog); return; };														// Se la variabile "message" e nulla, restituisce l'errore si inchide fisierul FD
		va_start(args, format);																					// Reinitializeaza lista de argumente si formateaza sirul
		vsprintf(message, format, args);																		// Inscrie in buffer sirul formatat cu valori
		va_end(args);																							// Incheie parsarea argumentilor
		fprintf(fpLog, "|%s|%s|%s|%s|%s|     | %s | %s \n", addSpaces(FDEL_GetLocalTimeNow(), 10).c_str(), addSpaces(_strPID, 9).c_str(), addSpaces(FDELog::level, 14).c_str(), addSpaces(FDELog::_function, 23).c_str(), addSpaces(vSFunction, 35).c_str(), memMsg, message);
		free(message);																							// Libera la memoria del puntatore
		fclose(FDELog::fpLog);																					// Inchide fisierul FD
	}																											//
	return;																										// Paraseste executia
}																												//

#pragma endregion 


//==============================================================================================================// 
//	Utilitati pt log																							//
//==============================================================================================================// 
#pragma region FD LOG INTERN FUNCTIONS

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE: allowsWritingLOG																					//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE SVOLTE: Verifica daca este permisa scrierea LOG-ului												//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 17-11-2023 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------//
// ARGOMENTI:																									//
//	endsLogOn		string	(I)	- Indica data pana cand se face LOG-ul											//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO:																										//
//				bool	- indica daca este permisa sau nu scrierea LOG-ului										//
//--------------------------------------------------------------------------------------------------------------//
bool allowsWritingLOG(std::string endsLogOn) {																	//
	/*----- Dichiarazione di variabili si initializare ---------------------------------------------------------*/
	time_t t = time(NULL);																						// Variabila de timp
	struct tm* _currTm = localtime(&t);																			// Structura de timp, initializata cu timpul local
	struct tm _currDate;																						// Structura de timp pentru data curenta
	struct tm _endsDate;																						// Structura de timp pentru data limita
	//==========================================================================================================// 
	/*----- Incarca o structura TM local cu data curenta (timp: 00:00:00) --------------------------------------*/
	_currDate.tm_year = _currTm->tm_year;																		// Seteaza structurii TM curente doar ANUL
	_currDate.tm_mon = _currTm->tm_mon;																			// Seteaza structurii TM curente doar LUNA
	_currDate.tm_mday = _currTm->tm_mday;																		// Seteaza structurii TM curente doar ZIUA
	_currDate.tm_sec = _currDate.tm_min = _currDate.tm_hour = 0;												// Initializeaza valorile de timp cu 0																											//
																												//
	/*----- Incarca o structura TM local cu data limita (timp: 00:00:00) ---------------------------------------*/
	_endsDate.tm_year = atoi(endsLogOn.substr(0, 4).c_str()) - 1900;											// Seteaza structurii TM limita doar ANUL
	_endsDate.tm_mon = atoi(endsLogOn.substr(4, 2).c_str()) - 1;												// Seteaza structurii TM limita doar LUNA
	_endsDate.tm_mday = atoi(endsLogOn.substr(6, 2).c_str());													// Seteaza structurii TM limita doar ZIUA
	_endsDate.tm_sec = _endsDate.tm_min = _endsDate.tm_hour = 0;												// Initializeaza valorile de timp cu 0																											//

	/*----- Calculeaza diferenta dintre data limita si data curenta in secunde ---------------------------------*/
	if (difftime(mktime(&_endsDate), mktime(&_currDate)) >= 0)													// Daca diferenta este mai mare sau egala cu 0
		return true;																							// Returneaza TRUE - este permisa scrierea LOG-ului
	return false;																								// Returneaza FALSE - nu este permisa scrierea LOG-ului 
}																												//


//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE: addSpaces																							//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE SVOLTE: Adaugarea spatiilor goale la string pentru a construi antetul log-ului						//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 20-10-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------//
// ARGOMENTI:																									//
//	str		string		(I)	- sirul de caractere ce se formateaza 												//
//	len		size_t		(I)	- lungimea necesara pentru formatare												//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO:																										//
//				string	- sirul de caractere formatat															//
//--------------------------------------------------------------------------------------------------------------//
std::string  addSpaces(std::string str, size_t len) {															//
	/*----- Dichiarazione di variabili -------------------------------------------------------------------------*/
	string strLocal;																							// Variabila in care se va formata sirul de caractere
	//==========================================================================================================// 
	strLocal.assign(" ");																						// Initializeaza sirul cu un sptiu gol
	strLocal.append(str);																						// Adauga sirul de caractere
	while (strLocal.length() < len)																				// Daca lungimea sirului este mai mica decat lungimea necesara
		strLocal.append(" ");																					// Adauga spatii goale la finalul sirului
	return strLocal;																							// Returneaza sirul formatat
}																												//

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE: FDEL_ConvertDecIntToString																			//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE SVOLTE: Converteste INT in STRING in baza 10														//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 20-10-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------//
// ARGOMENTI:																									//
//	x		int		(I)	- numarul ce se converteste 															//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO:																										//
//				string	- numarul convertir in STR																//
//--------------------------------------------------------------------------------------------------------------//
string FDEL_ConvertDecIntToString(int x) {																		//
	/*----- Dichiarazione di variabili -------------------------------------------------------------------------*/
	char nr[MAX_50] = "";																						//
	string str;																									//
	//==========================================================================================================// 
	_itoa(x, nr, 10);																							// Converteste numarul X in STR in baza 10
	nr[strlen(nr)] = '\0';																						// Adauga la final terminator
	str.assign(nr);																								// Initializeaza sirul de retur cu sirul ce contine numarul
	return str;                                                                                   				// Returneaza sirul de caractere cu numarul convertit
}

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE: FDEL_CheckFileExists																				//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE SVOLTE: Verifica daca exista fisierul																//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 20-10-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------//
// ARGOMENTI:																									//
//	filePath	char*		(I)	- calea completa a fisierului ce se verifica									//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO:																										//
//				int	- 0 - fisierul nu exista | 1 - fisierul exista												//
//--------------------------------------------------------------------------------------------------------------//
int FDEL_CheckFileExists(char* filePath) {																		//
	return PathFileExistsA(filePath);																			//
}																												//

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE: FDEL_CheckDirectoryExists																			//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE SVOLTE: Verifica daca exista folderul																//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 20-10-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------//
// ARGOMENTI:																									//
//	dirPath	char*		(I)	- calea completa a folderului ce se verifica										//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO:																										//
//				int	- 0 - folderul nu exista | 1 - fisierul exista												//
//--------------------------------------------------------------------------------------------------------------//
int FDEL_CheckDirectoryExists(char* dirPath) {																	//
	return PathIsDirectoryA(dirPath);																			//
}																												//

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE: FDEL_GetTemporaryDirectoryPath																		//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE SVOLTE: Identifica calea catre folderul TMP															//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 20-10-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO:																										//
//				string	- calea completa catre folderul TMP														//
//--------------------------------------------------------------------------------------------------------------//
std::string FDEL_GetTemporaryDirectoryPath() {																	//
	/*----- Dichiarazione di variabili -------------------------------------------------------------------------*/
	static char tmpDir[_MAX_PATH] = "\0";																		// Var. pentru stocarea caii complete cate TMP
	//==========================================================================================================// 
	if (!flagInitTMP) {																							// Daca inca nu s-a identificat calea catre folderul TMP
		if (FDEL_CheckDirectoryExists(getenv("TMP_DIR_PATH")))														// Daca exista folderul TMP specificat in var. globala TMP_DIR_PATH de sistem
			strcpy_s(tmpDir, _MAX_PATH, getenv("TMP_DIR_PATH"));														// Stocheaza calea catre folderul dat pentru return
		else if (FDEL_CheckDirectoryExists(DIR_TMP))															//
			strcpy_s(tmpDir, _MAX_PATH, DIR_TMP);																// Stocheaza calea catre folderul dat pentru return
		else if (FDEL_CheckDirectoryExists(DIR_HTMP))															//
			strcpy_s(tmpDir, _MAX_PATH, DIR_HTMP);																// Stocheaza calea catre folderul dat pentru return
		else																									//
			strcpy_s(tmpDir, _MAX_PATH, getenv("TMP"));															// Stocheaza calea catre folderul dat pentru return
		/*----- Verifica ultimul separator ---------------------------------------------------------------------*/
		size_t length = strlen(tmpDir);																			// Obtine lungimea path-ului
		if (length > 0 && tmpDir[length - 1] != H_TREE) {														// Daca lungimea este mai mare ca 0 si ultimul caracter este diferit de separator
			if (length + 1 < _MAX_PATH) {																		// Daca adaugand un caracter nu se depaseste marimea PATH-ului
				tmpDir[length] = H_TREE;																		// Adauga pe ultima pozitie separatorul
				tmpDir[length + 1] = '\0';																		// Adauga la final terminatorul de sir
			}
		}																										//
		PathAddBackslashA(tmpDir);																				// Adauga backslash daca este necesar
	}																											//
	flagInitTMP = true;																							// Activeaza flagul, indica ca s-a determinat calea catre folderul TMP
	return std::string(tmpDir);																					// Returneaza calea completa catre folderul TMP
}																												//

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE: FDEL_GetLocalDateNow																				//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE SVOLTE: Determina data curenta din sistem															//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 20-10-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO:																										//
//				string	- current local date																	//
//--------------------------------------------------------------------------------------------------------------//
std::string FDEL_GetLocalDateNow() {																			//
	/*----- Dichiarazione di variabili -------------------------------------------------------------------------*/
	char DateNow[TIME_SIZE] = "";																				// String-ul in care se va stoca valoarea de timp formatata
	time_t t = time(NULL);																						// Variabila de timp
	struct tm* tm = localtime(&t);																				// Structura de timp, initializata cu timpul local
	//==========================================================================================================// 
	strftime(DateNow, TIME_SIZE, "%d-%m-%y", tm);            													// Formateaza valoarea de timp dupa formatul specificat
	DateNow[strlen(DateNow)] = '\0';																			// Adauga la final terminator
	return std::string(DateNow);																				// Returneaza sirul cu data curenta
}																												//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE: FDEL_GetLocalTimeNow																				//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE SVOLTE: Determina timpul curenta din sistem															//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 20-10-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO:																										//
//				string	- current local time																	//
//--------------------------------------------------------------------------------------------------------------//
std::string FDEL_GetLocalTimeNow() {
	/*----- Dichiarazione di variabili -------------------------------------------------------------------------*/
	char TimeNow[TIME_SIZE] = "";																				// String-ul in care se va stoca valoarea de timp formatata
	time_t t = time(NULL);																						// Variabila de timp
	struct tm* tm = localtime(&t);																				// Structura de timp, initializata cu timpul local
	//==========================================================================================================// 
	strftime(TimeNow, TIME_SIZE, "%H:%M:%S", tm);            													// Formateaza valoarea de timp dupa formatul specificat
	TimeNow[strlen(TimeNow)] = '\0';																			// Adauga la final terminator
	return std::string(TimeNow);																				// Returneaza sirul cu timpul curenta
}																												//

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE: FDEL_RunCmdInSilentMode																			//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE SVOLTE: run cmd commands in silent mode																//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 20-10-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------//
// ARGOMENTI:																									//
//	strFunct	char*		(I)	- md function ex: del, type, dir...												//
//	strParams	char*		(I)	- cmd function parameters														//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO:																										//
//				int	- eroarea retunata la executa CMD															//
//--------------------------------------------------------------------------------------------------------------//
unsigned int FDEL_RunCmdInSilentMode(char* strFunct, char* strParams) {											//
	/*----- Dichiarazione di variabili -------------------------------------------------------------------------*/
	STARTUPINFO StartupInfo;																					//
	PROCESS_INFORMATION ProcessInfo;																			//
	LPWSTR pArgs;																								//
	char Args[MAX_4096];																						//
	char* pEnvCMD = NULL;																						//
	char* pDefaultCMD = (char*)"CMD.EXE";																		//
	ULONG runError;																								//
	//==========================================================================================================// 																												//
	memset(&StartupInfo, 0, sizeof(StartupInfo));																//
	StartupInfo.cb = sizeof(STARTUPINFO);																		//
	StartupInfo.dwFlags = STARTF_USESHOWWINDOW;																	//
	StartupInfo.wShowWindow = SW_HIDE;																			//
																												//
	Args[0] = 0;																								//
																												//
	pEnvCMD = getenv("COMSPEC");																				//
																												//
	if (pEnvCMD)																								//
		STRCPY(Args, pEnvCMD);																					//
	else 																										//
		STRCPY(Args, pDefaultCMD);																				//
																												//
	// "/c" option - Do the command then terminate the command window											//
	STRCAT(Args, " /c ");																						//
	//the application you would like to run from the command window												//
	STRCAT(Args, strFunct);																						//
	STRCAT(Args, " ");																							//
	//the parameters passed to the application being run from the command window.								//
	STRCAT(Args, strParams);																					//
																												//
	const size_t cSize = strlen(Args) + 1;																		// Obtine lungimea sirului ce trebuie convertit
	std::wstring wStr(cSize, TEXT('#'));																		// Formeaza sirul WCHAR de lungimea sirului ce se converteste
	mbstowcs(&wStr[0], Args, cSize);																			// Converteste sisrul in WCHAR
	pArgs = (LPWSTR)wStr.c_str();																				//

	if (!CreateProcess(NULL, pArgs, NULL, NULL, FALSE,															//
		CREATE_NEW_CONSOLE,																						//
		NULL,																									//
		NULL,																									//
		&StartupInfo,																							//
		&ProcessInfo))																							//
		return GetLastError();																					//
																												//
	WaitForSingleObject(ProcessInfo.hProcess, INFINITE);														//
	if (!GetExitCodeProcess(ProcessInfo.hProcess, &runError))													//
		runError = 0;																							//
	CloseHandle(ProcessInfo.hThread);																			//
	CloseHandle(ProcessInfo.hProcess);																			//
	return runError;																							//
}																												//

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE: FDEL_GetPID																						//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE SVOLTE: Identifica PID-ul procesului in executie													//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 25-10-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO:																										//
//				string	- PID-ul procesului in executie															//
//--------------------------------------------------------------------------------------------------------------//
std::string FDEL_GetPID() {																						//
	/*----- Dichiarazione di variabili -------------------------------------------------------------------------*/
	char sPID[MAX_26] = "";																						// ID-ul procesului in format STRING
	DWORD dPID = 0;																								// ID-ul procesului in format uLong
	//==========================================================================================================//
	dPID = GetCurrentProcessId();																				// Obtine ID-ul procesului din sistem
	_ultoa_s(dPID, sPID, 10);																					// Converteste uLong in STRING ID-ul
	return std::string(sPID);																					// Returneaza ID-ul in format STRING
}

//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE: FDEL_GetPdfNetCVersionNumber																		//
//--------------------------------------------------------------------------------------------------------------// 
// FUNZIONE SVOLTE: Determina versiunea librariei PDFNetC ce se utilizeaza										//
//--------------------------------------------------------------------------------------------------------------// 
// REVISIONI:																									//
//	- Ticau Vasile - 20-10-2022 : Prima stesura																	//
//--------------------------------------------------------------------------------------------------------------// 
// BUGS CONOSCIUTI:																								//
//--------------------------------------------------------------------------------------------------------------// 
// RITORNO:																										//
//				string	- versiunea librariei in string															//
//--------------------------------------------------------------------------------------------------------------//
string FDEL_GetPdfNetCVersionNumber() {																			//
	return PDFNetC_VERSION;																						// Returneaza versiunea librariei PDFNetC
}
//

#pragma endregion 


