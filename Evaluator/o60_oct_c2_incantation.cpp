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
ll dp[200][200];
ll ans[200][200];
ll tmp[200][200];
    int n,k;
void merge(ll a[200][200],ll b[200][200],ll c[200][200]){
        for(int i=0;i<1<<(k-1);i++){
            for(int j=0;j<1<<(k-1);j++){
                for(int x=0;x<1<<(k-1);x++){
                    c[i][j]=max(a[i][x]+b[x][j],c[i][j]);
                  //  db(a[i][x]+b[x][j]);
                }
                //printf("%d ",c[i][j]);
            }//cout<<endl;
        }
}
int main(){
    rf();
    cin>>n>>k;
    n-=k-1;
    FOR(i,1<<k){
        scanf("%lld",&dp[i>>1][i&((1<<(k-1))-1)]);
       // printf("%d %d/",i>>1,i&((1<<(k-1))-1));
    }
    while(n!=0){
        if(n%2){
            for(int i=0;i<1<<(k-1);i++){
                for(int j=0;j<1<<(k-1);j++){
                    tmp[i][j]=ans[i][j];
                }
            }
            merge(tmp,dp,ans);
        }
        for(int i=0;i<1<<(k-1);i++){
            for(int j=0;j<1<<(k-1);j++){
               tmp[i][j]=dp[i][j];
            }
        }
       // printf("\n\nDP\n");
        merge(tmp,tmp,dp);
        n>>=1;
    }
    ll mx=0;
    for(int i=0;i<1<<(k-1);i++){
        for(int j=0;j<1<<(k-1);j++){
            mx=max(mx,ans[i][j]);
        }
    }
    cout<<mx;

}
