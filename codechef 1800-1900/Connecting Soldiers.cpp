#include <bits/stdc++.h>
using namespace std;

void accept_ho_ja(vector<pair<int,int>>& arr){
    int n,m;
    cin>>n>>m;
    if(arr[n].first>m) cout<<-1;
    else if(arr[n].second<=m) cout<<m-arr[n].second;
    else cout<<0;
    cout<<endl;
}

vector<pair<int,int>> pre_compute(){
    int n=30,m=1000;
    vector<pair<int,int>> arr(n+1,make_pair(INT_MAX,INT_MIN));
    arr[0]=make_pair(0,0);
    arr[1]=make_pair(2,2);
    
    for(int i=2; i<=n; i++){
        for(int j=1; j<=i; j++){
            int ld=j-1,rd=i-j;
            arr[i].first=min(arr[i].first,i+1+arr[ld].first+arr[rd].first);
            arr[i].second=max(arr[i].second,i+1+arr[ld].second+arr[rd].second);
        }
    }
    return arr;
}

int main() {
    int t;
    cin>>t;
    vector<pair<int,int>> arr=pre_compute();
    while(t--) accept_ho_ja(arr);
}


// link-https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/NOKIA
