#pragma once

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAIL 1

int checkinput(int argc, char *argv[]);
FILE *verbose_fopen(const char *filename, const char *modes);

int min(int array[], long size);
int max(int array[], long size);
