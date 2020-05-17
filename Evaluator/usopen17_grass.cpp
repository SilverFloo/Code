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
vector<ii> up[200005];
pair<int,ii> edge[200005];
int type[200005];
int ans[200005];
int t[200005];
void ud(int p){
    if(p==0)return;
    for(int i=p;i<=200005;i+=i&-i){
        t[i]+=1;
    }
}
int qr(int p){
    int ans=0;
    for(int i=p;i>=1;i-=i&-i){
        ans+=t[i];
    }
    return ans;
}
void update(int l,int st,int ed){

    if(ed<st)return;
    //printf("<%d %d %d %d>",st,ed,l,qr(4));
    if(qr(ed)-qr(st-1)==0){
        for(int i=st;i<=ed;i++)ans[i]=l,ud(i);
        return;
    }
    if(st!=ed){
    int m=(st+ed)/2;
    update(l,st,m);
    update(l,m+1,ed);
    }
}
int main(){
    int n,m,k,q;
    cin>>n>>m>>k>>q;
    FOR(i,m){
        scanf("%d %d %d",&edge[i].s.f,&edge[i].s.s,&edge[i].f);
    }
    sort(edge,edge+m);
    FOR1(i,n)scanf("%d",&type[i]);
    FOR1(i,q){
        int a,b;
        scanf("%d %d",&a,&b);
        up[a].pb(i,b);
    }
    FOR(i,m){
        int a=0,b=0;
        int u=edge[i].s.f,v=edge[i].s.s;
        int tu=type[u],tv=type[v];
        int bf=1;
       // printf("\n%d %d>>",u,v);
        while(1){
                //printf("%d %d/",a,b);
                //printf("%d %d %d %d %d/",bf,up[u][a].f,up[v][b].f,a,b);
//printf("%d",bf);

            if(a<up[u].size()&&b<up[v].size()){
                if(tu!=tv)update(edge[i].f,bf,min(up[u][a].f,up[v][b].f)-1);
            bf=min(up[u][a].f,up[v][b].f);
                if(up[u][a].f<up[v][b].f){
                    tu=up[u][a].s;
                    a++;
                }
                else{
                    tv=up[v][b].s;
                    b++;
                }
            }
            else if(a==up[u].size()){
            if(tu!=tv)update(edge[i].f,bf,up[v][b].f-1);
            bf=up[v][b].f;
                tv=up[v][b].s;
                b++;
            }
            else{
            if(tu!=tv)update(edge[i].f,bf,up[u][a].f-1);
            bf=up[u][a].f;
                tu=up[u][a].s;
                a++;
            }if(a==up[u].size()&&b==up[v].size())break;
        }
//printf("%d %d %d %d/",bf,q,tu,tv);
            if(tu!=tv)update(edge[i].f,bf,q);

    }
    FOR1(i,q)printf("%d\n",ans[i]);
}
