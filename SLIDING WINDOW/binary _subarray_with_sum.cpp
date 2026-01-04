#include<bits/stdc++.h>
using namespace std;

//Given a binary array nums and an integer goal, return the number of non-empty subarrays with sum equal to goal.

/*Input: nums = [1,0,1,0,1], goal = 2
Output = 4
*/

int brute(vector<int>& nums,int goal){
    int n=nums.size();
    int count=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=nums[j];
            if(sum==goal){
                count++;
            }
        }
    }
    return count;
}

//TC-O(N*N)  SC-O(1)

int atmost(vector<int> &nums,int goal){
    if(goal<0) return 0;
    int n=nums.size();
    int sum=0;
    int left=0,right=0;
    int count=0;
    while(right<n){
        sum+=nums[right];
        while(sum>goal && left<=right){
            sum-=nums[left];
            left++;
        }
        count+=(right-left+1);
        right++;
    }
    return count;
}

int optimal(vector<int>& nums,int goal){
    return atmost(nums,goal)-atmost(nums,goal-1);
}

//TC-O(N)  SC-O(1)

int main(){
    vector<int> nums={1,0,1,0,1};
    int goal=2;
    cout << brute(nums,goal) << endl;
    cout << optimal(nums,goal) << endl;
    return 0;
}