#include <bits/stdc++.h>
using namespace std;
using ll=long long;


ll _ceil(ll a, ll b){
    return(a%b==0?a/b:a/b+1);
}

void accept_ho_ja(){
    ll n,x,y;
    cin>>n>>x>>y;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    ll idx=max_element(arr.begin(),arr.end())-arr.begin();
    ll ele=arr[idx];
    if(y>x){
        cout<<_ceil(ele,y)<<endl;
    }else{
        int ans=0;
        for(int i=n-1; i>=0; i--){
            arr[i]-=ans*y;
            if(arr[i]>0) ans+=_ceil(arr[i],x);
        }
        cout<<ans<<endl;
    }
    
}

int main() {
    int t;
    cin>>t;
    while(t--) accept_ho_ja();
}
