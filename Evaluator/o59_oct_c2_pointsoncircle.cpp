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
int pt[2][1005];
int ans[1005];
int main(){
    int n,m;
    cin>>n>>m;
    FOR(i,m)scanf("%d",&pt[0][i]);
    FOR(i,m)scanf("%d",&pt[1][i]);
    ans[0]=0;
    ans[1]=pt[0][1];
    int x=ans[1];
    for(int i=2;i<m;i++){
        int a=pt[0][i];
        int b=pt[1][i];
        if(abs(a-b)==x){
            if(a>b)ans[i]=x+b;
            else ans[i]=n-a;
        }
        else if(a+b==x)ans[i]=a;
        else ans[i]=x+b;
    }
    FOR(i,m)printf("%d\n",ans[i]);
}
