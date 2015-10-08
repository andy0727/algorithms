//
//  main.cpp
//  Search in Rotated Sorted Array
//
//  Created by Andy Zhu on 11/7/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
using namespace std;
int search(int A[], int n, int target) {
    int start=0;
    int end = n-1;
    
    if(end<0)
        return -1;
    
    while(start<end){
        int middle= (start+end)/2;
        if(A[middle]>A[end])
            start =middle+1;
        else
            end = middle;
    }
    cout<<start<<" "<<end<<endl;
    
    int rot= start;
    start =0;
    end = n-1;
    while(start<=end){
        int midd = (start+end)/2;
        int realmidd = (midd+rot)%n;
        if(A[realmidd]== target)
            return realmidd;
        
        if(A[realmidd]> target)
            end = midd-1;
        else
            start = midd+1;
    
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int v[3]= {3,1,2};
    
   
    std::cout << search(v,3,1);
    return 0;
}
