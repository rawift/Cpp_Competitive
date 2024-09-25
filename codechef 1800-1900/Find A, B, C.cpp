#include <bits/stdc++.h>
using namespace std;


int findMSBPosition(int num) {
    for(int i=31; i>=0; i--){
        if(num&(1<<i)) return i;
    }
    return -1;
}



void accept_ho_ja(){
    int n;
    cin>>n;
    vector<int> arr(n+1);
    for(int i=0; i<n+1; i++) cin>>arr[i];
    int msb=findMSBPosition(n);
    
    vector<int> ans(3,0);

    for(int i=msb; i>=0; i--){
        int mask=(1<<i);
        int set_bits=3+(arr[0]-arr[mask])/mask;
        set_bits/=2;
        
    
        if (set_bits==1) {
            sort(ans.begin(),ans.end());
            ans[0]|=mask;
        }else if(set_bits==2) {
            sort(ans.begin(),ans.end());
            ans[0]|=mask;
            ans[1]|=mask;
        }else if(set_bits==3) {
            ans[0]|=mask;
            ans[1]|=mask;
            ans[2]|=mask;
        }
    }
    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) accept_ho_ja();
}
