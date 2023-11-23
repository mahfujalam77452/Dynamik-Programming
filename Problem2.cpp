//Problem link
//https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
int solvememo(vector<int>&nums,int n,vector<int>&dp){
    if(n<0)
         return 0;
    if(n==0)
          return nums[n];
    if(dp[n]!=-1)
          return dp[n];
    //if we add the current number we should skep the next element
    int add=solvememo(nums,n-2,dp)+nums[n];
    //if we dosen't add the current number we can go to the next
    //element.
    int escape=solvememo(nums,n-1,dp);
    dp[n]=max(add,escape);
    return dp[n];
}
//Tabulation method
int solvetable(vector<int>&nums){
    int n=nums.size();
    vector<int>dp(n,-1);
    dp[0]=nums[0];
    for(int i=1;i<n;i++){
        dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
    }
    return dp[n-1];
}
//memori optimization
int solvemem(vector<int>&nums){
    int n;
    n=nums.size();
    int pre=0;
    int post=nums[0];
    for(int i=1;i<n;i++){
       int ans=max(pre+nums[i],post);
       pre=post;
       post=ans; 
    }
    return post;
}
