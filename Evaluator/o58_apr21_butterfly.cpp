/*#include<bits/stdc++.h>
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
int main(){
    int k,n;
    cin>>k>>n;

    while(n--){
        ii a,b; int cnt=0;
        scanf("%d %d %d %d",&a.f,&a.s,&b.f,&b.s);
        for(int i=0;i<k+1;i++){
            if((a.f^b.f)==0)break;
            if(((a.f&(1<<i))^(b.f&(1<<i)))!=0){
                    //printf("<%d>",a.f|(1<<i));
                if((a.f&(1<<i))==0){
                    a.f|=(1<<i);
                }
                else{
                    a.f&=~(1<<i);
                }
            }
            a.s++;
            cnt++;
            printf("%d %d>",a.f,a.s);
        }
        printf("%d\n",cnt+abs(b.s-a.s));
    }
}
*/
