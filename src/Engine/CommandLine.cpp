/**
 * @file CommandLine.cpp
 *
 * @brief Command line processor (implementation).
 */

#include "CommandLine.h"

#include "Logger.h"

#include <assert.h>
#include <cstdio>

#include <string.h>

namespace CmdLine
{

const size_t INVALID_PARAM_INDEX(-1);

static const char *const *argumentsVector = nullptr;
static size_t argumentsCount = 0;

void Init(const int argc, const char *const *const argv)
{
	assert(argc > 0);

	argumentsCount = static_cast<size_t>(argc);
	argumentsVector = argv;
}

size_t GetParamIndex(const char *const paramName)
{
	assert(paramName);
	const size_t paramLen = strlen(paramName);
	if (!paramLen) {
		return INVALID_PARAM_INDEX;
	}

	for (size_t i = 1; i < argumentsCount; ++i) {
		const char *const arg = argumentsVector[i];
		if (strlen(arg) < 2) {
			continue;
		}

		if (arg[0] != '-') {
			continue;
		}

		if (! strcmp(arg + 1, paramName)) {
			return i;
		}
	}
	return INVALID_PARAM_INDEX;
}

bool IsParamSet(const char *const paramName)
{
	return GetParamIndex(paramName) != INVALID_PARAM_INDEX;
}

const char *GetParamValue(const char *const paramName)
{
	const size_t parameterIndex = GetParamIndex(paramName);
	if (parameterIndex == INVALID_PARAM_INDEX) {
		return nullptr;
	}

	if (parameterIndex == (argumentsCount - 1)) {
		return nullptr;
	}
	return argumentsVector[parameterIndex + 1];
}

} /* namespace CmdLine */

/* eof */
