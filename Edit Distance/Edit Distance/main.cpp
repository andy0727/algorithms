//
//  main.cpp
//  Edit Distance
//
//  Created by Andy Zhu on 11/21/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int minDistance(string word1, string word2) {
    int m= word1.size();
    int n= word2.size();
    if(m==0) return n;
    if(n==0) return m;
    int dp [m+1][n+1];
    for(int i=0;i<=m;i++)
        dp[i][0]=i;
    
    for(int j=0;j<=n;j++)
        dp[0][j]=j;
    
    for(int i=1;i<=m;i++){
        char w1= word1[i-1];
        int cost=0;
        for(int j=1;j<=n;j++){
            char w2=word2[j-1];
            if(w1==w2)
                cost=0;
            else
                cost=1;
            dp[i][j]=min(min(dp[i-1][j]+1,dp[i][j-1]+1),dp[i-1][j-1]+cost);
        }
    }
    return dp[m][n];
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << minDistance("a", "a")<<endl;
    return 0;
}
