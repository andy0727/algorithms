//
//  main.cpp
//  Pow(x,n)
//
//  Created by Andy Zhu on 11/19/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>

double pow(double x, int n) {
    if(n==-1)
        return 1/x;
    if(n==0)
        return 1;
    
    if(n==1)
        return x;
    double res= pow(x,n/2);
    if(n%2 ==0)
        return res*res;
    else
        return res*res*pow(x,n%2);
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << pow(2,5);
    return 0;
}
