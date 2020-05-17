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
vector<int> l[50005],f[50005];
int st[50005];
int dp[2][50][50];
int n,c;
int check(int i,int j){
    for(auto x:l[i]){
            int y=(x-st[i]+n)%n;
            y=4-y;
        if(((1<<y)&j)!=0)return 1;
    }
    for(auto x:f[i]){
        int y=(x-st[i]+n)%n;
        y=4-y;
        if(((1<<y)&j)==0)return 1;
    }
    return 0;
}
int main(){
    cin>>n>>c;
    FOR(i,c){
        int a,b,c;
        scanf("%d %d %d",&st[i],&a,&b);
        st[i]--;
        while(a--){
            scanf("%d",&c);
            c--;
            f[i].pb(c);
        }
        while(b--){
            scanf("%d",&c);
            c--;
            l[i].pb(c);
        }
    }
    int ptr=0;
    int now=0,bf=1;
    FOR(i,n){
        for(int j=0;j<1<<5;j++){
            int tmp=ptr;
            int h=0;
            while(st[tmp]==i&&tmp<c){
                    h+=check(tmp,j);
                    tmp++;
            }
            for(int k=0;k<1<<5;k++){
                if(i==0&&j!=k)dp[now][k][j]=-INF;
                else if(i>0)dp[now][k][j]=h+max(dp[bf][k][j>>1],dp[bf][k][(j>>1)|(1<<4)]);
                else dp[now][k][j]=h;
               // if(dp[i][k][j]>0&&h>0)printf("%d %d %d %d\n",i,k,j,dp[i][k][j]);
            }
        }
        while(st[ptr]==i&&ptr<c){
            ptr++;
        }
        swap(bf,now);
    }
    int ans=0;
    FOR(i,1<<5){
        ans=max(ans,max(dp[bf][i][i>>1],dp[bf][i][(i>>1)|(1<<4)]));
    }
    printf("%d" ,ans);

}
