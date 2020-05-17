// ‡¡“““““
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
int size[405];
int par[405];
root(int i){
while(i!=par[par[i]]){
par[i]=par[par[i]];
i=par[par[i]];
}
return i;
}
int main(){
    int t;
    cin>>t;
    while(t--){
    int n,m;
    cin>>n>>m;
    int cnt=n;
    FOR1(i,n)par[i]=i,size[i]=1;
    FOR(i,m){
    int a,b;
    scanf("%d %d",&a,&b);
    if(root(a)!=root(b)){
    cnt--;
    size[root(a)]+=size[root(b)];
    par[root(b)]=root(a);
    }
    }
    //printf(">%d<",cnt);
    if(cnt>2)printf("-1\n");
    else if(cnt==1){printf("%d\n",n%2);}
    else printf("%d\n",(int)fabs(size[root(1)]-n+size[root(1)]));
    }
}
