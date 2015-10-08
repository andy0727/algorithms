//
//  main.cpp
//  Balanced Binary Tree
//
//  Created by Andy Zhu on 11/3/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool helper (TreeNode* root, int& h){
    if (root == NULL){
        h = 0;
        return true;
    }
    
    int l= 0;
    int r =0;
    bool lb= helper(root->left, l);
    bool rb= helper(root->right, r);
    if (lb|| rb)
        h= max(l,r) +1;
    
    return lb&& rb && abs(l-r)<=1;
    
}
bool isBalanced(TreeNode *root) {
    int l =0;
    int r =0;
    
    if (root == NULL)
        return true;
    
    return (helper(root->left, l) && helper (root->right,r) && abs (l-r)<=1);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode* root= new TreeNode(1);
    TreeNode* node1= new TreeNode(2);
    TreeNode* node2= new TreeNode(3);
    root->left= node1;
    node1->right= node2;
    if (isBalanced(root))
        std::cout << "Hello, World!\n";
    else
        cout<<"oops"<<endl;
    return 0;
}
