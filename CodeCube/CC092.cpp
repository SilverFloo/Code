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
double x[100005];
int main(){
    FOR1(i,100000){
    x[i]=log10(i);
    x[i]+=x[i-1];
    }
    int q;
    cin>>q;
    while(q--){
    int a;
    scanf("%d",&a);
    printf("%.0f\n",floor(x[a])+1);
    }
}
