//
//  main.cpp
//  Find Minimum in Rotated Sorted Array II
//
//  Created by Andy Zhu on 11/12/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int findMin(vector<int> &num) {
    int l=0;
    int r= num.size()-1;
    if(r<=0)
        return -1;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(num[l]<num[r])
            return num[l];
        
        else if(num[l]>num[r]){
            if(num[mid]<=num[r])
                r=mid;
            else
                l=mid+1;
        }
        else
            r=r-1;
        
    }
    return num[l];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
