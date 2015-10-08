//
//  main.cpp
//  Container With Most Water
//
//  Created by Andy Zhu on 11/5/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int Area(int a1, int a2, int diff){return min(a1,a2)*abs(diff);}
int maxArea(vector<int> &height) {
    int res;
    if (height.size()<=1)
        return 0;
    int low=0;
    int high = height.size()-1;
    res=0;
    while (low <high){
        cout<<"low: "<<low<<" high: "<<high<<endl;
        
        res = max(res, Area(height[high],height[low],high-low));
        if (height[low]<height[high])
            low++;
        else
            high--;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int>h;
    h.push_back(2);
    h.push_back(1);
    h.push_back(4);
    h.push_back(3);
    std::cout << maxArea(h)<<endl;
    return 0;
}
