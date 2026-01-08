#include<bits/stdc++.h>
using namespace std;

/*
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order,
find two numbers such that they add up to a specific target number.

Return the indices of the two numbers (1-indexed).
You may assume that exactly one solution exists.
*/

/*
Input:  numbers = [2,7,11,15], target = 9
Output: [1,2]
*/

//Edge cases:
//1.if(n<2) -> no answer
//2.arrays can contain negative numbers

//Brute approach
/*using a nested loop check all pairs if the sum of arr[i]+arr[j]== target any time we have to
return the indices i and j. if there is not such pair we will return {-1,-1}*/

//TC-O(N*N) SC-O(1)

vector<int> optimal(vector<int>& nums,int target){
    int n=nums.size();
    int i=0,j=n-1;
    while(i<j){
        if(nums[i]+nums[j]==target){
            return {i+1,j+1};
        }else if(nums[i]+nums[j]>target){
            j--;
        }else if(nums[i]+nums[j]<target){
            i++;
        }
    }
    return {-1,-1};
}

//TC-O(N)  SC-O(1)

int main(){
    vector<int> nums={2,7,11,15};
    int target=9;
    vector<int> res=optimal(nums,target);
    for(int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}

