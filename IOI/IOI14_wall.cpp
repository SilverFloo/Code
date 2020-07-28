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
ii t[2000005<<2];
void uplz(int p,ii x){
    t[p].f = min(t[p].f,x.f);
    t[p].f = max(t[p].f,x.s);
    t[p].s = max(t[p].s,x.s);
    t[p].s = min(t[p].s,x.f);
}
void dolz(int p){
    if(t[p].f==INF&&t[p].s==0)return;
    uplz(p<<1,t[p]);
    uplz(p<<1|1,t[p]);
    t[p].f = INF;
    t[p].s = 0;
}
void update(int op,int x,int st,int ed,int p,int l,int r){
    if(st<=l&&r<=ed){
        if(op==2){
            t[p].f = min(t[p].f,x);
            t[p].s = min(t[p].s,x);
        }
        else{
            t[p].f = max(t[p].f,x);
            t[p].s = max(t[p].s,x);
        }
        return;
    }
    else if(r<st||l>ed)return;
    int m=(l+r)/2;
    dolz(p);
    update(op,x,st,ed,p<<1,l,m);
    update(op,x,st,ed,p<<1|1,m+1,r);
}
ii query(int x,int p,int l,int r){
    if(l==r){
        return t[p];
    }
    dolz(p);
    int m=(l+r)/2;
    if(x<=m)return query(x,p<<1,l,m);
    else return query(x,p<<1|1,m+1,r);
}
void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]){
    for(int i=0;i<k;i++){
        update(op[i],height[i],left[i],right[i],1,0,n-1);
    }
    for(int i=0;i<n;i++){
        ii a =  query(i,1,0,n-1);
        finalHeight[i] = min(a.f,a.s);
    }
    //FOR(i,n)printf("%d ",finalHeight[i]);
}
int main(){
    int l[]={1,4,3,0,2,6},r[]={8,9,6,5,2,7};
    int h[]={4,1,5,3,5,0},op[]={1,2,2,1,1,2};
    int final[100];
    buildWall(10,6,op,l,r,h,final);
}