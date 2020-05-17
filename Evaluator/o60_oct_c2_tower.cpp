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
const int MAX=200005;
pair<ii,ii> t[MAX<<2];
int lz[MAX<<2];
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
void update(int st,int ed,int v,int p=1,int l=1,int r=MAX){
    if(st>r||ed<l){if(t[p].f.s==0)t[p].f.s=1;return;}
    if(st<=l&&r<=ed){
        uplz(p,v);
        return;
    }
    dolz(p);
    int m=(l+r)/2;
    update(st,ed,v,p<<1,l,m);
    update(st,ed,v,p<<1|1,m+1,r);
    //printf("/%d %d %d %d/",t[p<<1].s.f,t[p<<1].s.s,t[p<<1|1].s.f,t[p<<1|1].s.s);
    if(t[p<<1].f.f==t[p<<1|1].f.f){
            t[p].f.f=t[p<<1].f.f;
            if(t[p<<1].s.s==t[p<<1|1].s.f&&t[p<<1].s.s==t[p<<1].f.f)t[p].f.s=t[p<<1].f.s+t[p<<1|1].f.s-1;
            else t[p].f.s=t[p<<1].f.s+t[p<<1|1].f.s;
       }
    else if(t[p<<1].f.f>t[p<<1|1].f.f){

            t[p].f.s=t[p<<1].f.s;
            t[p].f.f=t[p<<1].f.f;
       }
    else t[p].f.s=t[p<<1|1].f.s,t[p].f.f=t[p<<1|1].f.f;
        t[p].s.f=t[p<<1].s.f;
        t[p].s.s=t[p<<1|1].s.s;
}

pair<ii,ii> query(int st,int ed,int p=1,int l=1,int r=MAX){
    if(st>r||ed<l)return {{0,1},{0,0}};
    if(st<=l&&r<=ed){if(t[p].f.s==0)t[p].f.s=1;return t[p];}
    dolz(p);
    int m=(l+r)/2;
    pair<ii,ii> a=query(st,ed,p<<1,l,m);
    pair<ii,ii> b=query(st,ed,p<<1|1,m+1,r);
    //printf("//%d %d//",a.f.s,b.f.s);
    if(a.f.f!=b.f.f){
            if(a.f.f>b.f.f)return {{a.f.f,a.f.s},{a.s.f,b.s.s}};
            else return {{b.f.f,b.f.s},{a.s.f,b.s.s}};
    }
    else{
          // printf("<%d %d %d %d %d %d>",a.f.f,a.f.s+b.f.s,a.s.f,a.s.s,b.s.f,b.s.s);
        if(a.s.s==b.s.f&&a.s.s==a.f.f)return {{a.f.f,a.f.s+b.f.s-1},{a.s.f,b.s.s}};
        else return {{a.f.f,a.f.s+b.f.s},{a.s.f,b.s.s}};
    }
}
int main(){
        int n,m;
        cin>>n>>m;
        while(m--){
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            update(a,b,c);
            ii x=query(1,n).f;
            printf("%d %d\n",x.f,x.s);
        }
}
