#include <bits/stdc++.h>
using namespace std;

using ll=long long int;

struct cmp{
  bool operator()(int& a, int& b){
      return a>b;
  }  
};

int lcheck(vector<ll>& arr, vector<ll>& lsum, int mid, int i){
    ll sum=lsum[mid-1]-lsum[i];
    if(arr[i]>=sum) return 1;
    else return 0;
}

int rcheck(vector<ll>& arr, vector<ll>& rsum, int mid, int i){
    ll sum=rsum[mid+1]-rsum[i];
    if(arr[i]>=sum) return 1;
    else return 0;
}

void print(vector<int>& a){
    int n=a.size();
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;
}

void accept_ho_ja(){
    int n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    vector<ll> lsum(n,0);
    vector<ll> rsum(n,0);
    for(int i=0; i<n; i++){
        lsum[i]+=arr[i]+(i-1>=0?lsum[i-1]:0);
    }
    for(int i=n-1; i>=0; i--){
        rsum[i]+=arr[i]+(i+1<n?rsum[i+1]:0);
    }
    vector<pair<int,int>> idx(n);
    for(int i=0; i<n; i++){
        int low=i+1,high=n-1,val=0;;
        while(low<=high){
            int mid=(low+high)/2;
            if(lcheck(arr,lsum,mid,i)){
                val=max(val,mid);
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
          idx[i].first=val;
    }

    for(int i=n-1; i>=0; i--){
        int low=0,high=i-1,val=n;;
        while(low<=high){
            int mid=(low+high)/2;
            if(rcheck(arr,rsum,mid,i)){
                val=min(val,mid);
                high=mid-1;
            }else{
                low=mid+1;
            }
            idx[i].second=val;
        }
    }
    vector<int> ans(n,0);
    priority_queue<int,vector<int>,cmp> pqn;
    for(int i=0; i<n; i++){
        ans[i]+=pqn.size();
        while(!pqn.empty() && pqn.top()<=i) pqn.pop();
        pqn.push(idx[i].first);
    }
    priority_queue<int> pqm;
    for(int i=n-1; i>=0; i--){
        ans[i]+=pqm.size();
        while(!pqm.empty() && pqm.top()>=i) pqm.pop();
        pqm.push(idx[i].second);
    }
    print(ans);
}

int main() {
    int t;
    cin>>t;
    while(t--) accept_ho_ja();
}


// link-https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/MINVOTE