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
#define ll long long
using namespace std;
const int INF=1e9;
bitset<2005> tab[10005];
    int n,m;
int a[3];
void check(int i,int j){
//printf("%d %d\n",i,j);
    vector<int> ans;
        while(tab[i][j]){
        int cnt=0;
        int tj=j;
        //printf("\n%d:",i);
        while(tj<m&&tab[i][tj]){
         //   printf("%d ",tj);
            tab[i][tj]=0;
            tj++;
            cnt++;
        }
        ans.pb(cnt);
        if(j>0&&tab[i+1][j-1]){j--;}
        else if(tab[i+1][j]){}
        else if(j<m-1&&tab[i+1][j+1]){j++;}
        else break;
        i++;
    }
    if(ans[0]==ans[1])a[0]++;
    else if(ans[1]==ans[0]+2&&ans[0]==ans[ans.size()-1])a[1]++;
    else a[2]++;
}
int main(){
    cin>>m>>n;
    FOR(i,n){FOR(j,m){
    char x;
    scanf(" %c",&x);
    tab[i][j]=x=='0'?0:1;
    }}
    FOR(i,n){
        FOR(j,m){
            if(tab[i][j])check(i,j);
        }
    }
    printf("%d %d %d",a[0],a[1],a[2]);
}
