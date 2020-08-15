#include "fun.h"
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
const int INF=1e9;
vector<int> lv[100005];
int level[100005];
set<int> s;
int get(int x,int dx,int y,int dy){
  int cnt=0;
  while(dx>dy){
    x = (x-1)/2;
    dx--;
    cnt++;
  }
  while(dy>dx){
    y = (y-1)/2;
    dy--;
    cnt++;
  }
  while(x!=y){
    x = (x-1)/2;
    y = (y-1)/2;
    cnt+=2;
  }
  return cnt;

}
std::vector<int> createFunTour(int N, int Q) {
  int n = N;
  int mx = 0;
  int ch=0;
  for(int i=1;i<n;i++){
    if(hoursRequired(i, (i-1)/2)!=1){
      ch=1;break;
    }
  }
  s.insert(0);
  for(int i=1;i<n;i++){
    s.insert(i);
    int x =hoursRequired(0, i); 
    lv[x].pb(i);
    level[i]=x;
    mx =max(mx,x);
  }
  int now = lv[mx][0];
  s.erase(now);
  vector<int> ans;
  ans.pb(now);
  while(!s.empty()){
    int mx=-1;
    int a=-1;
    for(auto i:s){
      
      int x;
      if(n>500&&ch==0){x = get(now,level[now],i,level[i]);}
     else x =hoursRequired(now, i); 
      if(x>mx){
        mx = x;
        a=i;
      }
    }
    ans.pb(a);
    s.erase(a);
    now = a;
  }
  return ans;
}