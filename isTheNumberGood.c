/*
This program finds if I like a number or not.
As a rule, I only like multiples of 2, 6, or 10.
There might be exceptions like 76, but that's rare.

Please note: I only really know Python, so this code might be rough
*/

#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num) {
    if (num == 2) {
        return true;
    }

    if (num <= 1 || num % 2 == 0) {
        return false;
    }

    for (int i = 3; i < num; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

bool isGood(int num) {
   
   // Upon second thought, I kinda like 76 but that's the only exception
   if (num == 76) {
      return true;
   }

   if (num % 2 == 0) {
      for (int i = 2; i < num; i++) {

	 // Get rid of even numbers with prime factors other than 3 and 5
         if (isPrime(i) && i != 2 && i != 3 && i != 5 && num % i == 0) {
            return false;
	 }

      }
   } else {
      return false; // Get rid of all odd numbers
   }

   return true;
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    if (isGood(number)) {
        printf("%d is acceptable\n", number);
    } else {
        printf("%d is NOT acceptable\n", number);
    }

    return 0;
}
