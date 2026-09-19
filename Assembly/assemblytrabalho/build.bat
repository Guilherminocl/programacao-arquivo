@echo off
set projectName=comparacao
echo --------------------------------------------
echo Compilando o programa Assembly: %projectName%.asm
echo --------------------------------------------
\masm32\bin\ml /c /Zd /coff %projectName%.asm
if errorlevel 1 (
    echo Erro na compilacao!
    pause
    exit /b
)

echo Ligando o arquivo objeto...
\masm32\bin\Link /SUBSYSTEM:CONSOLE %projectName%.obj
if errorlevel 1 (
    echo Erro na ligacao!
    pause
    exit /b
)

echo --------------------------------------------
echo Executando o programa:
echo --------------------------------------------
%projectName%.exe
echo --------------------------------------------
pause
