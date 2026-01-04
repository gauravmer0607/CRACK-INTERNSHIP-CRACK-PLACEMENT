#include<bits/stdc++.h>
using namespace std;

//Given a string s, return the length of the longest substring without repeating characters.

/*Input:  s = "abcabcbb"
Output: 3
Explanation: "abc"
*/

//Edge cases
//1.if(s.length()<2) return s.length();

int brute(string& s){
    int n=s.length();
    if(n<2) return n;
    int longest=0;
    for(int i=0;i<n;i++){
        unordered_map<char,int> mpp;
        for(int j=i;j<n;j++){
            mpp[s[j]]++;
            if(mpp[s[j]]>1) break;
            longest=max(longest,j-i+1);
        }
    }
    return longest;
}

//TC-O(N*N)  SC-O(1)

int optimal(string& s){
    int n=s.length();
    if(n<2) return n;
    unordered_map<char,int> mpp;
    int left=0,right=0;
    int longest=0;
    while(right<n){
        mpp[s[right]]++;
        while(mpp[s[right]]>1){
            mpp[s[left]]--;
            left++;
        }
        longest=max(longest,right-left+1);
        right++;
    }
    return longest;
}

//TC-O(N)  SC-O(1)

//ultra optimized..
int ultraoptimal(string s){
    int left=0;
    vector<int> last(256,-1);
    int n=s.length();
    int longest=0;
    for(int right=0;right<n;right++){
        if(last[s[right]]>=left){
            left=last[s[right]]+1;
        }
        last[s[right]]=right;
        longest=max(longest,right-left+1);
    }
    return longest;
}
//TC-O(N)  SC-0(1)

int main(){
    string s="abcabcbb";
    cout << brute(s) << endl;
    cout << optimal(s) << endl;
    cout << ultraoptimal(s) << endl;
    return 0;
}
