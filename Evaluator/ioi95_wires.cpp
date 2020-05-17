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
int n;
int sol[100];

#include "wirelib.h"
/*#include <cstdlib>
#include <cstdio>

#define MAX_M 100

#define MAX_CALL 10000000

static int m;

static int conn[MAX_M];
static bool status[MAX_M];

static int ccount;

int wire_init()
{
  scanf("%d",&m);
  for(int i=0; i<m; i++) {
    scanf("%d",&conn[i]);
    conn[i]--;
    status[i] = false;
  }
  ccount = 0;
  return m;
}

static void cmd_check()
{
  ccount++;
  if(ccount > MAX_CALL) {
    printf("too many calls\n");
    exit(0);
  }
}

bool cmd_T(int w)
{
  cmd_check();
  return status[conn[w-1]];
}

bool cmd_C(int s)
{
  cmd_check();
  status[s-1] = !status[s-1];
  return status[s-1];
}

void cmd_D(int sol[])
{
  cmd_check();
  for(int i=0; i<m; i++) {
    printf("%d\n",sol[i+1]);
  }
  exit(0);
}*/

void check(int l,int r,vector<int> x,int st){
    if(l==r){
        for(auto i:x)sol[i]=l;
        return;
    }
    vector<int> xl,xr;
    int m=(l+r)/2;
    if(m>l)m--;
    for(int i=l;i<=m;i++){
        cmd_C(i);
    }
    for(auto i:x){
        if(cmd_T(i)!=st)xl.pb(i);
        else xr.pb(i);
    }
    check(l,m,xl,!st);
    check(m+1,r,xr,st);
}
int main(){
        vector<int> x;
        n = wire_init();
        FOR1(i,n)x.pb(i);
        check(1,n,x,0);
        cmd_D(sol);
}
