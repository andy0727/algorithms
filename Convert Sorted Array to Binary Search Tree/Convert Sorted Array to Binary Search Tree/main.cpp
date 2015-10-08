//
//  main.cpp
//  Convert Sorted Array to Binary Search Tree
//
//  Created by Andy Zhu on 11/3/14.
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

TreeNode *sortedArrayToBST(vector<int> &num) {
    vector<int> right;
    if (num.size() <= 0)
        return NULL;
    if (num.size()==1)
        return new TreeNode(num[0]);
    int size = num.size();
    int half = size/2;
    
    TreeNode* root= new TreeNode(num[half]);
    
    
    for (size_t i = half+1; i<size; ++i){
        right.push_back(num[i]);
       
    }
    num.erase(num.begin()+half,num.end());
    
    root->left = sortedArrayToBST(num);
    root->right= sortedArrayToBST(right);
    return root;
    
    
}
void inorder(TreeNode* root){
    if (root == NULL)
        return;
    if (root->left != NULL)
        inorder(root->left);
    else
        cout<<"#"<<endl;
    
    cout<<root->val<<endl;
    
    if (root->right != NULL)
        inorder(root->right);
    
    else
        cout<<"#"<<endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(4);
    //num.push_back(5);
    TreeNode* root = sortedArrayToBST(num);
    inorder(root);
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
