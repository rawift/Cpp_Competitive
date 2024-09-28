#include <bits/stdc++.h>
using namespace std;

using ll=long long int;


bool isPerfectSquare(ll num) {
    if(num<0) return false;
    ll sqrtValue=(sqrt(num));
    return (sqrtValue*sqrtValue==num);
}

void accept_ho_ja(){
    ll n;
    cin>>n;
    
    ll count=0;
    while(!(n&1)){
        n/=2;
        count++;
    }
    
    if(count&1){
        count--;
        n*=2;
    }
    
    count/=2;
    ll temp=pow(2, count);
    
    for(ll i=0; i*i<=n; i++){
        
        ll ans=n-i*i;
	    ll ans1=sqrt(ans);
        
        if(isPerfectSquare(ans)){
            cout<<(i)*temp<<" "<<ans1*temp<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) accept_ho_ja();
}

// link-https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/PYTHAGORAS?tab=statement