// Copyright 2017 Vasin Stanislav
#ifndef MODULES_MINESWEEPER_INCLUDE_MINESWEEPERAPP_H_
#define MODULES_MINESWEEPER_INCLUDE_MINESWEEPERAPP_H_

#include <string>

class MinesweeperApp {
 public:
  MinesweeperApp();
  ~MinesweeperApp();
  std::string operator()(int argc, const char** argv);
 private:
  std::string message_;
  typedef struct {
        char x_size_;
        char y_size_;
        char mine_count_;
        char x_clic_;
        char y_clic_;
    } Arguments;
  void help(const char* appname, const char* message = "");
  bool validateNumberofArguments(int argc, const char** argv);
};

#endif  // MODULES_MINESWEEPER_INCLUDE_MINESWEEPERAPP_H_"
