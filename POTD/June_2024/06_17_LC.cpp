#include <bits/stdc++.h>
using namespace std;

class TwoPointer {
public:
    bool judgeSquareSum(int c) {
        long long i = 1, j = sqrt(c);
        if(j * j == c) return true;
        j++;
        while(i<=j){
            long long curr = (i*i)+(j*j);
            if(curr==c) return true;
            else if(curr>c) j--;
            else i++;
        }
        return false;
    }
};

class BinarySearch {
public:
    bool binary_search(long st, long ed, long n){
        if(st > ed) return false;
        long mid = st + (ed - st)/2;
        if(mid * mid == n)
            return true;
        else if(mid * mid > n)
            return binary_search(st,mid-1,n);
        else
            return binary_search(mid+1,ed,n);
    }
    bool judgeSquareSum(int c) {
        for(long i=0;i*i<=c;i++){
            long rem = c - (i*i);
            if(binary_search(0,rem,rem))
                return true;
        }
        return false;
    }
};

class Map {
public:
    unordered_map<long long,int> mp;
    Map(){
        for(long long i=0;i<=50000;i++){
            mp[i*i] = 1;
        }
    }
    bool judgeSquareSum(int c) {
        for(long long i=0;i*i<=c;i++){
            long long curr = i*i;
            long long diff = (long long)c - curr;
            if(mp[diff]==1)return true;
        }
        return false;
    }
};