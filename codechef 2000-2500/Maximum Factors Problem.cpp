#include <bits/stdc++.h>
using namespace std;

using ll=long long int;

vector<ll> sieve(int n){
    
    vector<ll> isPrime(n,1);
    for(int i=2; i*i<n; i++){
        if(isPrime[i]==1){
            for(int j=i*i; j<n; j+=i) isPrime[j]=0;
        }
    }
    return isPrime;
}

ll expo(ll n, ll p){
    ll count=0;
    while(n%p==0){
        n/=p;
        count++;
    }
    return count;
}

void accept_ho_ja(vector<ll>& isPrime){
    ll n;
    cin>>n;
    ll size=isPrime.size();
    
    ll curr_expo=0, curr_p=LLONG_MAX;
    
    
    for(int i=2; i<size; i++){
        if(isPrime[i]){
            ll count=expo(n,i);
            if(count){
                if(curr_expo<count){
                    curr_p=i;
                    curr_expo=count;
                }
            }
        }
    }
    
    if(curr_p==LLONG_MAX) cout<<n<<endl;
    else cout<<curr_p<<endl;
}

int main() {
    
    vector<ll> isPrime=sieve(sqrt(1e9));

    
    int t;
    cin>>t;
    while(t--) accept_ho_ja(isPrime);
}


// link-https://www.codechef.com/practice/course/5-star-and-above-problems/DIFF2500/problems/MXFACS?tab=statement