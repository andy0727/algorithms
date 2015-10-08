//
//  main.cpp
//  Pointer
//
//  Created by Andy Zhu on 3/12/15.
//  Copyright (c) 2015 Andy Zhu. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    struct crazyPointer{int x, *y;};
    crazyPointer a={3,NULL};
    crazyPointer *p= &a;
    ++(p->x);
    cout<<p->x<<endl;//4
    cout<<p->y<<endl;
    
    
    p->y= &(p->x);
    cout<< p->y<<endl;
    
    *(p->y)=p->x;
    cout<<*(p->y)<<endl;
    
    (++p)->x;
    cout<<p->x<<endl;
    *(p->y)++;
    cout<<p->x<<endl;
    *p++->y;
    cout<<p->y<<endl;
    
    p->y=&(p->x);
    cout<<*(p->y)<<endl;
    return 0;
}
