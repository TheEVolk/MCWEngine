#include "common.h"
#include "console.h"
#include "cvar.h"
#include <map>
#include <vector>
#include "filesystem.h"

void FS_Init(std::string botdir)
{
	Console_Log("Initialization Filesystem...", "Core:FS_Init");
}

std::string FS_GetFullPath(std::string path)
{
	return "";
}

std::string FS_GetRootPath()
{
	return (std::string)(char *)Cvar_GetValue("bot_dir") + "/";
}

bool FS_Exists(std::string path)
{
	std::ifstream fin;
		fin.open(path);
	if (fin.is_open()) {
		fin.close();
		return true;
	}
	else
		return false;
}

std::fstream FS_OpenFile(std::string path)
{
	if (!FS_Exists(path)) {
		Console_Log("Error: " + path + " not found", "Core:FS_OpenFile");
		return std::fstream();
	}
	std::fstream fin;
	fin.open(path);
	return fin;
}