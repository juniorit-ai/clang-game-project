#include "juniorit/GameCraft/utils.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

void getResourceFilePath(char* outPath, int inSize, const char* inFile)
{
    assert(inSize > strlen(inFile) + 5);

    int ret = sprintf(outPath, "res/%s", inFile);

    assert(ret != -1);
}