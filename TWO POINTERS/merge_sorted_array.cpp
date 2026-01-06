#include<bits/stdc++.h>
using namespace std;
 
/*You are given two sorted arrays:
nums1 of size m + n, where first m elements are valid
nums2 of size n
Merge nums2 into nums1 in-place, so that nums1 becomes sorted.*/

/*Input: nums1 = [1,2,3,0,0,0],m = 3
nums2 = [2,5,6],n = 3

Output:
[1,2,2,3,5,6]*/

//Edge cases
//1. n == 0 → nums1 already sorted
// 2. m == 0 → copy nums2 into nums1
// 3. both empty → do nothing

//brute approach -copy nums2 into nums1 and sort the whole array.
//TC-(NLOGN) SC-O(1)

void optimal(vector<int>& nums1,int m,vector<int>& nums2,int n){
    int i=m-1;
    int j=n-1;
    int k=m+n-1;
    while(i>=0 && j>=0){
        if(nums1[i]>=nums2[j]){
            nums1[k]=nums1[i];
            i--;
        }
        else if(nums1[i]<nums2[j]){
            nums1[k]=nums2[j];
            j--;
        }
        k--;
    }
    while(j>=0){
        nums1[k]=nums2[j];
        j--;k--;
    }
}

//TC-O(N)  SC-0(1)

int main(){
    vector<int> nums1={1,2,3,0,0,0};         
    vector<int> nums2={2,5,6};
    int m=3,n=3;
    optimal(nums1,m,nums2,n);
    for(int i=0;i<m+n;i++){
        cout << nums1[i] << " ";
    }         
    cout << endl;
    return 0;
}