@echo off
MD simple_testing_system
g++ .\typer\main.cpp -o .\simple_testing_system\convertor.exe
g++ .\task_for_testing_system\sol.cpp .\task_for_testing_system\before_code.cpp -o .\simple_testing_system\sol.exe
g++ .\cheker\main.cpp -o .\simple_testing_system\checker.exe