/*
PROBLEM STATEMENT:
    Agent Mickey is on a mission to arrange his pets in a particular order for inspection by Professor Ludwig Von Drake.
    There happens to be a slight problem. His 'sortinator3000' machine is not working as the evil Peter Pete Sr. has messed with its code.
    Mickey has to get this machine to work as soon as possible.
    His pets are named with just a single letter like 'a', 'c', 'b' and so on. 
    After sorting the pets in order according to their names, the pets with the same name has to be grouped together. 
    For example: If there are four pets with the name 'a', it should be grouped as 'a4' instead of 'aaaa'.
    It is upto you to save Mickey!
INPUT:
    The inputs are taken from a file named data.txt. You are not expected to make any changes to it.
OUTPUT: 
    The output is a string in the format specified in the problem statement.
Sample input 1: 
    'acbgabbc'
Sample output 1:
    'a2b3c2g1'
CORRECT OUTPUT:
    Sorted pet names(before removing the duplicates) is: 
    aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbcccccccccccccccccccccccccccccccccddddddddddddddddddddddddddddddddddddddddeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeefffffffffffffffffffffffffffffffffffffffffffffgggggggggggggggggggggggggggggggggggghhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiijjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkklllllllllllllllllllllllllllllllllllllllllllllmmmmmmmmmmmmmmmmmmmmmmmmmmmmmnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnooooooooooooooooooooooooooooooooooopppppppppppppppppppppppppppppppppppppppppppqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrsssssssssssssssssssssssssssssssssssssssstttttttttttttttttttttttttttttttuuuuuuuuuuuuuuuuuuuuuuuuuvvvvvvvvvvvvvvvvvvvvvvvvvwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz

    The array after removing the duplicates and grouping the pets is:
    a41b35c33d40e32f45g36h40i40j52k47l45m29n41o35p43q41r35s40t31u25v25w41x45y35z48

    Congratulations! Here is the key: 235458 (Type this in the website)
*/

#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

long p = 0;

void swap(char *x, char *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Sort(char arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])    ////BUG CORRECTED - Should be arr[j] > arr[j + 1] and not arr[i] > arr[i + 1]
            {
                swap(&arr[j], &arr[j + 1]);
                p++; //Just a counter, ignore this
            }
        }
    }
}

int removeDups(char arr[], int n)
{
    int i = 0, j = 0, temp[n];
    if (n == 0 || n == 1)
        return n;

    for (i = 0; i < n - 1; i++)
        if (arr[i] != arr[i + 1])
        {
            temp[j++] = arr[i];
            p++; //Just a counter, ignore this
        }
    temp[j++] = arr[n - 1];

    for (i = 0; i < j; i++)
        arr[i] = temp[i];
    return j;
}

void countDups(char orig[], int count[], int n, int newLength)
{
    int i = 0, j = 0;

    for (i = 0; i < newLength; i++)
    {
        count[i] = 1;  ////BUG CORRECTED - Should be count[i] = 1 instead of count[i] = 0
        p += count[i]; //Just a counter, ignore this
    }

    for (i = 0; i < n - 1; i++)
    {
        if (orig[i] == orig[i + 1])
        {
            ++count[j];
        }
        else
        {
            p--; //Just a counter, ignore this
            j++;
        }
    }
}

void Group(char arr[], int n)
{
    int newLength, i = 0;
    char orig[n];   ////BUG CORRECTED - Should be 'int' instead of 'char'
    for (i = 0; i < n; i++)
    {
        orig[i] = arr[i];
    }
    newLength = removeDups(arr, n);
    int *count = (int *)malloc(newLength * sizeof(int));
    countDups(orig, count, n, newLength);

    for (i = 0; i < newLength; i++)
    {
        printf("%c%d", arr[i], *(count + i));
    }
}

void printIt(char *a, int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
        printf("%c", *(a + i)); ////BUG CORRECTED - Should be *(a + i) instead of a[i] 
    }
    printf("\n");
}

int main()
{
    int i = 0;
    int pet;
    int length = 1000, res;

    char *arr = (char *)malloc(length * sizeof(char)); ////BUG CORRECTED - Should be 'int' instead of 'char'

    FILE *fp = fopen("./data.txt", "r");
    while (fp != NULL)
    {
        pet = fgetc(fp);
        if (pet == EOF)
            break;
        *(arr + i) = pet; ////BUG CORRECTED - Should be *(arr + i) instead of arr[i]
        i++;
    }

    Sort(arr, length);
    printf("\nSorted pet names(before removing the duplicates) is: \n");
    printIt(arr, length);

    printf("\nThe array after removing the duplicates and grouping the pets is:\n");
    Group(arr, length);

    // Just a hash function. Do not worry about this.
    res = mystify(p);

    if (res != -1)
    {
        printf("\n\nCongratulations! Here is the key: %d (Type this in the website)\n", res);
    }
    else
    {
        printf("Try again.\n");
    }
    return 0;
}

