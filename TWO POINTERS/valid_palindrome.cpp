#include<bits/stdc++.h>
using namespace std;

/*Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.*/

/*Input:  "A man, a plan, a canal: Panama"
Output: true
*/

//Edge cases
// 1. empty string → true
// 2. string with only special characters → true
// 3. single character → true

//Brute approach- remove the non-alphanumeric characters and  convert to lowercase and then chack palindrome..

//TC-O(N)  SC-O(N)

bool optimal(string s){
    int n=s.length();
    int i=0,j=n-1;
    while(i<j){
        while(i<j && !isalnum(s[i])) i++;
        while(i<j && !isalnum(s[j])) j--;
        if(tolower(s[i])!=tolower(s[j])) return false;
        i++;
        j--;
    }
    return true;
}

//TC-O(N)  SC-O(1)


int main(){
    string s="A man, a plan, a canal: Panama";
    cout << optimal(s) << endl; 
    return 0;
}