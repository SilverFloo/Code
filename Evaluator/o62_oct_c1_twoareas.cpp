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
#define rf() freopen("input.txt","r",stdin)
using namespace std;
const int INF=1e9;
int tab[305][305];
int up[305][305][305],down[305][305][305];
int get(int i1,int j1,int i2,int j2){
    return tab[i2][j2]+tab[i1-1][j1-1]-tab[i2][j1-1]-tab[i1-1][j2];
}
int main(){
   //rf();
    int n,m;
    cin>>m>>n;
    FOR1(i,n)FOR1(j,m)scanf("%d",&tab[i][j]),tab[i][j]+=tab[i-1][j]+tab[i][j-1]-tab[i-1][j-1];
    //FOR1(i,n){FOR1(j,m)printf("%d ",tab[i][j]);cout<<endl;}
    for(int i=1;i<=m;i++){
        for(int j=i;j<=m;j++){
            int mn=0;
            down[i][j][0]=-INF;
            for(int k=1;k<=n;k++){
                down[i][j][k]=max(down[i][j][k-1],get(1,i,k,j)-mn);
                mn=min(get(1,i,k,j),mn);
               // printf("%d %d %d %d\n",i,j,k,down[i][j][k]);
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=i;j<=m;j++){
            int mn=0;
            up[i][j][n+1]=-INF;
            for(int k=n;k>0;k--){
                up[i][j][k]=max(up[i][j][k+1],get(k,i,n,j)-mn);
                mn=min(get(k,i,n,j),mn);
               // printf("%d %d %d %d\n",i,j,k,up[i][j][k]);
            }
        }
    }
    int ans=-INF;
    for(int i=1;i<=m;i++){
        for(int j=i;j<=m;j++){
            for(int k=2;k<=n-1;k++){
                if(down[i][j][k-1]+up[i][j][k+1]>ans)ans = down[i][j][k-1]+up[i][j][k+1];
            }
        }
    }

     for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
int mn=0;
            up[i][j][0]=-INF;
             for(int k=1;k<=m;k++){
                down[i][j][k]=max(down[i][j][k-1],get(i,1,j,k)-mn);
                mn=min(get(i,1,j,k),mn);
               // printf("%d %d %d %d\n",i,j,k,down[i][j][k]);
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int mn=0;
            up[i][j][n+1]=-INF;
            for(int k=m;k>0;k--){
                up[i][j][k]=max(up[i][j][k+1],get(i,k,j,m)-mn);
                mn=min(get(i,k,j,m),mn);
                //printf("%d %d %d %d\n",i,j,k,up[i][j][k]);
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int k=2;k<=m-1;k++){
                if(down[i][j][k-1]+up[i][j][k+1]>ans)ans = down[i][j][k-1]+up[i][j][k+1];
            }
        }
    }
    printf("%d",ans);
}
