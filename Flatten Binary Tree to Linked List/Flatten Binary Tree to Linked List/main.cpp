//
//  main.cpp
//  Flatten Binary Tree to Linked List
//
//  Created by Andy Zhu on 11/12/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void flatten(TreeNode *root) {
    if(root==NULL)
        return;
    flatten(root->left);
    flatten(root->right);
    TreeNode* cursor = root->left;
    if(cursor==NULL)
        return;
    
   
    while(cursor->right!=NULL)
        cursor=cursor->right;
    cursor->right= root->right;
    
    
    root->right = root->left;
    root->left=NULL;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
