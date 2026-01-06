#include<bits/stdc++.h>
using namespace std;

/*Move all 0’s to the end of the array while maintaining the relative order of non-zero elements.
Do it in-place. */

/* Input:[0,1,0,3,12]
Output:[1,3,12,0,0] */

//Edge cases
// 1. n == 0 → do nothing
// 2. n == 1 → do nothing
// 3. no zeros → array remains same
// 4. all zeros → array remains same

//Brute approach- copy all non-zero elements in another array and then copy back the elements in nums upto the size of another array and fill rest of the elements to zero..

//TC-O(N)  SC-O(N)

void optimal(vector<int>& nums){
    int n=nums.size();
    int i=0,j=0;
    while(j<n){
        if(nums[j]!=0){
            swap(nums[i],nums[j]);
            i++;
        }
        j++;
    }
}

//TC-O(N)  SC-O(1)

int main(){
    vector<int> nums={0,1,0,3,12};
    optimal(nums);
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << endl;
    }
}