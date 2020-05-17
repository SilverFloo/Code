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
ll tab[505][505];
ll sum[505];
int ch[505];
void makeTriangle() {
    int i, j;
    tab[0][0] = 1;

    for(i = 1; i < 505; i++) {
        tab[i][0] = 1;
        for(j = 1; j <= i; j++) {
            tab[i][j] = tab[i - 1][j - 1] + tab[i - 1][j];
            sum[i]+=tab[i][j];
        }
    }
}

ll C(int n, int r) {
    return tab[n][r];
}

int main(){
    makeTriangle();
    int t;
    cin>>t;
    FOR1(k,t){
        FOR(i,505)ch[i]=0;
        int n;
        cin>>n;
        int x=n;
        int cnt=1;
        while(x!=0){
            x/=2;
            cnt++;
        }
        cnt-=2;

        for(int i=cnt;i>=0;i--){
               // printf("%d %d/%d\n",n,(int)1<<i,i);
            if(n-(1<<i)>=i){
                ch[i]=1;
                n-=(1<<i);
            }
            else {
                n--;
            }
        }
        //printf("//%d//",n);
        cnt+=n;
        int di=0;
        int d=1;
        printf("Case #%d:\n",k);
        for(int line=0;line<=cnt;line++){
                //printf("<%d>\n",ch[line]);

            if(ch[line]==1){
                if(di==0){
                    for(int i=1;i<=line+1;i++){
                        printf("%d %d\n",line+1,i);
                    }
                }else{
                    for(int i=1;i<=line+1;i++){
                        printf("%d %d\n",line+1,line-i+2);
                    }
                }
                swap(di,d);
            }
            else {
                if(di==0){
                    printf("%d 1\n",line+1);
                }
                else{
                    printf("%d %d\n",line+1,line+1);
                }
            }
        }

    }
}
