/**
 * @file Logger.h
 *
 * @brief Logger (interface)
 */

#pragma once

namespace Logger
{

/**
 * Initialize the logger.
 *
 * @param[in] logFileName The log file name. If @c nullptr logger will use default name.
 * @return @c true in case logger has been successfully initialized @c false otherwise.
 */
bool Initialize(const char *const logFileName);

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

} /* namespace Logger */

/* eof */
