//
//  main.cpp
//  Single Number
//
//  Created by Andy Zhu on 10/30/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
using namespace std;
int singleNumber(int A[], int n) {
    unordered_map<int,int> hash_table;
    for (int i = 0 ; i < n; i++)
    {
        hash_table[A[i]]++;
    }
    
    for (auto it= hash_table.begin(); it != hash_table.end(); ++it)
    {
        if (it->second < 2)
            return it->first;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    
    int A[5] = {1,5,3,3,5};
    int n = 5;
    
    std::cout <<singleNumber(A, n);
    return 0;
}
