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
using namespace std;
const int INF=1e9;

int edge[50005][27];
int cnt[50005];
string s[1005];
int ans;
int find(int u){
   // printf("in");
    for(int i=0;i<26;i++){
        if(edge[u][i]!=0)cnt[u]+=find(edge[u][i]);
    }
    if(edge[u][26]==1){cnt[u]++;}
    //printf(" %d",cnt[u]);
    if(u!=0&&cnt[u]>=2)cnt[u]-=2,ans+=2;
    return cnt[u];
}
int main(){
    int c;
    cin>>c;
    FOR(k,c){
        ans=0;
        int n;;
        cin>>n;
        FOR(i,n)cin>>s[i];
        FOR(i,50005)FOR(j,27)edge[i][j]=0;
        FOR(i,50005)cnt[i]=0;
        int pos=0;
        int now=0;
       // printf("in");
        FOR(i,n){
            now=0;
            for(int j=s[i].size()-1;j>=0;j--){
                if(edge[now][s[i][j]-'A']==0)edge[now][s[i][j]-'A']=++pos;
                now=edge[now][s[i][j]-'A'];
            }
           // printf("%d>",now);
            edge[now][26]=1;
        }
        find(0);
        printf("Case #%d: %d\n",k,ans);

    }
}
