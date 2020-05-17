#include<bits/stdc++.h>
using namespace std;
int dp[(int)1e5+5];
const int MAX=85142019;
int main(){
char s[(int)1e5+5];
scanf("%s",s);
if(s[0]=='0'){printf("0");exit(0);}
for(int i=1;i<strlen(s);i++){if(s[i]=='0'&&s[i-1]>'2'){printf("0");exit(0);}}
dp[strlen(s)]=1;
dp[strlen(s)-1]=s[strlen(s)-1]=='0'?0:1;
for(int i=strlen(s)-2;i>=0;i--){
if(s[i]!='0')dp[i]+=dp[i+1];
if((s[i]-'0')*10+s[i+1]-'0'<=26&&s[i]!='0'){dp[i]+=dp[i+2];}
dp[i]%=MAX;
}
printf("%d",dp[0]);
}
