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
    char cc[]="codecube";
    scanf("%s",a);
    int ansl,ansr,ans=INF;
    int cnt=0;
    int now=0;
    int l,r;
    int nxt=-1;
    FOR(i,strlen(a)){
    //printf("<%d %d>",cnt,i);

    if(a[i]==cc[now]){
    if(now==0)l=i;
    now++;}
    else if(now!=0)cnt++;
    if(now==1&&a[i]=='c'){cnt=0;l=i;}

    if(a[i]=='c'&&now!=1&&nxt==-1){nxt=i;}

    if(now==8){r=i;

    if(cnt<ans){
    ans=cnt;
    ansr =r;
    ansl =l;
    }
    if(nxt!=-1)i=nxt-1;

    now=0;cnt=0;nxt=-1;
    }

    }
    if(ans==INF)printf("-1");
    else printf("%d %d",ansl+1,ansr+1);
}
//codeccubecodecube
