#include<bits/stdc++.h>
using namespace std;

/*Given a sorted array nums, remove duplicates in-place such that each element appears at most twice.
Return the new length k.
The first k elements of nums should contain the result.*/

/*Input:  nums = [0,0,1,1,1,1,2,3,3]
Output: 7
Array after removal: [0,0,1,1,2,3,3]*/

// EDGE cases
// 1. n <= 2 → return n (already valid)
// 2. all elements same
// 3. no duplicates
// 4. negative numbers allowed

//Brute force
//1.use another array
//2.allow each number twice
//3.copy back to original array

//TC-o(n)  sc-o(n)

int optimal(vector<int>& nums){
    int n=nums.size();
    if(n<=2) return n;
    int i=2;
    for(int j=2;j<n;j++){
        if(nums[j]!=nums[i-2]){
            nums[i]=nums[j];
            i++;
        }
    }
    return i;
}

//TC-O(N) sc-O(1)


int main(){
    vector<int> nums = {0,0,1,1,1,1,2,3,3};
    int k = optimal(nums);
    cout << "New length: " << k << endl;
    cout << "Array: ";
    for(int i = 0; i < k; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}