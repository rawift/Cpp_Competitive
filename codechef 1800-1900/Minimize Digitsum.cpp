#include <bits/stdc++.h>
using namespace std;

using ll=long long int;

ll sumofdigit(ll n){
    if(n==0) return 0;
    return n%10+sumofdigit(n/10);
}

void solve(ll cstep, ll cn, ll d, ll& astep, ll& an){
    
    if(cstep>15) return;
    
    if(an>cn){
        an=cn;
        astep=cstep;
    }
    if(an==cn) astep=min(astep,cstep);
    
    solve(cstep+1,cn+d,d,astep,an);
    solve(cstep+1,sumofdigit(cn),d,astep,an);
    
}

void accept_ho_ja(){
    ll n,d;
    cin>>n>>d;
    ll astep=16, an=n;
    solve(0,n,d,astep,an);
    cout<<an<<" "<<astep<<"\n";
    
}

int main() {
    int t;
    cin>>t;
    while(t--) accept_ho_ja();
}

// link-https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/MINDSUM?tab=statement