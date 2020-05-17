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
int visit[20][20][20][20];
int way[20][20];
queue<pair<int,pair<ii,ii>>> q;
void add(int a,int b,int c,int d,int e){
    if(way[b][c]==0||way[d][e]==0)return;
    if(visit[b][c][d][e])return;
    visit[b][c][b][c]=1;
    visit[b][c][d][e]=1;
    q.p(mp(a,mp(mp(b,c),mp(d,e))));
}
void make_portal(int i,int j,int l){
    int r=i;
    while(way[r+1][j]!=0)r++;
    add(l,i,j,r,j);
    r=i;
    while(way[r-1][j]!=0)r--;
    add(l,i,j,r,j);
    r=j;
    while(way[i][r+1]!=0)r++;
    add(l,i,j,i,r);
    r=j;
    while(way[i][r-1]!=0)r--;
    add(l,i,j,i,r);

}
int main(){
    int ques;
    cin>>ques;
    FOR1(qu,ques){
        while(!q.empty())q.pop();
        FOR(i,20)FOR(j,20)way[i][j]=0;
        FOR(i,20)FOR(j,20)FOR(k,20)FOR(l,20)visit[i][j][k][l]=0;
        int n,m;
        cin>>n>>m;
        int si,sj;
        FOR1(i,n){
            FOR1(j,m){
                char a;
                scanf(" %c",&a);
                if(a=='.')way[i][j]=1;
                else if(a=='O'){
                    si=i;sj=j;
                    way[i][j]=1;
                }
                else if(a=='X')way[i][j]=2;
            }
        }
        make_portal(si,sj,0);
    printf("Case #%d: ",qu);
        int f=0;
        while(!q.empty()){
            int i=q.front().s.f.f;
            int j=q.front().s.f.s;
            int pi=q.front().s.s.f;
            int pj=q.front().s.s.s;
            int l=q.front().f;
            q.pop();
//found cake
            if(way[i][j]==2){
                printf("%d\n",l);
                f=1;
                break;
            }
//use portal ans make new portal
            if(way[i-1][j]==0||way[i+1][j]==0||way[i][j-1]==0||way[i][j+1]==0){
                make_portal(pi,pj,l+1);
                add(l+1,pi,pj,pi,pj);
            }
//walk and make new portal
            for(int x=-1;x<=1;x++){
                for(int y=-1;y<=1;y++){
                    if(abs(x)==abs(y))continue;
                    make_portal(i+x,j+y,l+1);
                }
            }

//walk
            for(int x=-1;x<=1;x++){
                for(int y=-1;y<=1;y++){
                    if(abs(x)==abs(y))continue;
                        add(l+1,i+x,j+y,pi,pj);
                }
            }
        }
        if(!f) printf("THE CAKE IS A LIE\n");
    }
}
