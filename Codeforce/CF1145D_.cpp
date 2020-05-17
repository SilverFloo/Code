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
int tab[10];
int main(){
    int n;
    cin>>n;
    int cnt=0;
    FOR(i,n){
        scanf("%d",&tab[i]);
        cnt+=floor(log2(tab[i]));
    }
//printf("%d",n-1);
    printf("%d",cnt);
}
