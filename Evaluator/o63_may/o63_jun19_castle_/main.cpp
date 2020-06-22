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
vector<int> A,B;
int cnt[100005];
int visit[100005];
vector<int> e[100005];
ii edge[100005];
int par[100005];
void dfs(int u){
  for(auto v:e[u]){
    if(v!=par[u]){
      par[v]=u;
      dfs(v);
    }
  }
}
int find(int u,int p){
  visit[u]=1;
  if(u==p)return 1;
  int x=0;
  for(auto v:e[u]){
      if(visit[v]==0)x|=find(v,p);
  }
  return x;
}
void change(int u,int num){
  
  for(auto v:e[u]){
    if(par[u]!=v&&visit[u]==visit[v])change(v,num);
  }visit[u]=num;
}
int main() {
  rf();
  castle_init(N,M,Q,Y);
  castle_read_map(A,B);
  if(N<=1000&&Q<=1000){
    for(int i=0;i<M;i++){
      edge[i].f=A[i];
      edge[i].s=B[i];
      e[A[i]].pb(B[i]);
      e[B[i]].pb(A[i]);
    }

        while (Q--) {
      int T,X,Y;
      castle_read_event(T,X,Y);
      if(T==1){
        
        Y=edge[X].f;
        X=edge[X].s;
        for(int i=0;i<e[X].size();i++){
          if(e[X][i]==Y){
            e[X].erase(e[X].begin()+i);break;
          }
        }
        for(int i=0;i<e[Y].size();i++){
          if(e[Y][i]==X){
            e[Y].erase(e[Y].begin()+i);break;
          }
        }
      }
      if (T == 2) {
        FOR(i,N)visit[i]=0;
        castle_answer(find(X,Y));
      }
    }


  }
  else if(M==N-1){
    for(int i=0;i<M;i++){
      edge[i].f=A[i];
      edge[i].s=B[i];
      e[A[i]].pb(B[i]);
      e[B[i]].pb(A[i]);
      cnt[A[i]]++;
      cnt[B[i]]++;
    }
    int root=-1;
    FOR(i,N){
      if(cnt[i]==2)root = i;
    }
    par[root]=-1;
    dfs(root);
    int ptr=1;
        while (Q--) {
      int T,X,Y;
      castle_read_event(T,X,Y);
      if(T==1){
        
        Y=edge[X].f;
        X=edge[X].s;
        if(par[X]==Y)swap(X,Y);
        change(Y,ptr++);
       // printf("cut %d %d\n",X,Y);
      }
      if (T == 2) {
        
        //printf("check %d %d %d %d\n",X,Y,visit[X],visit[Y]);
        castle_answer(visit[X]==visit[Y]);
      }
    }
  }
}