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
using namespace std;
const int INF=1e9;
int t[1000005<<2];
int n,m;
void update(int x,int v,int p=1,int l=0,int r=n-1){
    if(l==r){
        t[p]=v;
        return;
    }
    int m=(l+r)/2;
    if(x<=m)update(x,v,p<<1,l,m);
    else update(x,v,p<<1|1,m+1,r);
    t[p]=max(t[p<<1],t[p<<1|1]);
}
ii query(int v,int x,int p=1,int l=0,int r=n-1){

    if(t[p]<=v){return {l,r};}
    if(l==r)return {-1,-1};
    int m=(l+r)/2;
    ii a,b;
    if(x<=m){
        a=query(v,x,p<<1,l,m);
        if(a.s==m)b=query(v,x,p<<1|1,m+1,r);
        else return a;
    }
    else{
        b=query(v,x,p<<1|1,m+1,r);
        if(b.f==m+1)a=query(v,x,p<<1,l,m);
        else return b;
    }
  //  printf("%d %d(%d %d + %d %d) %d/",l,r,a.f,a.s,b.f,b.s,t[p]);
    if(a==mp(-1,-1))return b;
    if(b==mp(-1,-1))return a;
    if(a.s+1==b.f)return {a.f,b.s};
    if(x<=a.s)return a;
    if(x>=b.f)return b;
    //return {a.f,b.s};
}
int main(){
    cin>>n>>m;
    FOR(i,m){
        int x,h;
        scanf("%d %d",&x,&h);
        update(x,h);
        ii a=query(h,x);
     //   printf(">%d %d/",a.f,a.s);
        if(a.f==0&&a.s==n-1)printf("%d",n);
        else if(a.f==0)printf("%d",a.s-x);
        else if(a.s==n-1)printf("%d",x-a.f);
        else printf("%d",min(a.s-x,x-a.f));
        printf("\n");
    }
}
/*

10 10
5 1000

2 500

1 501

8 3
*/

