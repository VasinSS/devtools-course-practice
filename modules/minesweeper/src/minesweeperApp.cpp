// Copyright 2017 Vasin Stanislav

#include "../include/minesweeperApp.h"

#include <stdlib.h>
#include <stdint.h>
#include <sstream>
#include <string>

#include "../include/minesweeper.h"

minesweeperApp::MinesweeperApp() : message_("") {}

minesweeperApp::~MinesweeperApp() {}

void minesweeperApp::help(const char* appname, const char* message) {
  message_ = std::string(message) +
            "This is a method of minesweeper application.\n\n" +
            "Please provide arguments in the following format:\n\n"+

            " $ " + appname +" <x_size> <y_size> <mine_count>\n\n"+

            " <x_clic> <y_clic> "+

            "Where <x_size> <y_size> <mine_count> <x_clic> <y_clic>"+

            "char-precision number, "+

            "\n";
}

bool minesweeperApp::validateNumberofArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 6) {
        help(argv[0], "Error: Should be 5 arguments.\n\n");
        return false;
    }
    return true;
}

char parseChar(const char* arg) {
  char* end = 0;
  char value = static_cast<char>(strtol(arg, &end, 10));

  if (end[0]) {
    throw std::string("Wrong input args format!\n");
  }

  return value;
}

std::string minesweeperApp::operator()(int argc, const char** argv) {
  Arguments args;
  if (!validateNumberofArguments(argc, argv)) {
    return message_;
  }
  try {
    args.x_size_  = parseChar(argv[1]);
    args.y_size_ = parseChar(argv[2]);
    args.mine_count_ = parseChar(argv[3]);
    args.x_clic_ = parseChar(argv[4]);
    args.y_clic_ = parseChar(argv[5]);
  }
  catch(std::string& str) {
    return str;
  }

  minesweeper m(args.x_size_, args.y_size_, args.mine_count_);
  char result = m.clic_on_cell(args.x_clic_, args.y_clic_);
  std::ostringstream stream;
  stream << static_cast<int>(result);
  message_ = "result: " + stream.str() + "\n";
  return message_;
}
