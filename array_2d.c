//
// Created by unity on 2022/07/06.
// puti Shiren.1
#include<stdio.h>
int main(){
    char r[]="I want to be a pen";
    //char r[]="I was ballpen";
    //char r[]="You are Eraser";
    char target[4]="pen";
    char tmp[4]="";
    int index=0;
    for (int i = 0; i < sizeof(r) / sizeof(r[0]); ++i){
        for (int j = 0; j < 4  -1; ++j) {
            tmp[j]=tmp[j+1];
        }
        tmp[3]=r[i];
        int cond=1;
        for (int j = 0; j < 4; ++j) {
            if(target[j]!=tmp[j])cond=0;
        }
        if(cond){
            index=i;
            break;}
    }

    if(index){
        printf("%d",index-3);
    } else printf("THERE IS NOT A PEN!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
}