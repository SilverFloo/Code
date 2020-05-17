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
    char a[100005];
    char b[]="codecube";
    int x=0;
    int cnt=0;
    scanf("%s",a);
    FOR(i,strlen(a)){
        while(b[x%8]!=a[i]){x++;cnt++;}
        x++;
    }
    while(x%8!=0){x++;cnt++;}
    printf("%d",cnt);
}
