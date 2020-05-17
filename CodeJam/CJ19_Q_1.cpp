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
    int t;
    cin>>t;
    FOR1(tt,t){
        int n;
        char s[40];
        scanf("%d %s",&n,s);
        ll sum=0;
        int a[40];
        int p=0;
        a[0]=0;
        FOR(i,strlen(s)){
        if(s[i]=='C'){
            p++;
            a[p]=0;
        }
        else a[p]++,sum+=1<<p;
        }
        sum-=n;
        int cnt=0;
        while(sum>0){
            //printf("%d",sum);
        while(a[p]==0&&p>0)p--;
        if(p==0)break;
        a[p]--;
        a[p-1]++;
        sum-=1<<p;
        sum+=1<<(p-1);
        //printf("%d ",sum);
        cnt++;
        }
        printf("Case #%d: ",tt);
        if(sum>0)printf("IMPOSSIBLE\n");
        else printf("%d\n",cnt);
    }
}
