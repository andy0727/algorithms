//
//  main.cpp
//  Sort Colors
//
//  Created by Andy Zhu on 11/4/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>

void sortColors(int A[], int n) {
    
    
    int i=-1, j=-1, k=-1;
    
    for(int p = 0; p < n; p++)
    {
        if(A[p] == 0)
        {
            A[++k]=2;
            A[++j]=1;
            A[++i]=0;
        }
        else if (A[p] == 1)
        {
            A[++k]=2;
            A[++j]=1;
            
        }
        else if (A[p] == 2)
        {
            A[++k]=2;
        }
    }
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int A[3]= {1,1,0};
    sortColors(A, 3);
    for (int i =0; i<3; i++)
        std::cout <<A[i];
    return 0;
}
