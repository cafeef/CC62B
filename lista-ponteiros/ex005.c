#include <stdio.h>
int main () {
 int i = 5, *p;
 p = &i;
 printf("%d, %d, %d, %d, %d", p,(*p+2),**&p,(3**p),(**&p+4));
}