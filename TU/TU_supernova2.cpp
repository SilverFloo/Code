#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<a;i++)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define pi pair<int,int>
using namespace std;
const int INF=2e9;
const int MAX=5e5+5;
int deg[MAX];
int par[MAX];
int size[MAX];
int main(){
int n;
cin>>n;
FOR(i,n){
    scanf("%d",&par[i]);par[i]--;
    deg[par[i]]++;
}
queue<int> q;
FOR(i,n){
if(deg[i]==0)q.p(i);
}

while(!q.empty()){
int a=q.front();
q.pop();
size[par[a]]+=size[a]+1;
deg[par[a]]--;
if(deg[par[a]]==0)q.p(par[a]);
}
int mn=INF,mx=0;
FOR(i,n){
if(deg[i]==1){
if(size[i]>mx)mx=size[i];
if(size[i]<mn)mn=size[i];
}
}
printf("%d",mx-mn);
}
