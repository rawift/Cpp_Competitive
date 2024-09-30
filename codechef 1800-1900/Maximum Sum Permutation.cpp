#include <bits/stdc++.h>
using namespace std;

using ll=long long int;

void accept_ho_ja(){
    int n,q;
    cin>>n>>q;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    
    vector<ll> d(n,0);
    while(q--){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        d[l]++;
        if(r+1<n) d[r+1]--;
    }
    
    vector<ll> freq(n,0);
    for(int i=0; i<n; i++) freq[i]=d[i]+freq[max(i-1,0)];
    
    vector<pair<ll,ll>> order(n);
    for(int i=0; i<n; i++) order[i]=make_pair(freq[i],i);
    sort(order.begin(),order.end());
    sort(arr.begin(),arr.end());
    
    
    ll sum=0;
    vector<ll> output(n);
    for(int i=0; i<n; i++){
        output[order[i].second]=arr[i];
        sum+=order[i].first*arr[i];
    }
    
    cout<<sum<<endl;
    for(int i=0; i<n; i++) cout<<output[i]<<" ";
    cout<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) accept_ho_ja();
}

// link-https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/MAXSUMPERM?tab=statement
