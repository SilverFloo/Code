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
int fenwick[(int)1e6+5];
void update(int x){
    for(int i=x;i<=1e6;i+=i&-i){
        fenwick[i]++;
    }
}
int query(int x){
    int sum=0;
    for(int i=x;i>0;i-=i&-i){
        sum+=fenwick[i];
    }
    return sum;
}
const int MAX=5e5+5;
int d[MAX];
pair<ii,int> qu[MAX];
int ans[MAX];
int main(){
    int n,q;
    cin>>n>>q;
    FOR1(i,n)scanf("%d",&d[i]);
    FOR(i,q){scanf("%d %d",&qu[i].f.f,&qu[i].f.s);qu[i].s=i;}
    sort(qu,qu+q);
    int now=1;
    FOR(i,q){
        while(now<=qu[i].f.f){update(d[now]);now++;}
        int l=1;int r=1e6;
        int a=-1;
        while(l<=r){
        int mid=(l+r)/2;
        //printf("%d ",query(mid));
        if(query(mid)>=qu[i].f.s){a=mid;r=mid-1;}
        else l=mid+1;
        }
        ans[qu[i].s]=a;
    }
    FOR(i,q)printf("%d\n",ans[i]);
}/*
7 3
3 5 6 4 2 5 7
5 3
7 5
3 2*/
