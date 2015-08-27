@echo off
mkdir ..\..\build
//<--'mkdir' Creates a new directory ('Build' folder)if the directory does not exist
pushd ..\..\build
//<--'pushd' Stores the name of the current dirtectory for use by 'popd' later
cl /Zi ..\MyProgram\code\MyProgram.cpp user32.lib
//^   ^                  ^            ^
//|   |                  |            |
//|   |                  |             Adds windows.h library dependency for build
//|   |                  Directory where our main cpp file is located
//|   (Debug Information Format) Zi produces a program database (PDB) -/Zi implies /Debug
//|   Other formats include: Z7, Zi, ZI (Look here for more details: 
//|http://msdn.microsoft.com/en-us/library/958x11bc.aspx)
//Uses the compiler (cl.exe) to compile and link source code files into apps, libraries and DLLs
popd
//^
//|
//'popd' Uses the saved directory in 'pushd' command (In this case, build will be saved in pushd's 
//saved location)