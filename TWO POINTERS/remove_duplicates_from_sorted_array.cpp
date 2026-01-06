#include<bits/stdc++.h>
using namespace std;

/*Given a sorted array nums, remove the duplicates in-place such that each element appears only once.
Return the number of unique elements k.

First k elements of nums should contain the unique values.*/

/*Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5
nums = [0,1,2,3,4,_,_,_,_,_]*/

//Edge Cases
//1. if(n == 0) return 0
//2. if(n == 1) return 1
//3. already unique array → return n

//brute approach - copy nums element to set and then again copy set elements to nums and return the index.
//TC-O(NLOGN) SC-O(N)


int optimal(vector<int>& nums){
    int n=nums.size();
    int i=0,j=0;
    while(j<n){
        if(nums[i]!=nums[j]){
            i++;
            nums[i]=nums[j];
        }
        j++;
    }
    return i+1;
}

//TC-O(N)  SC-O(1)


int main(){
    vector<int> nums={0,0,1,1,1,2,2,3,3,4};
    int n=optimal(nums);
    for(int i=0;i<n;i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}