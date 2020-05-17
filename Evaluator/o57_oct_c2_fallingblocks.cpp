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
pair<ii,ii> t[100005<<2];
int lz[100005<<2];
void uplz(int p,int v){
    t[p].f.f+=v;
    t[p].f.s+=v;
    lz[p]+=v;
}
void dolz(int p){
    if(lz[p]==0)return;
    uplz(p<<1,lz[p]);
    uplz(p<<1|1,lz[p]);
    lz[p]=0;
}
void update(int st,int ed,int p=1,int l=0,int r=100005){
    if(st<=l&&r<=ed){
        uplz(p,1);
        return;
    }
    if(r<st||l>ed)return;
    dolz(p);
    int m = (l+r)/2;
    update(st,ed,p<<1,l,m);
    update(st,ed,p<<1|1,m+1,r);
    pair<ii,ii> a,b,c;
    a = t[p<<1];
    b = t[p<<1|1];
    t[p].f.f=a.f.f;
    t[p].f.s=b.f.s;
    t[p].s.f=a.s.f+b.s.f;
    t[p].s.s=a.s.s+b.s.s;
    if(a.f.s>b.f.f)t[p].s.s++;
    if(a.f.s<b.f.f)t[p].s.f++;
}
pair<ii,ii> query(int st,int ed,int p=1,int l=0,int r=100005){
    if(st<=l&&r<=ed){
        return t[p];
    }
    if(r<st||l>ed)return{{-1,-1},{-1,-1}};
    dolz(p);
    int m=(l+r)/2;
    pair<ii,ii> a,b,c;
    a = query(st,ed,p<<1,l,m);
    b = query(st,ed,p<<1|1,m+1,r);
    if(a.f.f==-1)return b;
    if(b.f.f==-1)return a;
    c.f.f=a.f.f;
    c.f.s=b.f.s;
    c.s.f=a.s.f+b.s.f;
    c.s.s=a.s.s+b.s.s;
    if(a.f.s>b.f.f)c.s.s++;
    if(a.f.s<b.f.f)c.s.f++;
    return c;
}

int main(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if(a==1)update(b,c);
        else{
            pair<ii,ii> x=query(b,c);
            printf("%d %d",x.f.f,x.f.s);
            if(a==3)
            printf(" %d %d",x.s.f,x.s.s);
            printf("\n");
        }

    }
}
