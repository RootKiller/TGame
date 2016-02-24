/**
 * @file Logger.cpp
 *
 * @brief Logger (implementation)
 */

#include <cstdio>
#include <cstring>

#include <cstdarg>

#include <assert.h>

#include "Logger.h"

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

bool Initialize(const char *const logFileName)
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

	g_logFile = fopen(finalFileName, "w+");
	assert(g_logFile);

	if (!g_logFile) {
		printf("[Logger] Unable to open log file. (%s)\n", finalFileName);
		return false;
	}
	return true;
}

void Shutdown(void)
{
	if (g_logFile) {
		fclose(g_logFile);
		g_logFile = nullptr;
	}
}

void Msg(const char *const message, ...)
{
	assert(g_logFile);

	fputs("<MSG> ", g_logFile);

	va_list vaArgs;
	va_start(vaArgs, message);

	va_list consoleVaArgs;
	va_copy(consoleVaArgs, vaArgs);

	vfprintf(g_logFile, message, vaArgs);
	va_end(vaArgs);

	vprintf(message, consoleVaArgs);
	va_end(consoleVaArgs);

	fputc('\n', g_logFile);
}

void Error(const char *const message, ...)
{
	assert(g_logFile);

	fputs("<ERROR> ", g_logFile);

	va_list vaArgs;
	va_start(vaArgs, message);

	va_list consoleVaArgs;
	va_copy(consoleVaArgs, vaArgs);

	vfprintf(g_logFile, message, vaArgs);
	va_end(vaArgs);

	vprintf(message, consoleVaArgs);
	va_end(consoleVaArgs);

	fputc('\n', g_logFile);
}

} /* namespace Logger */
/* eof */
