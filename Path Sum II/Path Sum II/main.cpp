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

void helper(TreeNode *root, int sum, int target, vector<vector<int> > &res, vector<int>& path)
{
    if(root==NULL)
        return;
    sum+=root->val;
    path.push_back(root->val);
    if(root->left!=NULL)
        helper(root->left,sum,target,res, path);
    
    if (root->right!=NULL)
        helper(root->right,sum,target,res,path);
    
    if(root->left==NULL&& root->right==NULL)
    {
       if(sum==target)
           res.push_back(path);
    }
    path.pop_back();
}

vector<vector<int> > pathSum(TreeNode *root, int sum) {
    vector<vector<int> > res;
    if(root==NULL)
        return res;
    vector<int> path;
    helper(root,0,sum,res, path);
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode* root = new TreeNode(1);
    TreeNode* node1= new TreeNode(2);
    root->left = node1;
    vector<vector<int> > res =  pathSum(root, 3);
        std::cout << "Hello, World!\n";
    return 0;
}
