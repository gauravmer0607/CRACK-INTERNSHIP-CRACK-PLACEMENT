#include<bits/stdc++.h>
using namespace std;

//Given a string s and an integer k, you can replace at most k characters in the string so that the resulting substring contains only one repeating character.Return the length of the longest such substring.

/*Input: s = "AABABBA", k = 1
Output = 4
Explanation: "AABA" or "ABBA"
*/

//Edge cases:
//1.if(k>=s.length()) return s.length()

int brute(string& s,int k){
    int n=s.length();
    if(k>=n) return n;
    int longest=0;
    for(int i=0;i<n;i++){
        unordered_map<char,int> mpp;
        int maxel=0;
        for(int j=i;j<n;j++){
            mpp[s[j]]++;
            maxel=max(maxel,mpp[s[j]]);
            if((j-i+1)-maxel>k)break;
            longest=max(longest,j-i+1);
        }
    }
    return longest;
}

//TC-O(n*n) SC-O(1)

int optimal(string &s,int k){
    int n=s.length();
    if(k>=n) return n;
    int left=0;
    int right=0;
    unordered_map<char,int> mpp;
    int maxlen=0,maxel=0;
    while(right<n){
        mpp[s[right]]++;
        maxel=max(maxel,mpp[s[right]]);
        while((right-left+1)-maxel>k){
            mpp[s[left]]--;
            left++;
        }
        maxlen=max(maxlen,right-left+1);
        right++;
    }
    return maxlen;
}

//TC-O(N)  SC-O(1)

int main(){
    string s="AABABBA";
    int k=1;
    cout << brute(s,k) << endl;
    cout << optimal(s,k) << endl;
    return 0;
}