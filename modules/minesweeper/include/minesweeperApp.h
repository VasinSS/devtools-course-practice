// Copyright 2017 Vasin Stanislav
#ifndef MODULES_MINESWEEPER_INCLUDE_MINESWEEPERAPP_H_
#define MODULES_MINESWEEPER_INCLUDE_MINESWEEPERAPP_H_

#include <string>

class minesweeperApp {
 public:
  minesweeperApp();
  ~minesweeperApp();
  std::string operator()(int argc, const char** argv);

 private:
  void help(const char* appname, const char* message = "");
  bool validateNumberofArguments(int argc, const char** argv);
  std::string message_;
  typedef struct {
        char x_size;
        char y_size;
        char mine_count;
        char x_clic;
        char y_clic;
    } Arguments;
};

#endif  // MODULES_MINESWEEPER_INCLUDE_MINESWEEPERAPP_H_"
