@echo off
REM -------------------------------
REM Script para subir proyecto GymC a GitHub
REM -------------------------------

REM Pedir mensaje de commit
set /p mensaje="Ingrese el mensaje de commit: "

REM Agregar todos los archivos excepto los ignorados
git add .

REM Hacer commit
git commit -m "%mensaje%"

REM Establecer rama main (solo la primera vez)
git branch -M main

REM Push al remoto
git push -u origin main

echo.
echo Proceso terminado.
pause
