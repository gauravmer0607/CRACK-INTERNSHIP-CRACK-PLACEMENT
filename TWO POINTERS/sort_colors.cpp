#include<bits/stdc++.h>
using namespace std;

/*Given an array nums with values 0, 1, and 2, sort them in-place so that all 0s come first, then 1s, then 2s*/

/*Input:  nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]*/

//edge cases
// 1. n == 0 → do nothing
// 2. n == 1 → already sorted
// 3. all elements same
// 4. already sorted / reverse sorted


//brute force
//1.count no. of 0s,1s,2s 
//2.overwrite them accordingly

//tc-o(n) sc-o(1)

//Dutch National Flag Algo

void optimal(vector<int>& nums){
    int low=0,mid=0,high=nums.size()-1;
    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[low],nums[mid]);
            low++,mid++;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else{
            swap(nums[mid],nums[high]);
            high--;
        }
    }
}

//TC-O(N)  SC-O(1)


int main(){
    vector<int> nums = {2,0,2,1,1,0};
    optimal(nums);
    for(int x : nums){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}