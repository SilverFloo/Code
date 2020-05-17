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

int p[17][1000];
pair<ii,int> l[1000];
int n;

int lcp(int a,int b){
    int ans=0;
    int i=1;
    while(1<<(i-1)<n)i++;
    i--;
    for(;i>=0;i--){
        if(p[i][a]==p[i][b])a+=1<<i,b+=1<<i,ans+=1<<i;
        if(a>=n||b>=n)break;
    }
    return ans;
}
int main(){
    char s[1000];
    scanf("%s",s);
    n=strlen(s);
    FOR(i,n)p[0][i]=s[i]-'a';
    for(int i=1;1<<(i-1)<n;i++){
        for(int j=0;j<n;j++){
            l[j].f.f=p[i-1][j];
            l[j].f.s=j+(1<<(i-1))<n?p[i-1][j+(1<<(i-1))]:-1;
            l[j].s=j;
        }
        sort(l,l+n);
        for(int j=0;j<n;j++){
            if(j>0&&l[j].f==l[j-1].f)p[i][l[j].s]=p[i][l[j-1].s];
            else p[i][l[j].s]=j;
        }
        if(1<<i>n)FOR(j,n)printf("%s\n",s+l[j].s);
    }
    while(1){
        int a,b;cin>>a>>b;
        cout<<lcp(a,b)<<endl;

    }
}
