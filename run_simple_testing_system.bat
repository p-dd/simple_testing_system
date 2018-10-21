@echo off
.\simple_testing_system\convertor typer .\simple_testing_system\mas.in
.\simple_testing_system\sol .\simple_testing_system\mas.in .\simple_testing_system\mas.out
.\simple_testing_system\checker .\simple_testing_system\mas.in .\simple_testing_system\mas.out
.\simple_testing_system\convertor viewer .\simple_testing_system\mas.out .\simple_testing_system\mas.in
echo Your output: 
type output.txt
echo.
echo.
type result.txt
echo.
echo.
pause