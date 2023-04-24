#include<stdio.h>
#include<math.h>

#define bin_dec_hex(bin)({\
int dec=0,rem,i=0;\
while(bin!=0){ \
    rem=bin%10;\
    dec+=rem*pow(2,i);\
    i++;\
    bin=bin/10;\
}\
dec;\
})
