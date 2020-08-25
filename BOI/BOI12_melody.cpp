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
string type[105];
int dist[105][105];
pair<int,ii> distbf[105][105];
int tab[100005],dp[100005];
set<int> b[100005];
int bf[100005];
int n,l,g;
int cnt = 0;
void print(int i,int j){
    //printf("<%d %d>",i+1,j+1);
    if(distbf[i][j]==mp(-1,mp(-1,-1))){
        printf("%d ",i+1);
        cnt++;
        //db(cnt);
        return;
    }
    print(distbf[i][j].f,distbf[i][j].s.f);
    print(distbf[i][j].s.f,distbf[i][j].s.s);
}
int diff(string a,string b){
    int cnt = 0;
    FOR(i,l){
        if(a[i]!=b[i])cnt++;
    }
    return cnt;
}
void printans(int n){
    if(n==-1)return;
    printans(bf[n]);
    if(bf[n]!=-1)print(tab[bf[n]],tab[n]);
    while(cnt<n)printf("%d ",tab[n]+1),cnt++;
}
int main(){
    //rf();
    // freopen("melody.in","r",stdin);
    // freopen("melody.out","w+",stdout);
    cin>>n>>l>>g;
    FOR(i,n){
        cin>>type[i];
    }
    FOR(i,n){
        FOR(j,n)dist[i][j]=INF,distbf[i][j]={-1,{-1,-1}};
    }
    FOR(i,n){
        dist[i][i]=1;
        FOR(j,n)if(diff(type[i],type[j])<=g){
            dist[i][j]=1;//printf("<%d %d>",i,j);
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                    distbf[i][j]={i,{k,j}};
                }
            }
        }
    }
    // FOR(i,n){
    //     FOR(j,n)printf("%d ",dist[i][j]);
    //     cout<<endl;
    // }
    int m;
    cin>>m;
    FOR(i,m){
        scanf("%d",&tab[i]);
        tab[i]--;
        bf[i]=-1;
    }

    b[tab[0]].p(0);
    FOR(i,m)dp[i]=1;
    int ans = -1;
    int mx = 0;
    for(int i=0;i<m;i++){
        FOR(j,n){
            auto x = b[j].upper_bound(i-dist[tab[i]][j]);
            if(x==b[j].begin())continue;
            x--;
            //printf("< %d , %d >",i-dist[tab[i]][j],*x);
            if(dp[*x]+1>dp[i]){  
                dp[i] = dp[*x]+1;
                bf[i] = *x;
            }
        }
        b[tab[i]].p(i);  
        if(dp[i]>mx){
            ans = i;
            mx = dp[i];
        }
        //printf("%d %d\n",dp[i],bf[i]);
    }
    printf("%d\n",m-mx);
    printans(ans);
    printf("%d ",tab[ans]+1);
    cnt++;
    while(cnt<m)printf("%d ",tab[ans]+1),cnt++;
}