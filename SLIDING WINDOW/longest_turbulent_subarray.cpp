#include<bits/stdc++.h>
using namespace std;

/* A subarray is turbulent if the comparison signs alternate:
nums[i-1] < nums[i] > nums[i+1] < nums[i+2] ...
OR
nums[i-1] > nums[i] < nums[i+1] > nums[i+2] ... */

/*Input:  nums = [9,4,2,10,7,8,8,1,9]
Output: 5
Explanation: [4,2,10,7,8]
*/

//EDGE CASES
//1.//1. if(n == 0) return 0
//2. if(n == 1) return 1
//3. if all elements equal → answer = 1

int brute(vector<int>& nums){
    int n=nums.size();
    if(n<=1) return n;
    int ans=1;
    for(int i=0;i<n;i++){
        int prev=0;
        for(int j=i+1;j<n;j++){
            int curr=0;
            if(nums[j]>nums[j-1]) curr=1;
            else if(nums[j]<nums[j-1]) curr=-1;
            else break;
            if(prev==0 || curr!=prev){
                ans=max(ans,j-i+1);
                prev=curr;
            }
            else{
                break;
            }
        }
    }
    return ans;
}

//TC-O(N*N) SC-O(1)

int optimal(vector<int> & nums){
    int n=nums.size();
    if(n<=1) return n;
    int ans=1;
    int len=1;
    int prev=0;
    for(int i=1;i<n;i++){
        int curr=1;
        if(nums[i]>nums[i-1]){
            curr=1;
        }
        else if(nums[i]<nums[i-1]){
            curr=-1;
        }
        else{
            len=1;
            prev=0;
            continue;
        }
        if(curr!=prev){
            len++;
        }else{
            len=2;
        }
        prev=curr;
        ans=max(ans,len);
    }
    return ans;
}

//TC-O(N)  SC-O(1);

int main(){
    vector<int> nums = {9,4,2,10,7,8,8,1,9};
    cout << brute(nums) << endl;
    cout << optimal(nums) << endl;
    return 0;
}
