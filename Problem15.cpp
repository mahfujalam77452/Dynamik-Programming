//Problem link
//https://www.geeksforgeeks.org/problems/dice-throw5349/1
//Memoization method.
long long SolveMem(int dice,int face,int target,vector<vector<long long>>&dp){
        if(target<0){
            return 0;
        }
        if(dice!=0&&target==0){
            return 0;
        }
        if(dice==0&&target!=0){
            return 0;
        }
        if(dice==0&&target==0){
            return 1;
        }
        if(dp[dice][target]!=-1){
            return dp[dice][target];
        }
        long long ans=0;
        for(int i=1;i<=face;i++){
            ans=ans+SolveMem(dice-1,face,target-i,dp);
        }
        return dp[dice][target]=ans;
    }
    //Tabulation method.
    long long SolveTab(int d,int f,int t){
        vector<vector<long long>>dp(d+1,vector<long long>(t+1,0));
        
        dp[0][0] = 1 ;
        
        for(int dice=1; dice <= d; dice++){
            for(int target = 1;target <= t; target++){
                long long ans=0;
                for(int i=1;i<=f;i++){
                  if(target - i >= 0)
                  ans=ans+dp[dice-1][target-i];
                }
                dp[dice][target]=ans;
            }
        }
        return dp[d][t];
    }
    long long noOfWays(int M , int N , int X) {
        // code here
        //vector<vector<long long >>dp(N+1,vector<long long>(X+1,-1));
        //return SolveMem(N,M,X,dp);
        return SolveTab(N,M,X);
    }
