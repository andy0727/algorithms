//
//  main.cpp
//  Best Time to Buy and Sell Stock
//
//  Created by Andy Zhu on 11/5/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int maxProfit(vector<int> &prices) {
    int res=0;
    if(prices.size()<=1)
        return 0;
    int min= prices[0];
    for (int i =0; i<prices.size();++i)
    {
        if(prices[i]<min)
            min=prices[i];
        
        res = max(res,prices[i]-min);
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
