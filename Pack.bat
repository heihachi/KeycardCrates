@ECHO OFF
setlocal EnableDelayedExpansion
for %%a in ("%~dp0\.") do set "parent=%%~nxa"
for %%i in ("%~dp0..") do set "folder=%%~fi"
set pboproject=C:\Program Files (x86)\Mikero\DePboTools\bin\pboProject.exe

"%pboProject%" -P -L="%parent%Client" +mod="%__CD__%" "%__CD__%Client"
"%pboProject%" -P -L="%parent%Server" +mod="%__CD__%" "%__CD__%Server" 

endlocal
pause