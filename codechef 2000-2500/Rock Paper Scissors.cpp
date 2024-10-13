#include <bits/stdc++.h>
using namespace std;

void accept_ho_ja(){
    int n;
    string str;
    cin>>n>>str;
    
    int r=-1,p=-1,s=-1;
    
    vector<int> lose(n,-1);
    
    for(int i=n-1; i>=0; i--){
        if(str[i]=='R'){
            if(p!=-1) lose[i]=p;
            r=i;
        }else if(str[i]=='P'){
            if(s!=-1) lose[i]=s;
            p=i;
        }else{
            if(r!=-1) lose[i]=r;
            s=i;
        }
    }
    
    vector<char> ans(n);
    for(int i=n-1; i>=0; i--){
        if(lose[i]==-1) ans[i]=str[i];
        else ans[i]=ans[lose[i]];
    }
    
    for(int i=0; i<n; i++) cout<<ans[i];
    cout<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) accept_ho_ja();
}

// link-https://www.codechef.com/practice/course/5-star-and-above-problems/DIFF2500/problems/ROPASCI?tab=statement