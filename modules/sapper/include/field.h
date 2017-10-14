// Copyright 2017 Fedorov Igor

//  #include<fstream>
#include<string>

#ifndef MODULES_SAPPER_INCLUDE_FIELD_H_
#define MODULES_SAPPER_INCLUDE_FIELD_H_

struct Cell {
    bool isBomb = false;
    char viewCell = '*';
    int num = 0;
};

class Field {
 public:
     explicit Field(int Width = 10, int Height = 10, int bombcount = 10);
     ~Field();
     std::string PrintField();
     // feedback from touch
     void OpenNearCell(int x, int y);
     bool OpenCurrentCell(int x_, int y_);
     // mark cell as cell with bomb
     bool MarkCell(int x, int y);
     // access to cell
     Cell* operator[] (int index);
     bool IsWin();

 private:
     int rand_m(int k);
     // add in field bombcount bombs
     void GenerateBomb(int bombcount);
     // generate num of bomb for each cell
     void GenerateCellNum();
     // create array[,]
     void GenerateField();
     Cell **field_;
     int Height_;
     int Width_;
     int NumBomb_;
};

#endif  // MODULES_SAPPER_INCLUDE_FIELD_H_
