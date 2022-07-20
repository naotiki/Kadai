//
// Created by unity on 2022/07/06.
//
#include<stdio.h>

int main() {
    char a[13] = "HELLO WORLD ";
    char arrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrray[3][13] = {"","",""};

    int index=0;
    for (int i = 0; i < 3; ++i) {
        int j=0;
        char tmp[13]="";
        for(;index<13;index++){
            if(a[index]==' ') {
                index++;
                break;
            }
            tmp[j]=a[index];
            j++;

        }
        for (int k = 0; k < 13; ++k) {
            arrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrray[i][k]=tmp[k];
        }
    }


    for (int i = 0; i < 3; ++i) {
        printf("%s",arrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrray[i]);
        printf("\n");
    }

}