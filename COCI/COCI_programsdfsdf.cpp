#include<bits/stdc++.h>
main(){
char s[50005];
scanf("%s",s);
int buc[strlen(s)+1][26];
for(int i=0;i<strlen(s)+1;i++){
for(int j=0;j<26;j++){if(i==0)buc[0][j]=0;
else buc[i][j]=buc[i-1][j];
}
buc[i][s[i-1]-'a']++;
}
int n;
scanf("%d",&n);
for(int i=0;i<n;i++){
int a,b,c,d;scanf("%d %d %d %d",&a,&b,&c,&d);
if(b-a!=d-c){printf("NE\n");}
else {int che=0;
for(int j=0;j<26;j++){
if(buc[b][j]-buc[a-1][j]!=buc[d][j]-buc[c-1][j]){
che=1;}
}
if(che)printf("NE\n");
else printf("DA\n");

}

}


}
