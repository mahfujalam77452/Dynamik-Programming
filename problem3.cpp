//Problem link.
//https://www.codingninjas.com/studio/problems/house-robber_839733?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
#include <bits/stdc++.h> 
long long int solvemem(vector<int>&nums){
    long long int n;
    n=nums.size();
    long long int pre=0;
    long long int post=nums[0];
    for(int i=1;i<n;i++){
       long long int ans=max(pre+nums[i],post);
       pre=post;
       post=ans; 
    }
    return post;
}
long long int houseRobber(vector<int>& valueInHouse)
{
   //This question is same as the previous question but 
   //The only difference is here 1 and n th elements are 
   //also adjacent .
   //So we can't take n th element if we take 1th element
   //and viseversa
   //So we can solve this problem using the previous algorithm
   // one's from (1-(n-1))and then(2-n)elements and take the
   //maximum. previous question problem 2 github
   int n=valueInHouse.size();
   //If there only one house.
   if(n==1)
        return valueInHouse[0];
    vector<int>first,second;
    for(int i=0;i<n;i++){
        if(i!=n-1)
               first.push_back(valueInHouse[i]);
        if(i!=0)
              second.push_back(valueInHouse[i]);
    }
    return max(solvemem(first),solvemem(second));
}
