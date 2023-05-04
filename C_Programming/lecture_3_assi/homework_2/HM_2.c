/*
 * HM_2.c

 *
 *  Created on: May 4, 2023
 *      Author: Shehab
 */
/* ex1
#include <stdio.h>

int main() {
	int x;
	printf("enter your number:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);
	if( x%2 ==0){
		printf("the number %d is EVEN",x);
	}
	else{
		printf("the number %d is ODD",x);
	}
}
 */
/* ex2
#include <stdio.h>

int main() {
	char x;
	printf("enter an alphapet:");
	fflush(stdin); fflush(stdout);
		scanf(" %c",&x);
	switch (x){
	case ('a'):
	case ('i'):
	case ('e'):
	case ('u'):
	case ('o'):{
	printf("%c is vowel",x);
	}
	break;
	default:
	{
		printf("%c is consontant",x);
	}
	}
}
 */
/* ex3
#include <stdio.h>

int main() {
	int x , y, z;
		printf("enter three numbers:");
		fflush(stdin); fflush(stdout);
		scanf("%d",&x);
		scanf("%d",&y);
		scanf("%d",&z);
		if(x>y && x>z){
			printf("the largest number is %d",x);
		}
		else if(y>x && y>z){
			printf("the largest number is %d",y);
		}
		else if(z>x && z>y){
					printf("the largest number is %d",z);
				}
}
 */
/*ex4
#include <stdio.h>

int main() {
	 int num;

	    printf("Enter a number: ");
	    fflush(stdin); fflush(stdout);
	    scanf("%d", &num);

	    if (num > 0) {
	        printf("%d is a positive number.\n", num);
	    } else if (num < 0) {
	        printf("%d is a negative number.\n", num);
	    } else {
	        printf("You entered zero.\n");
	    }
}
 */
/* ex5
#include <stdio.h>

int main() {
	char ch;

	    printf("Enter a character: ");
	    fflush(stdin); fflush(stdout);
	    scanf("%c", &ch);

	    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
	        printf("%c is an alphabet.\n", ch);
	    } else {
	        printf("%c is not an alphabet.\n", ch);
	    }
}
 */
/*ex6
#include <stdio.h>

int main() {
	 int num , sum =0;

		    printf("Enter a number: ");
		    fflush(stdin); fflush(stdout);
		    scanf("%d", &num);
		    for(int i =1;i<num;i++){
		    	sum+=i;
		    }
		    printf("sum: %d",sum);
}
 */
/*ex7
#include <stdio.h>

int main() {
	int num;
	int factorial =1;
	printf("Enter a number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &num);
	if(num==0){
		printf("factorial of 0 is 1");
	}
	else if(num<0){
		printf("factorial does not exist");
	}
	else{

		for(int i =1;i<=num;i++){
			factorial*=i;
		}
		printf("factorial: %d",factorial);
	}
}
*/
