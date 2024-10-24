#include <stdio.h>
int main() {
	int x = 5;
	char str[3];
	int *p = &x;
	char *c = str;
	printf("p = %x\nc = %x\n", p, c);
	p++;
	c++;
	printf("p = %x\nc = %x\n", p, c);
}