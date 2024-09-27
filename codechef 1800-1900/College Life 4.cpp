#include <bits/stdc++.h>
using namespace std;

using ll=long long int;

void accept_ho_ja(){
    ll N,E,H,A,B,C;
    cin>>N>>E>>H>>A>>B>>C;
    
    ll ans=LLONG_MAX;
    
    for(ll z=0; z<=min({E,H,N}); z++){
        ll ux=(E-z)/2, uy=(H-z)/3;
        
        ll price=z*C,n=N-z;
        
        if(A<B){
            if(ux>=n){
                price+=A*n;
            }else{
                price+=A*ux;
                if(uy>=(n-ux)) price+=(n-ux)*B;
                else continue;
            }
            
            ans=min(ans,price);
            
        }else if(A>B){
            if(uy>=n){
                price+=B*n;
            }else{
                price+=B*uy;
                if(ux>=(n-uy)) price+=(n-uy)*A;
                else continue;
            }
            ans=min(ans,price);
        }else{
            if(ux+uy>=n) price+=n*A;
            else continue;
            ans=min(ans,price);
        }
        
    }
    
    if(ans==LLONG_MAX) cout<<-1<<endl;
    else cout<<ans<<endl;
    
}

int main() {
    int t;
    cin>>t;
    while(t--) accept_ho_ja();
}

// link-https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/COLGLF4?tab=statement