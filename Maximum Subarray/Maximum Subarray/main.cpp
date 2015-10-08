//
//  main.cpp
//  Maximum Subarray
//
//  Created by Andy Zhu on 11/2/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include<math.h>
using namespace std;
struct divide {
    int s,m,l,r;
    
    divide(int s, int m, int l, int r): s(s), m(m), r(r), l(l) {}
};

divide helper(int A[], int n){
    if(n ==1)
        return divide(A[0], A[0], A[0], A[0]);
    int s,m,l,r;
    divide first = helper(A, n/2);
    divide second= helper(A+n/2, n- n/2);
    s= first.s+second.s;
    l = max(first.l,first.s+second.l);
    r = max(second.r,first.r+second.s);
    m = max(max(first.m, second.m), first.r+second.l);
    
    return divide(s,m,l,r);
    

}
int maxSubArray(int A[], int n) {
    /*
    if (n <= 0 )
        return 0;
    if (n ==1)
        return A[0];
    
    int sum =0;
    int max =A[0];
    
    for (int i =0; i< n ; ++i){
   
        if (sum <= 0)
            sum=0;
        sum+=A[i];
        if (max <= sum)
            max = sum;
    }
    return max;
    */
    
    //divide and conquer
    divide res = helper(A,n);
    
    return res.m;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int array[9] = {-1,0,3};
    std::cout << maxSubArray(array, 3);
    return 0;
}
