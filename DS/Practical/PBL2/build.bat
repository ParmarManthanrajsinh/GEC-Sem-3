@echo off
setlocal

where cmake >nul 2>nul
if errorlevel 1 (
    echo CMake was not found on your PATH.
    echo Install it from https://cmake.org/download/ and re-run this script.
    exit /b 1
)

echo Configuring build...
cmake -S . -B build
if errorlevel 1 exit /b 1

echo Building (Release)...
cmake --build build --config Release
if errorlevel 1 exit /b 1

echo.
echo Build complete.
echo Run the benchmark with one of:
echo   build\Release\sorting_benchmark.exe   (Visual Studio / MSVC)
echo   build\sorting_benchmark.exe           (MinGW / Ninja)
echo.
echo Then generate the Excel report with:
echo   python generate_report.py
echo.

endlocal
