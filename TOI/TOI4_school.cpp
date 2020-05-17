#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
using namespace std;
const int INF=1e9;
int mx=0;
bool visit[70][70];
char cc[70][70];

int n,m;
void flood(int i,int j){
    if(i<0||j<0||i>=n||j>=m)return;
    if(cc[i][j]!='P')return;
    if(visit[i][j]==1)return;
visit[i][j]=1;
flood(i-1,j);
flood(i,j-1);
flood(i+1,j);
flood(i,j+1);
}


int pr(){

    FOR(i,n){
    FOR(j,m){   printf("%d",visit[i][j]);
    }printf("\n");
    }

}


int find(int a,int b){
    int ans=0;
    FOR(i,mx){
    FOR(j,mx){if(cc[a+i][b+j]=='P'&&!visit[a+i][b+j]){flood(a+i,b+j);ans++;//printf("%d ",ans);//pr();
    }
   // printf("%c",ff[i][j]);

    }//printf("\n");
    }
    return ans;
}
int main(){
vector<pair<int,int>> a;

cin>>m>>n;
int tab[n][m];
FOR(i,n){
FOR(j,m){
scanf(" %c",&cc[i][j]);
tab[i][j]=cc[i][j]=='T'?0:1;
}
}
FOR(i,n){
FOR(j,m){
if(tab[i][j]==1)if(i>0&&j>0)tab[i][j]=min(tab[i-1][j],min(tab[i][j-1],tab[i-1][j-1]))+1;
if(tab[i][j]>mx){a.resize(0);mx=tab[i][j];a.pb(i-mx+1,j-mx+1);}
else if(tab[i][j]==mx)a.pb(i-mx+1,j-mx+1);
}
}
int mn=2e9;
printf("%d",mx*mx);
for(auto ss:a){
        int x=find(ss.f,ss.s);
        mn=min(x,mn);
        FOR(i,70)FOR(j,70)visit[i][j]=0;
}
    printf(" %d",mn);
}
/*
5 5
TSSST
SSPPP
SPPST
PSSSS
SPSPS
*/
