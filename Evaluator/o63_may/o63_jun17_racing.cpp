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
#define rf() freopen("_working/input.in","r",stdin)
#define pf() freopen("_working/output.out","w+",stdout)
using namespace std;
const int INF=1e9;
int car[100005];
pair<ii,ii> t[200005];
vector<ii> st[100005][10];
vector<ii> ed[100005][10];
int ans[100005];
int main(){
    rf();
    int n,m;
    cin>>n>>m;
    FOR(i,n){
        scanf("%d",&car[i]);
        ans[i]=car[i]*100000000;
    }
    for(int i=0;i<m;i++){
        int k;
        scanf("%d %d %d %d %d",&k,&t[i].f.f,&t[i].f.s,&t[i].s.f,&t[i].s.s);
        if(k!=1)return 0;
        int x = t[i].s.s/t[i].f.f;
        if(x>5)x=5;
        st[t[i].f.s][x].pb(t[i].s.s,t[i].f.f);
           ed[t[i].s.f][x].pb(t[i].s.s,t[i].f.f);
    
    }
    for(int cnt=0;cnt<=5;cnt++){
        set<ii> s;
        for(int i=0;i<n;i++){
            for(auto j:st[i][cnt]){
                s.insert(j);
            }

            if(s.empty())continue;

            ii x = *s.begin();
            if(car[i]<=cnt){
                ans[i]=min(ans[i],x.f);
            }
            for(auto j:ed[i][cnt]){
                s.erase(j);
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d\n",ans[i]);
    }
}