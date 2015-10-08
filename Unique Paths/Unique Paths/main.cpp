//
//  main.cpp
//  Unique Paths
//
//  Created by Andy Zhu on 11/5/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
using namespace std;
int uniquePaths(int m, int n) {
    /*
    if (n<0 ||m<0)
        return 0;
    if((n==2 && m==1)||(n==1 && m==2))
        return 1;
    else
        return uniquePaths(m-1,n)+ uniquePaths(m,n-1);
    */
    if (n<0 ||m<0)
        return 0;
    int res[m][n];
    res[0][0]=1;
    if ((n<=1)||(m<=1))
        return 1;
    
    res[0][1]=1;
    
    res[1][0]=1;
    for (int i=2; i<m; ++i)
        res[i][0]=res[i-1][0];
    
    for(int i=2; i<n; ++i)
        res[0][i]=res[0][i-1];
    
    
    for (int i =1; i<m;++i )
        for(int j =1; j<n; ++j){
            res[i][j]=res[i-1][j]+res[i][j-1];
        }
    return res[m-1][n-1];
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << uniquePaths(1, 1);
    return 0;
}
