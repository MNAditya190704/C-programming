#include <stdio.h>

int main() 
{
    // Initialize previous as 0 and current as 1
    int fib_limit, previous = 0, current = 1, next = 0;

    printf("Give a limit for negative fibonacci series: ");
    scanf("%d", &fib_limit);

    // Ensure the limit is actually negative or zero
    if (fib_limit > 0) 
    {
        printf("Please enter negative numbers only (e.g., -10).\n");
    } 
    else
    {
        printf("Fibonacci Series: ");
        
        /* 
           Logic: To go backwards, use the formula F(n-2) = F(n) - F(n-1).
           In the loop: next = previous - current.
           The sequence will be: 0, 1, -1, 2, -3, 5, -8...
        */
        while (1)
        {
            // Check if 'next' is within the negative limit
            // For negative series, 'next' can be positive or negative
            if (next < 0 && next < fib_limit) break;
            if (next > 0 && next > -fib_limit) break;

            printf("%d ", next);

            previous = current;    
            current = next;        
            next = previous - current; // Backwards calculation
        }
        printf("\n");
    }
    return 0;
}