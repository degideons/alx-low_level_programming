#include "main.h"
#include <stdio.h>
/**
 * infinite_add - add 2 strings.
 * @n1: string1.
 * @n2: string2.
 * @r: buffer
 * @size_r: buffer size
 * Return: String with all letters in ROT13 base.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r);

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int i, j, k, len1, len2, carry, sum;

    // Calculate lengths of the input strings
    for (len1 = 0; n1[len1]; len1++)
        ;
    for (len2 = 0; n2[len2]; len2++)
        ;

    // Check if the result can be stored in the buffer
    if (len1 >= size_r || len2 >= size_r)
        return 0;

    // Initialize variables for addition
    i = len1 - 1;
    j = len2 - 1;
    k = 0;
    carry = 0;

    // Perform addition from right to left
    while (i >= 0 || j >= 0 || carry > 0)
    {
        // Get the digits to add (or zero if the numbers have different lengths)
        int digit1 = (i >= 0) ? n1[i] - '0' : 0;
        int digit2 = (j >= 0) ? n2[j] - '0' : 0;

        // Calculate the sum of digits and carry
        sum = digit1 + digit2 + carry;

        // Store the result digit in the result buffer
        if (k < size_r - 1) // Reserve space for the null terminator
        {
            r[k] = sum % 10 + '0';
            k++;
        }
        else
        {
            return 0; // Result cannot be stored in the buffer, return 0
        }

        // Update carry for the next iteration
        carry = sum / 10;

        // Move to the next digits of the input numbers
        i--;
        j--;
    }

    // Add null terminator to the result string
    r[k] = '\0';

    // Reverse the result string to get the correct order
    for (i = 0, j = k - 1; i < j; i++, j--)
    {
        char temp = r[i];
        r[i] = r[j];
        r[j] = temp;
    }

    return r;
}
