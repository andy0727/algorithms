//
//  main.cpp
//  3Sum Closest
//
//  Created by Andy Zhu on 11/16/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include<vector>
#include <math.h>
using namespace std;

int threeSumClosest(vector<int> &num, int target) {
    
    sort(num.begin(), num.end());
    
    int sum= num[0]+num[1]+num[2];
    int max=sum;
    for(int i=0;i<num.size()-2;i++){
        int j=i+1;
        int k=num.size()-1;
        while(j<k){
            sum= num[i]+num[j]+num[k];
            if(abs(target-sum)<= abs(target-max))
                max=sum;
            (target>sum)?j++:k--;
        }
    }
    return max;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
