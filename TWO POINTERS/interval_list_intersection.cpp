#include<bits/stdc++.h>
using namespace std;

/*Given two lists of closed intervals firstList and secondList,
return the intersection of these two interval lists.*/

/*Input:
firstList  = [[0,2],[5,10],[13,23],[24,25]]
secondList = [[1,5],[8,12],[15,24],[25,26]]

Output:
[[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]*/

//Edge Cases
// 1. one list empty → no intersection
// 2. intervals just touching at boundary → valid intersection
// 3. completely non-overlapping intervals
// 4. one interval fully inside another

//Intuition
//Intersection of two intervals exists if:
// max(start1, start2) <= min(end1, end2)

//Optimal Approach (Two Pointers)
//1. Use pointers i and j for both interval lists
//2. Find overlap between firstList[i] and secondList[j]
//3. Move the pointer whose interval ends first


vector<vector<int>> optimal(vector<vector<int>>& firstList,
                            vector<vector<int>>& secondList) {
    vector<vector<int>> ans;
    int i = 0, j = 0;
    while(i < firstList.size() && j < secondList.size()) {
        int start = max(firstList[i][0], secondList[j][0]);
        int end   = min(firstList[i][1], secondList[j][1]);
        if(start <= end) {
            ans.push_back({start, end});
        }
        // move the pointer which ends earlier
        if(firstList[i][1] < secondList[j][1]) {
            i++;
        } else {
            j++;
        }
    }
    return ans;
}

//TC-O(N + M)  SC-O(1) (excluding output)

int main(){
    vector<vector<int>> firstList = {
        {0,2},{5,10},{13,23},{24,25}
    };
    vector<vector<int>> secondList = {
        {1,5},{8,12},{15,24},{25,26}
    };
    vector<vector<int>> result = optimal(firstList, secondList);
    for(auto &v : result){
        cout << "[" << v[0] << "," << v[1] << "] ";
    }
    cout << endl;
    return 0;
}
