#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define db(a) printf("<%d> ",a)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_bajck
#define p emplace
#define ii pair<int,int>
#define ll long long
#define rf() freopen("_working/input.in","r",stdin)
#define pf() freopen("_working/output.out","w+",stdout)
using namespace std;
const int INF=1e9;
int tab[105][105];
int main(){
    rf();
    pf();
    int q;
    int n;
    cin>>q;
   FOR1(x,q){
       scanf(" %d",&n);
        FOR(i,n)FOR(j,n){
            tab[i][j]=0;
            if(abs(i-j)==1||i==j)tab[i][j]=1;
        }
        char c;
        FOR(i,n){
            cin>>c;
            if(c=='N'){
                if(i>0)tab[i-1][i]=0;
                if(i<n-1)tab[i+1][i]=0;
            }
        }
        FOR(i,n){
            cin>>c;
            if(c=='N'){
               if(i>0)tab[i][i-1]=0;
                if(i<n-1)tab[i][i+1]=0;
            }
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++)if(tab[i][k]&&tab[k][j])tab[i][j]=1;
            }
        }
        printf("Case #%d:\n",x);
        FOR(i,n){
            FOR(j,n)printf("%c",tab[i][j]?'Y':'N');
            cout<<endl;
        }
    }
}