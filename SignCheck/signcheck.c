#include<stdio.h>
#include<limits.h> /* CHAR_BIT */
/* this program detects the sign of an integer */

main(){

int v = -20;      // we want to find the sign of v
int sign;   // the result goes here 
//const int CHAR_BIT = 8;  //referenced in limit.h package
// CHAR_BIT is the number of bits per byte (normally 8).

sign = -(v < 0);  // if v < 0 then -1, else 0.

// or, to avoid branching on CPUs with flag registers (IA32):
sign = -(int)((unsigned int)((int)v) >> (sizeof(int) * CHAR_BIT - 1));  //right shift an integer with total bits in an integer. In this machine its 4 bytes

/* the cast is to ENSURE the size of the variable being shifted, also no information has been lost*/

// or, for one less instruction (but not portable):
//sign = v >> (sizeof(int) * CHAR_BIT - 1);  

printf("%d",sign);
}

