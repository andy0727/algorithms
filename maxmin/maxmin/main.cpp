//
//  main.cpp
//  maxmin
//
//  Created by Andy Zhu on 9/28/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[])
{
    double test_array[3] = {1.1,2.2,3.3};
    
    //find max and min
    bool first = true;
    double min= 0, max=0;
    for (int i=0; i<sizeof(test_array)/sizeof(double);i++){
        double temp = test_array[i];
        if (first == true)
        {
            first = false;
            min = temp;
            max = temp;
        }
        
        else if (temp > max)
            max = temp;
        else if (temp < min)
            min = temp;
    }
    
    
    cout<<"min: " <<min<<endl;
    cout<<"max: " <<max<<endl;
    return 0;
}

