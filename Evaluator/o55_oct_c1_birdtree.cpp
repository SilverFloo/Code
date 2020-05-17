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
int main(){
    int n;
    cin>>n;
    while(n--){
        int f,s;
        char c;
        scanf("%d %c %d",&f,&c,&s);
        while(1){
            if(f<s){
                printf("L");
                swap(f,s);
                f-=s;
            }
            else{
                printf("R");
                swap(f,s);
                s-=f;
            }
            //printf("%d %d",f,s);
            if(s==1&&f==1)break;
        }
            printf("\n");
    }
}
