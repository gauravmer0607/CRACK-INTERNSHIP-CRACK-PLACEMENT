#include<bits/stdc++.h>
using namespace std;

//Given two strings s and t, return the minimum window in s which contains all characters of t (including duplicates).If no such window exists, return "".

/*s = "ADOBECODEBANC"
t = "ABC"
Output = "BANC" */

//Egde Cases-
// 1. if(t.size() > s.size()) return ""
// 2. if(t is empty) return ""
// 3. if(s == t) return s

string brute(string s,string t){
    int n=s.size();
    int minlen=INT_MAX;
    string ans="";
    for(int i=0;i<n;i++){
        unordered_map<char,int> mpp;
        for(int j=i;j<n;j++){
            mpp[s[j]]++;
            bool ok =true;
            for(char ch:t){
                if(mpp[ch]==0){
                    ok=false;
                    break;
                }
            }
            if(ok && j-i+1 < minlen){
                minlen=j-i+1;
                ans=s.substr(i,minlen);
            }
        }
    }
    return ans;
}

//TC-O(N*N*N)  SC-O(1)

string optimal(string s,string t){
    int n=s.size();
    if(t.size() > s.size() || t.empty()) return "";
    unordered_map<char,int> mpp;
    for(char ch:t){
        mpp[ch]++;
    }
    int required=t.size();
    int minlen=INT_MAX,start=0;;
    int left=0,right=0;
    while(right<n){
        if(mpp[s[right]]>0){
            required--;
        }
        mpp[s[right]]--;
        while(required==0){
            if(right-left+1<minlen){
                minlen=right-left+1;
                start=left;
            }
            mpp[s[left]]++;
            if(mpp[s[left]]>0){
                required++;
            }
            left++;
        }
        right++;
    }
    string ans=s.substr(start,minlen);
    return ans;
}

//TC-O(N)  SC-O(1)

int main(){
    string s="ADOBECODEBANC";
    string t="ABC";
    cout << brute(s,t) << endl;
    cout << optimal(s,t) << endl;
    return 0;
}