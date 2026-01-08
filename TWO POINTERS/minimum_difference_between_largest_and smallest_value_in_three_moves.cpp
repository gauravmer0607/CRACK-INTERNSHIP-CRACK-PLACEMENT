#include<bits/stdc++.h>
using namespace std;

/*You are given an integer array nums.
In one move, you can remove any element from the array.
You can make at most 3 moves.
Return the minimum possible difference between the largest and smallest value of the remaining array.*/

/*Input: nums = [5,3,2,4]
Output: 0
Explanation:
Remove 5, 4, 3 → remaining [2]
Difference = 0*/

//EDGE CASES
// 1. if(nums.size() <= 4) return 0
//    (we can remove all but one element)
// 2. negative numbers allowed
// 3. array already sorted or unsorted


int optimal(vector<int>& nums){
    int n=nums.size();
    if(n<=4) return 0;
    int ans=INT_MAX;
    sort(nums.begin(),nums.end());
    for(int i=0;i<=3;i++){
        int mn=nums[i];
        int mx=nums[n-1-(3-i)];
        ans=min(ans,mx-mn);
    }
    return ans;
}

//TC-O(NLOGN)  SC-O(1)

int main(){
    vector<int> nums={5,3,2,4};
    cout << optimal(nums) << endl;
    return 0;
}