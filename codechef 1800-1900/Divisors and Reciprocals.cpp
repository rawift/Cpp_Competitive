#include <bits/stdc++.h>
using namespace std;

using ll=long long int;

void accept_ho_ja(){
    ll X,A,B;
    cin>>X>>A>>B;
    ll n=(X*B)/A;
    if(A>B || n==1) cout<<n<<"\n";
    else cout<<-1<<"\n";
}

int main() {
    int t;
    cin>>t;
    while(t--) accept_ho_ja();
}

// link-https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/DIVREC