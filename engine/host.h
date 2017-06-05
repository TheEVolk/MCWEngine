#pragma once
#define EXPORT	 __declspec( dllexport ) 
extern "C" {
	int EXPORT Host_Main();
}