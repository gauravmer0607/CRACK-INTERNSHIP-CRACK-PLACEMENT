#include<bits/stdc++.h>
using namespace std;

//Given an array of positive integers nums and an integer k, return the number of contiguous subarrays where the product < k.

/*Input : nums = [10,5,2,6], k = 100
Output = 8
*/

//EDGE CASES
//1.if(n==0) return 0;
//2.if(k<=1) return 0;

int brute(vector<int>& nums,int k){
    int n=nums.size();
    if(n==0) return 0;
    if(k<=1) return 0;
    int count=0;
    for(int i=0;i<n;i++){
        long long prod=1;
        for(int j=i;j<n;j++){
            prod*=nums[j];
            if(prod>=k){
                break;
            }
            count++;
        }
    }
    return count;
}

//TC-O(N*K)  SC-0(1)

int optimal(vector<int>& nums,int k){
    int n=nums.size();
    if(n==0) return 0;
    if(k<=1) return 0;
    int left=0,right=0;
    long long prod=1;
    int count=0;
    while(right<n){
        prod*=nums[right];
        while(prod>=k && left<=right){
            prod/=nums[left];
            left++;
        }
        count+=(right-left+1);
        right++;
    }
    return count;
}

//TC-O(N) SC-O(1);

int main(){
    vector<int> nums={10,5,2,6};
    int k=100;
    cout << brute(nums,k) << endl;
    cout << optimal(nums,k) << endl;
    return 0;
}
