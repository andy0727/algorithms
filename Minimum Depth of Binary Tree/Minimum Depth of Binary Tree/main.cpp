//
//  main.cpp
//  Minimum Depth of Binary Tree
//
//  Created by Andy Zhu on 11/11/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct A{
    TreeNode* node;
    int level;
    A(TreeNode* root, int level): node(root), level(level){}
};


int minDepth(TreeNode *root) {
    queue<A> myqueue;
    int res=0;
    if(root==NULL)
        return 0;
    
    myqueue.push(A(root,1));
    while(!myqueue.empty()){
        A temp= myqueue.front();
        myqueue.pop();
        TreeNode* node= temp.node;
        int level = temp.level;
        if (node->left!=NULL)
            myqueue.push(A(node->left,level+1));
        if(node->right!=NULL)
            myqueue.push(A(node->right,level+1));
        
        if(node->left==NULL&node->right==NULL)
            return level;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
