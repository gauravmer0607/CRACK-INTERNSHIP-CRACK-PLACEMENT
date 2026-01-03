#include<bits/stdc++.h>
using namespace std;

//Given a string s and an integer k, return the length of the longest substring that contains at most k distinct characters.

/* Input :s = "aa", k = 1
Output = 2 */

//Edge cases
//1.if(k==0) return 0;
//2.if(s.size<=k) return s.size();
//if(s.empty()) return 0;

int brute(string& s,int k){
    int n=s.size();
    if(k==0) return 0;
    if(n<=k) return n;
    int maxlen=0;
    for(int i=0;i<n;i++){
        unordered_map<char,int> mpp;
        for(int j=i;j<n;j++){
            mpp[s[j]]++;
            if(mpp.size()>k) break;
            maxlen=max(maxlen,j-i+1);
        }
    }
    return maxlen;
}

//TC-O(N*N)  SC-O(1)

int optimal(string& s,int k){
    int n=s.size();
    if(k==0) return 0;
    if(n<=k) return n;
    int left=0,right=0;
    int maxlen=0;
    unordered_map<char,int> mpp;
    while(right<n){
        mpp[s[right]]++;
        while(mpp.size()>k){
            mpp[s[left]]--;
            if(mpp[s[left]]==0){
                mpp.erase(s[left]);
            }
            left++;
        }
        maxlen=max(maxlen,right-left+1);
        right++;
    }
    return maxlen;
}

//TC-O(N)  SC-O(1)


int main(){
    string s="aa";
    int k=1;
    cout << brute(s,k) << endl;
    cout << optimal(s,k) << endl;
    return 0;
}