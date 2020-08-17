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
#define rf() freopen("_working/IOI17_nowruz_/input/nowruz1.in.txt","r",stdin)
#define pf() freopen("_working/IOI17_nowruz_/output/nowruz1.out.txt","w+",stdout)
using namespace std;
const int INF=1e9;
char tab[2000][2000];

char intab[2000][2000];
int visit[2000][2000];
char tabcp[2000][2000];
int n,m,k;
int x = 0;
priority_queue<pair<int,pair<ii,ii>>> q;
void dfs(int i,int j,int pi,int pj){
    q.p(rand(),mp(mp(i,j),mp(pi,pj)));
}
int countans(){
    int ans=0;
    FOR1(i,n){
        FOR1(j,m){
            int cnt = visit[i-1][j]+visit[i+1][j]+visit[i][j+1]+visit[i][j-1];
            if(cnt==1)ans++;
        }
    }
    return ans;
}
int mx = 0;

int main(){

    rf();
    pf();
    cin>>n>>m>>k;
    FOR1(i,n){
        FOR1(j,m)cin>>intab[i][j];
    }
    srand(time(NULL));
    FOR(xx,10){
        FOR1(i,n){
        FOR1(j,m)tab[i][j]=intab[i][j];
    }
    int a = rand()%n+1;
    int b = rand()%m+1;
    while(tab[a][b]=='#'){
        a = rand()%n+1;
        b = rand()%m+1;
    }
    FOR1(i,n)FOR1(j,m)visit[i][j]=0;
    dfs(a,b,0,0);
    while(!q.empty()){//printf("in");
        int i=q.top().s.f.f;
        int j=q.top().s.f.s;
        int pi = q.top().s.s.f;
        int pj = q.top().s.s.s;
        q.pop();
    if(tab[i][j]=='X'||tab[i][j]=='#')continue;
    if(i>0&&j>0&&i<=n&&j<=m)visit[i][j]=1;
    else continue;
    x++;
    int aa=x;
    //printf("<%d %d>",i,j);
    visit[pi][pj]=0;
    if(visit[i-1][j]==1||visit[i+1][j]==1||visit[i][j+1]==1||visit[i][j-1]==1){
        tab[i][j]='X';
       visit[i][j]=0;
       
    visit[pi][pj]=1;
        continue;
    }
    visit[pi][pj]=1;
if(aa%4==0){
    
    if(visit[i+1][j]!=1)dfs(i+1,j,i,j);
    if(visit[i-1][j]!=1)dfs(i-1,j,i,j);
    if(visit[i][j-1]!=1)dfs(i,j-1,i,j);
    if(visit[i][j+1]!=1)dfs(i,j+1,i,j);
}
else if(aa%4==1){ 
    if(visit[i-1][j]!=1)dfs(i-1,j,i,j);
    if(visit[i][j-1]!=1)dfs(i,j-1,i,j);
    if(visit[i][j+1]!=1)dfs(i,j+1,i,j);
    if(visit[i+1][j]!=1)dfs(i+1,j,i,j);
    }
    else if(aa%4==2){
        if(visit[i][j-1]!=1)dfs(i,j-1,i,j);
        if(visit[i][j+1]!=1)dfs(i,j+1,i,j);
        if(visit[i+1][j]!=1)dfs(i+1,j,i,j);
        if(visit[i-1][j]!=1)dfs(i-1,j,i,j);
    }

    else if(aa%4==3){
        if(visit[i][j+1]!=1)dfs(i,j+1,i,j);
        if(visit[i+1][j]!=1)dfs(i+1,j,i,j);
        if(visit[i-1][j]!=1)dfs(i-1,j,i,j);
        if(visit[i][j-1]!=1)dfs(i,j-1,i,j);
    }
    }
    
    FOR1(i,n){
        FOR1(j,m)if(visit[i][j]==0&&tab[i][j]!='#'&&tab[i][j]!='X')tab[i][j]='X';
    }//cout<<endl;
    if(countans()>mx){
        mx=countans();
        FOR1(i,n)FOR1(j,m)tabcp[i][j]=tab[i][j];
    }
    
        
}
        printf("%d",mx);
        FOR1(i,n){
            FOR1(j,m){
                printf("%c",tabcp[i][j]);
            }cout<<endl;
        }
    
}