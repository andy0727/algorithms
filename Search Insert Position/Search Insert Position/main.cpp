//
//  main.cpp
//  Search Insert Position
//
//  Created by Andy Zhu on 11/1/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
using namespace std;
/*
int searchInsert(int A[], int n, int target) {
    for (int i =0; i<n; i++){
        if (target <=A[i])
            return i;
    }
    return n;
}
*/

//binary search
int searchInsert(int A[], int n, int target) {
    int start= 0;
    int end = n;
    
    while (start < end)
    {
        int middle = (end+start)/2;
        if (target > A[middle]){
            start = middle+1;
        }
        
        else if (target<=A[middle]){
            if (target == A[middle])
                return middle;
            end = middle;
        }
    }
    
    return end;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int array[5]={1,2,3,4,5};
    std::cout << searchInsert(array,5,4);
    return 0;
}
