/**
 * @file Logger.cpp
 *
 * @brief Logger (implementation)
 */

#include <cstdio>
#include <cstring>

#include <cstdarg>

#include <ctime>

#include <assert.h>

#include "Logger.h"

#ifdef OS_WINDOWS
#	define EOL "\r\n"
#else
#	define EOL "\n"
#endif

namespace Logger
{
/**
 * Log file handler.
 */
static FILE *g_logFile = nullptr;

/**
 * Default log file name.
 */
static const char *DEFAULT_LOG_FILENAME("engine.log");

/**
 * Log level.
 */
static LogLevel g_logLevel = LOG_LEVEL_Standard;

bool Initialize(const char *const logFileName, const LogLevel level)
{
	// In case this assert fails then you are probably trying to initialize the
	// logger twice. It is not allowed.
	assert(!g_logFile);

	const size_t logFileNameLen = logFileName ? strlen(logFileName) : 0;
	assert(logFileNameLen < 260);

	char finalFileName[260] = { 0 };

	const bool logFileNameValid = logFileName && (logFileNameLen > 0);
	if (!logFileNameValid) {
		strcpy(finalFileName, DEFAULT_LOG_FILENAME);
	}
	else {
		strcpy(finalFileName, logFileName);
	}

	g_logLevel = level;

	g_logFile = fopen(finalFileName, "w+");
	assert(g_logFile);

	if (!g_logFile) {
		printf("[Logger] Unable to open log file. (%s)\n", finalFileName);
		return false;
	}

	time_t timer;
	time(&timer);
	struct tm *const timeinfo = localtime(&timer);

	static const size_t timeBufferData = 20;
	char timeData[timeBufferData] = { 0 };
	strftime(timeData, timeBufferData, "%d-%m-%Y %H:%M:%S", timeinfo);

	Msg("Logger started %s (%s)", timeData, finalFileName);

	return true;
}

void Shutdown(void)
{
	if (g_logFile) {
		fclose(g_logFile);
		g_logFile = nullptr;
	}
}

/// Print severity into file and system console.
void PrintSeverity(const char *const severity)
{
	fputs(severity, g_logFile);
	printf(severity);
}

/// Print end of line into log file and system console.
void PrintEol(void)
{
	fputs(EOL, g_logFile);
	printf(EOL);

	fflush(g_logFile);
}

void Msg(const char *const message, ...)
{
	if (g_logLevel == LOG_LEVEL_Critical) {
		return;
	}

	assert(g_logFile);

	PrintSeverity("<MSG> ");

	va_list vaArgs;
	va_start(vaArgs, message);

	va_list consoleVaArgs;
	va_copy(consoleVaArgs, vaArgs);

	vfprintf(g_logFile, message, vaArgs);
	va_end(vaArgs);

	vprintf(message, consoleVaArgs);
	va_end(consoleVaArgs);

	PrintEol();
}

void Error(const char *const message, ...)
{
	assert(g_logFile);

	PrintSeverity("<MSG> ");

	va_list vaArgs;
	va_start(vaArgs, message);

	va_list consoleVaArgs;
	va_copy(consoleVaArgs, vaArgs);

	vfprintf(g_logFile, message, vaArgs);
	va_end(vaArgs);

	vprintf(message, consoleVaArgs);
	va_end(consoleVaArgs);

	PrintEol();
}

void Warning(const char *const message, ...)
{
	assert(g_logFile);

	PrintSeverity("<WARN> ");

	va_list vaArgs;
	va_start(vaArgs, message);

	va_list consoleVaArgs;
	va_copy(consoleVaArgs, vaArgs);

	vfprintf(g_logFile, message, vaArgs);
	va_end(vaArgs);

	vprintf(message, consoleVaArgs);
	va_end(consoleVaArgs);

	PrintEol();
}
} /* namespace Logger */
/* eof */
