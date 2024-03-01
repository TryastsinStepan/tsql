#pragma once
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
FILE* file;
char line[100];
char* lines[1000];
char* read(char *file);