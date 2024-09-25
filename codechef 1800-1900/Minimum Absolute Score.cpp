#include <bits/stdc++.h>
using namespace std;

void accept_ho_ja(){
    int n;
    string a,b;
    cin>>n>>a>>b;
    int sum=0;
    for(int i=0; i<n; i++){
        if(b[i]>a[i]) sum+=b[i]-a[i];
        else sum+=26+b[i]-a[i];
    }
    cout<<min(sum%26,abs(26-sum%26))<<endl;
}


int main() {
    int t;
    cin>>t;
    while(t--) accept_ho_ja();
}

// link-https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/MINABS