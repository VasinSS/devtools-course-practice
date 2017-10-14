// Copyright 2017 Kiselev Ivan

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "../include/Application.h"

int main(int argc, char ** argv) {
    Application app;
    int output = app(argc, argv);
    printf("%i\n", output);
    return 0;
}
