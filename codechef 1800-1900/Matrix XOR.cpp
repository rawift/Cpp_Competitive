#include <bits/stdc++.h>
using namespace std;

using ll=long long int;

void accept_ho_ja(){
    ll n,m,k;
    cin>>n>>m>>k;
    
    ll ans=0;
    for(ll i=1; i<=n; i++){
        ll count=min(i,m);
        if(count&1) ans^=(k+i+1);
    }
    for(ll i=2; i<=m; i++){
        ll count=min(m-(i-1),n);
        if(count&1) ans^=(k+i+n);
    }
    cout<<ans<<endl;
    
}

int main() {
    int t;
    cin>>t;
    while(t--) accept_ho_ja();
}

// link-https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/MATXOR?tab=statement