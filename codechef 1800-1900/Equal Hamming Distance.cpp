#include <bits/stdc++.h>
using namespace std;

using ll=long long int;
ll mod=1000000000+7;

ll power(ll x, ll y, ll p){
    if(y==0) return 1;
    
    ll z=power(x,y/2,p);
    z=(z*z)%mod;
    
    if(y&1) return (z*x)%p;
    else return z;
}


ll inv(ll a, ll p){
    return power(a,p-2,p);
}

ll nCk(vector<ll>& fac, ll n, ll k, ll p){
    return ((fac[n]*inv(fac[k],p)%p)*inv(fac[n-k],p))%p;
}

void pre_compute(vector<ll>& fac, int size){
    for(ll i=2; i<size; i++) fac[i]=(i*fac[i-1])%mod;
}

void accept_ho_ja(vector<ll>& fac){
   int n;
   string a,b;
   cin>>n>>a>>b;
   
   ll sam=0,diff=0;
   for(int i=0; i<n; i++){
       if(a[i]==b[i]) sam++;
       else diff++;
   }
   
   if(diff&1){
       cout<<0<<endl;
       return; 
   }
   
   ll s=power(2,sam,mod)%mod;
   ll d=nCk(fac,diff,diff/2,mod);
  
  
   ll ans=(d%mod*s%mod)%mod;
   
   cout<<ans<<endl;
}

int main() {
    int t;
    cin>>t;
    
    int size=2*100000+1;
    vector<ll> fac(size,1);

    pre_compute(fac,size);
    
    while(t--) accept_ho_ja(fac);
}


// link-https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/EQUALHAMMING?tab=statement