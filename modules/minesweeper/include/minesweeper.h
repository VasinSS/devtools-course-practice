// Copyright 2017 Vasin Stanislav
#ifndef MODULES_MINESWEEPER_INCLUDE_MINESWEEPER_H_
#define MODULES_MINESWEEPER_INCLUDE_MINESWEEPER_H_

class minesweeper {
 private:
  char x_size;
  char y_size;
  char mine_count;
  int  remaining_moves;
  char* x_mine_pos;
  char* y_mine_pos;
  char cell_is_mine(char ix, char iy);
  char get_area_mine_count(char ix, char iy);
 public:
  minesweeper();
  minesweeper(char ix_size, char iy_size, char imine_count);
  minesweeper(minesweeper m);
  ~minesweeper();
  char clic_on_cell(char ix, char iy);
  char get_x_size();
  char get_y_size();
};

#endif  //MODULES_MINESWEEPER_INCLUDE_MINESWEEPER_H_"
