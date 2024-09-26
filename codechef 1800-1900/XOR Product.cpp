#include <bits/stdc++.h>
using namespace std;

using ll=long long;
ll mod=998244353;

void accept_ho_ja(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    
    sort(arr.begin(),arr.end());
    vector<int> even;
    int c1=0;
    
    for(int i=0; i<n; i++){
        if(arr[i]==1) c1++;
        
        if(!(arr[i]&1)){
            if(c1){
                arr[i]++;
                c1--;
            }
        }
    }
    
    ll ans=1;
    for(int i=0; i<n; i++) ans=(ans%mod*arr[i]%mod)%mod;
    cout<<ans<<endl;
    
}

int main() {
    int t;
    cin>>t;
    while(t--) accept_ho_ja();
}


// link-https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/XORPROD?tab=statement