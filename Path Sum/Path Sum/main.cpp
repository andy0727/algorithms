//
//  main.cpp
//  Path Sum
//
//  Created by Andy Zhu on 11/10/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool helper(TreeNode* root, int cur ,int sum){
    if(root==NULL)
        return false;
    
    cur = cur+root->val;
    if(root->left==NULL&& root->right==NULL)
        return (cur==sum);
    else
        return helper(root->left, cur, sum) || helper(root->right, cur, sum);
}
bool hasPathSum(TreeNode *root, int sum) {
    if(root==NULL)
        return false;
    
    if(root->left==NULL&& root->right==NULL)
        return (root->val==sum);

    else
        return helper(root->left, root->val, sum) || helper(root->right, root->val, sum);
    
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode* root = new TreeNode(1);
    TreeNode* node1= new TreeNode(2);
    //root->left = node1;
    if(hasPathSum(root, 1))
        std::cout << "Hello, World!\n";
    return 0;
}
