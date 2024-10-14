#include <bits/stdc++.h>
using namespace std;

using ll=long long int;


void accept_ho_ja(){
    ll a,b;
    cin>>a>>b;
    
    while(__gcd(b,a)!=1) b/=__gcd(b,a);

    if(b==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
}


int main() {
    int t;
    cin>>t;
    while(t--) accept_ho_ja();

}

// link-https://www.codechef.com/practice/course/5-star-and-above-problems/DIFF2500/problems/PRIMEFACDIV?tab=statement