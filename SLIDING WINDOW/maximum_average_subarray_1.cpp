#include<bits/stdc++.h>
using namespace std;

//Given an integer array nums consisting of n elements, and an integer k, find a contiguous subarray of length k that has the maximum average value and return this value.
//Answers will be accepted if the error is less than 10⁻⁵.

//INPUT : nums = [1,12,-5,-6,50,3] k = 4
//OUTPUT : 12.75

//EDGE CASES
//if(n==k) return sum(nums)/k;
//if(k==1) return max(nums);

double brute(vector<int> nums,int k){
    int n=nums.size();
    if(n==k) return (double)accumulate(nums.begin(),nums.end(),0)/k;
    if(k==1) return *max_element(nums.begin(),nums.end());
    double maxavg=-DBL_MAX;
    for(int i=0;i<=n-k;i++){
        long long sum=0;
        for(int j=i;j<i+k;j++){
            sum+=nums[j];
        }
        maxavg=max(maxavg,(double)sum/k);
    }
    return maxavg;
}

//T.C-0(N*k)  S.C-O(1)

double optimal(vector<int> nums,int k){
    int n=nums.size();
    if(n==k) return (double)accumulate(nums.begin(),nums.end(),0)/k;
    if(k==1) return *max_element(nums.begin(),nums.end());
    double maxavg=-DBL_MAX;
    int left=0,right=0;
    long long sum=0;
    while(right<n){
        sum+=nums[right];
        if((right-left+1)==k){
            double avg=(double)sum/k;
            maxavg=max(maxavg,avg);
            sum-=nums[left];
            left++;
        }
        right++;
    }
    return maxavg;
}

//TC - O(n)  SC-O(1)

int main(){
    vector<int> nums={1,12,-5,-6,50,3};
    int k=4;
    cout << brute(nums,k) << endl;
    cout << optimal(nums,k) << endl;
}

