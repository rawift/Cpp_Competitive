#include <bits/stdc++.h>
using namespace std;

using ll=long long int;

void accept_ho_ja(){
    int n,x;
    cin>>n>>x;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    
    vector<vector<ll>> dp(n,vector<ll>(2,0));
    
    for(int i=1; i<n; i++){
  
        dp[i][1]=max(dp[i][1],((arr[i]+x)^(arr[i-1]+x)) + dp[i-1][1]);
        dp[i][1]=max(dp[i][1],((arr[i]+x)^(arr[i-1])) +dp[i-1][0]);
      
        dp[i][0]=max(dp[i][0],((arr[i])^(arr[i-1]+x)) + dp[i-1][1]);
        dp[i][0]=max(dp[i][0],((arr[i])^(arr[i-1])) +dp[i-1][0]);
     
    }
    
     cout<<max(dp[n-1][1],dp[n-1][0])<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) accept_ho_ja();
}


// link-https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/ADJXOR2