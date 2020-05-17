#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
int main(){
int n,m,t,ans,ma=0;
cin>>n>>m>>t;
vector<int> sh[n];
for(int i=0;i<m;i++){int u,v;scanf("%d %d",&u,&v);sh[u].push_back(v);}
int dist[n+1];
for(int i=0;i<=n;i++)dist[i]=INF;
dist[0]=0;
for(int i=0;i<n;i++){
if(dist[i+1]>dist[i]+1)dist[i+1]=dist[i]+1;
for(auto j:sh[i])if(dist[j]>dist[i]+1)dist[j]=dist[i]+1;
if(dist[i]>=ma&&dist[i]<=t){ma=dist[i];ans=i;}
}
printf("%d\n",dist[n]);
if(dist[n]<=t)printf("1");
else printf("0 %d",ans);
}
