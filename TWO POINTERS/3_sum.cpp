#include<bits/stdc++.h>
using namespace std;

/*Given an integer array nums, return all unique triplets [a, b, c] such that:
a + b + c = 0
The solution set must not contain duplicate triplets.*/

/*Input:  nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]*/

//Edge cases
// 1. if(nums.size() < 3) return {}
// 2. array may contain negatives
// 3. duplicates allowed in input but not in output
// 4. answer order does not matter

//Brute force-Try all triplets and check sum..
//use three loops and check if the triplet is equal to 0 then store the triple in an vector 
//the sort it and store it in a set so that it will store only unique..

//TC-O(N^3)  sc-O(N)(for set)

vector<vector<int>> optimal(vector<int>& nums){
    int n=nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    if(n<3) return ans;
    for(int i=0;i<n;i++){
        while(i>0 && nums[i]==nums[i-1]) i++;
        int j=i+1;
        int k=n-1;
        while(j<k){
            long long sum=nums[i]+nums[j]+nums[k];
            if(sum>0){
                k--;
            }
            else if(sum<0){
                j++;
            }
            else{
                vector<int> temp={nums[i],nums[j],nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1])j++;
                while(j<k && nums[k]==nums[k+1])k--;
            }
        }
    }
    return ans;
}

//TC-O(N^2)  SC-O(1) ignoring output vector

int main(){
    vector<int> nums={-1,0,1,2,-1,-4};
    vector<vector<int>> res=optimal(nums);
    for(auto v:res){
        for(auto x:v) cout << x << " ";
        cout << endl;
    }
    cout << endl;
    return 0;
}
