// https://www.geeksforgeeks.org/problems/construct-list-using-given-q-xor-queries/1

// Given a list s that initially contains only a single value 0. There will be q queries of the following types:
// 0 x: Insert x in the list
// 1 x: For every element a in s, replace it with a ^ x. ('^' denotes the bitwise XOR operator)
// Return the sorted list after performing the given q queries.


#include <bits/stdc++.h>
using namespace std;

class IteratingFromStart {
  public:
    vector<int> constructList(int q, vector<vector<int>> &queries) {
        int zeroQueries = 1, oneQueries = 0;
        for(int i=0;i<queries.size();i++){
            if(queries[i][0]==0) zeroQueries++;
            else oneQueries++;
        }
        vector<int> preXor(zeroQueries,0);
        int xorr = 0;
        vector<int> answer(zeroQueries,0);
        answer[0] = 0;
        int index = 1;
        for(int i=0;i<queries.size();i++){
            if(queries[i][0] == 0){
                answer[index] = queries[i][1];
                preXor[index] = xorr;
                index++;
            }
            else{
                xorr = xorr ^ queries[i][1];
            }
        }
        for(int i=0;i<zeroQueries;i++){
            answer[i] = answer[i] ^ xorr ^ preXor[i];
        }
        sort(answer.begin(),answer.end());
        return answer;
    }
};

class IteratingFromLast { // Expected Solution
  public:
    vector<int> constructList(int q, vector<vector<int>> &queries) {
        vector<int> answer;
        int xorr = 0;
        for(int i=queries.size()-1;i>=0;i--){
            if(queries[i][0]==1){
                xorr = xorr ^ queries[i][1];
            }
            else{
                answer.push_back(queries[i][1]^xorr);
            }
        }
        answer.push_back(xorr);
        sort(answer.begin(),answer.end());
        return answer;
    }
};