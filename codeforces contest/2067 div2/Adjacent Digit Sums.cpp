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
 
void accept_ho_ja(){
    int x,y;
    cin>>x>>y;
    
    if(y>x+1){
        cout<<"NO"<<endl;
        return;
    }
    if(y==x+1){
        cout<<"YES"<<endl;
        return;
    }
    while(true){
        x-=9;
        if(y==x+1){
            cout<<"YES"<<endl;
            return;
        }
        if(x<=0) break;
    }
    
    cout<<"NO"<<endl;
    return;
}

signed main(){
    int t;
    cin>>t;
    while(t--) accept_ho_ja();
}


// https://codeforces.com/contest/2067/problem/A