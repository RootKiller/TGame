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

#include "SDL.h"

Engine::Engine()
	: m_exitCode(EXIT_CODE_UNINITIALIZED)
	, m_isRunning(false)
	, m_app(nullptr)
	, m_window(nullptr)
{
}

Engine::~Engine()
{
	if (m_window) {
		SDL_DestroyWindow(m_window);
		m_window = nullptr;
	}

	SDL_Quit();

	Logger::Shutdown();
}

bool Engine::Initialize(const int argc, const char *const argv[])
{
	CmdLine::Init(argc, argv);

	const char *const logFileName(CmdLine::IsParamSet("log") ? CmdLine::GetParamValue("log") : "engine.log");
	Logger::Initialize(logFileName, Logger::LOG_LEVEL_Standard);

	SDL_Init(SDL_INIT_VIDEO);

	m_window = SDL_CreateWindow("Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_OPENGL);
	if (!m_window) {
		Logger::Error("Unable to create application window. (%s)", SDL_GetError());
		return false;
	}

	m_isRunning = true;
	m_exitCode = EXIT_CODE_OK;
	return true;
}

void Engine::Run(BaseApplication *const app)
{
	assert(!m_app);
	m_app = app;

	while (m_isRunning) {
		SDL_PumpEvents();

		SDL_Event e;
		while(SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				m_isRunning = false;
			}
		}

		m_app->Pulse();
	}

	m_app = nullptr;
}

int	Engine::GetExitCode(void) const
{
	return m_exitCode;
}

/* eof */
