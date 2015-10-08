//
//  main.cpp
//  Binary Tree Zigzag Level Order Traversal
//
//  Created by Andy Zhu on 11/17/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if(root==NULL)
        return res;
    
    queue<TreeNode*> myqueue;
    
    myqueue.push(root);
    myqueue.push(NULL);
    bool left= true;

    vector<int> v;
    while(true)
    {
        TreeNode* temp= myqueue.front();
        myqueue.pop();
        
        
        if(temp !=NULL)
        {
            v.push_back(temp->val);
            if(temp->left!=NULL)
                myqueue.push(temp->left);

            if(temp->right!=NULL)
                myqueue.push(temp->right);
        }
        else
        {
            if(left)
                res.push_back(v);
            else
            {
                vector<int> v2(v.rbegin(),v.rend());
                res.push_back(v2);
            }
            v.clear();
            left=!left;
            if(myqueue.empty())
                break;
            myqueue.push(NULL);
        }

    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode* root=new TreeNode(1);
    TreeNode* node1=new TreeNode(2);
    TreeNode* node2=new TreeNode(3);
    TreeNode* node3=new TreeNode(4);
    TreeNode* node4=new TreeNode(5);
    root->left=node1;
    root->right=node2;
    node1->left=node3;
    node1->right=node4;
    vector<vector<int> >res= zigzagLevelOrder(root);
    std::cout << "Hello, World!\n";
    return 0;
}
