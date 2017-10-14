// Copyright 2017 Vinogradova Ekaterina

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

#include "include/numbers_converter_app.h"
#include "include/rom_numbers_converter.h"

Application::Application() : message_("") {}

int parseArabic(const char* arg) {
    for (unsigned int i = 0; i < strlen(arg); i++) {
        if (arg[i] < '0' || arg[i] > '9')
            throw std::string("Wrong number format!");
    }
    int value = atoi(arg);

    if (value <= 0)
        throw std::string("The number can't be less than 1!");

    return value;
}

string parseRoman(const char* arg) {
    for (unsigned int i = 0; i < strlen(arg); i++) {
        if (arg[i] != 'M' && arg[i] != 'D' && arg[i] != 'C' && arg[i] != 'L'
            && arg[i] != 'X' && arg[i] != 'V' && arg[i] != 'I')
            throw std::string("Wrong number format!");
    }
    return arg;
}


void Application::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a converter of arabic and roman numbers application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <number>\n\n" +

        "Where argument is integer positive arabic number " +
        "or roman number consisting of set of letters:\n" +
        "I, V, X, L, C, D, M.";
}

bool Application::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 2) {
        help(argv[0], "ERROR: Should be 1 argument.\n\n");
        return false;
    }
    return true;
}

std::string Application::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        if (argv[1][0] >= '0' && argv[1][0] <= '9') {
            args.arabic_number = parseArabic(argv[1]);
            args.flag = Arabic;
        } else {
            args.roman_number = parseRoman(argv[1]);
            args.flag = Roman;
        }
    }
    catch (std::string& str) {
        return str;
    }

    RomNumConverter number;
    std::ostringstream stream;

    switch (args.flag) {
    case Arabic:
        stream << number.ConvertArabicToRom(args.arabic_number);
        break;
    case Roman:
        stream << number.ConvertRomToArabic(args.roman_number);
        break;
    }

    message_ = stream.str();

    return message_;
}
