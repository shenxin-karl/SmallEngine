@echo off
call clean.bat
MKDIR build
cmake -S . -G "Visual Studio 16 2019" -B build
if %errorlevel% == 0 (
	MKLINK /D .\SmallEngine.sln .\build\SmallEngine.sln
	echo build successed
) else (
	echo build faiure
)
pause