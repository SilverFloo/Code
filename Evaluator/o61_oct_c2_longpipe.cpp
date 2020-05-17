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
ll mod = 1e9+7;
ll ans[3][3]={1,0,0,0,1,0,0,0,1};
ll dp[3][3]={1,1,1,2,1,0,1,0,1};
void mul(ll a[3][3],ll b[3][3]){
   ll c[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            c[i][j]=a[i][j];
            a[i][j]=0;
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                a[i][j]+=c[i][k]*b[k][j];
                a[i][j]%=mod;
            }
        }
    }
}
void muldp(ll a[3][3]){
    ll b[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            b[i][j]=a[i][j];
            a[i][j]=0;
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                a[i][j]+=(b[i][k]*b[k][j])%mod;
                a[i][j]%=mod;
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    while(n>0){
        if(n%2==1)mul(ans,dp);
        muldp(dp);
        n>>=1;

    }
    printf("%d",(2*(ans[0][0]+ans[0][1])+ans[1][1]+ans[1][0])%mod);
}
