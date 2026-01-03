#include<bits/stdc++.h>
using namespace std;

//You are given an integer array fruits where fruits[i] is the type of fruit at tree i.You have 2 baskets, and each basket can carry only one type of fruit, but unlimited quantity.You must pick fruits from contiguous trees.Return the maximum number of fruits you can collect.

/*Input : fruits = [1,2,1]
Output = 3
*/

//EDGE CASES
//1.if(n<=2) return n;
//2.ALL fruits same -> return n;

int brute(vector<int>& fruits){
    int n=fruits.size();
    if(n<=2) return n;
    int maxlen=0;
    for(int i=0;i<n;i++){
        int b1=-1,b2=-1;
        for(int j=i;j<n;j++){
            if(b1==-1) b1=fruits[j];
            else if(b2==-1) b2=fruits[j];
            else if(fruits[j]!=b1 || fruits[j]!=b2){
                break;
            }
            maxlen=max(maxlen,j-i+1);
        }
    }
    return maxlen;
}

//TC-O(N*N)  SC-O(1)

int optimal(vector<int>& fruits){
    int n=fruits.size();
    if(n<=2) return n;
    int left=0,right=0;
    unordered_map<int,int> mpp;
    int maxlen=0;
    while(right<n){
        mpp[fruits[right]]++;
        while(mpp.size()>2){
            mpp[fruits[left]]--;
            if(mpp[fruits[left]]==0){
                mpp.erase(fruits[left]);
            }
            left++;
        }
        maxlen=max(maxlen,right-left+1);
        right++;
    }
    return maxlen;
}

//TC-O(N)  SC-O(1);

int main(){
    vector<int> fruits={1,2,1};
    cout << brute(fruits) << endl;
    cout << optimal(fruits) << endl;
    return 0;
}