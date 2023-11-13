//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    
     
public:
    const int M=1e9+7;
     long long dp[1001][1001];
long long ncr(int n,int r){
    if(n<r)return 0;
    if(n==r || r==0)return 1;
    else if(r==1)return n;
    else if(dp[n][r]!=(-1))return dp[n][r];
    dp[n][r]=(ncr(n-1,r)%M+ncr(n-1,r-1)%M)%M;
    return dp[n][r]%M;

}
    long long nCr(long long n, long long r){
        memset(dp,-1,sizeof dp);
        return ncr(n,r);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends
/*
    By pre computing
int fecto[N];//Pre computing factorial upto N by modulo M.
int binPow(int a,int b)
{
    if (b == 0)return 1;
    if (b == 1)return a;
    int ret = binPow(a,b/2);
    if (b%2 == 0)return (ret * ret)%M;
    return ((ret * ret)%M * a)%M;
}
int inv(int a)
{
    return (binPow(a,M - 2)%M + M)%M;
}
int ncr(int a,int b)
{
    if (b < 0 or a < 0)return 0;
    return (((fecto[a] * inv(fecto[b]))%M * inv(fecto[a - b]))%M + M)%M;
}
/*
