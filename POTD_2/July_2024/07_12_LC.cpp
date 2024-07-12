#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int remove(string s, int score, char first, char second,int score2){
        int sco = 0;
        int curr = 0;
        int second_sc = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]==first){
                curr++;
            }
            else if(s[i]==second){
                if(curr!=0){
                    sco += score;
                    curr--;
                }
                else{
                    second_sc++;
                }
            }
            else{
                sco += (min(second_sc,curr)*score2);
                second_sc = 0;
                curr=0;
            }
        }
        if(curr && second_sc){
            sco += (min(second_sc,curr)*score2);
        }
        return sco;
    }
    int maximumGain(string s, int x, int y) {
        char first = 'a';
        char second = 'b';
        if(y>x){
            swap(first,second);
        }   
        return remove(s,max(x,y),first,second,min(x,y));
    }
};