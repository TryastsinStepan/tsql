#pragma once
#include"read_file.h"
#include"utils.h"
i32_t count;
char** fileread;
char** parseLineByLine();
char** allocMemory();
void initFile(char* file);
void freemem(char** line);

