#include<bits/stdc++.h>
using namespace std;

/* A string s of length n contains only Q, W, E, R.
String is balanced if each character appears exactly n/4 times.
You can replace one substring with any characters.
Return the minimum length of substring to replace to make s balanced. */

/*Input: s = "WQWRQQQW" n = 8 
Output: 3 */

int brute(string s,int n){
    unordered_map<char,int> mpp;
    for(char c:s){
        mpp[c]++;
    }
    int ans=n;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                mpp[s[k]]--;
            }
            int need=n/4;
            if(mpp['Q']<=need && mpp['W']<=need && mpp['E']<=need && mpp['R']<=need){
                ans=min(ans,j-i+1);
            }
            for(int k=i;k<=j;k++){
                mpp[s[k]]++;
            }
        }
    }
    return ans;
}
//TC-O(N*N*N)  SC-O(1)


int optimal(string s,int n){
    unordered_map<char,int> mpp;
    for(char ch:s){
        mpp[ch]++;
    }
    int need=n/4;
    if(mpp['Q']==need && mpp['W']==need && mpp['E']==need && mpp['R']==need){
        return 0;
    }
    int ans=0;
    int left=0,right=0;
    while(right<n){
        mpp[s[right]]--;
        while(mpp['Q']<=need && mpp['W']<=need && mpp['E']<=need && mpp['R']<=need){
            ans=min(ans,right-left+1);
            mpp[s[left]]++;
            left++;
        }
        right++;
    }
    return ans;
}

//TC-O(N)  SC-O(1)

int main(){
    string s="WQWRQQQW";
    int n=8;
    cout << brute(s,n) << endl;
    cout << optimal(s,n) << endl;
    return 0;
}