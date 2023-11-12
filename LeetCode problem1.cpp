//problem link;
//https://leetcode.com/problems/min-cost-climbing-stairs/submissions/
class Solution {

public:

   
    int solve(vector<int>&cost,int n,vector<int>&dp){
        //base case
        if(n==0)
             return cost[0];
        if(n==1)
              return cost[1];
        //precomputed
        if(dp[n]!=-1)
              return dp[n];
        dp[n]=cost[n]+min(solve(cost,n-1,dp),solve(cost,n-2,dp));
        return dp[n];
    }
    //Bottom up aproach.
    int solve1(vector<int>&cost,int n){
        vector<int>dp(n+1,-1);
        //Base case
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
    //memory optimization.
    int solve2(vector<int>&cost,int n){
       
        //Base case
       int pre=cost[0];
       int post=cost[1];
        for(int i=2;i<n;i++){
            int current=cost[i]+min(pre,post);
            pre=post;
            post=current;
        }
        return min(pre,post);
    }
    
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
       //  vector<int>dp(n+1,-1);
     // int ans=min(solve(cost,n-1,dp),solve(cost,n-2,dp);
      //  int ans=solve1(cost,n);
      int ans=solve2(cost,n);

        return ans;
    }
};
