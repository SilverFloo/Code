#include <iostream>
#include <vector>
#include "castle.cpp"
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
#define rf() freopen("_working/input.in","r",stdin)
#define pf() freopen("_working/output.out","w+",stdout)
using namespace std;
int N,M,Q,Y;
vector<int> edge[100005];
vector<int> A,B;
int par[100005];
int color[100005];
vector<int> e[100005];
int visit[100005];
vector<ii> path;
void dfs(int u){
  for(auto v:edge[u]){
    if(v!=par[u]&&par[v]==-1){
        par[v]=u;
        dfs(v);
    }
  }
}
int root(int u){
  if(par[u]==-2)return u;
  return root(par[u]);
}
int find(int u,int f){
  visit[u]=1;
  if(u==f)return 1;
  int tmp = 0;
  for(auto v:e[u]){
    if(!visit[v])tmp|=find(v,f);
  }
  return tmp;
}
int main() {
  rf();
  castle_init(N,M,Q,Y);
  castle_read_map(A,B);
  for(int i=0;i<M;i++){
    edge[A[i]].pb(B[i]);
    edge[B[i]].pb(A[i]);
  }
 
  FOR(i,N)par[i]=-1;
  par[0]=-2;
  dfs(0);
//  FOR(i,N)printf("%d ",par[i]);
 for(int i=0;i<M;i++){
    if(par[A[i]]!=B[i]&&par[B[i]]!=A[i]){
      if(A[i]>B[i])swap(A[i],B[i]);
      path.pb(A[i],B[i]);
    }
  }

  //FOR(i,path.size())printf("%d %d\n",path[i].f,path[i].s);
  while(Q--){
    int T,X,Y;
    castle_read_event(T,X,Y);
    if(T==1){
      Y=A[X];
      X=B[X];
      //printf("cut %d %d\n",X,Y);
      if(par[X]==Y||par[Y]==X){
        if(par[Y]==X)swap(X,Y);
        par[X]=-2;
      }
      else{
        if(X>Y)swap(X,Y);
        for(int i=0;i<path.size();i++){
          if(path[i].f==X&&path[i].s==Y){
            path.erase(path.begin()+i);
            break;
          }
        }
      }
    }
    else{
      int check=0;
      int a = root(X);
      int b = root(Y);
     // printf("find %d-%d %d-%d\n",X,a,Y,b);
      if(a==b)check=1;
      if(check==0){
        for(auto x:path){
          int f = root(x.f);
          int s = root(x.s);
          e[f].pb(s);
          e[s].pb(f);
      //  printf("<%d %d>",f,s);
        }
        check = find(a,b);
        for(auto x:path){
          int f = root(x.f);
          int s = root(x.s);
          e[f].clear();
          e[s].clear();
          visit[f]=0;
          visit[s]=0;
        }
      }
      castle_answer(check);
    }
  }
}