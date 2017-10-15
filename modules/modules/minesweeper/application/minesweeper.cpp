// Copyright 2017 Vasin Stanislav

#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "../include/minesweeperApp.h"

int main(int argc, const char** argv) {
    MinesweeperApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
