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
int tab[1505][1505],dpul[1505][1505],dpur[1505][1505],dpdl[1505][1505],dpdr[1505][1505];
int tmp[1505];
int main(){
    //rf();
    int n,m;
    cin>>n>>m;
    FOR(i,n)FOR(j,m)scanf("%d",&tab[i][j]);
    FOR(i,n){
        FOR(j,m){
            if(i==0&&j==0){dpul[i][j]=tab[i][j];continue;}
            int a = INF;
            int b = INF;
            if(i>0)a=dpul[i-1][j];
            if(j>0)b=dpul[i][j-1];
            dpul[i][j]=min(a,b)+tab[i][j];
        }
    }

    FOR(i,n){
        for(int j=m-1;j>=0;j--){
            if(i==0&&j==m-1){dpur[i][j]=tab[i][j];continue;}
            int a = INF;
            int b = INF;
            if(i>0)a=dpur[i-1][j];
            if(j<m-1)b=dpur[i][j+1];
            dpur[i][j]=min(a,b)+tab[i][j];
        }
    }

    for(int i=n-1;i>=0;i--){
        FOR(j,m){
            if(i==n-1&&j==0){dpdl[i][j]=tab[i][j];continue;}
            int a = INF;
            int b = INF;
            if(i<n-1)a=dpdl[i+1][j];
            if(j>0)b=dpdl[i][j-1];
            dpdl[i][j]=min(a,b)+tab[i][j];
        }
    }

    for(int i=n-1;i>=0;i--){
        for(int j=m;j>=0;j--){
            if(i==n-1&&j==m-1){dpdr[i][j]=tab[i][j];continue;}
            int a = INF;
            int b = INF;
            if(i<n-1)a=dpdr[i+1][j];
            if(j<m-1)b=dpdr[i][j+1];
            dpdr[i][j]=min(a,b)+tab[i][j];
        }
    }
    int ans = INF;
    for(int i=0;i<n;i++){
        tmp[m]=INF;
        for(int j=m-1;j>=0;j--){
            tmp[j]=min(tmp[j+1]+tab[i][j],dpur[i][j]+dpdr[i][j]-tab[i][j]);
        }
        for(int j=0;j<m;j++){
            ans = min(ans,dpdl[i][j]+dpul[i][j]-tab[i][j]+tmp[j+1]);
        }
    }

    for(int j=0;j<m;j++){
        tmp[n]=INF;
        for(int i=n-1;i>=0;i--){
            
            tmp[i]=min(tmp[i+1]+tab[i][j],dpdl[i][j]+dpdr[i][j]-tab[i][j]);
            
            
        }
        for(int i=0;i<n;i++){
            ans = min(ans,dpul[i][j]+dpur[i][j]-tab[i][j]+tmp[i+1]);
        }
    }
    printf("%d",ans);

}