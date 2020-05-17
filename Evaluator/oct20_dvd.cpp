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
int tmn[200005],tmx[200005];
int st[100005];
int n,k;
void update(int x,int v,int p=1,int l=1,int r=n){
    if(l==r){
        tmn[p]=v;
        tmx[p]=v;
        return;
    }
    int m = (l+r)/2;
    if(x<=m)update(x,v,p<<1,l,m);
    else update(x,v,p<<1|1,m+1,r);
    //printf("%d",tmn[p]);
    tmn[p] = min(tmn[p<<1],tmn[p<<1|1]);
   // printf(" %d/",tmn[p]);
    tmx[p] = max(tmx[p<<1],tmx[p<<1|1]);
}
ii query(int st,int ed,int p=1,int l=1,int r=n){
    if(st>r||ed<l)return {INF,-INF};
    if(st<=l&&r<=ed)return {tmn[p],tmx[p]};
    int m=(l+r)/2;
    ii x=query(st,ed,p<<1,l,m);
    ii y=query(st,ed,p<<1|1,m+1,r);
    return {min(x.f,y.f),max(x.s,y.s)};
}
int main(){
    cin>>n>>k;
    FOR1(i,n){
        st[i]=i;
    }
    FOR1(i,n)update(i,i);
    while(k--){
        int q,a,b;
        scanf("%d %d %d",&q,&a,&b);
        a++;b++;
        if(q==0){
            update(a,st[b]);
            update(b,st[a]);
            swap(st[a],st[b]);
        }
        else{
            ii x=query(a,b);
            //printf("<%d %d/%d %d>",a,b,x.f,x.s);
            if(x.f==a&&x.s==b){
                printf("YES\n");
            }
            else printf("NO\n");
        }
    }

}
