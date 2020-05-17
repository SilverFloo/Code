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
const int MAX=505;
bool visit[505][505][8];
char tab[505][505];
    queue<pair<ii,ii>> q;
   void pu(int a,int b,int c,int d){
    q.p(mp(a,b),mp(c,d));
    }
int main(){
    int n,m;
    cin>>n>>m;
    ii st;
    FOR(i,n){
        FOR(j,m){
            scanf(" %c",&tab[i][j]);
            if(tab[i][j]=='S')st.f=i,st.s=j;
        }
    }

    q.p(st,mp(0,0));
    while(!q.empty()){
        int i=q.front().f.f;
        int j=q.front().f.s;
        int state=q.front().s.f;
        int t=q.front().s.s;
        q.pop();
        if(i>=0&&j>=0&&i<n&&j<m){
        if(!visit[i][j][state]){

            visit[i][j][state]=1;
            if(tab[i][j]=='E'){printf("%d",t);return 0;}
            if(tab[i][j]=='j')state|=1;
            if(tab[i][j]=='b')state|=2;
            if(tab[i][j]=='p')state|=4;

            if(tab[i][j]=='.'||tab[i][j]=='S'||tab[i][j]=='j'||tab[i][j]=='b'||tab[i][j]=='p'||(tab[i][j]=='J'&&((state&1)>0))||(tab[i][j]=='B'&&((state&2)>0))||(tab[i][j]=='P'&&((state&4)>0))){
               //  printf("%d %d %d %d\n",i,j,state,t);
            pu(i-1,j,state,t+1);
            pu(i+1,j,state,t+1);
            pu(i,j+1,state,t+1);
            pu(i,j-1,state,t+1);
            }

            }
        }
    }
    printf("-1");
}

