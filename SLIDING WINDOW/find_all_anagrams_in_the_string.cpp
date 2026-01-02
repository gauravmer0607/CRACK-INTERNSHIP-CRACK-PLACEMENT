#include<bits/stdc++.h>
using namespace std;

//Given two strings s (the main string) and p (the pattern), find all start indices of p’s anagrams in s. Return them in any order.

//Input: s = "cbaebabacd", p = "abc"
//Output: [0,6]
/*Explanation: 
- "cba" at index 0 is an anagram of "abc"
- "bac" at index 6 is an anagram of "abc" */

//Edge cases
//1.if(p>s) return {};
//2.if(s.length()==0 || p.length()==0) return {};
//3.if(p.size()==s.size()) -> check if s is a anagram of p or not

vector<int> brute(string s,string p){
    vector<int> ans;
    int n=s.length();
    sort(p.begin(),p.end());
    for(int i=0;i<=n-p.size();i++){
        string curr=s.substr(i,p.size());
        sort(curr.begin(),curr.end());
        if(curr==p){
            ans.push_back(i);
        }
    }
    return ans;
}
//T.C-O(N*NLOGN) S.C-O(1);

vector<int> optimal(string s,string p){
    vector<int> ans;
    int n=s.length();
    int k=p.size();
    unordered_map<char,int> mpp1;
    for(char ch:p){
        mpp1[ch]++;
    }
    unordered_map<char,int> mpp2;
    int left=0,right=0;
    while(right<n){
        mpp2[s[right]]++;
        if((right-left+1)>k){
            mpp2[s[left]]--;
            if(mpp2[s[left]]==0){
                mpp2.erase(s[left]);
            }
            left++;
        }
        if((right - left + 1) == k && mpp1==mpp2){
            ans.push_back(left);
        }
        right++;
    }
    return ans;
}

//T.C-O(N) SC-O(1)


int main(){
    string s="cbaebabacd";
    string p="abc";
    vector<int> ans1=brute(s,p);
    for(int i:ans1) cout << i << " ";
    vector<int> ans2=optimal(s,p);
    for(int i:ans2) cout << i << " ";
    return 0;
}