#include <stdio.h>

#include "Engine/App/BaseApplication.h"

#include "Engine/Engine.h"

#include "Engine/AutoPtr.h"

int EngineMain(const int argc, const char *const argv[])
{
	Engine engine;

	if (!engine.Initialize(argc, argv)) {
		printf("Unable to initialize engine.\n");
		return 0;
	}

	AutoPtr<BaseApplication> app(new BaseApplication());
	engine.Run(app);

	return engine.GetExitCode();
}

/* eof */
