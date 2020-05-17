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
int tab[26][26];
    char a[1000005],b[1000005];
    int ans[1000005];

int main(){
    scanf("%s %s",a,b);
    FOR(i,26)FOR(j,26){
    tab[i][j]=((i-j)+26)%26;
    }
    int x=strlen(a);
    FOR(i,x){
    ans[i]=tab[tolower(a[i])-'a'][tolower(b[i])-'a'];
    if(ans[i]>=10){printf("R.I.P.");return 0;}
    }
    FOR(i,x)printf("%d",ans[i]);
}
