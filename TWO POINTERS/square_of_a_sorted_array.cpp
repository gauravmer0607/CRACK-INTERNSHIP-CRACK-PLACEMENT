#include<bits/stdc++.h>
using namespace std;
 
/*Given an integer array nums sorted in non-decreasing order,
return an array of the squares of each number sorted in non-decreasing order.*/

/*Input:  nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100] */

// Edge Cases:
// 1. n == 0 → return empty array
// 2. single element → return its square
// 3. all positive numbers
// 4. all negative numbers

//Brute approach- square all the elements in the array then sort the array.
//TC-O(NLOGN) SC-O(1)

vector<int> optimal(vector<int>& nums){
    int n=nums.size();
    vector<int> ans(n);
    int i=0,j=n-1;
    int k=n-1;
    while(i<=j){
        if(abs(nums[i])>abs(nums[j])){
            ans[k]=nums[i]*nums[i];
            i++;
        }
        else{
            ans[k]=nums[j]*nums[j];
            j--;
        }
        k--;
    }
    return ans;
}

//TC-O(N) SC-O(N)


int main(){
    vector<int> nums={-4,-1,0,3,10};
    vector<int> result=optimal(nums);
    for(int i=0;i<result.size();i++){
        cout << result[i] << " ";
    }         
    cout << endl;
    return 0;
}