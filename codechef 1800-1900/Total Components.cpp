#include <bits/stdc++.h>
using namespace std;

using ll=long long int;

vector<ll> sieve(){
    ll n=10000000+1;
    vector<ll> prime(n,1);
    for(ll i=2; i*i<=n; i++){
        if(prime[i]){
            for(ll j=i*i; j<=n; j+=i) prime[j]=0;
        }
    }
    return prime;
}

void accept_ho_ja(vector<ll>& prime, vector<ll>& countprime){
    ll n;
    cin>>n;
    ll ans=countprime[n]-countprime[n/2];
    if(n/2>=2) ans++;
    cout<<ans<<endl;
}

int main() {
    ll n=10000000+1;
    vector<ll> prime=sieve();
    vector<ll> countprime(n,0);
    countprime[2]=1;
    for(int i=3; i<=n; i++){
        countprime[i]=countprime[i-1];
        if(prime[i]) countprime[i]++;
    }
    
    int t;
    cin>>t;
    while(t--) accept_ho_ja(prime,countprime);
}

// link-https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/NUMCOMP1?tab=statement