//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
//Problem link
//https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1
class Solution{
public:
    //Memoization Method
    bool SolveMem(int index,int N ,  int arr[], int target_sum, vector<vector<int>>&dp){
        //Base case 1
        if(index >= N){
            return 0;
        }
        //Base Case 2
        if(target_sum == 0){
            return 1;
        }
        //Base Case 3
        if(target_sum < 0){
            return 0;
        }
        
        if(dp[index][target_sum] != -1){
            return dp[index][target_sum];
        }
        
        int include = SolveMem(index + 1, N, arr, target_sum - arr[index] , dp);
        int exclude = SolveMem(index + 1, N ,arr, target_sum - 0, dp);
        return dp[index][target_sum] = include or exclude;
    }
    //Tabulation Method
    bool SolveTab(int N , int arr[] , int total){
        vector<vector<int>>dp(N+1,vector<int>(total + 1,0));
        for(int i = 0 ;i <= N ;i++){
            dp[i][0] = 1;
        }
        for ( int index = N-1; index >= 0 ;index --){
            for( int target = 0 ;target <= total / 2 ;target ++){
                
                bool include = 0;
                if(target - arr[index] >= 0){
                    include = dp[index+1][target - arr[index]];
                }
                bool  exclude = dp[index + 1][target - 0];
                
                dp[index][target] = include or exclude;
            }
            
        }
        return dp[0][total/2];
    }
    //Memory Optimization
    bool SolveTabOp(int N , int arr[] , int total){
        //vector<vector<int>>dp(N+1,vector<int>(total + 1,0));
        vector<int>curr(total/2 + 1,0);
        vector<int>next(total/2 + 1,0);
        curr[0] = 1;
        next[0] = 1;
        for ( int index = N-1; index >= 0 ;index --){
            for( int target = 0 ;target <= total / 2 ;target ++){
                
                bool include = 0;
                if(target - arr[index] >= 0){
                    include = next[target - arr[index]];
                }
                bool  exclude = next[target - 0];
                
                curr[target] = include or exclude;
            }
            next = curr;
            
        }
        return next[total/2];
    }
    
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i =0 ;i < N ;i++){
            sum += arr[i];
        }
        if(sum & 1){
            return 0 ;
        }
        int target_sum = sum / 2;
        vector<vector<int>> dp(N+1,vector<int>(target_sum + 1, -1));
        //return SolveMem(0,N,arr,target_sum,dp);
        return SolveTabOp(N, arr, sum);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
