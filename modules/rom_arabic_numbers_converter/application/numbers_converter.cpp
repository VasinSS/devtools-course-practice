// Copyright 2017 Vinogradova Ekaterina

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/numbers_converter_app.h"

int main(int argc, const char** argv) {
    Application app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
