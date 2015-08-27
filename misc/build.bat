@echo off
mkdir ..\FirstProgram\build
pushd ..\FirstProgram\build
cl /Zi ..\MyProgram\code\MyProgram.cpp user32.lib
popd
