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
map<int,int> m;
int tab[100005];
ii t[100005<<2];
int lz[100005<<2];
int val[100005];
int n,l;
void uplz(int p){
    lz[p]^=1;
    swap(t[p].f,t[p].s);
}
void dolz(int p){
    if(lz[p]==0)return;
    uplz(p<<1);
    uplz(p<<1|1);
    lz[p]=0;
}
void built(int p=1,int l=0,int r=n){
    if(l==r){
        t[p].f=val[l+1]-val[l];
      //  printf("%d -> %d \n",l,t[p].f);
        return;
    }
    int m=(l+r)/2;
    built(p<<1,l,m);
    built(p<<1|1,m+1,r);
    t[p].f=t[p<<1].f+t[p<<1|1].f;
    t[p].s=t[p<<1].s+t[p<<1|1].s;
}
void update(int st,int ed=n,int p=1,int l=0,int r=n){
    if(st<=l&&r<=ed){
        uplz(p);
        return;
    }
    if(r<st||l>ed){
        return;
    }
    dolz(p);
    int m=(l+r)/2;
    update(st,ed,p<<1,l,m);
    update(st,ed,p<<1|1,m+1,r);
    t[p].f=t[p<<1].f+t[p<<1|1].f;
    t[p].s=t[p<<1].s+t[p<<1|1].s;
  //  printf("%d %d %d %d\n",l,r,t[p].f,t[p].s);
}
int main(){
    cin>>l>>n;
    FOR(i,n){
        scanf("%d",&tab[i]);
        m[tab[i]]=1;
        val[i+1]=tab[i];
    }
    val[n+1]=l;
    sort(val,val+n+2);

    m[0]=1;
    int ptr=0;
    for(auto &i:m)i.s=ptr++;
    built();
    FOR(i,n){
        update(m[tab[i]]);
        printf("%d\n",t[1].f);
    }

}
