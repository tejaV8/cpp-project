@echo off
if not exist bin mkdir bin
for %%f in (src\Assignments\*.cpp) do (
    set "filename=%%~nf"
    g++ "%%f" -o "bin\%%~nf.exe"
)
echo All programs built. Executables are in the bin folder.