#include<bits/stdc++.h>
using namespace std;

//Given an integer array nums and an integer k, find the maximum sum of any contiguous subarray of size k.

//Input: nums = [2,1,5,1,3,2] k = 3
// Output: 9

//Edge cases
//1.if(n==k) return sum(nums);
//2.if(k==1) return max(nums);

int brute(vector<int> nums,int k){
    int n=nums.size();
    int maxsum=INT_MIN;
    for(int i=0;i<=n-k;i++){
        int sum=0;
        for(int j=i;j<i+k;j++){
            sum+=nums[j];
        }
        maxsum=max(maxsum,sum);
    }
    return maxsum;
}

//TC-O(N*K)  SC-O(1)

int optimal(vector<int> nums,int k){
    int n=nums.size();
    int maxsum=INT_MIN;
    int left=0,right=0;
    int sum=0;
    while(right<n){
        sum+=nums[right];
        if((right-left+1)==k){
            maxsum=max(maxsum,sum);
            sum-=nums[left];
            left++;
        }
        right++;
    }
    return maxsum;
}

//TC-O(N)  SC-0(1)

int main(){
    vector<int> nums={2,1,5,1,3,2};
    int k=3;
    cout << brute(nums,k) << endl;
    cout << optimal(nums,k) << endl;
    return 0;
}
