#include <bits/stdc++.h>
using namespace std;

using ll=long long;

bool cmp(ll& a, ll& b){
    return a>b;
}


void accept_ho_ja(){
    ll n;
    cin>>n;
    vector<ll> B(n);
    for(ll i=0; i<n; i++) cin>>B[i];
    sort(B.begin(), B.end(), cmp);
    
    vector<ll> odd;
    vector<ll> even;
    
    for(int i=0; i<n; i++){
        if(B[i]&1) odd.push_back(B[i]);
        else even.push_back(B[i]);
    }
    
    if(odd.size()&1 || even.size()&1 || n&1){
        cout<<-1<<endl;
        return;
    }
    
    int oddhalf=odd.size()/2, evenhalf=even.size()/2;
    
 
    vector<ll> ans(n);
    ll k=0;
    
    for(int i=0; i<oddhalf; i++){
        ll a=(odd[i]+odd[i+oddhalf])/2;
        ll b=odd[i]-a;
        ans[k]=a;
        ans[k+n/2]=b;
        k++;
    }
    for(int i=0; i<evenhalf; i++){
        ll a=(even[i]+even[i+evenhalf])/2;
        ll b=even[i]-a;
        ans[k]=a;
        ans[k+n/2]=b;
        k++;
    }
    
    for(int i=0; i<n; i++) cout<<ans[i]<<" ";
    cout<<endl;
    
}

int main() {
    int t;
    cin>>t;
    while(t--) accept_ho_ja();
}

// link-https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/ALT?tab=statement