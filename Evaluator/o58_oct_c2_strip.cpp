#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define db(a) printf("<%d> ",a)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
#define ll long long
#define rf() freopen("input.txt","r",stdin)
using namespace std;
const int INF=1e9;
pair<ii,ii> p[50000];
ii q[50000];
int t[100005];
void update(int p,int x){
    for(int i=p;i<100005;i+=i&-i){
        t[i]+=x;
    }
}
int query(int p){
    int ans=0;
    for(int i=p;i>0;i-=i&-i){
        ans+=t[i];
    }
    return ans;
}
vector<int> st[100005],ed[100005],qu[100005];
int ans[50000];
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    FOR(i,n){
        scanf("%d %d %d %d",&p[i].f.f,&p[i].s.f,&p[i].f.s,&p[i].s.s);
        p[i].f.f++;
        p[i].f.s++;
        p[i].s.f++;
        p[i].s.s++;
        st[p[i].f.f].pb(i);
        ed[p[i].f.s].pb(i);
    }
    FOR(i,m){scanf("%d %d",&q[i].f,&q[i].s);
    q[i].f++;
    q[i].s++;
        qu[q[i].f].pb(i);
    }
    for(int j=0;j<100005;j++){
        for(auto i:st[j]){
            update(p[i].s.f,1);
            update(p[i].s.s+1,-1);
        }
        for(auto i:qu[j]){
            ans[i] = query(q[i].s);
        }
        for(auto i:ed[j]){
            update(p[i].s.f,-1);
            update(p[i].s.s+1,1);
        }

    }
    FOR(i,m)printf("%d\n",ans[i]);
}
