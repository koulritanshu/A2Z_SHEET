#include <bits/stdc++.h>
using namespace std;

// Orientation of point with respect to line

// pt. (x,y) 
// (x1,y1) starting coordinates of the line
// y - y1 - m*(x - x1) > 0 it is above the line
// y - y1 - m*(x - x1) < 0 it is below the line
// y - y1 - m*(x - x1) = 0 it is on the line

class Solution {
  public:
    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        double m1 = (double)(q1[1]-p1[1])/(double)(q1[0]-p1[0]);
        double m2 = (double)(q2[1]-p2[1])/(double)(q2[0]-p2[0]);
        if(m1 == m2){
            if(p2[0]<=q1[0] && p2[1]<=q1[1]) return "true";
            return "false";
        }
        bool check1 = ((p2[1]-p1[1]) - m1*(p2[0]-p1[0]))>0?true:false;
        bool check2 = ((q2[1]-p1[1]) - m1*(q2[0]-p1[0]))>0?true:false;
        bool check3 = ((p1[1]-p2[1]) - m2*(p1[0]-p2[0]))>0?true:false;
        bool check4 = ((q1[1]-p2[1]) - m2*(q1[0]-p2[0]))>0?true:false;
        if(check1==check2) return "false";
        if(check3==check4) return "false";
        return "true";
    }
};