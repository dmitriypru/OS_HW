#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int main() {
    for (int i = 0; i < 10; i++) {
        int *ptr = malloc(1024 * 1024 * 10);
        memset(ptr, 0, 1024 * 1024 * 10);
        sleep(1);
    }
    return 0;
}

/*
 What I got from vm_stat:
 
 free   active   specul inactive throttle    wired  prgable   faults     copy    0fill reactive   purged file-backed anonymous cmprssed cmprssor  dcomprs   comprs  pageins  pageout  swapins swapouts
248313  1171492   301942  1254344        0   712776    23454 1274559K 16428104  453022K 45557589  2400670     1200509   1527269  4698921   505075 43417813 57121535 33241324    45211 46786657 48786395
239619  1177238   302305  1254774        0   712694    23661    21672       33     5641        0        0     1201302   1533015  4696179   507241     2124        0      306        0     2550        0
233560  1179392   302302  1254492        0   716663    24260    18910        8     7713        0        0     1201315   1534871  4696179   507241        0        0        0        0        0        0
229509  1182281   302369  1252530        0   719788    26976    42333      138    31285        0        0     1201340   1535840  4696178   507241        1        0        0        0        0        0
229729  1181960   302321  1252553        0   719755    23358    19500       25     8446        0        0     1201340   1535494  4696178   507241        0        0        0        0        0        0
194797  1183968   302302  1252511        0   752831    21659   130306       99   118475        0        0     1201340   1537441  4696178   507241        0        0        0        0        0        0
203063  1196530   302302  1252469        0   731903    31549    15385       50     4636        0        0     1201340   1549961  4696178   507241        0        0        0        0        0        0
200936  1198879   302323  1252492        0   731904    31248    15689       25     4368        0        0     1201361   1552333  4696175   507241        3        0        0        0        0        0
198280  1201601   302323  1252468        0   731869    31248    16211        0     4705        0        0     1201361   1555031  4696175   507241        0        0        0        0        0        0
131287  1197772   302323  1252500        0   802758    21295   165232      141   154771        0        0     1201361   1551234  4696174   507241        1        0        0        0        0        0
176306  1209291   302323  1252461        0   746118    29902    18497       42     7790        0        0     1201361   1562714  4696167   507241        7        0        0        0        0        0
 
 Free memory decreases because ex2 allocate memory.
 Swapins and swapouts equal to zero => nothing swapped.

 ex3: ex2.out gets higher in the list every second
 */

