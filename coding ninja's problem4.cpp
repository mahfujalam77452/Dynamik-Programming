//Problem link
//https://www.codingninjas.com/studio/problems/ninja-and-the-fence_3210208?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
#include <bits/stdc++.h>
#define M 1000000007
int add(int a,int b){
    return (a%M+b%M)%M;
}
int mul(int a,int b){
    return ((a%M)*1LL*(b%M))%M;
}
//Recurtion and memoyzation.
int ansmem(int n,int k,vector<int>&dp){
    if(n==1)
         return k;
    if(n==2)
         return add(k,mul(k,k-1));
    if(dp[n]!=-1)
         return dp[n];
    int ans=add(mul(ansmem(n-2,k,dp),k-1),mul(ansmem(n-1,k,dp),k-1));
    dp[n]=ans;
    return dp[n];
}
//Tabulation
int ansTab(int n,int k){
    vector<int>dp(n+1,0);
    dp[1]=k;
    dp[2]=add(k,mul(k,k-1));
    for(int i=3;i<=n;i++){
        dp[i]=add(mul(dp[i-2],k-1),mul(dp[i-1],k-1));
        
    }
    return dp[n];
}
//Speace optimization
int ansTabso(int n,int k){
   int  pre=k;
   int  post=add(k,mul(k,k-1));
    for(int i=3;i<=n;i++){
        int ans=add(mul(pre,k-1),mul(post,k-1));
        pre=post;
        post=ans;
    }
    return post;
}
