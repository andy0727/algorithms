//
//  main.cpp
//  Unique Binary Search Trees
//
//  Created by Andy Zhu on 11/1/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
using namespace std;
int helper (int start, int end){
    int count=0;
    if (start >=end)
        return 1;
    
    for (int i =start; i <= end ;i++)
    {
        count+= helper(start, i-1) * helper(i+1, end);
        
    }
    return count;
}

int numTrees(int n) {
    int count =0;
    if (n <= 0)
        return 0;
    if (n==1 || n==2)
        return n;
    
    for (int i =1; i <= n ;i++)
    {
        count+= helper(1,i-1) * helper(i+1,n);
        //cout<<i<<" "<<count<<endl;
    }
    return count;
}
int numTrees2(int n) {
    int a[n+1];
    int res;
    a[0]=1;
    a[1]=1;
    for(int i=2;i<=n;i++){
        a[i]=a[i-1]*a[0];
        res=a[i];
        for(int j=1;j<i;j++)
            a[i]+=a[j-1]*a[i-j];
        res=a[i];
    }
    return a[n];
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << numTrees2(4);
    return 0;
}
