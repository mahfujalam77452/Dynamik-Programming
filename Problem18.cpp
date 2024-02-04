//Problem link
//https://leetcode.com/problems/unique-binary-search-trees/submissions/1165349486/
//Memoization Method
int Solve(int n,vector<int>&dp){
        if(n <= 1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];

        }
        int ans =0;
        for(int i =1;i<=n;i++){
          ans += Solve(i-1,dp)*Solve(n-i,dp);
        }
        return dp[n] = ans;
    }
