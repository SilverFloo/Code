#include<bits/stdc++.h>
using namespace std;
main(){
int tab[9][9];
int n;
scanf("%d",&n);
for(int i=0;i<9;i++){
for(int j=0;j<9;j++)scanf("%d",&tab[i][j]);
}
for(int k=0;k<n;k++){
int t[9][9];int check=1;
for(int i=0;i<9;i++){
for(int j=0;j<9;j++){scanf("%d",&t[i][j]);
if(tab[i][j]!=0&&tab[i][j]!=t[i][j])check=0;
}}
if(check){
bool ch[9];
for(int i=0;i<9;i++){
for(int j=0;j<9;j++){ch[j]=0;}
for(int j=0;j<9;j++){ch[t[i][j]-1]=1;}
for(int j=0;j<9;j++){if(ch[j]!=1){check=0;}}
}
for(int i=0;i<9;i++){
for(int j=0;j<9;j++){ch[j]=0;}
for(int j=0;j<9;j++){ch[t[j][i]-1]=1;}
for(int j=0;j<9;j++){if(ch[j]!=1)check=0;}
}

}
if(check)printf("%d\n",k+1);
}
printf("END");
}
