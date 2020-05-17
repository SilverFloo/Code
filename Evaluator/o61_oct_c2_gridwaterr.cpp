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
typedef struct edge{
    int u,v,w;
    edge(int u,int v,int w):u(u),v(v),w(w){}
    bool operator < (const edge &ot)const{
        return w<ot.w;
    }
}edge;
int par[405*405];
root(int i){
    while(i!=par[par[i]]){
        par[i]=par[par[i]];
        i=par[par[i]];
    }
    return i;
}
vector<edge> e,a,b;

int main(){
    int n,m;
    cin>>n>>m;
    FOR(i,n){
        FOR(j,m-1){
            int c;
            scanf("%d",&c);
            e.pb(i*m+j,i*m+j+1,c);
        }
        if(i!=n-1)FOR(j,m){
            int c;
            scanf("%d",&c);
            e.pb(i*m+j,(i+1)*m+j,c);
        }
    }

    FOR(i,n*m)par[i]=i;
    sort(all(e));
    for(auto i:e){

        if(root(i.u)!=root(i.v)){ //cout<<i.u<<' '<<i.v<<' '<<i.w<<'\n';
            par[root(i.u)]=root(i.v);
            a.pb(i);
        }
        else b.pb(i);
    }
   // cout<<a.size()<<' '<<b.size();
    sort(all(a));
    sort(all(b));
    int l=0,r=1e9;
    int ans=0;
    while(l<=r){
        int mid=(l+r)/2;
       // cout<<mid<<endl;

        FOR(i,n*m)par[i]=i;
        int i=0,j=0;
        int ch=0;
        while(i<a.size()&&j<b.size()){
            if(a[i].w+mid<=b[j].w){
                if(root(a[i].u)!=root(a[i].v)){
                    par[root(a[i].u)]=root(a[i].v);
                }
                else {ch=1;break;}
                i++;
            }
            else{
                if(root(b[j].u)!=root(b[j].v)){
                    ch=1;break;
                }
                j++;
            }
        }
        if(ch){r=mid-1;}
            else{
                ans=mid;
                l=mid+1;
            }
    }
    //cout<<a.size();
    printf("%d",ans);
}
