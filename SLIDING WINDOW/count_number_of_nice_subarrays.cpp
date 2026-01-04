#include<bits/stdc++.h>
using namespace std;

//Given an array nums and an integer k, return the number of nice subarrays.A nice subarray contains exactly k odd numbers.

/*Input: nums = [1,1,2,1,1], k = 3
Output: 2
*/

int brute(vector<int>& nums,int k){
    int n=nums.size();
    int count=0;
    for(int i=0;i<n;i++){
        int odd=0;
        for(int j=i;j<n;j++){
            if(nums[j]%2==1) odd++;
            if(odd==k) count++;
            if(odd>k) break;
        }
    }
    return count;
}

//TC-O(N*N)  SC-0(1)

int atmost(vector<int>& nums,int k){
    int n=nums.size();
    if(k<0) return 0;
    int count=0;
    int left=0,right=0;
    int odd=0;
    while(right<n){
        if(nums[right]%2==1){
            odd++;
        }
        while(odd>k){
            if(nums[left]%2==1){
                odd--;
            }
            left++;
        }
        count+=(right-left+1);
        right++;
    }
    return count;
}

int optimal(vector<int>& nums,int k){
    return atmost(nums,k) - atmost(nums,k-1);
}

int main(){
    vector<int> nums={1,1,2,1,1};
    int k=3;
    cout << brute(nums,k) << endl;
    cout << optimal(nums,k) << endl;
    return 0;
}