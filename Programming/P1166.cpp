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
using namespace std;
const int INF=1e9;
int tab[35][35];
int n,m,cnt;

void go(int i,int j){
    if(tab[i][j]!=1)return;
    tab[i][j]=0;
    cnt++;
    go(i-1,j);
    go(i+1,j);
    go(i,j-1);
    go(i,j+1);
}

int main(){
    scanf("%d %d",&n,&m);
    char a[n+2][m+2];
    FOR1(i,n){
        FOR1(j,m){
            scanf(" %c",&a[i][j]);
            if(a[i][j]=='.')tab[i][j]=1;
        }
    }
    FOR1(i,n){
        FOR1(j,m){
            if(a[i][j]=='#'){
                tab[i-1][j]=0;
                tab[i+1][j]=0;
                tab[i][j-1]=0;
                tab[i][j+1]=0;
            }
        }
    }
    int M=0;
    FOR1(i,n){
        FOR1(j,m){
            if(tab[i][j]==1){
                cnt=0;
                go(i,j);
                if(M<cnt)M=cnt;
            }
        }
    }
    printf("%d",M);
}
