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
int tab[1000005];
int main(){
    int n;
    cin>>n;
    FOR(i,n){
    int a,b;
    scanf("%d %d",&a,&b);
    tab[a]++;tab[b]--;
    }
    int cnt=0;
    int mx=-1;
    FOR(i,1000005){
    cnt+=tab[i];
    if(cnt>mx)mx=cnt;
    }
    printf("%d",mx);
}
