#include <bits/stdc++.h>
using namespace std;

using ll=long long int;

void accept_ho_ja(){
    int n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
        arr[i]%=2;
    }
    vector<pair<ll,ll>> count(n,make_pair(0,0));
    ll freq=0;
    for(int i=0; i<n; i++){
        if(arr[i]==arr[0]){
            count[i].first=freq;
            freq++;
        }else{
            count[i].first=freq;
        }
    }
    freq=0;
    for(int i=n-1; i>=0; i--){
        if(arr[i]==arr[n-1]){
            count[i].second=freq;
            freq++;
        }else{
            count[i].second=freq;
        }
    }
    
    if(arr[0]==arr[n-1]){
        cout<<count[n-1].first<<endl;
    }else{
        ll ans=INT_MAX;
        for(int i=0; i<n; i++){
            if(arr[i]==arr[0]) ans=min(ans,count[i].first+count[i].second);
        }
        cout<<ans<<endl;
    }
}

int main() {
    int t;
    cin>>t;
    while(t--) accept_ho_ja();
}

// link-https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/JS?tab=statement