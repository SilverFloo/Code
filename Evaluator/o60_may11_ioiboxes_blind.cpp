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
int t[105][105];
ii visit[105][105];
ii fr[105][105];
ii par[105][105];
ii now = {0,0};
int tab(int i,int j){
    return t[i+50][j+50];
}
void up(int i,int j,int x){
    t[i+50][j+50]=x;
}
void print(ii x){
    if(par[x.f+50][x.s+50]==mp(-INF,-INF))return;
    //printf("<%d %d %d %d>",x.f,x.s,par[x.f+50][x.s+50].f,par[x.f+50][x.s+50].s);
    
    print(par[x.f+50][x.s+50]);
    if(par[x.f+50][x.s+50]==mp(x.f-1,x.s)){
        printf("U");
    }
    if(par[x.f+50][x.s+50]==mp(x.f+1,x.s)){
        printf("D");
    }
    if(par[x.f+50][x.s+50]==mp(x.f,x.s-1)){
        printf("R");
    }
    if(par[x.f+50][x.s+50]==mp(x.f,x.s+1)){
        printf("L");
    }
}
int walk(ii st,ii ed){
    FOR(i,105)FOR(j,105)par[i][j]={INF,INF};
    queue<pair<ii,ii>> q;
    q.p(st,mp(-INF,-INF));
    par[st.f+50][st.s+50]={-INF,-INF};
    while(!q.empty()&&q.front().f!=ed){
        int i=q.front().f.f,j=q.front().f.s;
        q.pop();
        if(tab(i-1,j)!=1)if(par[i+50-1][j+50]==mp(INF,INF))q.p(mp(i-1,j),mp(i,j)),par[i+50-1][j+50]={i,j};
        if(tab(i,j-1)!=1)if(par[i+50][j+50-1]==mp(INF,INF))q.p(mp(i,j-1),mp(i,j)),par[i+50][j+50-1]={i,j};
        if(tab(i+1,j)!=1)if(par[i+50+1][j+50]==mp(INF,INF))q.p(mp(i+1,j),mp(i,j)),par[i+50+1][j+50]={i,j};
        if(tab(i,j+1)!=1)if(par[i+50][j+50+1]==mp(INF,INF))q.p(mp(i,j+1),mp(i,j)),par[i+50][j+50+1]={i,j};
    }
    if(q.empty())return-1;
    //printf("%d %d",par[1][0].f,par[1][0].s);
    print(ed);
    return 0;
}

int main(){
    pf();
    printf("UUUUUUUUUUU");
    printf("R");
    printf("UUUUUUUUUUU");
    printf("L");
    printf("DDDDDDDDDDD");
    printf("RRRRRRRRRR");
    for(int i=10;i>=-10;i--){
        printf("DDDDDDDDDDD");
        if(i!=-10)printf("UUUUUUUUUUU");
        printf("L");
    }
    printf("D");
    for(int i=9;i>=1;i--){
        for(int j=0;j<10*i;j++){
            printf("R");
        }
        if(i!=1)for(int j=0;j<10*i;j++){
            printf("L");
        }
        if(i!=1)printf("D");
        
    }
    printf("LLLLLLLLLLDDRRRRRRRRRRRRRRRRRRRRRULLLLLLLLLLDLLLLLLLLLLLUURRRRRRRRRR");
    for(int i=0;i<9;i++){
        printf("U");
        for(int k=0;k<10;k++){
            printf("R");
            for(int j=0;j<=i;j++){
                printf("D");
            }
            if(i==8&&k==9)continue;
            for(int j=0;j<=i;j++){
                printf("U");
            }
        }
    }
    printf("RD");
    for(int i=0;i<90;i++){
        printf("L");
     }
    now = {-10,0};
    for(int i=-10;i>0;i--)up(-10,i,1);
    walk(now,{-11,-10});
    printf("UUUUU");
    up(-10,-10,0);
    up(-5,-10,1);
    now = {-6,-10};

    
   
    walk(now,{-11,-9});
    printf("UUURUL");
    up(-10,-9,0);
    up(-7,-10,1);
    now = {-7,-9};


    walk(now,{-11,-8});
    now = {-11,-8};
    printf("UURULL");
    up(-10,-8,0);
    up(-8,-10,1);
    now = {-8,-9};

    walk(now,{-11,-7});
    printf("UUURUL");
    up(-10,-7,0);
    up(-7,-8,1);
    now = {-7,-7};

    
    
    walk(now,{-11,-6});
    up(-10,-6,0);
    up(-8,-8,1);
    printf("UURULL");
    now = {-8,-7};

    
      
    walk(now,{-11,-5});
    printf("UUURULL");
    up(-10,-5,0);
    up(-7,-7,1);
    now = {-7,-6};


    walk(now,{-11,-4});
    printf("UURULLL");
    up(-10,-4,0);
    up(-8,-7,1);
    now = {-8,-6};

    // for(int i=10;i>=-10;i--){
    //     for(int j=-20;j<=20;j++){
    //         printf("%d",tab(i,j));
    //     }cout<<endl;
    //  }
    
    walk(now,{-11,-3});
    printf("UUUUURULL");
    up(-10,-3,0);
    up(-5,-5,1);
    now = {-5,-4};

    
    walk(now,{-11,-2});
    printf("UUURULLL");
    up(-10,-2,0);
    up(-7,-5,1);
    now = {-7,-4};
    
    walk(now,{-11,-1});
    printf("UURULLLL");
    up(-10,-1,0);
    up(-8,-5,1);
    now = {-8,-4};

}