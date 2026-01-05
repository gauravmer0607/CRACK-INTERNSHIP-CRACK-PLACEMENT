#include<bits/stdc++.h>
using namespace std;

//Given an array nums and an integer k, return the maximum element in every contiguous subarray of size k.

/*Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output = [3,3,5,5,6,7] */

//Edge Cases
//1.if(n==0) return{}
//2.if(k==1) return nums;
//3.if(k==n) return max(nums);


vector<int> brute(vector<int>& nums,int k){
    vector<int> ans;
    int n=nums.size();
    for(int i=0;i<=n-k;i++){
        int maxel=*max_element(nums.begin()+i,nums.begin()+i+k);
        ans.push_back(maxel);
    }
    return ans;
}

//TC-O(N*k)  SC-O(1)

vector<int> optimal(vector<int>& nums,int k){
    vector<int> ans;
    deque<int> dq;
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(!dq.empty() && dq.front()==i-k){
            dq.pop_front();
        }
        while(!dq.empty() && nums[dq.back()]<=nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k-1){
            ans.push_back(nums[dq.front()]);
        }
    }
    return ans;
}

//TC-O(N)  SC-O(k)

int main(){
    vector<int> nums={1,3,-1,-3,5,3,6,7};
    int k=3;
    vector<int> ans1=brute(nums,k);
    for(int i=0;i<ans1.size();i++) {
        cout << ans1[i] << " ";
    }
    cout << endl;
    vector<int> ans2=optimal(nums,k);
    for(int i=0;i<ans2.size();i++) {
        cout << ans2[i] << " ";
    }
    cout << endl;
    return 0;
}