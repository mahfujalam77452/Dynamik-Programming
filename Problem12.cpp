//Problem Link
//https://leetcode.com/problems/reducing-dishes/submissions/
//Memoization Method.
int SolveMem(vector<int>& satisfaction,int index,int time,vector<vector<int>>&dp){
    //Base case.
    if(index==satisfaction.size()){
        return 0;
    }
    if(dp[index][time]!=-1){
        return dp[index][time];
    }
    int take=satisfaction[index]*(time+1)+SolveMem(satisfaction,index+1,time+1,dp);
    int skip=0+SolveMem(satisfaction,index+1,time,dp);
    return dp[index][time]=max(take,skip);
}
//Tabulation Method
int SolveTab(vector<int>& satisfaction){
    int n=satisfaction.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    
    for(int index=n-1;index>=0;index--){
        for(int time=index;time>=0;time--){
            int take=satisfaction[index]*(time+1)+dp[index+1][time+1];
            int skip=0+dp[index+1][time];
             dp[index][time]=max(take,skip);
        }
    }
    return dp[0][0];
}
//Memory Optimization.
int SolveTab2(vector<int>& satisfaction){
    int n=satisfaction.size();
    vector<int>next(n+1,0);
    vector<int>curr(n+1,0);
    
    for(int index=n-1;index>=0;index--){
        for(int time=index;time>=0;time--){
            int take=satisfaction[index]*(time+1)+next[time+1];
            int skip=0+next[time];
             curr[time]=max(take,skip);
        }
        next=curr;
    }
    return next[0];
}

int maxSatisfaction(vector<int>& satisfaction) {
       sort(satisfaction.begin(),satisfaction.end());
      // int n=satisfaction.size();
       //vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
      // return SolveMem(satisfaction,0,0,dp);
      //return SolveTab(satisfaction);
      return SolveTab2(satisfaction);
    }
