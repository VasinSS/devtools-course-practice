// Copyright 2017 Vasin Stanislav

#ifndef MODULES_MINESWEEPER_INCLUDE_MINESWEEPER_H_
#define MODULES_MINESWEEPER_INCLUDE_MINESWEEPER_H_

class minesweeper {
 public:
     minesweeper();
     minesweeper(unsigned int x_size,
     unsigned int y_size,
     unsigned int mine_count);
     minesweeper(const minesweeper &m);
     ~minesweeper();
     minesweeper& operator=(const minesweeper &m);
     unsigned int get_x_size_field();
     unsigned int get_y_size_field();
     unsigned int clic_on_field(unsigned int x, unsigned int y);
     unsigned int get_mine_count();

 private:
    unsigned int mine_count_on_field;
    unsigned int x_size_field;
    unsigned int y_size_field;
    char**           field;

    unsigned int x_borderline_fix(int x);
    unsigned int y_borderline_fix(int y);
    void cicle_search_free_position_for_mine(unsigned int *x_pos,
                                             unsigned int *y_pos);
    void mine_filling();
};

#endif  // MODULES_MINESWEEPER_INCLUDE_MINESWEEPER_H_
