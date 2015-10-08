//
//  main.cpp
//  Sum Root to Leaf Numbers
//
//  Created by Andy Zhu on 11/10/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
using namespace std;
struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int helper(TreeNode *root, int sum)
{
    int res=0;
    if(root==NULL)
        return sum;
    
    sum=sum*10;
    sum+=root->val;
    if(root->left==NULL && root->right==NULL)
        return sum;
    
    if(root->left !=NULL)
        res+=helper(root->left, sum);
    
    if(root->right!=NULL)
        res+=helper(root->right,sum);
    return res;
}

int sumNumbers(TreeNode *root) {
    if(root==NULL)
        return 0;
    
    return helper(root,0);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
