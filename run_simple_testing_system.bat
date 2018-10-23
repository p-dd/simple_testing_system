@echo off
.\simple_testing_system\convertor typer .\simple_testing_system\mas.in
for /L %%i in (1,1,5) do (
    .\simple_testing_system\testGen .\tests\%%i
    .\simple_testing_system\sol .\tests\%%i .\tests\%%i.ans
    .\simple_testing_system\sol .\tests\%%i .\simple_testing_system\%%i.out
    .\simple_testing_system\checker .\simple_testing_system\mas.in .\simple_testing_system\%%i.out result%%i.txt .\tests\%%i.ans
    .\simple_testing_system\convertor viewer .\simple_testing_system\%%i.out .\simple_testing_system\mas.in .\output_and_result\output%%i.txt
)
for /L %%i in (1,1,5) do (
    echo.
    echo Your output and result in test %%i: 
    type .\output_and_result\output%%i.txt
    type result%%i.txt
    echo.
    echo.
)
pause