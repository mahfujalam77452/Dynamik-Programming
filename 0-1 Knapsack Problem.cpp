//Problem Link
//https://www.codingninjas.com/studio/problems/0-1-knapsack_920542?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION

//Recursion and Memoization
int SolveMem(vector<int>& weight, vector<int>& value, int index, int capacity, vector<vector<int>>& dp) {

    // Base case
    // If there is 1 item to steal. Then just compare the weight with the knapsack capacity
    if (index == 0) {
        if (weight[index] <= capacity)
            return value[0];
        else
            return 0;
    }

    if (dp[index][capacity] != -1)
        return dp[index][capacity];

    int include = 0;
    if (weight[index] <= capacity)
        include = value[index] + SolveMem(weight, value, index - 1, capacity - weight[index], dp);

    int exclude = 0 + SolveMem(weight, value, index - 1, capacity, dp);
    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}
//Tabulation
int SolveTab(vector<int>&weight,vector<int>&value,int n,int capacity){
	//Step 1
   vector<vector<int>>dp(n,vector<int>(capacity+1,0));
   //Step2
   //Base case analysis
   for(int w=weight[0];w<=capacity;w++){
	   if(weight[0]<=capacity)
	            dp[0][w]=value[0];
	   else 
	        dp[0][w]=0;
   }
   for(int index=1;index<n;index++){
	   for(int w=0;w<=capacity;w++ ){
		   int include=0;
		  if(weight[index]<=w)
		                 include= value[index]+dp[index-1][w-weight[index]];
		  int exclude=0+dp[index-1][w];
		  dp[index][w]=max(include,exclude);
	   }
   }
   return dp[n-1][capacity];
}
