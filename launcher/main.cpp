/*
main.cpp -- executable launcher

Copyright (C) 2011 Uncle Mike
Copyright (C) 2017 Elektro-volk

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
*/
//SDL
#include <SDL_main.h>
#include <SDL_messagebox.h>
#pragma comment(lib, "SDL2.lib")
//Other
#include <windows.h>
#include <string>
#include <iostream>
#include <cstdlib> // для system

#define dlmount(x) LoadLibraryA(x)
#define dlclose(x) FreeLibrary(x)
#define dlsym(x,y) GetProcAddress(x,y)

typedef int(*pfnInit)();

pfnInit Host_Main;
HINSTANCE	hEngine;

void Sys_Error(std::string err)
{
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "MCWEngine Error", err.c_str(), NULL);
	exit(1);
}

void Sys_LoadEBP(void)
{
	if ((hEngine = dlmount("bin/engine.dll")) == NULL)
		Sys_Error("Unable to load the bin/engine.dll");
	Host_Main = (pfnInit)GetProcAddress(hEngine, "Host_Main");
	
	if ((Host_Main = (pfnInit)dlsym(hEngine, "Host_Main")) == NULL)
		Sys_Error("Missed 'Host_Main' export");
}


#if _WIN32 && !__MINGW32__ && _MSC_VER >= 1200 
#pragma comment(lib, "shell32.lib")
int __stdcall WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR cmdLine, int nShow)
#else // _WIN32
int main(int argc, char **argv)
#endif
{
	Sys_LoadEBP();
	return Host_Main();
}