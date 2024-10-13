#include <bits/stdc++.h>
using namespace std;

using ll=long long int;

void accept_ho_ja(vector<ll>& palin){
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    
    unordered_map<ll,ll> mp;
    
    ll ans=0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<palin.size(); j++) ans+=mp[palin[j]^arr[i]];
        mp[arr[i]]++;
    }
    
    cout<<ans+n<<endl;
}

vector<ll> palindrome(ll limit){
    vector<ll> palin;
    for(int i=0; i<limit; i++){
        string a=to_string(i);
        string b=a;
        reverse(b.begin(),b.end());
        if(a==b) palin.push_back(i);
    }
    return palin;
}

int main() {
    int t;
    cin>>t;
    
    vector<ll> palin=palindrome((1<<15)+1);
    
    while(t--) accept_ho_ja(palin);
}


// link-https://www.codechef.com/practice/course/5-star-and-above-problems/DIFF2500/problems/PALIXOR?tab=statement