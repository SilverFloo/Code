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
int val[20005];
int lv[20005];
int dp[2][20005];
int main(){
    int n, m, k;
    cin>>n>>m>>k;
    int bf = 0;
    FOR(i, m){
        int x;
        scanf("%d", &x);
        val[i] = x-bf;
        bf = x;
    }
    val[m] = n-bf;
    m++;
    FOR(i, k) scanf("%d", &lv[i]);
    int now = 0, pre = 1;
    FOR(i, k){
    int mx = 0;
        for(int j = i ; j < m; j++){
            if(j)mx = max(mx, dp[pre][j-1]);
            mx += lv[i]*val[j];
            dp[now][j] = mx;
            //printf("%d ",mx);
        }
       // printf("\n");
        swap(now, pre);
    }
    printf("%d", dp[pre][m-1]);
}
