@echo on
set BUILD_DIR=build

if "%~1" == "" (
    echo Error : No filename provided
    exit /b 1
)

cd %BUILD_DIR%

mingw32-make

cd ..

.\build\ASCII-generator.exe %~1

echo success!