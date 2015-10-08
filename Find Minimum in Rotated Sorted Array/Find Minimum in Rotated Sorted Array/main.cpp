//
//  main.cpp
//  Find Minimum in Rotated Sorted Array
//
//  Created by Andy Zhu on 11/5/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int findMin(vector<int> &num) {
    int end = num.size()-1;
    int middle = end/2;
    int start = 0;
    bool found = false;
    while (!found){
        if (start == middle)
            return ((num[start]< num[end])?num[start]:num[end]);
        if(num[start] < num[middle] && num[middle]<num[end]){
         
            return num[start];
            
        }
        
        else if(num[start] > num[middle])
        {
            end = middle;
            middle = (middle+start)/2;
            
        }
        else{
            start = middle;
            middle = (middle+end)/2;
        }
        
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(1);
    v.push_back(2);
    std::cout << findMin(v)<<endl;
    return 0;
}
