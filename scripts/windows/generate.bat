@echo off

echo ===== Generating Visual Studio 2022 workspace
pushd ..\..\
call scripts\windows\premake5.exe vs2022
popd
echo.
echo ===== Done.
pause
