/**
 * @file CommandLine.cpp
 *
 * @brief Command line processor (implementation).
 */

#include "CommandLine.h"

#include "Logger.h"

#include <assert.h>
#include <cstdio>

namespace CmdLine
{

struct ParameterData
{
	const char *name;
	const char *value;
};

static ParameterData *g_parameters = nullptr;
static size_t g_parametersCount = 0;

void Parse(const int argc, const char *const argv[])
{
	assert(argc > 0);

	// Cases:
	// -name "value" -name2 "value2"	OK
	// -name "value -name2" "value"		NOT OK
	// -name 1 -name2 "value" -name3 45 OK
	// -name							OK
	// -name "value						NOT OK

	for (int i = 0; i < argc; ++i) {
		const char *const currentParam = argv[i];
	}
}

bool IsParamSet(const char *const paramName)
{
	return false;
}

const char *GetParamValue(const char *const paramName)
{
	return nullptr;
}

} /* namespace CmdLine */

/* eof */
