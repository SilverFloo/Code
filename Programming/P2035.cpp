#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
#define ll long long
using namespace std;
const int INF=1e9;
int p[105];
int c[2005];
int pos[2005];
int main(){
    int n,m;
    cin>>n>>m;
    FOR(i,n)scanf("%d",&p[i]);
    FOR1(i,m)scanf("%d",&c[i]);
    ll ans=0;
    priority_queue<int,vector<int>,greater<int>> blank;
    queue<int> q;
    FOR(i,n)blank.p(i);
    FOR(i,2*m){
        int x;
        scanf("%d",&x);
        if(x<0){
            if(!q.empty()){
                pos[q.front()]=pos[-x];
                ans+=(ll)c[q.front()]*p[pos[q.front()]];
                q.pop();
            }
            else blank.p(pos[-x]);
        }
        else{
            if(blank.empty()){q.p(x);}
            else{
                pos[x]=blank.top();
                blank.pop();
                ans+=(ll)c[x]*p[pos[x]];
            }
        }

    }
    printf("%lld",ans);
}
