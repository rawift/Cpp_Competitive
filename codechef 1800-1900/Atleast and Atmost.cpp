#include <bits/stdc++.h>
using namespace std;

using ll =long long int;

void accept_ho_ja(){
    ll n;
    cin>>n;
    vector<ll> mex(n);
    for(ll i=0; i<n; i++) cin>>mex[i];
    
    sort(mex.begin(),mex.end());
    
    vector<pair<ll,ll>> count(n);
    vector<ll> counti(n,0);
    
    ll maxis=0;
    
    for(ll i=0; i<n; i++){
        ll above=mex.end()-upper_bound(mex.begin(),mex.end(),i);
        ll below=lower_bound(mex.begin(),mex.end(),i)-mex.begin();
        count[i]=make_pair(below,above);
        counti[mex[i]]++;
        maxis+=count[i].second;
    }
    
    for(ll i=0; i<n; i++){
        ll mini=count[i].second;
        ll maxi=n*n-maxis+count[i].second-(n-i)*counti[i];
        cout<<mini<<" "<<maxi<<endl;
    }
}

int main() {
    int t;
    cin>>t;
    while(t--) accept_ho_ja();
}

// link-https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/ATAT?tab=statement