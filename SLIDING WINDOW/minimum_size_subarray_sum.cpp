#include<bits/stdc++.h>
using namespace std;

//Given an array of positive integers nums and an integer target, find the minimal length of a contiguous subarray [nums[l], nums[l+1], ..., nums[r]] of which the sum ≥ target. If no such subarray exists, return 0.

/*Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: [4,3] is the smallest subarray with sum ≥ 7*/

//Egde Cases:
//1.if(n==0) return 0;
//2.if(n==1) return (nums[0]>=target)?1:0;
//2.if(target<=0)return 0;
//3.if(target>sum(nums)) return 0;

int brute(vector<int> nums,int target){
    int n=nums.size();
    int minlen=INT_MAX;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=nums[j];
            if(sum>=target){
                minlen=min(minlen,j-i+1);
                break;
            }
        }
    }
    return minlen;
}

//TC-O(N*N)  SC-0(1)

int optimal(vector<int> nums,int target){
    int n=nums.size();
    int minlen=INT_MAX;
    int sum=0;
    int left=0,right=0;
    while(right<n){
        sum+=nums[right];
        while(sum>=target && left<=right){
            minlen=min(minlen,right-left+1);
            sum-=nums[left];
            left++;
        }
        right++;
    }
    return minlen;
}

//TC-O(N)  SC-O(1)

int main(){
    vector<int> nums={2,3,1,2,4,3};
    int target=7;
    cout << brute(nums,target) << endl;
    cout << optimal(nums,target) << endl;
    return 0;
}