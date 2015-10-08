//
//  main.cpp
//  PrintLevel
//
//  Created by Andy Zhu on 1/5/15.
//  Copyright (c) 2015 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
struct Node{
    Node* l;
    Node* r;
    int val;
    Node(int val): val(val){}
};

void printlevel(Node* root, int level){
    queue<Node*> curlevel;
    int levelcount=0;
    int currentlevel=0, nextlevel=0;
    curlevel.push(root);
    currentlevel++;
    Node* cursor = root;
    while(cursor){
        if(curlevel.empty())
            break;
        cursor= curlevel.front();
        curlevel.pop();
        currentlevel--;
        
        if(levelcount==level)
            cout<<cursor->val<<" "<<endl;
        else{
            if(cursor->l){
                curlevel.push(cursor->l);
                nextlevel++;
            }
            if(cursor->r){
                curlevel.push(cursor->r);
                nextlevel++;
            }
        }
        if(currentlevel==0){
            currentlevel=nextlevel;
            levelcount++;
        }
            }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    Node* root= new Node(8);
    root->l= new Node(2);
    root->r = new Node(3);
    root->l->l=new Node(4);
    root->l->r=new Node(5);
    root->r->l=new Node(6);
    root->r->r=new Node(7);
    printlevel(root, 3);
    std::cout << "Hello, World!\n";
    return 0;
}
