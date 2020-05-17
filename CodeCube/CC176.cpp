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
int par[MAX];

int root(int i){
while(i!=par[par[i]]){
par[i]=par[par[i]];
i=par[par[i]];
}
return i;
}

void merge(int a,int b){
par[root(a)]=root(b);
}

int main(){
int n,m,q;
cin>>n>>m>>q;
FOR(i,n)par[i]=i;
FOR(i,m){
int u,v;
scanf("%d %d",&u,&v);
merge(u,v);
}
FOR(i,q){
int u,v;
scanf("%d %d",&u,&v);
if(root(u)==root(v))printf("yes\n");
else printf("no\n");
}
}
