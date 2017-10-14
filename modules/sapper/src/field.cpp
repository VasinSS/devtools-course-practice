// Copyright 2017 Fedorov Igor

#include "include/field.h"

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

Field::Field(int Width , int Height , int bombcount ) {
    if (Width < 0 || Height < 0 || ((Width*Height) < bombcount)) {
        throw("wrong value");
    } else {
        Width_ = Width;
        Height_ = Height;
        NumBomb_ = bombcount;
        GenerateField();
        GenerateBomb(bombcount);
        GenerateCellNum();
    }
}

Field::~Field() {
    for (int i = 0; i < Height_; i++) {
        delete[] field_[i];
    }
    delete[] field_;
}

void Field::GenerateField() {
    field_ = new Cell*[Height_];
    for (int i = 0; i < Height_; i++) {
        field_[i] = new Cell[Width_];
    }
}

void Field::GenerateBomb(int bombcount) {
    int16_t i = 0, x = 0, y = 0;
    unsigned int seedp = 1;
    srand(time(0));
    while (i < NumBomb_) {
        x = rand_m(seedp++) % Height_;
        y = rand_m(seedp++) % Width_;
        if (!field_[x][y].isBomb) {
            field_[x][y].isBomb = true;
            field_[x][y].num = -1;
            i++;
        }
    }
}

void Field::GenerateCellNum() {
    int countBomb = 0;
    int i1, k1, Hlimit, Wlimit , temp;
    for (int i = 0; i < Height_; i++)
        for (int k = 0; k < Width_; k++) {
            if (!field_[i][k].isBomb) {
                k1 = i1 = temp = -1;
                Wlimit = Hlimit = 2;
                if (i == 0)
                    i1 = 0;
                if (i == Height_ -1)
                    Hlimit = 1;
                if (k == 0)
                    k1 = temp = 0;
                if (k == Width_ - 1)
                    Wlimit = 1;
                for (; i1 < Hlimit; i1++) {
                    for (; k1 < Wlimit; k1++) {
                        if (field_[i + i1][k + k1].isBomb)
                            countBomb++;
                    }
                    k1 = temp;
                }
                field_[i][k].num = countBomb;
                countBomb = 0;
            }
        }
}

std::string Field::PrintField() {
    std::string temp;
    temp += " |";
    for (int i = 0; i < Width_; i++)
        temp += std::to_string(i) + " ";
    temp += "|\n-+";
    for (int i = 0; i < 2 * Width_; i++)
        temp += "-";
    temp += "+\n";
    for (int i = 0; i < Height_; i++) {
        temp += std::to_string(i) + "|";
        for (int k = 0; k < Width_; k++) {
            temp += field_[i][k].viewCell;
            temp += " ";
        }
        temp += "|\n";
    }
    temp += "-+";
    for (int i = 0; i < 2 * Height_; i++)
        temp += "-";
    temp += "+\n";
    return temp;
}

void Field::OpenNearCell(int x, int y) {
    int i1, k1, Hlimit, Wlimit, temp;
    k1 = i1 = temp = -1;
    Wlimit = Hlimit = 2;
    if (x == 0)
        i1 = 0;
    if (x == Height_ - 1)
        Hlimit = 1;
    if (y == 0)
        k1 = temp = 0;
    if (y == Width_ - 1)
        Wlimit = 1;
    for (; i1 < Hlimit; i1++) {
        for (; k1 < Wlimit; k1++) {
            if (field_[x + i1][y + k1].viewCell == '*') {
                if (field_[x + i1][y + k1].num == 0 &&
                    (x + i1 != x || y != y + k1))
                    OpenNearCell(x + i1, y + k1);
                if (field_[x + i1][y + k1].num == 0)
                    OpenCurrentCell(x + i1, y + k1);
                if (field_[x + i1][y + k1].num > -1 &&
                    field_[x + i1][y + k1].num < 10)
                    OpenCurrentCell(x + i1, y + k1);
            }
        }
        k1 = temp;
    }
}

bool Field::OpenCurrentCell(int x_, int y_) {
    if (x_<0 || y_<0 || x_ >= Height_ || y_ >= Width_)
        return false;
    std::string temp = std::to_string(field_[x_][y_].num);
    field_[x_][y_].viewCell = temp[0];
    return true;
}

bool Field::IsWin() {
    for (int i = 0; i < Height_; i++)
        for (int k = 0; k < Width_; k++)
            if (!field_[i][k].isBomb)
                if (field_[i][k].viewCell == '!'
                    || field_[i][k].viewCell == '*')
                    return false;
            return true;
}

bool Field::MarkCell(int x, int y) {
    if (x < 0 || y < 0 || x >= Height_ || y >= Width_)
        return false;
    field_[x][y].viewCell = '!';
    return true;
}

Cell* Field::operator[](int index) {
    return field_[index];
}
int temp[100];
int Field::rand_m(int k) {
    int t = time(0)%32000;
    int16_t i = 0;
    if (k % 100 == 1) {
        while (i < 10) {
            temp[10 * i] = 10 * i + t / 7;
            temp[10 * i + 1] = 10 * i + 1 * t;
            temp[10 * i + 2] = 10 * i + 2 + t % 50;
            temp[10 * i + 3] = 10 * i + 3 + t % 10;
            temp[10 * i + 4] = 10 * i + 4 + t % 13;
            temp[10 * i + 5] = 10 * i + 5 + t % 19;
            temp[10 * i + 6] = 10 * i + 6 + t % 109;
            temp[10 * i + 7] = 10 * i + 7 + t % 100;
            temp[10 * i + 8] = 10 * i + 8 + t % 10000;
            temp[10 * i + 9] = 10 * i + 9 + t % 1000;
            i++;
            t = time(0) % 32000;
            t *= t % 32000;
        }
    }
    if (k < 100)
        return temp[k];
    else
        return temp[k % 100];
}
