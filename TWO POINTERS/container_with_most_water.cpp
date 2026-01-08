#include<bits/stdc++.h>
using namespace std;

/*Given an integer array height where height[i] represents the height of a vertical line at index i,
find two lines that together with the x-axis form a container such that the container holds the maximum water.*/

/*Input:  height = [1,8,6,2,5,4,8,3,7]
Output: 49*/

// key formula = min(height[left],height[right])*(right-left)

//EDGE CASES
//1.if(n<2) return 0;
//2.all heights zero-> return 0

//Brute Force
//try all pairs  find the area using the formula and find the max area..
//TC-O(N*N)  SC-O(1)

int optimal(vector<int>& height){
    int n=height.size();
    int i=0,j=n-1;
    int maxarea=INT_MIN;
    int area=0;
    while(i<j){
        area=min(height[i],height[j])*(j-i);
        maxarea=max(area,maxarea);
        if(height[i]<height[j]){
            i++;
        }
        else{
            j--;
        }
    }
    return maxarea;
}

//TC-O(N) SC-O(1)

int main(){
    vector<int> height={1,8,6,2,5,4,8,3,7};
    cout << optimal(height) << endl;
    return 0;
}