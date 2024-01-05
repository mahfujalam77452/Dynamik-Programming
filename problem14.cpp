//Problem link
//https://leetcode.com/problems/pizza-with-3n-slices/submissions/
    int SolveMem(int index,int endindex,vector<int>&slices,int n,vector<vector<int>>&dp){
      if(n==0||index>endindex){
          return 0;
      }
      if(dp[index][n]!=-1){
          return dp[index][n];
      }
      int take=slices[index]+SolveMem(index+2,endindex,slices,n-1,dp);
      int notTake=0+SolveMem(index+1,endindex,slices,n,dp);
      return dp[index][n]=max(take,notTake);
    }

    int maxSizeSlices(vector<int>& slices) {
        int k=slices.size();
        vector<vector<int>>dp1(k+1,vector<int>(k+1,-1));
        int case1=SolveMem(0,k-2,slices,k/3,dp1);
        vector<vector<int>>dp2(k+1,vector<int>(k+1,-1));
        int case2=SolveMem(1,k-1,slices,k/3,dp2);
        return max(case1,case2);
    }
