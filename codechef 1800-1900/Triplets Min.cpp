#include <bits/stdc++.h>
using namespace std;

using ll=long long int;

ll nc2(ll n){
    return (n*(n-1))/2;
}

void accept_ho_ja(){
    ll n,q;
    cin>>n>>q;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin>>arr[i];
    
    sort(arr.begin(),arr.end());
    
    vector<ll> range;
    for(ll i=1; i<n; i++){
        range.push_back(nc2(n-i));
    }
    for(ll i=1; i<range.size(); i++){
        range[i]+=range[i-1];
    }
    
    
    while(q--){
        ll k;
        cin>>k;
        ll pos=lower_bound(range.begin(),range.end(),k)-range.begin();
        cout<<arr[pos]<<endl;
    }
    
}

int main() {
    int t;
    cin>>t;
    while(t--) accept_ho_ja();
}

// link-https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/TRIPLETMIN?tab=statement