#include <bits/stdc++.h>
using namespace std;

void accept_ho_ja(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0; i<n; i++) cin>>arr[i];
  
  unordered_map<int,int> mp;
  for(auto i:arr) mp[i]++;
  
  int len=0,l=-1,r=-1,s=0;
  
  for(int i=0; i<n; i++){
      if(mp[arr[i]]==1){
          if(len<i-s+1){
              len=max(len,i-s+1);
              l=s;
              r=i;
          }
      }else{
          s=i+1;
      }
  }
  
  if(l==-1 || r==-1) cout<<0<<endl;
  else cout<<l+1<<" "<<r+1<<endl;
  
}

int main(){
  int t;
  cin>>t;
  while(t--) accept_ho_ja();
}

// https://codeforces.com/contest/2064/problem/B