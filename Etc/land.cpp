#include<bits/stdc++.h>
#define p pair<int,int>
#define pp pair<int,pair<int,int>>
#define s second
#define f first
bool visit[5][5];
using namespace std;
int main(){
int n,m;
cin>>n>>m;
double tab[n+2][m+2];

for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        pair<int,p> x;scanf("%lf",&tab[i][j]);}
double ans=0;
for(int k=0;k<n*m;k++){

int i,j;double M=2e9;
for(int x=1;x<=n;x++){
    for(int y=1;y<=m;y++){if(tab[x][y]<M&&!visit[x][y]){M=tab[x][y];i=x;j=y;}}

}
visit[i][j]=1;
    ans+=tab[i][j];
    tab[i-1][j-1]+=0.1*tab[i][j];
    tab[i-1][j+1]+=0.1*tab[i][j];
    tab[i+1][j+1]+=0.1*tab[i][j];
    tab[i+1][j-1]+=0.1*tab[i][j];
    tab[i][j-1]+=0.1*tab[i][j];
    tab[i][j+1]+=0.1*tab[i][j];
    tab[i-1][j]+=0.1*tab[i][j];
    tab[i+1][j]+=0.1*tab[i][j];
}
printf("%.2f",ans);
}
