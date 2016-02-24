/**
 * @file WindowsMain.cpp
 *
 * @brief Windows OS main entry-point.
 */

int EngineMain(const int argc, const char *const argv[]);

#if defined(OS_WINDOWS) && (defined(PUBLIC_RELEASE) || defined(DEV_NO_CONSOLE))
#include <Windows.h>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	return EngineMain(__argc, __argv);
}
#else
int main(const int argc, const char *const argv[])
{
	return EngineMain(argc, argv);
}
#endif

/* eof */
