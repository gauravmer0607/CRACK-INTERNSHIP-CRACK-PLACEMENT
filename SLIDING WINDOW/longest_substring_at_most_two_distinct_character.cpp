#include<bits/stdc++.h>
using namespace std;

//Given a string s, return the length of the longest substring that contains at most 2 distinct characters.

/*Input: s = "eceba"
Output: 3
Explanation: "ece"
*/

//EDGE CASES 
//1.if(s.size()<=2) return s.size()
//2.if all charater same -> ans=s.size();

int brute(string& s){
    int n=s.size();
    if(n<=2) return n;
    int maxlen=0;
    for(int i=0;i<n;i++){
        unordered_map<char,int> mpp;
        for(int j=i;j<n;j++){
            mpp[s[j]]++;
            if(mpp.size()>2) break;
            maxlen=max(maxlen,j-i+1);
        }
    }
    return maxlen;
}

//TC-O(N*N)  SC-O(1)

int optimal(string& s){
    int n=s.size();
    if(n<=2) return n;
    int left=0,right=0;
    int maxlen=0;
    unordered_map<char,int> mpp;
    while(right<n){
        mpp[s[right]]++;
        while(mpp.size()>2){
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
    string s="eceba";
    cout << brute(s) << endl;
    cout << optimal(s) << endl;
    return 0;
}