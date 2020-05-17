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
int main(){
    int n;
    int x=1,y=1,z=1;
    cin>>n;
    int bf=-1;
    FOR(i,n){
        int a;
        scanf("%d",&a);
        if(a==10)y++;
        if(a==13)z++;
        if(a==10&&bf==13)x++;
        bf=a;
        }
        printf("%d %d %d",x,y,z);
}
