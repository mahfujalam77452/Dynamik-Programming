//Problem link
//https://practice.geeksforgeeks.org/problems/get-minimum-squares0538/1
//Recursion + Memoization
	int solveMem(int n,vector<int>&dp){
    if(n==0)
        return 0;
    if(dp[n]!=-1)
        return dp[n];
    int ans=n;
    for(int i=1;i*i<=n;i++){
        ans=min(ans,1+solveMem(n-i*i,dp));
    }
    dp[n]=ans;
    return dp[n];
    }
    //Tabulation
    int solveTab(int n){
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        int ans=n;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
           dp[i]=min(dp[i],1+dp[i-j*j]);
            }
        }
        return dp[n];
    }
