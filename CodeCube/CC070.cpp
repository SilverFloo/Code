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
int a[200005],b[200005];
int main(){
    int n;
    cin>>n;
    FOR(i,n){scanf("%d",&a[i]);}
    FOR(i,n)scanf("%d",&b[i]);
    int i=0;
    int cnt=0;
    FOR(j,n){
        if(a[i]==b[j])i++,cnt++;
    }
    printf("%d",n-cnt);
}
