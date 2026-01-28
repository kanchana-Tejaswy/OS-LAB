#include<stdio.h>
#include<unistd.h>
void main(){
		printf("A\n");
		fork();
		printf("B\n");
		fork();
		printf("C\n");
}
