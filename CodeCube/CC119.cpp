#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
using namespace std;
int tab[105][10005];
int ans[105][10005];
int main(){
int n,m,k;
scanf("%d %d %d",&n,&m,&k);
FOR(i,n)FOR(j,m)scanf("%d",&tab[i][j]);
FOR(j,m)ans[0][j]=tab[0][j];
for(int i=0;i<n-1;i++){
deque<int> q;
for(int j=0;j<=k;j++){
    while(!q.empty()&&ans[i][j]>ans[i][q.back()]){q.pop_back();}
    q.push_back(j);
}
ans[i+1][0]=tab[i+1][0]+ans[i][q.front()];
//printf("%d ",ans[i][q.front()]);
for(int j=k+1;j<m;j++){
    while(!q.empty()&&q.front()<j-k-k){q.pop_front();}
   while(!q.empty()&&ans[i][j]>ans[i][q.back()]){q.pop_back();}
    q.push_back(j);
ans[i+1][j-k]=tab[i+1][j-k]+ans[i][q.front()];
//printf("%d ",ans[i][q.front()]);
}
for(int j=m;j<m+k;j++){
 while(!q.empty()&&q.front()<j-k-k){q.pop_front();}
 ans[i+1][j-k]=tab[i+1][j-k]+ans[i][q.front()];
//printf("%d ",ans[i][q.front()]);
}

//cout<<'\n';
}
int mx=0;
FOR(i,m)if(ans[n-1][i]>mx)mx=ans[n-1][i];
printf("%d",mx);
}

