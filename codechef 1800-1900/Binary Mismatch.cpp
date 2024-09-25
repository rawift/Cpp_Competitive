#include <bits/stdc++.h>
using namespace std;

void accept_ho_ja() {
    int n;
    string s;
    cin>>n>>s;
    if (n&1) {
        cout << "NO" << endl;
        return;
    }

    int c0=0,c1=0;
    for (int i=0; i<n; i++) {
        if (s[i]=='0') c0++;
        else c1++;
    }

    if (c0==c1) {
        cout<<"YES"<<endl;
        cout<<0+1<<" "<<n-1+1<<endl;
        return;
    }

    if (c0 > c1) {
        int diff=c0-c1;
        int sum=0,a=-1,b=-1;
        unordered_map <int,int> mp;
        for(int i=0; i<n; i++){
            if(s[i] == '0')sum-=2;
            else sum+=2;

            mp[sum]=i;
            if (sum==-1*diff){
                a=0;
                b=i;
                break;
            }
            if(mp.find(sum-(-1*diff))!=mp.end()){
                a=mp[sum-(-1*diff)];
                b=i;
            }

        }

        if(a!=-1 && b!=-1){
            cout<<"YES"<<endl;
            cout<<a+1<<" "<<b+1<<endl;
        } else {
            cout<<"NO"<<endl;
        }
        
    }else{
        int diff=c1-c0;
        int sum=0,a=-1,b=-1;
        unordered_map <int,int> mp;
        for(int i=0; i<n; i++){
            if(s[i] == '1')sum-=2;
            else sum+=2;

            mp[sum]=i;
            if (sum==-1*diff){
                a=0;
                b=i;
                break;
            }
            if(mp.find(sum-(-1*diff))!=mp.end()){
                a=mp[sum-(-1*diff)];
                b=i;
            }

        }

        if(a!=-1 && b!=-1){
            cout<<"YES"<<endl;
            cout<<a+1<<" "<<b+1<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) accept_ho_ja();
}

// link-https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/BINMIS?tab=statement