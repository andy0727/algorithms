//
//  main.cpp
//  Rotate Image
//
//  Created by Andy Zhu on 11/6/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
void rotate(vector<vector<int> > &matrix) {
    int h,v,temp;
    
    v = matrix.size()-1;
    
    if (v>=1)
        h = matrix[0].size()-1;
    else
        return;
    if (v>h){
        for(int i=0; i<v-h; ++i){
            for(int j=v-h;j<=v;++j)
                matrix[j].push_back(matrix[i][j-v+h]);
            matrix.erase(matrix.begin());
        }
        
    }
    else if (v<h){
        for(int i=v; i<h; ++i)
        {
            matrix.push_back(vector<int>());
            for(int j=v; j>=0; --j){
                matrix[i+1].push_back(matrix[j][h]);
                matrix[j].erase(matrix[j].end()-1);
            }
            
        }
    }
        
    int s=min(v,h);
    for (int i=0; i<=s/2;++i)
    {
        for(int j=0; j<(s+1)/2; j++){
            cout<<"i: "<<i<<" j: "<<j<<endl;
            temp = matrix[j][s-i];
            matrix[j][s-i]= matrix[i][j];
            matrix[i][j] = temp;
            
            temp = matrix[s-i][s-j];
            matrix[s-i][s-j]= matrix[i][j];
            matrix[i][j] = temp;
            
            temp =matrix[s-j][i] ;
            matrix[s-j][i]= matrix[i][j];
            
            matrix[i][j] = temp;
        }
        
    }
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int> > m;
    m.push_back(vector<int>());
    m.push_back(vector<int>());
    //m.push_back(vector<int>());
    //m.push_back(vector<int>());
    
    m[0].push_back(1);
    m[0].push_back(2);
    //m[0].push_back(3);
    //m[0].push_back(4);
    m[1].push_back(5);
    m[1].push_back(6);
    //m[1].push_back(7);
    //m[1].push_back(8);
    //m[2].push_back(9);
    //m[2].push_back(10);
    //m[2].push_back(11);
    //m[2].push_back(12);
    //m[3].push_back(13);
    //m[3].push_back(14);
    //m[3].push_back(15);
    //m[3].push_back(16);
    //m[2].push_back(8);
    rotate(m);
    for (vector<vector<int> >::iterator i = m.begin(); i!= m.end(); ++i)
    {
        for(vector<int>::iterator j = i->begin(); j!= i->end(); ++j)
            cout<< (*j)<<" ";
        cout<<endl;
    }
            
    std::cout << "Hello, World!\n";
    return 0;
}
