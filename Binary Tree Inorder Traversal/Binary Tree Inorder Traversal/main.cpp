//

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//recursive
/*
vector<int> inorderTraversal(TreeNode *root) {
    unordered_map<TreeNode*, int> checked;
    vector<int> myvector;
    if (root == NULL)
        return myvector;
    
    myvector = inorderTraversal(root->left);
    
    
    myvector.push_back(root->val);
    
    vector<int> temp = inorderTraversal(root->right);
    
    for (auto it = temp.begin(); it!= temp.end();++it)
        myvector.push_back(*it);
    return myvector;
    
}
*/

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> myvector;
    stack<TreeNode*> parents;
    unordered_map<TreeNode*, int> checked;
    //bool parentpushed = false;
    
    TreeNode* cursor = root;
    while (cursor != NULL)
    {
        
        if (cursor->left!=NULL && checked[cursor->left]!=1){
   
            parents.push(cursor);
            cursor=cursor->left;
        }
        
        else if (checked[cursor]!=1){
            
            myvector.push_back( cursor->val);
            checked[cursor]=1;
        }
        
        else if(cursor->right != NULL&& checked[cursor->right]!=1)
        {
            parents.push(cursor);
            cursor=cursor->right;
        }
        
        else if (!parents.empty())
        {
            cursor= parents.top();
            parents.pop();
        }
        else
            cursor =NULL;
    }
    
    return myvector;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode* root = new TreeNode(2);
    TreeNode* node2 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    root->left = node2;
    root->right = node3;
    node3->left = node4;
    
    vector<int> myvector;
    myvector = inorderTraversal(root);
    for (auto it = myvector.begin(); it!= myvector.end();++it)
        std::cout << (*it)<<endl;
    cout<<"done"<<endl;
    return 0;
}