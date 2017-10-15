// Copyright 2017 Vasin Stanislav

#include "../include/minesweeper.h"

int absi(int i) {
  if ( i < 0 )
    return ~--i;
  return i;
}

Minesweeper::Minesweeper(char ix_size, char iy_size, char imine_count) {
  x_size_ = ix_size;
  y_size_ = iy_size;
  mine_count_ = imine_count;
  remaining_moves_ = x_size_ * y_size_ - mine_count_;

  x_mine_pos_ = new char[mine_count_];
  y_mine_pos_ = new char[mine_count_];

  for (int i = 0; i < mine_count_; i++) {
    x_mine_pos_[i] = i;
  }

  for (int i = 0; i < mine_count_; i++) {
    y_mine_pos_[i] = i;
  }
}

Minesweeper::Minesweeper(const Minesweeper &m) {
  x_size_ = m.x_size_;
  y_size_ = m.y_size_;
  mine_count_ = m.mine_count_;
  remaining_moves_ = m.remaining_moves_;

  x_mine_pos_ = new char[mine_count_];
  y_mine_pos_ = new char[mine_count_];

  for (int i = 0; i < mine_count_; i++) {
    x_mine_pos_[i] = m.x_mine_pos_[i];
    y_mine_pos_[i] = m.y_mine_pos_[i];
  }
}

Minesweeper::Minesweeper() {
  x_size_ = 10;
  y_size_ = 10;
  mine_count_ = 5;
  remaining_moves_ = x_size_ * y_size_ - mine_count_;

  x_mine_pos_ = new char[mine_count_];
  y_mine_pos_ = new char[mine_count_];

  for (int i = 0; i < mine_count_; i++) {
    x_mine_pos_[i] = i;
  }
  for (int i = 0; i < mine_count_; i++) {
    y_mine_pos_[i] = i;
  }
}

Minesweeper::~Minesweeper() {
  delete[] x_mine_pos_;
  delete[] y_mine_pos_;
}

char Minesweeper::cell_is_mine(char ix, char iy) {
  char search_result = 0;
  for (int i = 0; i < mine_count_; i++) {
    if ( (ix == x_mine_pos_[i]) && (iy == y_mine_pos_[i]) ) {
      search_result = 9;
      break;
    }
  }
  return search_result;
}

char Minesweeper::get_area_mine_count(char ix, char iy) {
  char area_mine = 0;
  for (int i = 0; i < mine_count_; i++) {
    if (absi(static_cast<int>(x_mine_pos_[i]
                 - static_cast<int>(ix)) ) <= 1) {
      if (absi(static_cast<int>(y_mine_pos_[i]
                  - static_cast<int>(iy)) ) <= 1) {
        area_mine = area_mine + 1;
      }
    }
  }
  return area_mine;
}

char Minesweeper::clic_on_cell(char ix, char iy) {
  char result_on_clic = cell_is_mine(ix, iy);
  if (result_on_clic != 9) {
    result_on_clic = get_area_mine_count(ix, iy);
  }
  return result_on_clic;
}

char Minesweeper::get_x_size() {
  return x_size_;
}

char Minesweeper::get_y_size() {
  return y_size_;
}

char Minesweeper::get_mine_count() {
  return mine_count_;
}

