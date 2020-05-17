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

int main(){
    int t;
    cin>>t;
    FOR1(k,t){
        ii com[105];
        int dist[105];
        vector<ii> to[105];
        ii con[1005];
        int ans[1005];
        priority_queue<ii> want;
        priority_queue<ii> toadd;
        int n,m;
        cin>>n>>m;
        FOR1(i,n-1){
            int x;
            scanf("%d",&x);
            if(x<=0){
                want.p(x,i);
            }
            else{
                toadd.p(-x,i);
            }
        }
        FOR(i,m){
            scanf("%d %d",&con[i].f,&con[i].s);
            to[con[i].f-1].pb(con[i].s-1,i);
            to[con[i].s-1].pb(con[i].f-1,i);
        }
        FOR(i,n)dist[i]=-1;
        dist[0]=0;
        int cnt=1;
        int distnow=0;
        int wantbf=0;
        while(!toadd.empty()){
            if(!want.empty()&&cnt >= -want.top().f){
                cnt++;
                ii a = want.top();
                want.pop();
                if(wantbf!=a.f)distnow++;
                dist[a.s]=distnow;
                wantbf=a.f;
                for(auto u:to[a.s]){
                    if(dist[u.f]!=-1){
                        ans[u.s]=dist[a.s]-dist[u.f];
                    }
                }
                continue;
            }
            cnt++;
            ii a = toadd.top();
            toadd.pop();
            dist[a.s]=-a.f;
            distnow=-a.f;
            for(auto u:to[a.s]){
                if(dist[u.f]!=-1){
                    ans[u.s]=dist[a.s]-dist[u.f];
                }
            }

        }

        while(!want.empty()){
            if(cnt >= -want.top().f){
                cnt++;
                ii a = want.top();
                want.pop();
                if(wantbf!=a.f)distnow++;
                dist[a.s]=distnow;
                wantbf=a.f;
                for(auto u:to[a.s]){
                    if(dist[u.f]!=-1){
                        ans[u.s]=dist[a.s]-dist[u.f];
                    }
                }
            }
        }
        printf("Case #%d: ",k);
        FOR(i,m)printf("%d ",ans[i]==0?1:ans[i]);
        printf("\n");
    }

}