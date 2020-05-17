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
using namespace std;
const int INF=1e9;
ii edge[100005];
int n,m;
int ans=100005;
int chk[100005];
vector<int> a;
void find(int cnt,int p){
   if(cnt>20)return;
  // if(p>n)return;
   // printf("%d %d\n",cnt,p);
   if(p==m){
        if(cnt<ans){
            ans=cnt;
            a.clear();
            for(int i=1;i<=n;i++)if(chk[i]==1)a.pb(i);
        }
        return;
   }//printf("%d %d\n",cnt,p);
   if(chk[edge[p].f]||chk[edge[p].s]){
        find(cnt,p+1);
   }
   else{
        chk[edge[p].f]=1;
        find(cnt+1,p+1);
        chk[edge[p].f]=0;
        chk[edge[p].s]=1;
        find(cnt+1,p+1);
        chk[edge[p].s]=0;
   }

}
int main(){

    cin>>n>>m;
    FOR(i,m)scanf("%d %d",&edge[i].f,&edge[i].s);
    find(0,0);
    printf("%d\n",ans);
    for(auto i:a)printf("%d\n",i);
}
