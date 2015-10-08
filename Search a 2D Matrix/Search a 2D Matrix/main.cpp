//
//  main.cpp
//  Search a 2D Matrix
//
//  Created by Andy Zhu on 11/6/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
bool helper(vector<int> v, int target, int start, int end){

    while(start<=end){
        int middle= (start+end)/2;

        if(v[middle] == target)
            return true;
        
        if(v[middle] < target)
            start= middle+1;
        
        else
            end = middle-1;
    }
    return false;

}

bool searchMatrix(vector<vector<int> > &matrix, int target) {
    int start,end;
    if (matrix.size()<=0)
        return false;
    
    start=0;
    end = matrix.size()-1;
    while(start<= end){
        int middle= (start+end)/2;
        if(matrix[middle][0] ==target)
            return true;
    
        if(matrix[middle][0]>target)
            end= middle-1;
        
        else{
            if (middle==(matrix.size()-1)||matrix[middle+1][0]> target )
                return helper(matrix[middle], target, 0, matrix[middle].size()-1);
            
            else
                start=middle+1;
        }
    }
    return false;

    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int> > m;
    m.push_back(vector<int>());
    //m.push_back(vector<int>());
    //m.push_back(vector<int>());
    //m.push_back(vector<int>());
    
    m[0].push_back(-8);
    //m[0].push_back(-7);
    //m[0].push_back(-5);
    //m[1].push_back(-5);
    /*
    m[1].push_back(5);
    m[1].push_back(6);
    m[1].push_back(7);
    m[1].push_back(8);
    m[2].push_back(9);
    m[2].push_back(10);
    m[2].push_back(11);
    m[2].push_back(12);
    m[3].push_back(13);
    m[3].push_back(14);
    m[3].push_back(15);
    m[3].push_back(16);
    */
    if(searchMatrix(m, -2))
        std::cout << "Hello, World!\n";
    return 0;
}
