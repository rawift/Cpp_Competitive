#include <bits/stdc++.h>
using namespace std;

void printmp(unordered_map<int,int>& mp){
    for(auto i:mp){
        cout<<i.first<<" "<<i.second;
        cout<<endl;
    }
    cout<<endl;
}

bool check(unordered_map<int,int>& w1, unordered_map<int,int>& w2){
    for(auto i:w1){
        if(w2[i.first]!=i.second) return 0;
    }
    return 1;
}


void accept_ho_ja(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> A(n,vector<int>(m,0));
    vector<vector<int>> B(n,vector<int>(m,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin>>A[i][j];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin>>B[i][j];
    }
    
    unordered_map<int,int> w1;
    unordered_map<int,int> b1;
    unordered_map<int,int> w2;
    unordered_map<int,int> b2;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i&1){
                if(j&1) w1[A[i][j]]++;
                else b1[A[i][j]]++;
            }else{
                if(j&1) b1[A[i][j]]++;
                else w1[A[i][j]]++;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i&1){
                if(j&1) w2[B[i][j]]++;
                else b2[B[i][j]]++;
            }else{
                if(j&1) b2[B[i][j]]++;
                else w2[B[i][j]]++;
            }
        }
    }
    
   
    
    if(n==1 || m==1){
        cout<<"NO"<<endl;
        return;
    }
    
    if(check(w1,w2) && check(b1,b2)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    
}

int main() {
    int t;
    cin>>t;
    while(t--) accept_ho_ja();
}

// link-https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/AFLIP?tab=statement 