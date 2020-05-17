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
int t[300005];
ii tab[300005];
int ans[300005];
void update(int x,int v){
    for(int i=x;i<300005;i+=i&-i){
        //printf("%d",i);
        t[i]+=v;
    }
}
int query(int x){
    int sum=0;
    for(int i=x;i>0;i-=i&-i){
        sum+=t[i];
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    int sum=0;
    FOR1(i,n)scanf("%d",&tab[i].f),tab[i].s=i,sum+=tab[i].f;
    sort(tab+1,tab+n+1,greater<ii>());
    FOR1(i,n){
        update(i,tab[i].f);
    }
    sum+=2;
    sum/=2;
    FOR1(i,n){
        update(i,-tab[i].f);
        int x=sum-tab[i].f;
        int l=1,r=n;
        int a=1;
        //printf("<%d",x);
        while(l<=r){
            int m=(l+r)/2;
            if(query(m)>=x){a=m;r=m-1;}
            else l=m+1;
        }
        if(a>i)a--;
        //printf("/%d>",a);
        ans[tab[i].s]=a;
        update(i,tab[i].f);
    }
    FOR1(i,n)printf("%d\n",ans[i]);
}
