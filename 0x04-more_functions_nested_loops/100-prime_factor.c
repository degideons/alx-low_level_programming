#include <stdio.h>
#include <math.h>

long int find_largest_prime_factor(long int n);

int main(void)
{
    long int number = 612852475143;
    long int largest_prime_factor;

    largest_prime_factor = find_largest_prime_factor(number);

    printf("%ld\n", largest_prime_factor);

    return 0;
}

long int find_largest_prime_factor(long int n)
{
    long int largest_prime = -1;

    while (n % 2 == 0)
    {
        largest_prime = 2;
        n /= 2;
    }

    for (long int i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            largest_prime = i;
            n /= i;
        }
    }

    if (n > 2)
        largest_prime = n;

    return largest_prime;
}

