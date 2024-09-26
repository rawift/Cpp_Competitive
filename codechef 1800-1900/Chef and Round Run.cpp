#include <bits/stdc++.h>
using namespace std;

void accept_ho_ja(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    
    vector<int> visited(n,0);
    vector<int> temp(n,0);
    
    for(int i=0; i<n; i++){
        
        if(visited[i]==0){
            int vert=i,start=i;
            while(temp[vert]==0){
                temp[vert]=1;
                vert=(arr[vert]+vert+1)%n;
            }
            while(start!=vert){
                visited[start]=-1;
                temp[start]=-1;
                start=(arr[start]+start+1)%n;
            }
            
        }
        
    }
    
    int ans=0;
    for(int i=0; i<n; i++){
        if(temp[i]==1) ans++;
    }
    cout<<ans<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) accept_ho_ja();
}

// link-https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/CHEFRRUN?tab=statement