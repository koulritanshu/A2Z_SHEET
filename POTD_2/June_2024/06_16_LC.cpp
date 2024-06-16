// https://leetcode.com/problems/minimum-number-of-coins-to-be-added/description/

// https://leetcode.com/problems/patching-array/description/

// pre-requisite : https://cses.fi/problemset/task/2183/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void input(ll n, ll arr[]){
    for(ll i=0;i<n;i++){
        cin >> arr[i];
    }
}

void solve()
{
    // Minimum Subset Sum that cannot be generated in the array
    ll n;
    cin >> n;
    ll arr[n];
    input(n,arr);
    sort(arr,arr+n);
    ll s = arr[0];
    if(s != 1){
        cout << 1 << endl;return;
    }
 
    for(ll i=1;i<n;i++){
        if((arr[i]-s) > 1){ 
            cout << s + 1 << endl;return;
        }
        s += arr[i];
    }
    cout << s + 1 << endl;
}

class POTD {
public:
    int minPatches(vector<int>& nums, int n) {
        long long s = 0;
        if(nums[nums.size()-1]<n) nums.push_back(n);
        int i = 0;
        int cnt = 0;
        while(i < nums.size() && s < n){
            if((nums[i]-s)>1){
                cnt++;
                s += (s+1);
            }
            else{
                s += nums[i];
                i++;
            }
        }
        if(i==nums.size() && ((s-nums[nums.size()-1])<n)) cnt--;
        return cnt; 
    }
};

class SimilarToPOTD {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        coins.push_back(target);
        int cnt = 0;
        sort(coins.begin(),coins.end());
        long long int s = 0;
        int i=0;
        while(i<coins.size()){
            if((coins[i]-s)>1){
                cnt++;
                s += (s+1);
            }
            else{
                s += coins[i];
                i++;
            }
        }
        if((s-coins[coins.size()-1])<target) cnt++;
        return cnt;
    }
};