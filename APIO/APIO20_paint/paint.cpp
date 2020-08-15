#include "paint.h"
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
int bf[100005];
vector<int> x[100005];
int dp[100005];
int cnt[100005];
int can[100005];
int minimumInstructions(
    int N, int M, int K, std::vector<int> C,
    std::vector<int> A, std::vector<std::vector<int>> B) {
  for(int i=0;i<M;i++){
    for(auto j:B[i]){
      x[j].pb(i);
    }
  }
  FOR1(i,M)bf[i]=-1;
  for(int i=0;i<N;i++){
    for(auto j:x[C[i]]){
      if(bf[(j-i-M)%M+M]==i-1){
        cnt[(j-i-M)%M+M]++;
      }
      else cnt[(j-i-M)%M+M]=1;
      if(cnt[(j-i)%M+M]>=M)can[i]=1;
      bf[(j-i-M)%M+M]=i;
      //printf("%d %d\n",(j-i-M)%M+M,cnt[(j-i-M)%M+M]);
   }
    //printf("%d \n",can[i]);
    //cout<<endl;
  }//cout<<endl;
  FOR1(i,N)dp[i]=INF;
  deque<int> q;
  for(int i=0;i<M;i++)q.pb(i);
  for(int i=M;i<=N;i++){
    if(can[i-1]==1){
      while(!q.empty()&&q.front()<i-M)q.pop_front();
      dp[i] = dp[q.front()]+1; 
    }
    while(!q.empty()&&dp[q.back()]>=dp[i])q.pop_back();
      q.push_back(i);
    //printf("%d ",dp[i]);
  }//cout<<endl;
  return dp[N]>=INF?-1:dp[N];

}
