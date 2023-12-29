//Problem link
//https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1
//Momoization Method
int solve(vector<vector<int>>&mat,int i,int j,int &maxi,vector<vector<int>>&dp){
        if(i>=mat.size()||j>=mat[0].size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right=solve(mat,i,j+1,maxi,dp);
        int diagonal=solve(mat,i+1,j+1,maxi,dp);
        int down=solve(mat,i+1,j,maxi,dp);
        if(mat[i][j]==1){
            int ans=1+min(right,min(diagonal,down));
            maxi=max(ans,maxi);
            return dp[i][j]= ans;
        }
        else{
            return dp[i][j]=0;
        }
    }
//Tabulation Method
void solveTab(vector<vector<int>>&mat,int &maxi){
        int row=mat.size();
        int col=mat[0].size();
        vector<vector<int>>dp(row+1,vector<int>(col+1,0));
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
                int right=dp[i][j+1];
                int diagonal=dp[i+1][j+1];
                int down=dp[i+1][j];
              if(mat[i][j]==1){
                  int ans=1+min(right,min(diagonal,down));
                  maxi=max(ans,maxi);
                  dp[i][j]= ans;
               }
        else{
             dp[i][j]=0;
        }
            }
        }
    }
