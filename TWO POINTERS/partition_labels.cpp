#include<bits/stdc++.h>
using namespace std;

/*Given a string s, partition it into as many parts as possible
so that each letter appears in at most one part.
Return a list of integers representing the size of these parts.*/

/*Input:  "ababcbacadefegdehijhklij"
Output: [9,7,8]*/

//Edge Cases
// 1. empty string → empty result
// 2. all characters same → one partition
// 3. all characters unique → every character is its own partition

//Brute Force
//1. Try all partitions
//2. Check if a character repeats in another partition
//Not optimal

//Optimal Approach (Greedy)
//1. Store last occurrence of each character
//2. Traverse string and extend current partition till
//   the farthest last occurrence of seen characters
//3. When current index == partition end → cut partition


vector<int> optimal(string s){
    vector<int> last(26, 0);
    for(int i = 0; i < s.size(); i++){
        last[s[i] - 'a'] = i;
    }
    vector<int> ans;
    int start = 0, end = 0;
    for(int i = 0; i < s.size(); i++){
        end = max(end, last[s[i] - 'a']);
        if(i == end){
            ans.push_back(end - start + 1);
            start = i + 1;
        }
    }
    return ans;
}

//TC-O(N)  SC-O(1)

int main(){
    string s = "ababcbacadefegdehijhklij";
    vector<int> result = optimal(s);
    for(int x : result){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
