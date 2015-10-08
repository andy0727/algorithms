//
//  main.cpp
//  Best Time to Buy and Sell Stock II
//
//  Created by Andy Zhu on 10/31/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int maxProfit(vector<int> &prices) {
    
    int profit=0;
    if(&prices == NULL || prices.size()==0)
        return 0;
    for (int i =0; i < prices.size(); i++)
    {
        if(prices[i+1]>prices[i])
            profit+= prices[i+1]- prices[i];
    }
    return profit;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int>prices;
    prices.push_back(2);
    prices.push_back(1);
    //prices.push_back(1);
    
    std::cout << maxProfit(prices);
    return 0;
}
