#include<bits/stdc++.h>
using namespace std;
char tab[10][10];
int score=0;
int n,m;
void move(int x,int y,char s);
void del();
void down();
void move(int x,int y,char s){
    if(tab[x][y]=='#'||tab[x][y]=='-'){score-=5;return;}
if(s=='L'){
if(y-1<0){score-=5;return;}
if(tab[x][y-1]!='-'){score-=5;return;}
else{
swap(tab[x][y-1],tab[x][y]);down();
}
}

if(s=='R'){
if(y+1>=m){score-=5;return;}
if(tab[x][y+1]!='-'){score-=5;return;}
else{
swap(tab[x][y+1],tab[x][y]);down();
}
}
}
void del(){
    int che=0;
for(int i=n-1;i>=0;i--){
for(int j=0;j<m;j++){
if(tab[i][j]!='-'&&tab[i][j]!='#'){
    int ch=0;
    if(j>0){if(tab[i][j-1]==tab[i][j]){tab[i][j-1]='-';ch=1;score+=5;}}

    if(i<n-1){if(tab[i+1][j]==tab[i][j]){tab[i+1][j]='-';ch=1;score+=5;}}
    if(ch){
         if(j+1<m){if(tab[i][j+1]!=tab[i][j]){tab[i][j]='-';score+=5;che=1;}}
         else {tab[i][j]='-';score+=5;che=1;}
         }}
}
}


if(che)down();
}
void down(){
for(int i=n-2;i>=0;i--){
for(int j=0;j<m;j++){
    int k=i;
while(tab[k][j]!='-'&&tab[k][j]!='#'&&tab[k+1][j]=='-'){
    swap(tab[k][j],tab[k+1][j]);k++;
}
}
}

del();
}
int main(){
scanf("%d %d",&n,&m);
for(int i=0;i<n;i++){
for(int j=0;j<m;j++)scanf(" %c",&tab[i][j]);
}
int l;
scanf("%d",&l);
for(int i=0;i<l;i++){
char s;int x,y;
scanf(" %d %d %c",&x,&y,&s);
move(x,y,s);
}
printf("%d\n",score);
for(int i=0;i<n;i++){
for(int j=0;j<m;j++)printf("%c ",tab[i][j]);printf("\n");
}
}
/*
5 5
# A B - #
# B A - #
# # B - #
# # A - #
# # # # #
1
1 2 R*/
