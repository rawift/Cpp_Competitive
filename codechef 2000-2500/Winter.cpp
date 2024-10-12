#include <bits/stdc++.h>
using namespace std;

using ll=long long int;

void bfs(queue<ll>& q, ll t, vector<ll>& vis, vector<vector<ll>>& graph){
    
    while(!q.empty() && t--){
        ll qsz=q.size();
        while(qsz--){
            ll node=q.front();
            q.pop();
            for(auto part:graph[node]){
                if(!vis[part]){
                    q.push(part);
                    vis[part]=1;
                }
            }
        }
    }
}

void accept_ho_ja(){
    ll n,m,Q;
    cin>>n>>m>>Q;
    vector<vector<ll>> graph(n);
    for(ll i=0; i<m; i++){
        ll u,v;
        cin>>u>>v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    vector<ll> vis(n,0);
    queue<ll> q;
    
    while(Q--){
        ll type;
        cin>>type;
        if(type==1){
            ll node;
            cin>>node;
            node--;
            if(!vis[node]){
                q.push(node);
                vis[node]=1;
            }
        }else if(type==2){
            ll t;
            cin>>t;
            bfs(q,t,vis,graph);
        }else{
            ll node;
            cin>>node;
            node--;
            if(vis[node]) cout<<"YES"<<"\n";
            else cout<<"NO"<<"\n";
        }
    }
    
}

int main() {
    accept_ho_ja();
}


// https://www.codechef.com/practice/course/5-star-and-above-problems/DIFF2500/problems/ELWINTER?tab=statement