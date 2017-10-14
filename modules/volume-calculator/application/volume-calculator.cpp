// Copyright 2017 Kochin Ivan

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/volume_calculator_app.h"

int main(int argc, const char** argv) {
    VolumeCalculator app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
