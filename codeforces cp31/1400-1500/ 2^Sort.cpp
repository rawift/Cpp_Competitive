#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define int long long

const int inf = 9e18;
const int mod = 1e9 + 7;
const int NUM = 1000030;
const int N = 10000000;

vector<int> lp, sieve;
vector<int> pr;
vector<int> power;
vector<int> fact;

void initpow(int x){
    power.resize(NUM);
    power[0] = 1;
    for (int i = 1; i<NUM; i++) power[i]=(power[i-1]*(x%mod))%mod;
}
void initFactorial(){
    fact.resize(NUM);
    fact[0]=1;
    for (int i = 1; i < NUM; i++) fact[i] = (fact[i - 1] * i) % mod;
}
void calc_sieve(){
    sieve.resize(NUM + 1, 0);
    for (int x = 2; x <= NUM; x++){
        if (sieve[x]) continue;
        for (int u = x; u <= NUM; u += x) sieve[u] = x;
    }
    //sieve[x] == x, then x is a prime number.
    //sieve[x] is smalled primefactor of x
}
void primefactor(){
    lp.resize(N + 1, 0);
    for (int i = 2; i <= N; ++i){
        if (lp[i] == 0){
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j) lp[i * pr[j]] = pr[j];
    }
    //lp[i] == i, then i is a prime number.
    //lp[i] gives the smallest prime factor for every number.
    //pr (Prime List) -> {2,3,5,7}
}

int binpow(int a, int b){
    int res = 1;
    while (b > 0){
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
    // Computes a^b
}
int binpow(int a, int b, int mod){
    int res = 1;
    while (b > 0){
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res % mod;
    // Computes (a^b) % mod
}
int gcd(int a, int b){
    if (b == 0) return a;
    else return gcd(b, a % b);
}
int lcm(int a, int b){
    return ((a / gcd(a, b)) * b);
}
int inversemod(int a, int mod){
    return binpow(a, mod - 2, mod);
    // Computes (1/a)%mod
}
int divmod(int a, int b, int c){
    return ((a % c) * inversemod(b, c)) % c;
    //  Computes (a / b) % c
}
int combination(int n, int k){
    if (k > n) return 0;
    int p1 = (fact[n] * inversemod(fact[k], mod)) % mod;
    int p2 = (1 * inversemod(fact[n - k], mod)) % mod;
    return (p1 * p2) % mod;
    // Computes nCk % mod or C(n,k)%mod
}

 
typedef pair<ll, ll> Interval;
vector<Interval> intervalIntersection(vector<Interval> &set1, vector<Interval> &set2){
    vector<Interval> result;
    int i=0,j=0;
    sort(set1.begin(),set1.end());
    sort(set2.begin(),set2.end());
    while(i<set1.size() && j<set2.size()){
        int start=max(set1[i].first, set2[j].first);
        int end=min(set1[i].second, set2[j].second);
        if(start<=end) result.push_back({start, end});
        if(set1[i].second<set2[j].second) i++;
        else j++;
    }
    return result;
}
 
vector<Interval> merge_Intervals(vector<Interval> &intervals){
    
    if (intervals.empty()) return {};
    sort(intervals.begin(), intervals.end());
    vector<Interval> result;
    result.push_back(intervals[0]);
 
    for (size_t i = 1; i < intervals.size(); i++){
        auto &last = result.back();
        if (intervals[i].first <= last.second + 1) last.second = max(last.second, intervals[i].second); 
        else result.push_back(intervals[i]); 
    }
    return result;
}
 
vector<Interval> valid_Intervals(ll prev, ll curr){
    // range of x for which prev ^ x >= curr
    vector<Interval> result;
    ll value = 0;
    for(int i=30-1; i>=0; i--){
        ll currb = 0;
        ll prevb = 0;
        
        if(curr & (1ll << i)) currb=1;
        if(prev & (1ll << i)) prevb = 1;
        
        if(currb){
            value = value | ((1 - prevb)*(1ll << i));
        }else{
            ll lb = value | ((1 - prevb)*(1ll << i));
            ll rb = lb;
            for(int j=i-1; j>=0; j--){
                rb |= (1ll << j);
            }
            result.push_back({lb, rb});
            value = value | ((prevb) * (1ll << i));
        }
    }
    result.push_back({value, value});
    return result;
}
 
bool isPresentInIntervals(const vector<Interval> &intervals, int x){
    // interval must be sorted [[1,4],[5,6],[9,14]]
    int left=0, right=intervals.size()-1;
    while (left<=right){
        int mid=left+(right-left)/2;
        if(intervals[mid].first <= x && x <= intervals[mid].second) return true;
        else if (intervals[mid].second < x) left = mid + 1; 
        else right=mid-1;
    }
    return false; 
}

bool isPresentInV(vector<int>& arr, int target) {
    int left=0, right=arr.size()-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid] == target) return true;  
        else if(arr[mid]<target) left=mid+1;
        else right=mid-1; 
    }
    return false;  
}

int countDigits(int num) {
    if (num == 0) return 1;  // Special case: 0 has 1 digit
    return floor(log10(abs(num))) + 1;
}
int countTrailingZeros(int n) {
    int cnt = 0;
    while (n > 0 && n % 10 == 0) {  // loop as long as last digit is 0
        cnt++;
        n /= 10;
    }
    return cnt;
}


void printV(vector<int>& arr){
    for(auto i:arr) cout<<i<<" ";
    cout<<endl;
}

void sortV(vector<int>& arr){
    sort(arr.begin(),arr.end());
}


void buildTree(vector<int>& arr, vector<ll>& tree, int s, int e, int idx){
    
    if(s==e){
        tree[idx]=arr[s];
        return;
    }
    
    int mid=(s+e)/2;
    
    buildTree(arr,tree,s,mid,2*idx);
    buildTree(arr,tree,mid+1,e,2*idx+1);
    
    tree[idx]=tree[2*idx]&tree[2*idx+1];
}


int query(vector<ll>& tree ,int s, int e, int idx, int l, int r){
    
    
    if(e<l||s>r) return -1;

    if(s>=l && e<=r) return tree[idx];
    
    int mid=(s+e)/2;
    
    int ans1=query(tree,s,mid,2*idx,l,r);
    int ans2=query(tree,mid+1,e,2*idx+1,l,r);
    
    return ans1&ans2;
}

void updateTree(vector<int>& arr, vector<ll>& tree, int s, int e, int idx, int i, int val){
    
    if(s==e){
        arr[i]=val;
        tree[idx]=val;
        return;
    }
    
    int mid=(s+e)/2;
    
    if(i>mid) updateTree(arr,tree,mid+1,e,2*idx+1,i,val);
    else updateTree(arr,tree,s,mid,2*idx,i,val);
    
    tree[idx]=tree[2*idx]&tree[2*idx+1];
} 

void dfs(vector<vector<int>>& graph, map<pair<int,int>,int>& pos, vector<int>& vis, int& ans, int root, int prevpos, int prevans){
    vis[root]=1;
    ans=max(ans,prevans);
    for(auto i:graph[root]){
        if(!vis[i]){
            int ps=pos[{root,i}];
            dfs(graph,pos,vis,ans,i,ps,prevans+(ps<prevpos));
        }
    }
}

pair<int,int> count5n0(int num){
    int temp=num;
    int c5=0, c2=0;
    while(temp && temp%5==0){
        c5++;
        temp/=5;
    }
    while(temp && temp%2==0){
        c2++;
        temp/=2;
    }
    return {c2,c5};
}



void accept_ho_ja(){
    // vector<ll> tree(4 * n);
    // buildTree(arr,tree,0,n-1,1);
    // query(tree,0,n-1,1,l,r);
    // updateTree(arr,tree,0,n-1,1,l,r);
    ll n,k;
    cin>>n>>k;
    
    vector<ll> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    
    ll l=0,ans=0;
    for(int i=1; i<n; i++){
        if(i-l+1<=k+1){
            if(arr[i-1]*power[1]<arr[i]*power[2]){
                if(i-l+1==k+1){
                    ans++;
                    l++;
                }
            }else{
                l=i;
            }
        }else{
            
        }
    }
    cout<<ans<<endl;

}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  initpow(2);
  while(t--) accept_ho_ja();
}

// link-https://codeforces.com/problemset/problem/1692/G