#include <bits/stdc++.h>
using namespace std;

using ll=long long int;

bool cmp(pair<string,int>& a, pair<string,int>& b){
    return a.second>b.second;
}

void accept_ho_ja(){
    int n,m;
    cin>>n>>m;
    
    vector<string> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    
    vector<pair<string,int>> order(n);
    
    ll t0=0;
    for(int i=0; i<n; i++){
        ll c0=0;
        for(auto c:arr[i]){
            if(c=='0') c0++;
        }
        t0+=c0;
        order[i]=make_pair(arr[i],c0);
    }
    
    sort(order.begin(),order.end(),cmp);
  
    ll c0=0, ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<order[i].first.size(); j++){
            if(order[i].first[j]=='0') c0++;
            else ans+=(t0-c0);
        }
    }
    cout<<ans<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) accept_ho_ja();
}

// link-https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/BININV?tab=statement
