#include <bits/stdc++.h>
using namespace std;

void accept_ho_ja(){
  string s;
  int n;
  cin>>n>>s;
  int ans=0;
  char f='1';
  for(int i=0; i<n; i++){
    if(s[i]==f){
      ans++;
      if(f=='1') f='0';
      else f='1';
    }
  }
  cout<<ans<<endl;
}

int main(){
  int t;
  cin>>t;
  while(t--) accept_ho_ja();
}

// https://codeforces.com/contest/2064/problem/A