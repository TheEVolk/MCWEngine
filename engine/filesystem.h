#pragma once
#include "common.h"
#include <iostream>
#include <fstream>

extern void FS_Init(std::string botdir);
extern std::string FS_GetFullPath(std::string path);
extern std::string FS_GetRootPath();
extern bool FS_Exists(std::string path);
extern std::fstream FS_OpenFile(std::string path);