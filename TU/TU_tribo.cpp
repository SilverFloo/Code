#include<bits/stdc++.h>
using namespace std;
long long fib[65][3][3]={1,1,1,1,0,0,0,1,0};
const int MAX=1e9+9;
void mul(long long a[3][3],long long b[3][3],long long c[3][3]){
long long xx[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){xx[i][j]=0;
            for(int k=0;k<3;k++){xx[i][j]+=a[i][k]*b[k][j]%MAX;
            xx[i][j]%=MAX;
            }
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
          c[i][j]=xx[i][j];
        }
    }
}
    int main(){
    //fib[0]={1,1,1,1,0,0,0,1,0};
    long long n;
    scanf("%lld",&n);
    for(int i=1;i<65;i++){
        mul(fib[i-1],fib[i-1],fib[i]);
    }
    long long ans[3][3]={1,0,0,0,1,0,0,0,1};
    int c=0;
    while(n>0){
        if(n%2)mul(ans,fib[c],ans);
        c++;n>>=1;
    }
    printf("%lld",ans[0][0]-ans[0][2]<0?ans[0][0]-ans[0][2]+MAX:ans[0][0]-ans[0][2]);

}

