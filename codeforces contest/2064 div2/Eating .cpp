#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define int long long
 
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
    // prev ^ x >= curr
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
 
bool check(vector<vector<Interval>>& possible, int mid, int x){
    return isPresentInIntervals(possible[mid], x);
}
 
 
void accept_ho_ja(){
    int n,q;
    cin>>n>>q;
    vector<int> arr(n,0);
    vector<vector<Interval>> possible(n);
    vector<Interval> full = {{0, (1ll << 30) - 1}};
    for(int i=0; i<n; i++) cin>>arr[i];
    
    
    int prev=0;
    for(int i=n-1; i>=0; i--){
        vector<Interval> vi = valid_Intervals(prev, arr[i]);
        vector<Interval> mi = merge_Intervals(vi);
        vector<Interval> ii = intervalIntersection(mi, full);
        full = ii;
        possible[i]=ii;
        prev^=arr[i];
    }
 
    
    while(q--){
        int x;
        cin>>x;
        int low=0,high=n-1,ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(possible,mid,x)){
                high=mid-1;
                ans=max(ans,n-mid);
            }else{
                low=mid+1;
            }
        }
        cout<<ans<<" ";
    }
    cout<<endl;
    
}
 
signed main() {
    int t;
    cin>>t;
    while(t--) accept_ho_ja();
}


// https://codeforces.com/contest/2064/problem/D