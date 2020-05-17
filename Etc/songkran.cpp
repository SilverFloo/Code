#include<bits/stdc++.h>
using namespace std;
int tab[105][105];
const inf = 2e9;
int main(){
int n,m,q;
scanf("%d %d %d",&n,&m,&q);
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){tab[i][j]=i==j?0:INF;}
}
for(int i=0;i<m;i++){
int u,v,w;
scanf("%d%d%d",&u,&v,&w);
u--;v--;
tab[u][v]=w;
tab[v][u]=w;
}
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
for(int k=0;k<n;k++){
tab[i][j]=min(tab[i][j],tab[i][k]+tab[k][j]);
}
}
}

}
