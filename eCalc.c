//eCacl.c

/******************************************************************************/

#include<stdio.h>
#include<math.h>  // To allow use of mathematical constant e

/******************************************************************************/
/* DOCUMENTATION */

/* PROGRAMMER:  Luis M. Herrnsdorf  
   ID: 5481644
   CLASS:       COP4338 U03   TT 7:50
   INSTRUCTOR:  William Feild
   ASSIGNMENT:  #1.   DUE Tuesday 2/09 */

/* DESCRIPTION: This program compute e and compares the result with the math.h
   library constant expected value.  Also shows how many iterations took to 
   find the answer. */

/* SPECIFICATIONS: Write an algorithm and program to compute e with ten 
   significant digit accuracy The calculation of the important mathematical
   constant e, base of the natural logarithms, frequently done as the sum of 
   the infinite Taylor Series:
          ∞
    e = ∑   1/n!
         n=0
 */

/* INPUT: The program will not accept user input.
   OUTPUT: The program will output the computed value for e, the math.h library
   constant expected value for e and the number of terms it took to find the
   answer. */

/* COMPILATION: gcc -eCalc.c -o eCalc.out */

/* EXECUTE: ./eCalc.out */

/* 
  CERTIFICATION: I hereby certify that this collective work is my own and none 
                 of it is the work of any other person or entity.
                    Luis Herrnsdorf
*/

/*  START PSEUDO CODE

#define The ten significant digit plus decimal point and null character

int main()
{
    variable for loop counter;
    variable for e calculation;
    variable to compare to calculated e;
    variable to caculate factorial;

    print out “What the program does”;

    call e calculation function to the compare e;

    while (e & compare e are not equals)
    {
	call e calculation function to the e variable;
	increase factorial variable;
	call e calculation function to the compare e;
	increase counter;
    }

    print result;
    return 0;
}

*******************************************************************************
Functions:

double fact(double x)
{
    variable for result
    for (decrease x to 0)
    {
	multiply x and save it to result;
    }
    return result;
}
********************************************************************************
int eComparator(double x, double y)
{
    save doubles into chars;
    variable for char index;
    variable for counter;
	
    for (length of char is less than constant)
    {
	if (both chars have equal index)
	{
	    increase counter;
	}
    }

    if (counter and constant are equals)
    {
	return 0;
    }
    else
    {
	return 1;
    }
}

END PSEUDO CODE

/******************************************************************************/

#define ACCURACY 0.000000001 // To check for ten significant digit accuracy
#define NOERRORS 0           // No errors found

/******************************************************************************/

double fact(double);

/******************************************************************************/

int main()
{
	int counter = 0;       // Count number of loops that takes to get e
	double e = 0.0;        // To compute the value of e
	double e1 = 0.0;       // To compare to when e reaches ten digits
	double divider = 0.0;  // To calculate factorials

	printf("%s\n", "This program calculate the mathematical constant e, and");
	printf("%s\n", "compares the result to the math.h library constant.");
	e1 += (1.0/fact(divider));  // Apply Taylor's series formula

	while ((e1 - e) >= ACCURACY)
	{
		e += (1.0/fact(divider));
		divider++;
		e1 += (1.0/fact(divider));
		counter++;
	}
	printf("\n");
	printf("%s %0.9lf\n", "The math.h ten digits value of 'e' is: ", exp(1));
	printf("%s %18.9lf\n", "The calculated value of 'e' is: ", e);
	printf("%s %d %s\n", "It took",counter,"iteration to calculate 'e'");

	return NOERRORS;
}

/******************************************************************************/

/*
* Function: fact
* ---------------
* Calculate the factorial of an int
*
* x: the int to calculate the factorial for
*/
double fact(double x)
{
	double result = 1.0;
	for (; x > 1; x--)
		{
			result *= x;
		}
		return result;
}

/******************************************************************************/
