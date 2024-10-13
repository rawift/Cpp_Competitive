#include <bits/stdc++.h>
using namespace std;


void accept_ho_ja(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    
    unordered_map<int,int> pos;
    for(int i=0; i<n; i++) pos[arr[i]]=i;
    
    int low=pos[n],high=pos[n],ans=0;
    
    for(int i=n; i>1; i--){
        
        high=max(high,pos[i]);
        low=min(low,pos[i]);
        
        if(high-low+1==n-i+1) ans=n-i+1;
    }
    
    cout<<ans<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) accept_ho_ja();
}


// link-https://www.codechef.com/practice/course/5-star-and-above-problems/DIFF2500/problems/REMSUBARR?tab=statement