//
//  main.cpp
//  Same Tree
//
//  Created by Andy Zhu on 10/31/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>


using namespace std;
/**
 * Definition for binary tree */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p ==NULL && q ==NULL)
        return true;
    else if (p==NULL || q==NULL)
        return false;
    
    if (p->val != q->val)
        return false;
    
    else
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(int argc, const char * argv[]) {
    cout<<"hi";
    
    TreeNode* root = new TreeNode(0);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    root->left = node2;
    root->right = node3;
    node2->left = node4;
    
    if (!isSameTree(root, node2))
        cout << "false";
    else
        cout<<"true";
    return 0;
}
