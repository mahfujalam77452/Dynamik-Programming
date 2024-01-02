//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int SolveMem(int n,int a[],int curr,int prev,vector<vector<int>>&dp){
        
        if(curr==n){
            return 0;
        }
        
        //Beacuse prev start from -1.
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        
        //Include
        int take=0;
        if(prev==-1||a[curr]>a[prev])
                       take=1+SolveMem(n,a,curr+1,curr,dp);
        
        //Exclude
        int notTake=0+SolveMem(n,a,curr+1,prev,dp);
        
        return dp[curr][prev+1]= max(take,notTake);
    }
    int solveOpt(int n,int a[]){
        
        if (n==0){
            return 0;
        }
        
        vector<int>ans;
        
        ans.push_back(a[0]);
        for(int i=1;i<n;i++){
            if(a[i]>ans.back()){
                ans.push_back(a[i]);
            }
            else{
                int index=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
                ans[index]=a[i];
            }
        }
        return ans.size();
    }
    int longestSubsequence(int n, int a[])
    {
       // your code here
       //vector<vector<int>>dp(n,vector<int>(n+1,-1));
       //return SolveMem(n,a,0,-1,dp);
       return solveOpt(n,a);
    }
};

