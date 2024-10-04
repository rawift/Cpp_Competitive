#include <bits/stdc++.h>
using namespace std;

using ll=long long int;

ll gcd(ll a, ll b){
    return b==0?a:gcd(b,a%b);
}

ll lcm(ll a , ll b){
    return (a/gcd(a,b))*b;
}

bool cmp(pair<ll,ll>& a, pair<ll,ll>& b){
    return a.first>b.first;
}

void accept_ho_ja(){
    ll n,m;
    cin>>n>>m;
    ll ans=0, fac=1, left=n;
    
    vector<pair<ll,ll>> order(m);
    
    for(int i=0; i<m; i++){
        ll x,y;
        cin>>x>>y;
        order[i]=make_pair(x,y);
    }
    
    sort(order.begin(),order.end(),cmp);
    
    for(int i=0; i<m; i++){
        ll x=order[i].first, y=order[i].second;     
        ll last=fac*left;
        ll lcmfacy=lcm(fac,y);
        ll right=left-last/lcmfacy;
        ans+=right*x;
        left-=right;
        fac=lcmfacy;
    }
    
    cout<<ans<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) accept_ho_ja();
}


// link-https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/ARRFILL?tab=statement