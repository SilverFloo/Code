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
pair<ii,int> l[100005];
int p[17][100005];
char s[100005];
int aa[100005];
int n;
int lcp(int a,int b){
    int cnt=0;
    for(int i=16;i>=0;i--){
        if(p[i][a]==p[i][b]){
            a+=1<<i;b+=1<<i;cnt+=1<<i;
            if(a>=n||b>=n)break;
        }
    }
    return cnt;
}
int main(){
    scanf("%s",s);
    n=strlen(s);
    FOR(i,n)p[0][i]=s[i]-'a';
    for(int i=1;i<17;i++){
        for(int j=0;j<n;j++){
            l[j].f.f=p[i-1][j];
            if(j+(1<<(i-1))<n)l[j].f.s=p[i-1][j+(1<<(i-1))];
            else l[j].f.s=-1;
            l[j].s=j;
        }
        sort(l,l+n);
        for(int j=0;j<n;j++){
            if(j>0&&l[j].f==l[j-1].f)p[i][l[j].s]=p[i][l[j-1].s];
            else p[i][l[j].s]=j;
        }
    }
    FOR(i,n-1)aa[i]=lcp(l[i].s,l[i+1].s);
   // FOR(i,n)printf("%d %s\n",aa[i],s+l[i].s);
    int q;
    cin>>q;
    while(q--){
            int x;
    scanf("%d",&x);
        int ans=0;
        int cnt=0;
        FOR(i,n-1){
            if(aa[i]>=x)cnt++;
            else ans=max(ans,cnt),cnt=0;
        }
        printf("%d\n",ans+1);
    }
}
