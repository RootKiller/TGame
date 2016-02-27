/**
 * @file Engine.cpp
 *
 * @brief Engine main class (implementation).
 */

#include <assert.h>

#include "App/BaseApplication.h"

#include "Engine.h"

#include "CommandLine.h"

#include "Logger.h"

Engine::Engine()
	: m_exitCode(EXIT_CODE_UNINITIALIZED)
	, m_isRunning(false)
	, m_app(nullptr)
{
}

Engine::~Engine()
{
	Logger::Shutdown();
}

bool Engine::Initialize(const int argc, const char *const argv[])
{
	CmdLine::Init(argc, argv);

	const char *const logFileName(CmdLine::IsParamSet("log") ? CmdLine::GetParamValue("log") : "engine.log");
	Logger::Initialize(logFileName);

	m_isRunning = true;
	m_exitCode = EXIT_CODE_OK;
	return true;
}

void Engine::Run(BaseApplication *const app)
{
	assert(!m_app);
	m_app = app;

	while (m_isRunning) {

		m_app->Pulse();
	}

	m_app = nullptr;
}

int	Engine::GetExitCode(void) const
{
	return m_exitCode;
}

/* eof */
