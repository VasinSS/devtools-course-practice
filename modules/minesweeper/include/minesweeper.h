// Copyright 2017 Vasin Stanislav
#ifndef _MINESWEEPER_H
#define _MINESWEEPER_H

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
 ~minesweeper();
 char clic_on_cell(char ix,char iy);
 char get_x_size();
 char get_y_size();
};

#endif