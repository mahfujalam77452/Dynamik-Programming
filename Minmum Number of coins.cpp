//Tabulation method.
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    vector<int>dp(x+1,INT_MAX);
   //Base case
    dp[0]=0;
    for(int i=1;i<=x;i++){
        for(int j=0;j<num.size();j++){
            if(i-num[j]>=0&&dp[i-num[j]]!=INT_MAX)
                                dp[i]=min(dp[i],1+dp[i-num[j]]);
        }
    }
    //If the amount can't be obtained by this type of coins.
    if(dp[x]==INT_MAX)
               return -1;
    return dp[x];
}
//Time complexity O(x*num.size())
//Space complexity O(n).
//recurtion and momoization.
int minimum(int x,vector<int>&num,vector<int>&dp){
    if(x==0)
       return 0;
    if(x<0)
       return INT_MAX;
    if(dp[x]!=-1)
       return dp[x];
    int mini=INT_MAX;
    for(int i=0;i<num.size();i++){
       int ans=minimum( x-num[i], num, dp) ;
      if(ans!=INT_MAX)
           mini=min(1+ans,mini);
           }
    dp[x]=mini;
    return mini;
}

int minimumElements(vector<int> &num, int x)
{  vector<int> dp(x + 1, -1);
    int ans = minimum(x, num, dp);
    // Return -1 as it is not possible to make desired sum 'X'.
    if (ans == INT_MAX)
    {
        return -1;
    }
    return ans;
}
