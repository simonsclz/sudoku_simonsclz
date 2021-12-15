//  File: sudoku.c              //
//  Date: 15th of Dec. 2021     //
//  Version: 1.0                //
//  Goal: practice backtracking //

#include <stdio.h>
#include <stdbool.h>


//grid: input given sudoku to solve
short int grid[9][9] = {
    {0,0,0,0,0,8,4,0,0},
    {0,3,0,0,6,0,0,0,9},
    {0,0,0,0,2,0,7,0,0},
    {6,0,0,4,0,0,0,3,0},
    {0,9,0,0,1,0,0,2,0},
    {0,8,0,0,0,9,0,0,6},
    {0,0,0,0,0,0,0,0,0},
    {8,0,0,0,3,0,0,5,0},
    {0,0,2,0,0,6,0,0,0}
};

bool solve();
bool isValid(int row, int col, int value);
bool sameRow(int row, int value);
bool sameCol(int col, int value);
bool sameSquare(int row, int col, int value);
void show();

int main() {
    fprintf(stdout, "\n\033[43m\033[30mHere's your input:\033[0m\n\n"); //using colors for bash
    show();
    bool solved = solve();
    if(solved) {
        fprintf(stdout, "\n\033[42m\033[30mSolution found:\033[0m\n\n");
        show();
    } else {
        fprintf(stderr, "\n\033[41m\033[30mError. No solution found.\033[0m\n\n");
    }
}

//recursive function to solve the sudoku
bool solve() {
    bool all = true;
    for(int row=0;row<9;row++) {
        for(int col=0;col<9;col++) {
            if(grid[row][col]==0) all = false;
        }
    }
    if(all == true) return true;

    for(int row=0;row<9;row++) {
        for(int col=0;col<9;col++) {
            if(grid[row][col]==0) { //only for non-given elements
                for(grid[row][col]=1;grid[row][col]<=9;grid[row][col]++) {
                    if(isValid(row,col,grid[row][col]) && solve()) return true; //everything correct --> recursion
                }
                grid[row][col] = 0;
                return false;
            }
        }
    } 
    return false;
}

//checks if the number would be valid
bool isValid(int row, int col, int value) {
    if(sameRow(row, value) && sameCol(col, value) && sameSquare(row, col, value)) return true;
    return false;
}

//checks row
bool sameRow(int row, int value) {
    short int counter = 0;
    for(int col=0;col<9;col++) {
        if(grid[row][col] == value) counter++;
    }
    if(counter>1) {
        return false;
    }
    return true;
}

//checks column
bool sameCol(int col, int value) {
    short int counter = 0;
    for(int row=0;row<9;row++) {
        if(grid[row][col] == value) counter++;
    }
    if(counter>1) {
        return false;
    }
    return true;
}

//checks 3x3-squares
bool sameSquare(int row, int col, int value) {
    short int counter = 0;
    for(int r=(row/3)*3;r<(row/3)*3+3;r++) {
        for(int c=(col/3)*3;c<(col/3)*3+3;c++) {
            if(grid[r][c]==value) counter++;
        }
    }
    if(counter>1) {
        return false;
    }
    return true;
}

//prints the grid
void show() {
    for(int row=0;row<9;row++) {
        for(int col=0;col<9;col++) {
            fprintf(stdout, "%d ", grid[row][col]);
            (((col % 3)-2)==0 && col!=8) ? (fprintf(stdout, "| ")):(fprintf(stdout, ""));
        }
        if((row%3)-2==0 && row!=8) {
            fprintf(stdout, "\n");
            for(int count=0;count<21;count++) {
                fprintf(stdout, "-");
            }
        }
        fprintf(stdout, "\n");
    }
    fprintf(stdout, "\n");
}