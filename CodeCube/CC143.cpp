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
int deg[30005];
int main(){
    int n,m;
    cin>>n>>m;
    FOR(i,n-1){
    int u,v;
    scanf("%d %d",&u,&v);
    deg[u-1]++;
    deg[v-1]++;
    }
    int cnt=0;
    vector<ii> ans;
    int ch=-1;
    FOR(i,n){
    if(deg[i]==1){
    if(ch==-1)ch=i;
    else{
        if(m==2)ans.pb(ch+1,i+1);
        cnt++;
        ch=-1;
    }
    }
    }
    if(ch!=-1){ans.pb(ch+1,2);cnt++;}
    printf("%d\n",cnt);
   if(m==2){ for(auto i:ans){
    printf("%d %d\n",i.f,i.s);
    }}

}
