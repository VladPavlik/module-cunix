#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/queens.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int count_in_row(Cell **desk, int row_n, int rows_number){
    int queen_number = 0;
    //logic
    Cell* row= desk[row_n];
    for (int i =0 ;i<rows_number;i++)
    {
      if (row[i].figure=='Q')
          queen_number++;
    }
    return queen_number;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int count_in_column(Cell **desk, int col_n, int columns_number){
    int queen_number = 0;
    for (int i =0 ;i<columns_number;i++)
    {
        Cell* row=desk [i];
        if (row[col_n].figure == 'Q')
            queen_number++;
    }
    return queen_number;
}

int min(int x, int y){
    
    if(x<y)
        return x;
    else
        return y;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int count_in_diagonal(Cell **desk, int row_n, int col_n, int columns_number){ // row = y, col = x
    int queen_number = 0;
    ///////////////////////////////////////
    int y = row_n;
    int x = col_n;
    int start_x = x - min(x,y);
    int start_y = y - min(x,y);
    for (int i = 0;(start_x+i)<columns_number && (start_y+i)<columns_number;i++){
        Cell* row = desk[start_y+i];
        Cell element = row [start_x+i];
        if(element.figure=='Q'){
            queen_number++;
        }
    }
    /////////////////////////////////////
    start_x=x+y;
    start_y=0;
    for(int i = 0;start_y+i<columns_number;i++){
        Cell* row=desk[start_y+i];
        if (start_x-i>=columns_number) continue;                
        if (row_n == start_y+i && col_n == start_x-i) continue; 
        Cell element = row[start_x - i];
        if (element.figure=='Q'){
            queen_number++;
        }
    }
        
    return queen_number;
}
// return 1 if rules are correct else return 0
int check_rules (Cell** desk, int row_n, int col_n, int columns_number){
    if (count_in_diagonal(desk, row_n, col_n, columns_number) == 1 &&
        count_in_column(desk, col_n, columns_number) == 1 &&
        count_in_row(desk, row_n, columns_number) == 1){
        return 1;
    }
    else
        return 0;
}
int general_queen_number(Cell **table,int size){
    int queen_number = 0;
    for (int i = 0;i<size;i++){
       for(int g = 0;g<size;g++){
          if (table[i][g].figure == 'Q'){
             queen_number++;
           }    
       }                                                                                                                  
    }
     return queen_number;  
}

void place_queens(Cell **table, int size){
    for (int i = 0;i<size; i++ ){
        for (int j =0;j<size;j++){
            if (table[i][j].figure =='Q') continue;
            table[i][j].figure ='Q';
            if ( check_rules(table, i, j, size) == 1){
                place_queens(table, size);
                if(general_queen_number(table,size) == size){
                    return;
                }
            }
            table[i][j].figure ='\0';
        }
    }
}