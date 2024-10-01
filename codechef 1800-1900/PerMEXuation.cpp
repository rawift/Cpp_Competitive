#include <bits/stdc++.h>
using namespace std;

void accept_ho_ja(){
    int n;
    string s;
    cin>>n>>s;
    
    if(s[0]=='0' || s[1]=='0' || s[n]=='0'){
        cout<<"NO"<<endl;
        return;
    }
    
    vector<int> ans;
    ans.push_back(0);
    
    for(int i=2; i<n; i++){
        if(s[i]=='0') ans.push_back(i);
    }
    ans.push_back(1);
    for(int i=2; i<n; i++){
        if(s[i]=='1') ans.push_back(i);
    }
    cout<<"YES"<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
        
    }
    cout<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) accept_ho_ja();
}


// link-https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/PERMEX?tab=statement