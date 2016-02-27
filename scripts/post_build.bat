rem
rem Script that copies SDL dynamic library into the bin folder after the build.
rem

@echo off

set CONFIGURATION=%1
set PLATFORM=%2

set TARGET_PATH=%TGAME_PATH%\bin\%CONFIGURATION%\%PLATFORM%\
set SOURCE_PATH=%TGAME_PATH%\3rdparty\SDL2\lib\%CONFIGURATION%\%PLATFORM%\

set TARGET_FILE=%TARGET_PATH%SDL2.dll
set SOURCE_FILE=%SOURCE_PATH%SDL2.dll

if not exist %TARGET_FILE% (
	copy /b "%SOURCE_FILE%" "%TARGET_FILE%" > nul
	echo SDL DLL has been copied!
)

exit /b 0
rem EOF
