//
//  main.cpp
//  Gas Station
//
//  Created by Andy Zhu on 11/19/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int start =0;
    int i=0;
    int sum=0;
    int size = gas.size();
    while(i<size){
        
        if(sum<0)
            start=i;
        sum+=gas[i];
        sum-=cost[i];
        i++;
    }
    if (sum<0)
        return -1;
    return start;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> gas={1,2,3,4,5};
    vector<int> cost={3,4,5,1,2};
    int index=canCompleteCircuit(gas, cost);
    std::cout << "Hello, World!\n";
    return 0;
}
