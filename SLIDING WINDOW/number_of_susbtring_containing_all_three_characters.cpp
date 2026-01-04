#include<bits/stdc++.h>
using namespace std;

//Given a string s consisting only of 'a', 'b', 'c',return the number of substrings that contain at least one 'a', 'b', and 'c'.

/*Input:  s = "abcabc"
Output: 10
*/

int brute(string s){
    int n=s.length();
    if(n<=2) return 0;
    int count=0;
    for(int i=0;i<n;i++){
        unordered_map<char,int> mpp;
        for(int j=i;j<n;j++){
            mpp[s[j]]++;
            if(mpp['a']>=1 && mpp['b']>=1 && mpp['c']>=1){
                count++;
            }
        }
    }
    return count; 
}

//Tc-O(n*n) SC-O(1)

int optimal(string s){
    int n=s.length();
    if(n<=2) return 0;
    unordered_map<char,int> mpp;
    int count=0;
    int left=0,right=0;
    while(right<n){
        mpp[s[right]]++;
        while(mpp['a']>0 && mpp['b']>0 && mpp['c']>0){
            count+=(n-right);
            mpp[s[left]]--;
            left++;
        }
        right++;
    }
    return count;
}

//TC-O(N)  SC-O(1)

int main(){
    string s="abcabc";
    cout << brute(s) << endl;
    cout << optimal(s) << endl;
    return 0;
}