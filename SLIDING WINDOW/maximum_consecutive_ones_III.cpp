#include<bits/stdc++.h>
using namespace std;

//Given a binary array nums and an integer k, return the maximum number of consecutive 1s you can get by flipping at most k zeros.

/*Input: nums = [1,1,1,0,0,0,1,1,1,1,0] k = 2
Output = 6
*/

//Edge cases-
//1.if(k>=no.of zeroes) ans=n;
//2.nums.size()==0 return 0;
//3.if(k==0) return the longest subarray with ones;

int brute(vector<int>& nums,int k){
    int n=nums.size();
    if(n==0) return 0;
    int maxlen=0;
    for(int i=0;i<n;i++){
        int zeros=0;
        for(int j=i;j<n;j++){
            if(nums[j]==0){
                zeros++;
            }
            if(zeros>k) break;
            maxlen=max(maxlen,j-i+1);
        }
    }
    return maxlen;
}

//TC-O(N*N) SC-O(1)

int optimal(vector<int>& nums,int k){
    int n=nums.size();
    if(n==0) return 0;
    int maxlen=0;
    int left=0,right=0;
    int cnt_zero=0;
    while(right<n){
        if(nums[right]==0){
            cnt_zero++;
        }
        while(cnt_zero>k){
            if(nums[left]==0){
                cnt_zero--;
            }
            left++;
        }
        maxlen=max(maxlen,right-left+1);
        right++;
    }
    return maxlen;
}

//TC-o(n)  SC-O(1) 

int main(){
    vector<int> nums={1,1,1,0,0,0,1,1,1,1,0};
    int k=2;
    cout << brute(nums,k) << endl;
    cout << optimal(nums,k) << endl;
    return 0;
}