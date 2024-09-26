#include <bits/stdc++.h>
using namespace std;

void accept_ho_ja(){
    int n;
    cin>>n;
    
    if(n==2){
        cout<<"NO"<<endl;
        return;
    }
    
    if(!(n&1)){
        cout<<"YES"<<endl;
        for(int i=(n+1)/2+1; i<=n; i++) cout<<i<<" ";
        for(int i=(n+1)/2; i>2; i--) cout<<i<<" ";
        cout<<1<<" "<<2<<endl;
    }else{
        cout<<"YES"<<endl;
        for(int i=(n+1)/2; i<=n; i++) cout<<i<<" ";
        for(int i=(n+1)/2-1; i>0; i--) cout<<i<<" ";
        cout<<endl;
    }
}

int main() {
    int t;
    cin>>t;
    while(t--) accept_ho_ja();
}

// link-https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/EQLIS
