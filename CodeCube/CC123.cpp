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
#define rf() freopen("input.txt","r",stdin)
using namespace std;
const int INF=1e9;
char a[1000005],b[1000005];
int lps[1000005];
int cnt[1000005];
int main(){
    int T;
    cin>>T;
    while(T--){
        scanf("%s %s",a,b);
        int j=0,i=1;
        while(b[i]!='\0'){
            if(b[i]==b[j]){
                lps[i]=j+1;
                i++;j++;
            }
            else{
                if(j!=0)j=lps[j-1];
                else i++;
            }
        }
        i=0;j=0;vector<ii> q;
        i=0;
        while(a[i]!='\0'){
            //printf("%d %d\n",i,j);
            if(a[i]==b[j]){
                cnt[i]=j;
                i++;j++;
                if(b[j]=='\0'){
                    int st=i-j;
                    while(!q.empty()&&st<=q.back().s)st-=q.back().s-q.back().f,q.pop_back();
                   //printf("<%d %d>",st,i);
                    j=cnt[st-1]+1;
                    q.pb(st,i);
                }
            }
            else{
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    cnt[i]=-1;
                    i++;
                }
            }
        }
        i=0;
        //while(a[i]!='\0')printf("%d ",cnt[i]),i++;
        i=0;
        int ch=0;
        int cnt=0;
        while(a[i]!='\0'){
            if(cnt!=q.size()&&i==q[cnt].f){
                i=q[cnt].s;
                cnt++;
            }
            if(a[i]=='\0')break;
            printf("%c",a[i]);
            ch=1;
            i++;
        }
        if(!ch)printf("No COI Secret Code");
        printf("\n");
    }
}
