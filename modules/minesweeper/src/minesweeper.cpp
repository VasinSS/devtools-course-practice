// Copyright 2017 Vasin Stanislav

#include "../include/minesweeper.h"
#include <math.h>

minesweeper::minesweeper(char ix_size, char iy_size, char imine_count)
{
   x_size = ix_size;
   y_size = iy_size;
   mine_count = imine_count;
   remaining_moves = x_size * y_size - mine_count;
   
   x_mine_pos = (char*)malloc(mine_count*sizeof(char));
   y_mine_pos = (char*)malloc(mine_count*sizeof(char));
   
   for(int i=0; i<mine_count; i++)
   {
     x_mine_pos[i] = i%x_size;  
   }
   
   for(int i=0; i<mine_count; i++)
   {
     y_mine_pos[i] = i%y_size;
   }
};

minesweeper::minesweeper()
{
   x_size = 10;
   y_size = 10;
   mine_count = 5;
   remaining_moves = x_size * y_size - mine_count;   
   
   x_mine_pos = (char*)malloc(mine_count*sizeof(char));
   y_mine_pos = (char*)malloc(mine_count*sizeof(char));
   
   for(int i=0; i<mine_count; i++)
   {
     x_mine_pos[i] = i%x_size;  
   }
   
   for(int i=0; i<mine_count; i++)
   {
     y_mine_pos[i] = i%y_size;
   }
};

minesweeper::~minesweeper()
{
   free(x_mine_pos);
   free(y_mine_pos);
};

char minesweeper::cell_is_mine(char ix, char iy)
{
  char search_result = -1;
  for(int i=0; i<mine_count; i++)
  {
    if((ix == x_mine_pos[i]) && (iy == y_mine_pos[i]))
    {
      search_result = 9;
      break;
    }
  }
  return search_result;
};

char minesweeper::get_area_mine_count(char ix, char iy)
{
  char area_mine = 0;
  for(int i=0; i<mine_count; i++)
  {
    if(abs(x_mine_pos-ix)<=1)
    {
      if(abs(y_mine_pos-iy)<=1)
      {
	area_mine++;
      }
    }
    return area_mine;
  }
};

char minesweeper::clic_on_cell(char ix, char iy)
{
  char result_on_clic = cell_is_mine(ix,iy);
  if(result_on_clic != 9);
  {
    result_on_clic = get_area_mine_count(ix,iy);
  }
  return result_on_clic;
};

char minesweeper::get_x_size()
{
  return x_size;
};

char minesweeper::get_y_size()
{
  return y_size;
};