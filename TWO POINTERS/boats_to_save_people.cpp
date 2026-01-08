#include<bits/stdc++.h>
using namespace std;

/*You are given an array people where people[i] is the weight of the i-th person,
and an integer limit representing the maximum weight a boat can carry.

Each boat can carry at most 2 people.
Return the minimum number of boats required to carry everyone.*/

/*Input:  people = [3,2,2,1], limit = 3
Output: 3
Explanation:
Boat 1: (1,2)
Boat 2: (2)
Boat 3: (3)*/

// Edge Cases
// 1. if(n == 0) return 0
// 2. if(all weights > limit) → impossible

int optimal(vector<int> people,int limit){
    int n=people.size();
    int boats=0;
    sort(people.begin(), people.end());
    int i=0,j=n-1;
    while(i<=j){
        if(people[i]+people[j]<=limit){
            i++;
        }
        boats++;
        j--;
    }
    return boats;
}

//TC-O(NLOGN)  SC-O(1)

int main(){
    vector<int> people={3,2,2,1};
    int limit=3;
    cout << optimal(people,limit) << endl;
    return 0;
}