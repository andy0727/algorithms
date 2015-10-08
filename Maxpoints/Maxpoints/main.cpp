//
//  main.cpp
//  Maxpoints
//
//  Created by Andy Zhu on 7/14/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;
/**
 * Definition for a point.
 */
 struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
 };
 

int maxPoints(vector<Point> &points) {
    if (points.size()<2)
        return (int) points.size();
    int maxcount =0;
    int temp = 0;
    for (int i =0; i< points.size()-1; i++)
    {
        Point point1 = points[i];
        for (int h =i+1; h<points.size();h++)
        {
            //cout<<h<<endl;
            Point point2 = points[h];

            if (point1.x == point2.x && point1.y == point2.y)
            {
                //cout<<"X: "<<point2.x<<" Y: "<<point2.y<<endl;
                ++temp;
                if (maxcount<temp)
                    maxcount= temp;
                continue;
            }
            /*calculate the line value*/
            // x=b
            if (point1.x == point2.x)
            {
                temp = 2;
                for (int j = h+1; j < points.size(); j++)
                    if (points[j].x == point1.x)
                        ++temp;
                
                cout<<"temp: "<<temp<<endl;

            }
            //y=kx+b
            else
            {
                double k = (point1.y - point2.y)*1.0 / (point1.x - point2.x);
                double b = point1.y - point1.x*k;
                temp =2;
                for (int j = h+1; j < points.size(); j++)
                {
                    Point point3 = points[j];
                    double appro_y = k* point3.x+b;
                    if (appro_y >=0)
                        appro_y+=0.5;
                    else
                        appro_y-=0.5;
                    
                    int new_y = static_cast<int>(appro_y);
                    if(new_y == point3.y)
                        temp++;
                    cout<<"X: "<<point3.x<<" Y: "<<new_y<<endl;
                    cout<<"temp: "<<temp<<endl;
                }
            }
            if(temp> maxcount)
                maxcount = temp;
            
            temp =1;
        }
    }

        
    return maxcount;
}




int maxPoints2(vector<Point> &points) {
    int tempcount =0;
    int maxcount =0;
    
    
}

int main(int argc, const char * argv[])
{
    vector<Point> points;
    for (int i =0; i<1; i++)
    {
        points.push_back(Point(0,0));
        points.push_back(Point(1,1));
        points.push_back(Point(0,0));

    }
    
    // insert code here...
    std::cout << "Hello, World!\n"<<  maxPoints(points);;
    return 0;
}

