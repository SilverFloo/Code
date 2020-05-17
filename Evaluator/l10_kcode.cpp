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
    char key[]="UUDDLRLRBAS";
    char a[105];
    scanf("%s",a);
    for(int i=max(0,(int)(strlen(a)-strlen(key)));i<strlen(a);i++){
        int j=0;
        for(;i+j<strlen(a)&&j<strlen(key);j++){
            if(key[j]!=a[i+j]){break;}
        }
        if(i+j==strlen(a)){for(;j<strlen(key);j++)printf("%c",key[j]);
        exit(0);
        }

    }
    printf("UUDDLRLRBAS");
}
