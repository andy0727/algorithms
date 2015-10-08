//
//  main.cpp
//  Maximum Depth of Binary Tree
//
//  Created by Andy Zhu on 10/30/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
/**
 * Definition for binary tree */
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


int maxDepth(TreeNode *root) {
    int result = 0;
    int left_depth =0;
    int right_depth = 0;
    if (root== NULL)
        return result;
    if (root->left != NULL)
        left_depth = maxDepth(root->left);
    if (root->right != NULL)
        right_depth = maxDepth(root->right);
    
    result = (right_depth>left_depth)? right_depth: left_depth;
    return result+1;
    
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
    
    std::cout << maxDepth(root);
    return 0;
}
