#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string compareFrac(string str) {
        string first = "";
        string second = "";
        bool change = false;
        for(int i=0;i<str.size();i++){
            if(str[i]==','){
                i++;
                change = true;
                continue;
            }
            if(change){
                second += str[i];
            }
            else{
                first += str[i];
            }
        } 
        int first_num=0, second_num=0, third_num=0,fourth_num=0;
        change = false;
        for(int i=0;i<first.size();i++){
            if(first[i]=='/'){
                change = true;
            }
            else if(change){
                second_num=second_num*10+(first[i]-'0');
            }
            else if(!change){
                first_num=first_num*10+(first[i]-'0');
            }
        }
        change = false;
        string temp = first;
        first = second;
        for(int i=0;i<first.size();i++){
            if(first[i]=='/'){
                change = true;
            }
            else if(change){
                fourth_num=fourth_num*10+(first[i]-'0');
            }
            else if(!change){
                third_num=third_num*10+(first[i]-'0');
            }
        }
        double ab = (double)((double)first_num/(double)second_num);
        double cd = (double)((double)third_num/(double)fourth_num);
        if(ab==cd){
            return "equal";
        }
        else if(ab>cd){
            return temp;
        }
        else{
            return first;
        }
    }
};
