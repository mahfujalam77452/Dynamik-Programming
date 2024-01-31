//problem link
//https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/
//Memoization Method
int Solve(vector<int>& nums1, vector<int>& nums2,int index,bool swaped,vector<vector<int>>&dp){
        if(index >= nums1.size()){
            return 0;
        }
        if(dp[index][swaped] != -1){
            return dp[index][swaped];
        }
        int ans  = INT_MAX;
        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];
        if (swaped){
            swap(prev1,prev2);
        }
        if(nums1[index]>prev1 && nums2[index] > prev2){
            ans = Solve(nums1,nums2,index+1,0,dp);
        }
        if(nums1[index] > prev2 && nums2[index] > prev1){
            ans = min (ans,1 + Solve(nums1,nums2,index+ 1 ,1,dp));
        }
        return dp[index][swaped]= ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        int n = nums1.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        bool swaped = 0;
        return Solve(nums1,nums2,1,swaped,dp);
        
    }
