// Copyright 2017 Vasin Stanislav

#include "../include/minesweeper.h"
#define _CRT_RAND_S
#include <stdlib.h>
#include <ctime>


#define int_MAX -1

minesweeper::minesweeper() {
    x_size_field        = 5;
    y_size_field        = 5;
    mine_count_on_field = 5;

    field = new char*[x_size_field];

    for (unsigned int i = 0; i < x_size_field; i++) {
        field[i] = new char[y_size_field];
    }

    mine_filling();
}
minesweeper::minesweeper(unsigned int x_size,
                         unsigned int y_size,
                         unsigned int mine_count) {
    if (x_size > ( (unsigned)int_MAX)>>1)
        x_size_field = (unsigned)int_MAX - x_size + 1;
    else
        x_size_field = x_size;

    if (y_size > ( (unsigned)int_MAX)>>1)
        y_size_field = (unsigned)int_MAX - y_size + 1;
    else
        y_size_field = y_size;

    if (mine_count > (unsigned int)x_size_field *
                     (unsigned int)y_size_field)
        mine_count_on_field = 1;
    else
        mine_count_on_field = mine_count;

    field = new char*[x_size_field];
    for (unsigned int i = 0; i < x_size_field; i++) {
        field[i] = new char[y_size_field];
    }
    mine_filling();
}
minesweeper::minesweeper(const minesweeper &m) {
    x_size_field = m.x_size_field;
    y_size_field = m.y_size_field;
    field = new char*[x_size_field];
    for (unsigned int i = 0; i < x_size_field; i++) {
        field[i] = new char[y_size_field];
    }
    for (unsigned int i = 0; i < x_size_field; i++)
        for (unsigned int j = 0; j < y_size_field; j++) {
            field[i][j] = m.field[i][j];
        }

    mine_count_on_field = m.mine_count_on_field;
}
minesweeper::~minesweeper() {
    for (unsigned int i = 0; i < x_size_field; i++) {
        delete[] (field[i]);
    }

    delete[] field;
}
minesweeper& minesweeper::operator=(const minesweeper &m) {
    if (this == &m) return *this;
    for (unsigned int i = 0; i < x_size_field; i++) {
        delete[] (field[i]);
    }

    delete[] field;

    x_size_field = m.x_size_field;
    y_size_field = m.y_size_field;

    field = new char*[x_size_field];
    for (unsigned int i = 0; i < x_size_field; i++) {
        field[i] = new char[y_size_field];
    }

    for (unsigned int i = 0; i < x_size_field; i++)
        for (unsigned int j = 0; j < y_size_field; j++) {
            field[i][j] = m.field[i][j];
        }
    mine_count_on_field = m.mine_count_on_field;

    return *this;
}
unsigned int minesweeper::get_mine_count() {
    return mine_count_on_field;
}
unsigned int minesweeper::clic_on_field(unsigned int x, unsigned int y) {
    return field[x % x_size_field][y % y_size_field];
}
unsigned int minesweeper::x_borderline_fix(int x) {
    return ((unsigned int)x>>31) * (x_size_field + x) +
           (~((unsigned int)x>>31) & 1) * x % x_size_field;
}
unsigned int minesweeper::y_borderline_fix(int y) {
    return ((unsigned int)y>>31) * (y_size_field + y) +
           (~( (unsigned int)y>>31) & 1) * y % y_size_field;
}
unsigned int minesweeper::get_x_size_field() {
    return x_size_field;
}
unsigned int minesweeper::get_y_size_field() {
    return y_size_field;
}
void minesweeper::cicle_search_free_position_for_mine(
    unsigned int *x_pos, unsigned int *y_pos) {
    unsigned int x_range, y_range, _x, _y;
    int flag, x, y;
    x_range = 0;
    y_range = 0;
    flag = 1;
    while (flag) {
        x_range++;
        y_range++;
        x = static_cast<int>(*x_pos - x_range);
        y = static_cast<int>(*y_pos - y_range);
        while (flag && (x < static_cast<int>(*x_pos + x_range))) {
            _x = x_borderline_fix(x);
            _y = y_borderline_fix(y);

            if (field[_x][_y] == 0) {
                *x_pos  = _x;
                *y_pos  = _y;
                flag   = 0;
            }
            x++;
        }
        while (flag && (y < static_cast<int>(*y_pos + y_range))) {
            _x = x_borderline_fix(x);
            _y = y_borderline_fix(y);
            if (field[_x][_y] == 0) {
                *x_pos  = _x;
                *y_pos  = _y;
                flag   = 0;
            }
            y++;
        }
        while (flag && (x > static_cast<int>(*x_pos - x_range))) {
            _x = x_borderline_fix(x);
            _y = y_borderline_fix(y);
            if (field[_x][_y] == 0) {
                *x_pos  = _x;
                *y_pos  = _y;
                flag   = 0;
            }
            x--;
        }
        while (flag && (y > static_cast<int>(*y_pos - y_range))) {
            _x = x_borderline_fix(x);
            _y = y_borderline_fix(y);
            if (field[_x][_y] == 0) {
                *x_pos  = _x;
                *y_pos  = _y;
                flag   = 0;
            }
            y--;
        }
    }
}
void minesweeper::mine_filling() {
    for (unsigned int i = 0; i < x_size_field; i++) {
        for (unsigned int j = 0; j < y_size_field; j++) {
            field[i][j] = 0;
        }
    }
    unsigned int seed =(unsigned int)time(0);
    for (unsigned int i = 0; i < mine_count_on_field; i++) {
#ifdef _WINDOWS
        unsigned int x_pos = (unsigned int)((static_cast<float>(rand_s(&seed)) /
            static_cast<float>(RAND_MAX)) *
            static_cast<float>(x_size_field));
        unsigned int y_pos = (unsigned int)((static_cast<float>(rand_s(&seed)) /
            static_cast<float>(RAND_MAX)) *
            static_cast<float>(y_size_field));
#else
        unsigned int x_pos = (unsigned int)((static_cast<float>(rand_r(&seed)) /
                             static_cast<float>(RAND_MAX)) *
                             static_cast<float>(x_size_field));
        unsigned int y_pos = (unsigned int)((static_cast<float>(rand_r(&seed)) /
                             static_cast<float>(RAND_MAX)) *
                             static_cast<float>(y_size_field));
#endif
        if (field[x_pos][y_pos] != 0) {
            cicle_search_free_position_for_mine(&x_pos, &y_pos);
        }
        field[x_pos][y_pos] = 9;
    }
    if (field[0][0] != 9) {
        if (field[1][1] == 9) field[0][0]++;
        if (field[0][1] == 9) field[0][0]++;
        if (field[1][0] == 9) field[0][0]++;
    }
    if (field[0][y_size_field-1] != 9) {
        if (field[1][y_size_field-1-1] == 9)
           field[0][y_size_field - 1]++;
        if (field[0][y_size_field-1-1] == 9)
           field[0][y_size_field - 1]++;
        if (field[1][y_size_field-1] == 9)
           field[0][y_size_field - 1]++;
    }
    if (field[x_size_field-1][0] != 9) {
        if (field[x_size_field-1-1][1] == 9)
           field[x_size_field-1][0]++;
        if (field[x_size_field-1][1] == 9)
           field[x_size_field-1][0]++;
        if (field[x_size_field-1-1][0] == 9)
           field[x_size_field-1][0]++;
    }
    if (field[x_size_field-1][y_size_field-1] != 9) {
        if (field[x_size_field-1-1][y_size_field-1-1] == 9)
           field[x_size_field-1][y_size_field-1]++;
        if (field[x_size_field-1][y_size_field-1-1] == 9)
           field[x_size_field-1][y_size_field-1]++;
        if (field[x_size_field-1-1][y_size_field-1] == 9)
           field[x_size_field-1][y_size_field-1]++;
    }
    for (unsigned int j = 1; j < y_size_field - 1; j++) {
        if (field[0][j] != 9) {
            for (int l = -1; l <= 1; l++)
            if (field[1][j + l] == 9) field[0][j]++;
            if (field[0][j - 1] == 9) field[0][j]++;
            if (field[0][j + 1] == 9) field[0][j]++;
        }
        if (field[x_size_field - 1][j] != 9) {
            for (int l = -1; l <= 1; l++)
            if (field[x_size_field - 2][j + l] == 9)
               field[x_size_field - 1][j]++;
            if (field[x_size_field - 1][j - 1] == 9)
               field[x_size_field - 1][j]++;
            if (field[x_size_field - 1][j + 1] == 9)
               field[x_size_field - 1][j]++;
        }
    }
    for (unsigned int i = 1; i < x_size_field - 1; i++) {
        if (field[i][0] != 9) {
            for (int l = -1; l <= 1; l++)
            if (field[i + l][1] == 9) field[i][0]++;
            if (field[i - 1][0] == 9) field[i][0]++;
            if (field[i + 1][0] == 9) field[i][0]++;
        }
        if (field[i][y_size_field - 1] != 9) {
            for (int l = -1; l <= 1; l++)
            if (field[i + l][y_size_field - 2] == 9)
               field[i][y_size_field - 1]++;
            if (field[i - 1][y_size_field - 1] == 9)
               field[i][y_size_field - 1]++;
            if (field[i + 1][y_size_field - 1] == 9)
               field[i][y_size_field - 1]++;
        }
        for (unsigned int j = 1; j < y_size_field - 1; j++) {
            if (field[i][j] != 9) {
                for (int k = -1; k <= 1; k++) {
                    if (field[i + k][j - 1] == 9) field[i][j]++;
                    if (field[i + k][j + 1] == 9) field[i][j]++;
                }
                if (field[i - 1][j] == 9) field[i][j]++;
                if (field[i + 1][j] == 9) field[i][j]++;
            }
        }
    }
}
