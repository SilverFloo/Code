#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<(a);i++);
using namespace std;
int main(){
int s[300];int a,b,c;
scanf("%1d%1d%1d",&a,&b,&c);
s[0]=a-1;
s[1]=b-1;
s[2]=c-1;
char input[300];
scanf("%s",input);
for(int i=0;i<strlen(input);i++){
printf("%d",(s[2]+(s[1]+(s[0]+input[i]-'1')%9)%9)%9+1);
s[0]+=a;s[0]%=9;
s[1]--;if(s[1]<0)s[i]+=9;
s[2]+=c;s[2]%=9;
}

}
