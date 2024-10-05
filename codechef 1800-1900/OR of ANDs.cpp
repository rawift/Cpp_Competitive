#include <bits/stdc++.h>
using namespace std;

void buildTree(vector<int>& tree, vector<int>& arr, int s, int e, int node){
    if(s==e){
        tree[node]=arr[s];
    }else{
        int mid=(s+e)/2;
        buildTree(tree,arr,s,mid,2*node);
        buildTree(tree,arr,mid+1,e,2*node+1);
        tree[node]=tree[2*node] | tree[2*node+1];
    }
}

int queryTree(vector<int>& tree, vector<int>& arr, int s, int e, int node, int l, int r){
    if(r<s || l>e) return 0;
    
    if(l<=s && r>=e) return tree[node];
    
    int mid=(s+e)/2;
    int left=queryTree(tree,arr,s,mid,2*node,l,r);
    int right=queryTree(tree,arr,mid+1,e,2*node+1,l,r);
    return left | right;
}

void updateTree(vector<int>& tree, vector<int>& arr, int s, int e, int node, int idx, int val){
    if(s==e){
        tree[node]=val;
        arr[idx]=val;
        return;
    }
    int mid=(s+e)/2;
    if(mid<idx){
        updateTree(tree,arr,mid+1,e,2*node+1,idx,val);
    }else{
        updateTree(tree,arr,s,mid,2*node,idx,val);
    }
    tree[node]=tree[2*node] | tree[2*node+1];
}

void accept_ho_ja(){
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    
    vector<int> tree(4*n+1);
    buildTree(tree,arr,0,n-1,1);
    
    cout<<queryTree(tree,arr,0,n-1,1,0,n-1)<<endl;
    while(q--){
        int idx,val;
        cin>>idx>>val;
        idx--;
        updateTree(tree,arr,0,n-1,1,idx,val);
        cout<<queryTree(tree,arr,0,n-1,1,0,n-1)<<endl;
    }
    
}

int main() {
    int t;
    cin>>t;
    while(t--) accept_ho_ja();
}
