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
int visit[20][20];
vector<ii> ans;
int ch=0;
bool check(int a,int b,int c,int d){
    if(a==c||b==d)return 0;
    if(a+b==c+d||a-b==c-d)return 0;
    return 1;
}
        int n,m;
void go(int a,int b,int cnt){
   // printf("%d %d %d\n",a,b,cnt);
if(ch==1)return;
visit[a][b]=1;
    FOR(i,n){
        FOR(j,m)if(!visit[i][j]&&check(i,j,a,b)&&!ch){

            ans.pb(i,j);
            go(i,j,cnt-1);
            ans.pop_back();
        }
    }
    if(cnt==1){
        printf("POSSIBLE\n");
        for(auto i:ans)printf("%d %d\n",i.f+1,i.s+1);
        ans.empty();
        ch=1;
        return;
    }
    visit[a][b]=0;
}
int main(){
    int c;;
    cin>>c;
    FOR1(k,c){
        printf("Case #%d: ",k);
        ch=0;
        cin>>n>>m;
        FOR(i,n)FOR(j,m)visit[i][j]=0;
        FOR(i,n)FOR(j,m){
            FOR(i,n)FOR(j,m)visit[i][j]=0;
            if(!ch){
                ans.pb(i,j);
                go(i,j,n*m);
                ans.pop_back();

            }
        }
        if(!ch)printf("IMPOSSIBLE\n");
    }

}
