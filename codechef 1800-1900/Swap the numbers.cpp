#include <bits/stdc++.h>
using namespace std;

void accept_ho_ja(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    
    vector<int> fix(n,1);
    for(int i=0; i<n; i++){
        if(i+k<n || i-k>=0) fix[i]=0;
    }
    
    vector<int> num;
    for(int i=0; i<n; i++){
        if(!fix[i]) num.push_back(arr[i]);
    }
    sort(num.begin(),num.end());
    int j=0;
    
    for(int i=0; i<n; i++){
        if(!fix[i]){
            arr[i]=num[j++];
        }
    }
    
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;
    
}

int main() {
    int t;
    cin>>t;
    while(t--) accept_ho_ja();
}

// link-https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/SWAPNUM31?tab=statement