#include<bits/stdc++.h>
int n,m,q;
char ques[200][20];
char tab[30][30];
int check(int i,int j,int k){
    int l=strlen(ques[k]);
    int r;
if(i-l+1>=0){
        for(r=1;r<l;r++){
            if(tab[i-r][j]!=ques[k][r])break;
                }
                if(r==l)return 1;
}

if(i+l-1<m){
        for(r=1;r<l;r++){
            if(tab[i+r][j]!=ques[k][r])break;
                }
                if(r==l)return 1;
}

if(j-l+1>=0){
        for(r=1;r<l;r++){
            if(tab[i][j-r]!=ques[k][r])break;
                }
                if(r==l)return 1;
}

if(j+l-1<n){
        for(r=1;r<l;r++){
            if(tab[i][j+r]!=ques[k][r])break;
                }
                if(r==l)return 1;
}

if(i-l+1>=0&&j+l-1<n){
        for(r=1;r<l;r++){
            if(tab[i-r][j+r]!=ques[k][r])break;
                }
                if(r==l)return 1;
}
if(i-l+1>=0&&j-l+1>=0){
        for(r=1;r<l;r++){
            if(tab[i-r][j-r]!=ques[k][r])break;
                }
                if(r==l)return 1;
}

if(i+l-1<m&&j-l+1>=0){
        for(r=1;r<l;r++){
            if(tab[i+r][j-r]!=ques[k][r])break;
                }
                if(r==l)return 1;
}

if(i+l-1<m&&j+l-1<n){
        for(r=1;r<l;r++){
            if(tab[i+r][j+r]!=ques[k][r])break;
                }
                if(r==l)return 1;
}

return 0;


}
main(){
scanf("%d %d",&m,&n);
int i,j,k;
for(i=0;i<m;i++)scanf("%s",tab[i]);
scanf("%d",&q);
for(i=0;i<q;i++)scanf("%s",ques[i]);
for(i=0;i<m;i++){
    for(j=0;j<n;j++){tab[i][j]=tolower(tab[i][j]);}
}

for(i=0;i<q;i++){
    for(j=0;j<strlen(ques[i]);j++){ques[i][j]=tolower(ques[i][j]);}
}

for(k=0;k<q;k++){
        int x=0;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(tab[i][j]==ques[k][0])if(check(i,j,k)){printf("%d %d\n",i,j);x=1;break;}
        }if(x==1)break;
    }
}


}
