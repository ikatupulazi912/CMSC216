#include <stdio.h>
#include "Rational.h"
#include <stdlib.h>


Rational_Type inverse(Rational_Type);

int main()
{
	printf("This program accepts two rational numbers (A and B) and performs operations on \nthem\n\n");
	Rational_Type A, B;
	int a;
	int b;

	
	/* Rational Number A */
	printf("Enter the numerator value for the A rational number\n");
	scanf("%d", &a);
	printf("Enter the denominator value for the A rational number\n");
	scanf("%d", &b);
	while(b == 0)
	{
		printf("The denominator cannot be zero. Enter another number.\n");
		scanf("%d", &b);
	}
	A = make_Rational(a, b);	

	/*Rational Number B */
	printf("\n\nEnter the numerator value for the B rational number\n");
        scanf("%d", &a);
        printf("Enter the denominator value for the B rational number\n");
        scanf("%d", &b);
	while(b == 0)
        {
                printf("The denominator cannot be zero. Enter another number.\n");
                scanf("%d", &b);
        }
	B = make_Rational(a, b);


	do{
		 int x;
                 printf("\n\nPlease choose the number that corresponds to the indicated operation.\n");
                 printf("1) A+B\n2) A-B\n3) B-A\n4) A*B\n5) A/B\n6) B/A\n7) 1/A\n8) 1/B\n9) Exit\n");

		
		do{
			scanf("%d",&x);

			if(x == 1)
			{
				display(addition(A, B));
			}
			else if(x == 2)
			{
				display(subtraction(A,B));
			}
			else if(x == 3)
			{
				 display(subtraction(B, A));
			}
			else if(x == 4)
			{
				display(multiplication(A,B));
			}
			else if(x == 5)
			{
				 if(B.numerator == 0)
                                {
                                        printf("\nDivision is not applicable.\n");
                                }
                                else
                                {
                                        display(division(A,B));
                                }

			
			}
			else if(x ==6)
			{
				 if(A.numerator == 0)
                                {
                                        printf("\nDivision is not applicable.\n");
                                }
                                else
                                {
                                        display(division(B,A));   
                                }

				
			}
			else if(x == 7)
			{
				 if(A.numerator == 0)
                                {
                                        printf("\nThe inverse is not applicable.\n");
                                }
                                else
                                {
                                        display(inverse(A));
                                }

			}
			else if(x == 8)
			{
				if(B.numerator == 0)
				{
					printf("\nThe inverse is not applicable.\n");
				}
				else
				{
					display(inverse(B));
				}
			}
			else if(x == 9)
			{
				exit(0);
			}
			else
			{	
				printf("Invalid response! Choose again.\n");
				x = 1234567890;
			}
		}while(x == 1234567890);
	}while(1);

}

Rational_Type inverse(Rational_Type x)
{
	int temp = x.numerator;
	x.numerator = x.denominator;
	x.denominator = temp;
/*	printf("\n");*/
	return x;
	
}

