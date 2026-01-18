#include<bits/stdc++.h>
using namespace std;

/*Given two strings s and t, return true if they are equal when both are typed into empty text editors.
'#' means a backspace character.*/

/*Input:  s = "ab#c", t = "ad#c"
Output: true
Explanation: both become "ac" */

//Edge Cases
// 1. both strings empty → true
// 2. string with only '#' → empty string
// 3. more '#' than characters
// 4. no '#' at all → direct comparison

//Brute force
//1.Simulate typing using a stack or string
//2.Process # by popping last character
//3.Compare final strings

//TC-O(N+M)  SC-O(N+M)

bool optimal(string s,string t){
    int i=s.size()-1;
    int j=t.size()-1;
    int skipS=0,skipT=0;
    while(i>=0 || j>=0){
        while(i>=0){
            if(s[i]=='#'){
                skipS++;
                i--;
            }
            else if(skipS>0){
                skipS--;
                i--;
            }
            else break;
        }
        while(j>=0){
            if(t[j]=='#'){
                skipT++;
                j--;
            }
            else if(skipT>0){
                skipT--;
                j--;
            }
            else break;
        }
        if(i>=0 && j>=0){
            if(s[i]!=t[j]) return false;
        }
        else if(i>=0 || j>=0){
            return false;
        }
        i--;
        j--;
    }
    return true;
}

//TC-O(N+M)  SC-O(1)

int main(){
    string s = "ab#c";
    string t = "ad#c";
    cout << optimal(s, t) << endl;
    return 0;
}