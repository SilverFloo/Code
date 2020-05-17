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
bool p[1005][1005];
int main(){
    int n;
    cin>>n;
    int cnt=0;
    FOR(i,n){
    int x,y;
    scanf("%d %d",&x,&y);
    if(!p[x][y]){cnt++;p[x][y]=1;}
    }
    printf("%d",cnt);
}
