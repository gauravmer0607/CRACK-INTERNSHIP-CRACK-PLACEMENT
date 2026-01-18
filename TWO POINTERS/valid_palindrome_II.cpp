#include<bits/stdc++.h>
using namespace std;

/*Given a string s, return true if the string can be a palindrome after deleting at most one character.*/

/*Input:  "abca"
Output: true
Explanation: delete 'b' → "aca"*/

//Brute Force
//1.Try deleting each character one by one
//2.check if it is palindrome or not.

//TC-O(N^2)  SC-O(1)

bool check(string &s,int i, int j){
    while(i<j){
        if(s[i]!=s[j] ) return false;
        i++;
        j--;
    }
    return true;
}

bool optimal(string &s){
    int i=0,j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j]){
            return check(s,i+1,j) || check (s,i,j-1);
        }
        i++;
        j--;
    }
    return true;
}

//TC-O(N) SC-O(1)

int main(){
    string s = "abca";
    cout << optimal(s) << endl;
    return 0;
}