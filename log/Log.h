﻿#pragma once
#include <fstream>
#include <iostream>
#include <filesystem>
#include <string>
#include <cstdarg>
#include "ErrorDefine.h"

namespace logg
{
    enum level_log
    {
        NONE,
        EXCEPTION,
        WARNING,
        INFO,
        DEBUG,
        TRACE
    };

    class LogF
    {
      private:
        // Level Log
        bool _isLevelNone = false;
        bool _isLevelInfo = false;
        bool _isLevelDebug = false;
        bool _isLevelWarning = false;
        bool _isLevelException = false;
        bool _isLevelTrace = false;

        level_log msgLevel; // default is none
        std::string functionName;

        std::string baseFilePathToLog = "log/log.txt";
        std::fstream fpLog;

        // functie care verifica daca exista fisierul, daca nu il creaza
        void ensureLogFileExists();

        void setFilePath(
            const char* file_path = "log/", const char* file_name = "log.txt");

        // setare nivel log (cu cat nivelul e mai mare, inseamna ca contine si nivelele inferioare activate)
        void setLevelLog(
            unsigned short logLevel = 0); // default Log Level este pe NONE

        //-----------------------------------------------------------------------------------------------------------
      public:
        // CTOR care primeste ca argumente PATH, nume fisier, si nivel de Log
        LogF(const char* file_path = "log/", const char* file_name = "log.txt",
            unsigned short levelLog = 0)
        {
            setFilePath(file_path, file_name);
            setLevelLog(levelLog);
			checkAndWriteHeader();
        }
        // CTOR care primeste ca argument nivel LOG, creand fisierul in locatia si directoriul default
        LogF(unsigned short levelLog = 0)
        {
            setFilePath();
            setLevelLog(levelLog);
        }

        // adaugare spatii intre coloane in fisierul log
        std::string addSpaces(std::string str, size_t len);

        // obtinere PID
        std::string GetPID();

        // obtinere nivel log
        unsigned short getLevelLog();

        // convertire enum nivel la string
        std::string levelToString(level_log level);

        // obtinere timpul curent
        std::string getCurrentTime();

		void checkAndWriteHeader();

		std::string getCurrentDate();

		std::string getLastLogDate();

        // scriere mesaj de nivel info in log
        void info(const char* functionName, const char* format, ...);

        // scriere mesaj de nivel debug in log
        void debug(const char* functionName, const char* format, ...);

        // scriere mesaj de nivel exception in log
        void exception(
            int lineNumber, const char* functionName, const char* format, ...);

        // scriere mesaj de nivel warning in log
        int warning(
            int warningCode, const char* functionName, const char* format, ...);

        // scriere mesaj de nivel trace in log
        void trace(const char* functionName, const char* format, ...);

        ~LogF()
        {
            if (fpLog.is_open())
                fpLog.close();
        }
    };

} // namespace logg

