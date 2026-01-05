#include<bits/stdc++.h>
using namespace std;

/*Given an array nums and two integers left and right,
return the number of contiguous subarrays such that:

left ≤ max(subarray) ≤ right */

/*Input: nums = [2,1,4,3], left = 2, right = 3
Output: 3
*/

int brute(vector<int>& nums,int left,int right){
    int n=nums.size();
    int count=0;
    for(int i=0;i<n;i++){
        int maxel=0;
        for(int j=i;j<n;j++){
            maxel=max(maxel,nums[j]);
            if(maxel>=left && maxel<=right){
                count++;
            }
        }
    }
    return count;
}

//TC-O(N*N) SC-O(1)

int atmost(vector<int> nums,int k){
    int n=nums.size();
    int count=0;
    int left=0,right=0;
    while(right<n){
        if(nums[right]>k){
            left=right+1;
        }
        count+=(right-left+1);
        right++;
    }
    return count;
}


int optimal(vector<int> nums,int left,int right){
    return atmost(nums,right)-atmost(nums,left-1);
}

//TC-O(N)  SC-O(1);


int main(){
    vector<int> nums = {2,1,4,3};
    int left = 2, right = 3;
    cout << brute(nums,left,right) << endl;
    cout << optimal(nums, left, right) << endl;
    return 0;
}