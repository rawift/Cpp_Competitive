#include <bits/stdc++.h>
using namespace std;

struct cmp1{
    bool operator()(int& a, int &b){
        return a>b;
    }
};
struct cmp2{
    bool operator()(int& a, int &b){
        return a<b;
    }
};

void accept_ho_ja(){
    int queries;
    cin>>queries;
    priority_queue<int,vector<int>,cmp1> pqn;
    priority_queue<int,vector<int>,cmp2> pqx;
    int totalx=0,pql=0;
    
    
    while(queries--){
        int q;
        cin>>q;
        if(q==1){
            int x;
            cin>>x;
            totalx++;
            int len=totalx/3;
            if(pql<len || pqn.empty()){
                
                if(!pqx.empty() && pqx.top()>x){
                    pqn.push(pqx.top());
                    pql++;
                    pqx.pop();
                    pqx.push(x);
                }else{
                    pqn.push(x);
                    pql++;
                }
                
            }else{
                
                if(pqn.top()<x){
                    pqx.push(pqn.top());
                    pqn.pop();
                    pqn.push(x);
                }else{
                    pqx.push(x);
                }
                
            }
            
        }else{
            if(!pqn.empty() && totalx>=3){
                cout<<pqn.top()<<endl;
            }else{
                cout<<"No reviews yet"<<endl;
            }
            
        }
    }
}

int main() {
    accept_ho_ja();
}

// link-https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/RRATING?tab=statement