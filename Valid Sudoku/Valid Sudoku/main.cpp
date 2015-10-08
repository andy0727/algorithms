//
//  main.cpp
//  Valid Sudoku
//
//  Created by Andy Zhu on 11/13/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isValidSudoku(vector<vector<char> > &board) {
    unordered_map<char, bool> ver[9];
    unordered_map<char, bool> hor[9];
    unordered_map<char, bool> in[9];
    
    for (int i=0;i<board.size();i++)
        for(int j=0; j<board[0].size();j++)
        {
            char num = board[i][j];
            if(num=='.')
                continue;
            
            if(ver[i][num]==true)
                return false;
            if(hor[j][num]==true)
                return false;
            if(in[i/3+j/3*3][num]==true)
                return false;
            ver[i][num]=true;
            hor[j][num]=true;
            in[i/3+j/3*3][num]=true;
        }
    return true;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
