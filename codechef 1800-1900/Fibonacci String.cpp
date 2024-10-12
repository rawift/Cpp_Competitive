#include <bits/stdc++.h>
using namespace std;

void accept_ho_ja(){
    string s;
    cin>>s;
    int n=s.size();
    vector<int> mp(26,0);
    for(int i=0; i<n; i++) mp[s[i]-'a']++;
    sort(mp.begin(),mp.end());
    
    int idx=-1;
    for(int i=0; i<26; i++){
        if(mp[i]!=0){
            idx=i;
            break;
        }
    }
    
    if(idx+2>=26){
        cout<<"Dynamic"<<endl;
        return;
    }
    
 
    int prev1=mp[idx],prev2=mp[idx+1];
    for(int i=idx+2; i<26; i++){
        if(mp[i]!=mp[i-1]+mp[i-2]){
            if(i==idx+3 && mp[i]==mp[i-1]+mp[i-3]) continue;
            cout<<"Not"<<endl;
            return;
        }
    }
    
    cout<<"Dynamic"<<endl;
    return;
}

int main() {
    int t;
    cin>>t;
    while(t--) accept_ho_ja();
}


https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/CLFIBD