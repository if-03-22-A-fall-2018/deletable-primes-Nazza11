/*----------------------------------------------------------
 *				HTBLA-Leonding / Class
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			deletable_primes.c
 * Author:			P. Bauer
 * Due Date:		October 16, 2012
 * ----------------------------------------------------------
 * Description:
 * Implementation of deletable_primes.h.
 * ----------------------------------------------------------
 */
 #include "deletable_primes.h"
 #include <math.h>

 unsigned long remove_digit(int index, unsigned long n){
   long x = pow(10, index);

   return (n / (x * 10)) * x + (n % x);
 }

 int get_ways(unsigned long n){
   int waysPossible = 0;

   if(n < 10 && is_prime(n))
   {
     return 1;
   }
   if(n < 10 && !is_prime(n))
   {
     return 0;
   }

   for (int i = 0; i < get_lenght(n); i++)
   {
     if(is_prime(remove_digit(i,n)))
     {
       waysPossible += get_ways(remove_digit(i,n));
     }
   }
   return waysPossible;
 }

 bool is_prime(unsigned long n){
   if (n <= 1 || (n % 2 == 0 && n > 2))
   {
     return false;
   }

   for(int i = 3; i <= sqrt(n); i += 2)
   {
     if (n % i == 0)
     {
       return false;
     }
   }

   return true;
 }

 int get_lenght(unsigned long n){
   int lenght = 0;

   while (n > 1)
   {
     n /= 10;

     lenght++;
   }

   return lenght;
 }
