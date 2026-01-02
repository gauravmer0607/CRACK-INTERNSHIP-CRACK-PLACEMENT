#include<bits/stdc++.h>
using namespace std;

//Given two strings s1 and s2, return true if s2 contains a permutation of s1.In other words, check if some substring of s2 is an anagram of s1.

/*Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains "ba" which is a permutation of s1*/

//Edge cases:
//1.if(s1.size()>s2.size()) return false;
//2.if(s1.size()==0 || s2.size()==0) return false;

bool brute(string s1,string s2){
    int n1=s1.size();
    int n2=s2.size();
    sort(s1.begin(),s1.end());
    for(int i=0;i<=n2-n1;i++){
        string curr=s2.substr(i,s1.size());
        sort(curr.begin(),curr.end());
        if(curr==s1) return true;
    }
    return false;
}
//TC-O(N*MLOGM) SC-O(1)

bool optimal(string s1,string s2){
    unordered_map<char,int> mpp;
    int k=s1.size();
    int n=s2.size();
    for(char ch:s1){
        mpp[ch]++;
    }
    int count=mpp.size();
    int left=0,right=0;
    while(right<n){
        mpp[s2[right]]--;
        if(mpp[s2[right]]==0){
            count--;
        }
        if(right-left+1<k){
            right++;
        }
        else if(right-left+1==k){
            if(count==0){
                return true;
            }
            if(mpp.find(s2[left])!=mpp.end()){
                mpp[s2[left]]++;
                if(mpp[s2[left]]==1){
                    count++;
                }
            }
            right++;
            left++;
        }
    }
    return false;
}
// TC-O(N)  SC-O(1)

int main(){
    string s1="ab";
    string s2="eidbaooo";
    cout << (brute(s1,s2)?"true":"false") << endl;
    cout << (optimal(s1,s2)?"true":"false") << endl;
    return 0;
}