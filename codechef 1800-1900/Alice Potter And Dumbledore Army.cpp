#include <bits/stdc++.h>
using namespace std;

using ll=long long int;

void accept_ho_ja(){
    int n,m;
    cin>>n>>m;
    
    vector<ll> arr(n,0);
    ll ans=0;
    
    while(m--){
        ll p,t;
        cin>>p>>t;
        p--;
        arr[p]+=t;
        ans+=arr[p];
        cout<<ans<<endl;
    }
    
}

int main() {
    accept_ho_ja();
}


// link -https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/DUMBLEDORE?tab=statement