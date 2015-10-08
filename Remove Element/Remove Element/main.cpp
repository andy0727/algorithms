//
//  main.cpp
//  Remove Element
//
//  Created by Andy Zhu on 11/3/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>

int removeElement(int A[], int n, int elem) {
    int newlen =n;
    if (n<=0)
        return 0;
    
    for(int i =0; i<newlen; ++i){
        if(A[i]== elem){
            while (newlen>0 && A[newlen-1] == elem){
                newlen--;
            }
            if (newlen >i){
                A[i] = A[newlen-1];
                newlen--;
            }
            else
                return newlen;
        }
    }
    return newlen;
}

int main(int argc, const char * argv[]) {
    int A[2]={4,5};
    int n = removeElement(A, 2, 4);
    std::cout << n<<std::endl;
    return 0;
}
