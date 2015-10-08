//
//  main.cpp
//  Validate Binary Search Tree
//
//  Created by Andy Zhu on 11/22/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isValidBST(TreeNode *root) {
    if(root==NULL)
        return true;
    
    if(isValidBST(root->left) &&isValidBST(root->right))
    {
        TreeNode *leftmost=root->left;
        while(leftmost&&leftmost->right)
            leftmost=leftmost->right;
        TreeNode *rightmost=root->right;
        while(rightmost&&rightmost->left)
            rightmost=rightmost->left;
        if((!leftmost ||leftmost->val<root->val) && (!rightmost ||rightmost->val>root->val))
            return true;
        else
            return false;
    }
    else
        return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode * root=new TreeNode(0);
    bool res = isValidBST(root);
    std::cout << "Hello, World!\n";
    return 0;
}
