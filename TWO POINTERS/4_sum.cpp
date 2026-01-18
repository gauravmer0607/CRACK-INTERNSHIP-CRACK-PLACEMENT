#include<bits/stdc++.h>
using namespace std;

/*Given an array nums of n integers and an integer target
Return all unique quadruplets [a, b, c, d] such that:
target=a+b+c+d */

/* Input : nums = [1,0,-1,0,-2,2] target = 0
Output : [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]] */

//Edge cases
//1.if(n<4) return empty

//Brute force
//1.try all 4 combinations
//2.if sum == target ,sort quadruplet
//3.store in set to avoid dupliacates.

//TC -o(n^4) SC-o(n)set

vector<vector<int>> optimal(vector<int> nums,int target){
    int n=nums.size();
    if(n<4) return {};
    sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    for(int i=0;i<n;i++){
        if(i>0 &&  nums[i]==nums[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if(j>i+1 && nums[j]==nums[j-1])continue;
            int k=j+1;
            int l=n-1;
            while(k<l){
                long long sum= nums[i]+nums[j];
                sum+=nums[k]+nums[l];
                if(sum>target){
                    l--;
                }
                else if(sum<target){
                    k++;
                }
                else{
                    vector<int> ans={nums[i],nums[j],nums[k],nums[l]};
                    res.push_back(ans);
                    k++;
                    l--;
                    while(k<l && nums[k]==nums[k-1])k++;
                    while(k<l && nums[l]==nums[l+1])l--;
                }
            }
        }
    }
    return res;
}

//TC-O(n^3) SC-O(1)

int main(){
    vector<int> nums={1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> res=optimal(nums, target);
    for(auto v : res){
        for(int x : v){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
