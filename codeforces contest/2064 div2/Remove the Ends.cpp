#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
 

 
void accept_ho_ja(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0; i<n; i++) cin>>arr[i];
  vector<ll> dp(n+1,0);
  
  for(int i=n-1; i>=0; i--){
      dp[i]+=dp[i+1];
      if(arr[i]<0) dp[i]+=abs(arr[i]);
  }
  
  ll ans=0, sum=0;
  for(int i=0; i<n; i++){
      if(arr[i]>0){
          sum+=arr[i];
          ans=max(ans,sum);
      }else{
          ans=max(ans,sum+dp[i]);
      }
  }
  
  cout<<ans<<endl;
  
}
 
int main(){
  int t;
  cin>>t;
  while(t--) accept_ho_ja();
}


// https://codeforces.com/contest/2064/problem/C