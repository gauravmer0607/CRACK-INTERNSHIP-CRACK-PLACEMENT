#include<bits/stdc++.h>
using namespace std;

/*Given n non-negative integers representing an elevation map, compute how much water it can trap after raining.*/

/*Input:  height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6*/

//Intuition 
// water at index i depends on -min(max height on left, max height on right) - height[i]

//Edge cases
//n < 3 → cannot trap water → 0
//All heights same → 0
//Strictly increasing / decreasing → 0
//Zeros in between → valid trapping

//brute force
//for each index
//1.find max height on left
//2.find max height on right
//3.add to water

//TC-O(N^2) SC-O(1)

int optimal(vector<int>&height){
    int n=height.size();
    if(n<3) return 0;
    int left=0,right=n-1;
    int leftmax=0,rightmax=0;
    int water=0;
    while(left<right){
        if(height[left]<=height[right]){
            if(height[left]>=leftmax){
                leftmax=height[left];
            }
            else{
                water+=leftmax-height[left];
            }
            left++;
        }
        else{
            if(height[right]>=rightmax){
                rightmax=height[right];
            }
            else{
                water+=rightmax-height[right];
            }
            right--;
        }
    }
    return water;
}

//TC-O(N) SC-O(1)

int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << optimal(height) << endl;
    return 0;
}