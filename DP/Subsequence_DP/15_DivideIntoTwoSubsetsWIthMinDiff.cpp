#include <bits/stdc++.h>
using namespace std;

// In Sheet, link is of different question

int SpaceOpti(vector<int>& arr, int n)
{
	int s = 0;
	for(int i=0;i<arr.size();i++){
		s += arr[i];
	}
	vector<bool> pre(s+1,false);
	vector<bool> curr(s+1,false);
	pre[0]=true;
	pre[arr[0]]=true;
	int ans = INT_MAX;
	for(int i=1;i<n;i++){
		for(int j=0;j<=s;j++){
			if(pre[j]){
				curr[j] = true;
				curr[j+arr[i]] = true;
				if(i==n-1){
					int other = s - j;
					int diff = abs(other-j);
					if(diff<ans){
						ans = diff;
					}
				}
			}
		}
		pre = curr;
	}
	return ans;
}

int Tabulation(vector<int>& arr, int n)
{
	int s = 0;
	for(int i=0;i<arr.size();i++){
		s += arr[i];
	}
	vector<vector<bool>> dp(arr.size(),vector<bool>(s+1,false));
	dp[0][0] = true;
	dp[0][arr[0]] = true;
	for(int i=1;i<arr.size();i++){
		for(int j=0;j<=s;j++){
			if(dp[i-1][j]){
				dp[i][j] = 1;
				dp[i][j+arr[i]] = 1;
			}
		}
	}
	int ans = INT_MAX;
	for(int i=0;i<=s;i++){
		if(dp[arr.size()-1][i]){
			int other = s - i;
			int diff = abs(i-other);
			ans = min(ans,diff);
		}
	}
	return ans;
}

int memoizationHelper(vector<int>&arr, int ind, int sum, int s, vector<vector<int>>&dp){
	if(ind==arr.size()){
		int other = abs(s - sum);
		return abs(other-sum);
	}
	if(dp[ind][sum]!=-1) return dp[ind][sum];
	int ans = min(memoizationHelper(arr,ind+1,sum,s,dp),memoizationHelper(arr,ind+1,sum+arr[ind],s,dp));
	return dp[ind][sum] = ans;
}

int Memoization(vector<int>& arr, int n)
{
	int s = 0;
	for(int i=0;i<arr.size();i++){
		s += arr[i];
	}
	vector<vector<int>> dp(arr.size(),vector<int>(s+1,-1));
	return memoizationHelper(arr,0,0,s,dp);
}
