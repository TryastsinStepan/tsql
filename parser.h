#pragma once
#include"read_file.h"
char** fileread;
char** parseLineByLine();
char** allocMemory();
void initFile(char* file);
void freemem(char** line);

