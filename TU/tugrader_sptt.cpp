#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a-1;i>=b;i--)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
using namespace std;
const int INF=1e9;
char a[10000],b[10000];
map<string,int> m;
int main(){
    scanf("%s %s",a,b);
    int c=0;
    for(int i=strlen(a);i>=0;i--){
        a[i]++;
        int x=i;
        while(a[x]=='3'&&x>0){a[x]='0';a[x-1]++;x--;}
        a[i]='\0';
       // FOR(j,0,strlen(a))printf("%c",a[i]+'0');cout<<'\n';
        m[a]=c;
        c++;
    }
    c=0;
    for(int i=strlen(b);i>=0;i--){
            b[i]++;
        int x=i;
        while(b[x]=='3'&&x>0){b[x]='0';b[x-1]++;x--;}
        b[i]='\0';
        if(m.find(b)!=m.end()){int x=m[b]+c-1; printf("%d",x>0?x:0);exit(0);}
        //FOR(j,0,strlen(b))printf("%c",b[i]+'0');cout<<'\n';
        c++;
    }
}
