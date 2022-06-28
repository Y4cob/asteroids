@echo off
call g++ main.cpp -o asteroids.exe -lsfml-system -lsfml-graphics -lsfml-window
if %ERRORLEVEL% == 0 goto :succeed
echo "Failed compiling!"
exit

:succeed
    asteroids.exe
    exit