/**
 * @file Logger.h
 *
 * @brief Logger (interface)
 */

#pragma once

namespace Logger
{

/**
 * Log setup level.
 */
enum LogLevel
{
	LOG_LEVEL_Standard	= 0, //< Standard display errors, warnings and info messages.

	LOG_LEVEL_Critical	= 1 //< Display only errors.
};

/**
 * Initialize the logger.
 *
 * @param[in] logFileName The log file name. If @c nullptr logger will use default name.
 * @param[in] level	The log level.
 * @return @c true in case logger has been successfully initialized @c false otherwise.
 */
bool Initialize(const char *const logFileName, const LogLevel level);

/**
 * Shutdown the logger.
 */
void Shutdown(void);

/**
 * Print message into the console and log.
 *
 * @param[in] message The message to be printed into the console and log.
 */
void Msg(const char *const message, ...);

/**
 * Print error into the console and log.
 *
 * @param[in] message The message to be printed into the console and log.
 */
void Error(const char *const message, ...);

/**
 * Print warning into the console and log.
 *
 * @param[in] message The message to be printed into the console and log.
 */
void Warning(const char *const message, ...);


} /* namespace Logger */

/* eof */
