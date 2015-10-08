//
//  main.cpp
//  Find Peak Element
//
//  Created by Andy Zhu on 12/16/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int findPeakElement(const vector<int> &num) {
    int l = 0;
    int r = num.size()-1;
    while(l<r)
    {
        int middle= (l+r)/2;
        if(num[middle]>num[middle+1])
            r= middle;
        else
            l= middle+1;
        
    }
    return l;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
