#include <bits/stdc++.h>
using namespace std;

void accept_ho_ja(){
    int n,k;
    string s;
    cin>>n>>k>>s;
    
    k--;
    
    vector<int> tim(n,n);
    
    string temp=s;
    
    for(int i=0; i<n; i++){
        if(temp[i]=='1'){
            s[i]='0';
            if(i-1>=0 && temp[i-1]=='0') s[i-1]='1';
            if(i+1<n && temp[i+1]=='0') s[i+1]='1';
        }
    }
    
    if(temp.find('1')==string::npos){
        cout<<temp<<endl;
        return;
    }
    if(temp.find('0')==string::npos){
        cout<<s<<endl;
        return;
    }
    

    
    int count=-1;
    for(int i=0; i<n; i++){
        if(s[i]=='1') count=0;
        if(s[i]=='0' && count!=-1){
            count++;
            tim[i]=min(tim[i],count);
        }
    }
    count=-1;
    for(int i=n-1; i>=0; i--){
        if(s[i]=='1') count=0;
        if(s[i]=='0' && count!=-1){
            count++;
            tim[i]=min(tim[i],count);
        }
    }
    
    
    for(int i=0; i<n; i++){
        if(s[i]=='0'){
            if(tim[i]<=k){
                if((k-tim[i])%2==0) s[i]='1';
            }
        }else{
            if(k&1) s[i]='0';
        }
    }
    
    cout<<s<<endl;
    
}

int main() {
    int t;
    cin>>t;
    while(t--) accept_ho_ja();
}

//link -https://www.codechef.com/practice/course/5-star-and-above-problems/DIFF2500/problems/ALTSUFF?tab=statement