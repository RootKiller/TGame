/**
 * @file CommandLine.h
 *
 * @brief Command line processor (interface).
 */

#pragma once

namespace CmdLine
{

/**
 * Initialize the command line.
 *
 * @param[in] argc The count of the parameters.
 * @param[in] argv The parameters data.
 */
void Init(const int argc, const char *const argv[]);

/**
 * Check if the parameter is set.
 *
 * @param[in] paramName The name of the parameter to be checked excluding the
 *                      minus prefix.
 * @return @c true if parameter is set @c false otherwise.
 */
bool IsParamSet(const char *const paramName);

/**
 * Get parameter value.
 *
 * @param[in] paramName The name of the parameter.
 * @return @c nullptr in case parameter is not set, char array containing the
 *         parameter value otherwise - the returned string can be also empty.
 */
const char *GetParamValue(const char *const paramName);

} /* namespace CmdLine */

/* eof */
