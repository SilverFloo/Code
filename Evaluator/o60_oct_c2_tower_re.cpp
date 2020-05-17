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
pair<ii,ii> t[200005<<2];
int lz[200005<<2];
int n;
void uplz(int p,int v){
    if(t[p].f.s==0)t[p].f.s=1;
    t[p].f.f+=v;
    t[p].s.f+=v;
    t[p].s.s+=v;
    lz[p]+=v;
}
void dolz(int p){
    if(lz[p]==0)return;
    uplz(p<<1,lz[p]);
    uplz(p<<1|1,lz[p]);
    lz[p]=0;
}
void update(int st,int ed,int v,int p=1,int l=1,int r=n){
    if(st<=l&&r<=ed){
        uplz(p,v);
        return;
    }
    if(r<st||l>ed){
        if(t[p].f.s==0)t[p].f.s=1;
        return;
    }
    int m = (l+r)/2;
    dolz(p);
    update(st,ed,v,p<<1,l,m);
    update(st,ed,v,p<<1|1,m+1,r);
    pair<ii,ii> a=t[p<<1];
    pair<ii,ii> b=t[p<<1|1];
    if(a.f.f>b.f.f){
        t[p]= {{a.f.f,a.f.s},{a.s.f,b.s.s}};
    }
    else if(a.f.f<b.f.f){
        t[p]= {{b.f.f,b.f.s},{a.s.f,b.s.s}};
    }
    else{
        if(a.s.s==b.s.f&&a.s.s==a.f.f){
            t[p]= {{a.f.f,a.f.s+b.f.s-1},{a.s.f,b.s.s}};
        }
        else{
            t[p]= {{a.f.f,a.f.s+b.f.s},{a.s.f,b.s.s}};
        }
    }
}
int main(){
    int m;
    cin>>n>>m;
    while(m--){
        int a,b,x;
        scanf("%d %d %d",&a,&b,&x);
        update(a,b,x);
        ii ans = t[1].f;
        printf("%d %d\n",ans.f,ans.s);
    }
}
