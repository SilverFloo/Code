#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define ii pair<int,int>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR1(i,n) for(int i=1;i<=n;i++)
#define pb push_back
using namespace std;
int val[300005];
ll sum[300005];
int par[300005];
bool visit[300005];
vector<int> edge[300005];
int lv[300005];
ii e[300005];
void bfs(int u){
    visit[u]=1;
    for(auto v:edge[u]){
        if(!visit[v]){


        par[v]=u;
        lv[v]=lv[u]+1;
        bfs(v);
        sum[u]+=sum[v];
        //printf("%d/%d/",u,lv[v]);
        }
    }
    sum[u]+=(ll)val[u];
    //printf("%d %lld",u,sum[u]);
}
int main(){
ll ans=1e18;
    int n;int ch=0;
    cin>>n;
    FOR1(i,n){
        scanf("%d",&val[i]);
    }
    FOR(i,n-1){
        int a,b;
        scanf("%d %d",&a,&b);
        if(a!=b-1)ch=1;
        edge[a].pb(b);
        edge[b].pb(a);
        e[i].f=a;
        e[i].s=b;
    }

    if(ch==0){ll ans=1e18;
            FOR1(i,n)sum[i]=sum[i-1]+(ll)val[i];
            for(int i=1;i<=n;i++){
                    int l=i,r=n;
                    ll mn=1e18,mx=0;
                    while(l<=r){

                        int m=(l+r)/2;
                    //printf("%d %d >> %lld %lld %lld\n",i,m,sum[i],sum[m]-sum[i],sum[n]-sum[m]);
                        int mx=max(max(sum[i],sum[m]-sum[i]),sum[n]-sum[m]);
                        int mn=min(min(sum[i],sum[m]-sum[i]),sum[n]-sum[m]);
                        if(mx-mn<ans)ans=mx-mn;
                        if(sum[m]-sum[i]<sum[n]-sum[m])l=m+1;
                        else r=m-1;
                    }

            }
        printf("%lld",ans);
        return 0;
    }


    bfs(1);//printf("ee");
    for(int i=0;i<n-1;i++){
            int a,b;
            for(int j=i+1;j<n-1;j++){
                int a=lv[e[i].f]>lv[e[i].s]?e[i].f:e[i].s;
                int b=lv[e[j].f]>lv[e[j].s]?e[j].f:e[j].s;
                //printf("%d %d %lld %lld\n",a,b,sum[a],sum[b]);
            int tmpa=a;
            int tmpb=b;
            while(lv[tmpa]>lv[tmpb]){
                   // printf("%d ",lv[tmpa]);
                tmpa=par[tmpa];
            }
            while(lv[tmpb]>lv[tmpa]){
                //printf("%d ",lv[tmpb]);
                tmpb=par[tmpb];
            }

            ll x,y,z;

            if(tmpa==tmpb){
                if(lv[a]>lv[b]){
                    x=sum[a];
                    y=sum[b]-sum[a];
                    z=sum[1]-x-y;
                }
                if(lv[b]>lv[a]){
                    x=sum[b];
                    y=sum[a]-sum[b];
                    z=sum[1]-x-y;
                }

            }
            else{
                x=sum[a];
                y=sum[b];
                z=sum[1]-x-y;
            }
            ll mn=min(min(x,y),z);
            ll mx=max(max(x,y),z);
            ans=min(mx-mn,ans);
            //printf("%lld %lld\n",mn,mx);
        }
    }
    printf("%lld",ans);
}
/*
6
1 2 3 4 5 6
1 2
2 3
3 4
4 5
5 6
*/
