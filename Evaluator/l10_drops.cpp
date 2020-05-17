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
int x[5005];
int main(){
    int h,l,n;
    scanf("%d %d %d",&h,&l,&n);
    int r=h+l;
    FOR(i,n){
        int a;
        scanf("%d",&a);
        x[a]++;
    }
    int mx=0;
    for(int i=l;i<=r;i++)if(x[i]>mx)mx=x[i];
    printf("%d",mx);
}
