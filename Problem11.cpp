//Problem link
//https://leetcode.com/problems/minimum-sideway-jumps/submissions/
//Memoization Method
int solveMem(vector<int>&obstacles,int curlen,int curpos,vector<vector<int>>&dp){
    //Base case.
    int n=obstacles.size()-1;
    if(curpos==n){
        return 0;
    }
    if(dp[curlen][curpos]!=-1){
        return dp[curlen][curpos];
    }
    if(obstacles[curpos+1]!=curlen){
        return dp[curlen][curpos]=solveMem(obstacles,curlen,curpos+1,dp);
    }
    else{
        int ans=INT_MAX;
        for(int i=1;i<=3;i++){
            if(i!=curlen&&obstacles[curpos]!=i){
                ans=min(ans,1+solveMem(obstacles,i,curpos,dp));
            }
        }
        return dp[curlen][curpos]= ans;
    }
}

int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>>dp(4,vector<int>(obstacles.size(),-1));
        return solveMem(obstacles,2,0,dp);
    }
