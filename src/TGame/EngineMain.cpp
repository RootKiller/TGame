#include <stdio.h>

#include "Engine/App/BaseApplication.h"

#include "Engine/Engine.h"

int EngineMain(const int argc, const char *const argv[])
{
	Engine engine;

	if (!engine.Initialize(argc, argv)) {
		printf("Unable to initialize engine.\n");
		return 0;
	}

	BaseApplication app; // ugly as fck
	engine.Run(&app);

	return engine.GetExitCode();
}

/* eof */
