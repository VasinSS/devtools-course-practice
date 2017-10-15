// Copyright 2017 Vasin Stanislav
#ifndef MODULES_MINESWEEPER_INCLUDE_MINESWEEPER_H_
#define MODULES_MINESWEEPER_INCLUDE_MINESWEEPER_H_

class Minesweeper {
 public:
  Minesweeper();
  Minesweeper(char ix_size, char iy_size, char imine_count);
  Minesweeper(const Minesweeper &m);
  ~Minesweeper();
  char clic_on_cell(char ix, char iy);
  char get_x_size();
  char get_y_size();
  char get_mine_count();
 private:
  char x_size_;
  char y_size_;
  char mine_count_;
  int  remaining_moves_;
  char* x_mine_pos_;
  char* y_mine_pos_;
  char cell_is_mine(char ix, char iy);
  char get_area_mine_count(char ix, char iy);
};


#endif  // MODULES_MINESWEEPER_INCLUDE_MINESWEEPER_H_"
