#include <termio.h>
#include <stdio.h>
#include <sys/time.h>
char getchar_sp(void) {
    struct termio old_term;
    struct termio new_term;
    char c;
    ioctl(0, TCGETA, &old_term);
    new_term = old_term;
    new_term.c_lflag &= ~(ICANON | ECHO);
    ioctl(0, TCSETAW, &new_term);
    c = getchar();
    ioctl(0, TCSETAW, &old_term);
    return (c);
}

//
// Created by unity on 2022/10/13.
//
int main() {
    long count=0;
    long milc=0;
    int isStop=1;
    time_t now, prev;
    struct tm
            *tm_now;
    prev = -1;
    struct timeval time;
    gettimeofday(&time, NULL);
    long old_epoch=time.tv_sec;
    long old_mil=time.tv_usec;
    while (1) {

        char pressedKey= getchar_sp();

        if(pressedKey=='R'){
            isStop=1;
            count=0;
            milc=0;
        }else if(pressedKey=='M'){
            if(isStop)
                isStop=0;
            else isStop=1;
        }
        gettimeofday(&time, NULL);
        long epoch=time.tv_sec;
        long mil=time.tv_usec;
        if(isStop){
            old_epoch=epoch;
            old_mil=mil;
        }else{
           count+=epoch-old_epoch;
           milc+=mil-old_mil;
           if(milc<0){
               count--;
               milc=1000000+mil-old_mil;

           }
            if(milc>1000000){
                count++;
                milc=milc-1000000;
            }
            old_epoch=epoch;
            old_mil=mil;
        }
        printf("%ld.%06ld\n",count,milc);
    }
    return 0;
}
