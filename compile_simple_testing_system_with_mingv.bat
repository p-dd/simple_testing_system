@echo off
MD simple_testing_system
MD tests
MD output_and_result
g++ .\typer\main.cpp -o .\simple_testing_system\convertor.exe
g++ .\task_for_testing_system\sol.cpp .\task_for_testing_system\before_code.cpp -o .\simple_testing_system\sol.exe
g++ .\cheker\main.cpp -o .\simple_testing_system\checker.exe
g++ .\test_gen\main.cpp -o .\simple_testing_system\testGen.exe