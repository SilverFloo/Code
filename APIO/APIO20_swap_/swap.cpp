//#include "swap.h"
#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define db(a) printf("<%d> ",a)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
#define ll long long
const int INF=1e9;
using namespace std;
vector<ii> edge[100005];
int dp[100005][2];
int n,m;
int x = 0;
int mx = -1;
void init(int N, int M,std::vector<int> U, std::vector<int> V, std::vector<int> W) {
  for(int i=0;i<M;i++){
    edge[U[i]].pb(V[i],W[i]);
    edge[V[i]].pb(U[i],W[i]);
    mx = max(mx,W[i]);
  }
  FOR(i,N){
   // printf("%d ",edge[i].size());
    if(edge[i].size()==2||edge[i].size()==1){
      x = 1;
    }else{
      x=0;
      break;
    }
  }
  if(x==1){
    x=2;
    FOR(i,N){
      if(edge[i].size()!=2){
        x=1;break;
      }
    }
  }
  n=N;
  m=M;
}
int getMinimumFuelCapacity(int X, int Y) {
 // printf("%d",x);
  if(x == 1)return -1;
  if(x==2)return mx;
  for(int i=0;i<n;i++)dp[i][0]=INF,dp[i][1]=INF;
  dp[X][0]=0;
  priority_queue<pair<ii,ii>,vector<pair<ii,ii>>,greater<pair<ii,ii>>> q;
  q.p(mp(0,-1),mp(X,0));
  while(!q.empty()){
    int w = q.top().f.f;
    int u = q.top().s.f;
    int st = q.top().s.s;
    int par = q.top().f.s;
    q.pop();
    if(dp[u][st]!=w)continue;
    int mn1=INF,mn2=INF;
      for(auto v:edge[u]){
        if(v.f == par)continue;
        if(v.s<=mn1){
          mn2 = mn1;
          mn1 = v.s;
        }
        else if(v.s<=mn2){
          mn2 = v.s;
        }
        if(max(v.s,w)<dp[v.f][0]){
          if(dp[v.f][0]<dp[v.f][1]){
            dp[v.f][1] = dp[v.f][0];
            if(v.f!=X&&v.f!=Y)q.p(mp(dp[v.f][1],u),mp(v.f,1));
          }
          dp[v.f][0] = max(v.s,w);
          if(v.f!=Y)q.p(mp(dp[v.f][0],u),mp(v.f,0));
        }
        else{
          if(max(v.s,w)<dp[v.f][1]&&v.f!=X){
            dp[v.f][1] = max(v.s,w);
            if(v.f!=X&&v.f!=Y)q.p(mp(dp[v.f][1],u),mp(v.f,1));
          }
        }
      }
      //if(u!=X&&u!=Y)printf("/%d %d/",mn1,mn2);
      if(u!=X&&u!=Y)for(auto v:edge[u]){
        if(v.f == par)continue;
        int a = v.s;
        if(v.s == mn1)v.s = max(v.s,mn2);
        else v.s = max(v.s,mn1);
        if(max(max(v.s,par),w)<dp[v.f][0]){
          if(dp[v.f][0]<dp[v.f][1]){
            dp[v.f][1] = dp[v.f][0];
            if(v.f!=X&&v.f!=Y)q.p(mp(dp[v.f][1],u),mp(v.f,1));
          }
          dp[v.f][0] = max(v.s,w);
          if(v.f!=Y)q.p(mp(dp[v.f][0],u),mp(v.f,0));
        }
        else{
          if(max(v.s,w)<dp[v.f][1]&&v.f!=X){
            dp[v.f][1] = max(v.s,w);
            if(v.f!=X&&v.f!=Y)q.p(mp(dp[v.f][1],u),mp(v.f,1));
          }
        }
        v.s = a;
      }
  }
 // printf("<%d %d>",dp[Y][0],dp[Y][1]);
  return max(dp[Y][0],dp[Y][1])==INF?-1:max(dp[Y][0],dp[Y][1]);
}
