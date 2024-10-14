#include <bits/stdc++.h>
using namespace std;

using ll=long long int;

void accept_ho_ja(){
    ll n,k;
    cin>>n>>k;
    
    k-=n;
    
    ll count=0,diff=0;
    vector<ll> ans;

    while(k>=count){
        ans.push_back(count+1);
        k-=(count);
        count++;
    }
    while(ans.size()<n) ans.push_back(count-k);
    
    for(int i=0; i<n; i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) accept_ho_ja();
}


// link-https://www.codechef.com/practice/course/5-star-and-above-problems/DIFF2500/problems/DISTK?tab=statement