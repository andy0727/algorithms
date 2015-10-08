//
//  main.cpp
//  Unique Binary Search Trees II
//
//  Created by Andy Zhu on 11/14/14.
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
vector<TreeNode *>* helper(int start, int end){
    vector<TreeNode* >* res = new vector<TreeNode*>();
    if(start>end){
        res->push_back(NULL);
        return res;
    }
    if(start == end)
    {
        TreeNode* root= new TreeNode(start);
        res->push_back(root);
    }
    
    else{
        for (int i =start; i<=end;i++)
        {
            vector<TreeNode *>* temp = helper(start, i-1);
            vector<TreeNode *>* temp2= helper(i+1, end);
        
            for(int j = 0; j<temp2->size();j++)
                for(int k=0; k<temp->size();k++){
                    TreeNode* root= new TreeNode(i);
                    root->left = (*temp)[k];
                    root->right= (*temp2)[j];
                    res->push_back(root);
                }
        }
    }
    return res;
}


vector<TreeNode *> generateTrees(int n) {
    return *helper(1,n);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<TreeNode*> *res = helper(1,3);
    std::cout << "Hello, World!\n";
    return 0;
}
