#pragma once
#include <string>
#include <vector>
typedef std::string(*xcommand_t)(std::vector<std::string> cmd_args);

extern void Cmd_AddCommand(const std::string cmd_name, xcommand_t function, const std::string cmd_desc);
extern std::string Cmd_ExeCommand(std::string text);
extern std::vector<std::string> Cmd_ParseArgs(std::string line);
extern bool Cmd_Exists(const std::string cmd_name);
extern void Cmd_Init();
extern void Cmd_ExeConfig(std::string cpath);
