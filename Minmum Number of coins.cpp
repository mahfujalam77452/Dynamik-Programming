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
