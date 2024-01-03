//problem link
    //https://leetcode.com/problems/maximum-height-by-stacking-cuboids/submissions/
    bool check(vector<int>&a,vector<int>&base){
        if(a[0]<=base[0]&&a[1]<=base[1]&&a[2]<=base[2])
              return true;
        else return false;
    }
    int SolveMem(int n,vector<vector<int>>&a,int curr,int prev,vector<vector<int>>&dp){
        
        if(curr==n){
            return 0;
        }
        
        //Beacuse prev start from -1.
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        
        //Include
        int take=0;
        if(prev==-1||check(a[curr],a[prev]))
                       take=a[curr][2]+SolveMem(n,a,curr+1,curr,dp);
        
        //Exclude
        int notTake=0+SolveMem(n,a,curr+1,prev,dp);
        
        return dp[curr][prev+1]= max(take,notTake);
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        int n=cuboids.size();
        for(auto &a:cuboids){
            sort(a.begin(),a.end());
        }
        sort(cuboids.begin(),cuboids.end(),greater<vector<int>>());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return SolveMem(n,cuboids,0,-1,dp);
    }
