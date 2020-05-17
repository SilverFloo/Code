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
int mine[3][1005][1005];
int sum[3][1005][1005];
int mx1[3][1005][1005];
int last[1005][1005];
int main(){
    int n,x;
    cin>>n>>x;
    FOR(k,3){
        FOR1(i,n){
            FOR1(j,n){
                scanf("%d",&mine[k][i][j]);
                mine[k][i][j]+=mine[k][i][j-1]+mine[k][i-1][j]-mine[k][i-1][j-1];
            }
        }
    }
    FOR(k,3){
        FOR(i,n-x+1){
            FOR(j,n-x+1){
                sum[k][i][j]=mine[k][i+x][j+x]-mine[k][i][j+x]-mine[k][i+x][j]+mine[k][i][j];
            }
        }
    }
    if(n==x){
        printf("%d",sum[0][0][0]+sum[1][0][0]+sum[2][0][0]);
        return 0;

    }
    FOR(k,3){
        FOR(i,n-x+1){
        deque<int> q;
            for(int j=0;j<x-1;j++){
                while(!q.empty()&&sum[k][i][q.back()]<sum[k][i][j])q.pop_back();
                q.pb(j);
            }
            for(int j=x-1;j<n-x+1;j++){
                while(!q.empty()&&sum[k][i][q.back()]<sum[k][i][j])q.pop_back();
                q.pb(j);
                while(!q.empty()&&q.front()<=j-x)q.pop_front();
                mx1[k][i][j-x+1]=sum[k][i][q.front()];
            }
        }
    }


     FOR(k,3){
        FOR(j,n-x-x+2){
        deque<int> q;
            for(int i=0;i<x-1;i++){
                while(!q.empty()&&mx1[k][q.back()][j]<mx1[k][i][j])q.pop_back();
                q.pb(i);
            }
            for(int i=x-1;i<n-x+1;i++){
                while(!q.empty()&&mx1[k][q.back()][j]<mx1[k][i][j])q.pop_back();
                q.pb(i);
                while(!q.empty()&&q.front()<=i-x)q.pop_front();
                sum[k][i-x+1][j]=mx1[k][q.front()][j];
            }
        }
    }

    FOR(k,3){
        FOR(i,n-x-x+2){
            FOR(j,n-x-x+2){
                last[i][j]+=sum[k][i][j];
            }
        }
    }
    int ans=0;
    FOR(i,n-x-x+2){FOR(j,n-x-x+2){ans=max(ans,last[i][j]);}}
    cout<<ans;
}
/*

3 3
1 2 3
4 5 6
7 8 9
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1

*/
