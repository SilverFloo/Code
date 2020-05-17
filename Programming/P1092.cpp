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
const int MAX=1e5+5;
ll val[MAX];
int par[MAX];
int root(int i){
while(par[par[i]]!=i){
par[i]=par[par[i]];
i=par[par[i]];
}return i;
}

int main(){
    int n,q;
    cin>>n>>q;
    FOR1(i,n)scanf("%lld",&val[i]);
    FOR1(i,n)par[i]=i;
    while(q--){
    int a,b;
    scanf("%d%d",&a,&b);
    a=root(a);
    b=root(b);
    if(a==b)printf("-1\n");
    else{
        if(val[a]<val[b])swap(a,b);
        if(val[a]==val[b]&&a>b)swap(a,b);
        printf("%d\n",a);
        val[a]+=val[b]/2;
        par[b]=a;
    }
    }
}
