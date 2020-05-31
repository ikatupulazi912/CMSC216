#include <stdio.h>
#include "Rational.h"


Rational_Type make_Rational(int numer, int denom)
{
	Rational_Type r1;
	r1.numerator = numer;
	r1.denominator = denom;
	
	return r1; 
}

Rational_Type addition (Rational_Type a, Rational_Type b)
{
	Rational_Type r1;
	if(a.denominator == b.denominator)
	{
		r1.numerator = a.numerator + b.numerator;
		r1.denominator = a.denominator;
	}
	
	if(a.denominator != b.denominator)
	{
		r1.denominator = a.denominator * b.denominator;
		r1.numerator = (a.numerator * b.denominator) + (b.numerator * a.denominator);
	}
	return r1;
}

Rational_Type subtraction (Rational_Type a, Rational_Type b)
{
	Rational_Type r1;
        if(a.denominator == b.denominator)
        {
                r1.numerator = a.numerator - b.numerator;
                r1.denominator = a.denominator;
       	}
	
	if(a.denominator != b.denominator)
        {
                r1.denominator = a.denominator * b.denominator;
                r1.numerator = (a.numerator * b.denominator) - (b.numerator * a.denominator);
        }
	
	return r1;	
}

Rational_Type multiplication (Rational_Type a, Rational_Type b)
{
	Rational_Type r1;
	r1.numerator = a.numerator * b.numerator;
	r1.denominator = a.denominator * b.denominator;
	
	return r1;
}

Rational_Type division (Rational_Type a, Rational_Type b)
{ 
	Rational_Type r1;
        r1.numerator = a.numerator * b.denominator;
        r1.denominator = a.denominator * b.numerator;  
	
	return r1;
}

void display (Rational_Type a)
{
	
	int divisor = 2;
	int smallest;
	int largest;
	if(a.numerator < a.denominator)
	{
		smallest = a.numerator;
		largest = a.denominator;
	}
	else if(a.numerator == a.denominator)
	{
		printf("\nThe answer is 1/1");
		return;
	}
	else
	{
		smallest = a.denominator;
		largest = a.numerator;
	}

	while(divisor <= smallest)
	{
		if((smallest % divisor)== 0)
		{
			if((largest % divisor) == 0)
			{
				a.numerator = a.numerator / divisor;
				a.denominator = a.denominator / divisor;

				if(a.numerator < a.denominator)
				{
					smallest = a.numerator;
			                largest = a.denominator;
				}
			        else if(a.numerator > a.denominator)
			        {
               				 smallest = a.denominator;
               				 largest = a.numerator;
       				}
			}
			else
			{
				divisor++;
			}
		}
		else
		{
			divisor++;	
		}	
	}	
	printf("\nThe answer is %d/%d", a.numerator, a.denominator);
}

