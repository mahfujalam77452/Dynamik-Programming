//Problem link
//https://www.codingninjas.com/studio/problems/cut-into-segments_1214651?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
//Recursion and Memoization
int solvemem(int n,int x,int y,int z,vector<int>&dp){
	if(n==0)
	      return 0;
  //invalid
	if(n<0){
		return INT_MIN;
	}
	if(dp[n]!=-1)
	          return dp[n];
	int u=solvemem(n-x,x,y,z,dp)+1;
	int v=solvemem(n-y,x,y,z,dp)+1;
	int w=solvemem(n-z,x,y,z,dp)+1;
	dp[n]=max(u,max(v,w));
	return dp[n];
}
//Tabulation 
int solvetable(int n,int x,int y,int z){
	vector<int>dp(n+1,INT_MIN);
	dp[0]=0;
	for(int i=1;i<=n;i++){
		if(i-x>=0)
		        dp[i]=max(dp[i],dp[i-x]+1);
        if(i-y>=0)
		        dp[i]=max(dp[i],dp[i-y]+1);
		if(i-z>=0)
		       dp[i]=max(dp[i],dp[i-z]+1);
	}
	return dp[n];
}
