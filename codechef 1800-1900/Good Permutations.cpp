#include <bits/stdc++.h>
using namespace std;

void print(vector<int>& arr){
    int n=arr.size();
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int check(vector<int>& arr, vector<int>& temp, int k, int n){
    for(int i=0; i<n; i++){
        if(arr[i]){
            if(arr[i]!=temp[i]) return 0;
        }
    }
    int cnt=0;
    for(int i=1; i<n; i++){
        if(temp[i]>temp[i-1]) cnt++;
    }
    if(cnt!=k) return 0;
    return 1;
}

void help(vector<int>& arr, vector<int>& temp, int mask, int n, int k, int& ans){
    
    if(mask==pow(2,n+1)-1){
        if(!check(arr,temp,k,n)) return;
        ans++;
        return;
    }
    for(int i=1; i<=n; i++){
        if(!(mask&(1<<i))){
            temp.push_back(i);
            help(arr,temp,mask^(1<<i),n,k,ans);
            temp.pop_back();
        }
    }
}

void accept_ho_ja(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    int mask=1;
    
    vector<int> temp; 
    int ans=0;

    help(arr,temp,mask,n,k,ans);
    cout<<ans<<endl;
    
    
}

int main() {
    int t;
    cin>>t;
    while(t--) accept_ho_ja();
}

// link-https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/GOODPERM