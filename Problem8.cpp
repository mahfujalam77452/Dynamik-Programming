//https://www.codingninjas.com/studio/problems/minimum-coins_2180776?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
//Memoization Method.
int solveMem(int n, vector<int> days, vector<int> cost,vector<int>&dp,int index){
    if(index>=n){
        return 0;
    }
    
    if(dp[index]!=-1)return dp[index];
    //1 Day pass
    int option1=cost[0]+solveMem(n,days,cost,dp,index+1);
    
    int i;
    //7 days pass
    for(i=index;i<n&&days[i]<days[index]+7;i++);
    int option2 = cost[1] + solveMem(n,days,cost,dp,i);
    
    //30 days pass
    for(i=index;i<n&&days[i]<days[index]+30;i++);
    int option3 = cost[2]+solveMem(n,days,cost,dp,i);
    
    dp[index]=min(option3,min(option2,option1));
    
    return dp[index];
}
//Tabulation Method
int solveTab(int n, vector<int> days, vector<int> cost){
    vector<int>dp(n+1,INT_MAX);
    dp[n]=0;
    for(int k=n-1;k>=0;k--){
        
    int option1=cost[0]+dp[k+1];
    
    int i;
    //7 days pass
    for(i=k;i<n&&days[i]<days[k]+7;i++);
    int option2 = cost[1] + dp[i];
    
    //30 days pass
    for(i=k;i<n&&days[i]<days[k]+30;i++);
    int option3 = cost[2]+dp[i];
    
    dp[k]=min(option3,min(option2,option1));
    }
    return dp[0];
}
