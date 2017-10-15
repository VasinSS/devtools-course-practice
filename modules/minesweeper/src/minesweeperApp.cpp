// Copyright 2017 Vasin Stanislav

#include "../include/minesweeperApp.h"
#include "../include/minesweeper.h"
#include <stdlib.h>
#include <stdint.h>

minesweeperApp::minesweeperApp() : message_("") {}

minesweeperApp::~minesweeperApp() {

}

void minesweeperApp::help(const char* appname, const char* message) {
  message_ = std::string(message) +
            "This is a method of minesweeper application.\n\n" +
            "Please provide arguments in the following format:\n\n"+

            " $ " + appname +" <x_size> <y_size> <mine_count>\n\n"+

            "Where <x_size> <y_size> <mine_count> char-precision number, " +

            "\n";
}

bool minesweeperApp::validateNumberofArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 4) {
        help(argv[0], "Error: Should be 3 arguments.\n\n");
        return false;
    }
    return true;
}

char parseChar(const char* arg) {
  char* end = 0;
  char value = static_cast<char>(strtol(arg, &end, 10));

  if (end[0]) {
    throw std::string("Wrong number format!");
  }

  return value;
}

std::string minesweeperApp::operator()(int argc, const char** argv) {
  Arguments args;
  if (!validateNumberofArguments(argc, argv)) {
    return message_;
  }
  try {
    args.x_size  = parseChar(argv[1]);
    args.y_size = parseChar(argv[2]);
    args.mine_count = parseChar(argv[3]);
  }
  catch(std::string& str) {
    return str;
  }

  minesweeper m(args.x_size, args.y_size, args.mine_count);
  m.get_x_size();
  message_ = "ssssssss";

  return message_;
}
