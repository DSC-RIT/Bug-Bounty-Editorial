/*
PROBLEM STATEMENT:
    Mr ImSooCool wants to become a competitive programming genius. He went to GeeksForGeeks and learnt about doubly linked list.
    Now he wants to show off to his classmates by writing a code that inserts nodes into a doubly linked list in a sorted way. 
    He shall insert the elements in the correct order so that he does not need to do any kind of sorting later.
    
    Basically when inserting a node, he finds its postion with respect to the previous nodes and inserts in the correct positon.
    This ensures that the list will reamain in sorted order after every insertion.
    Unfortunately his code has soo many bugs and mistakes that everyone doubts his genius. He now seeks your help to regain respect in the eyes of his classmates. Help him and get your KEY!
    
    INPUT: 
        Integers, i.e. the data of the nodes. You don't need to worry about this, this part has been handled.
    OUTPUT: 
        Integers sorted in non-decending order. 
    
    NOTE: Don't change any code indicated as CORRECT.
    
    KEY: 1542575763
         

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"

typedef struct node
{
    int data;
    struct node *llink;
    struct node *rlink;

} node;

node *temp = NULL, *ptr = NULL, *start = NULL;
long long key_to_enter_in_website = 100;

///////////////////////////////////////// CODE ABOVE IS CORRECT, DON'T CHANGE ////////////////////////////////////

void order(node *temp)
{
    if (start == NULL) ///////// BUG CORRECTED- should use equality operator and not assignment operator /////
    {
        start = temp;
        key_to_enter_in_website *= 5;
    }
    else if (temp->data < start->data)
    {
        start->llink = temp;
        temp->rlink = start;
        start = temp; //////BUG CORRECTED- start should be reassigned to the first node///////
        key_to_enter_in_website *= (key_to_enter_in_website + 1);
    }
    else
    {
        ptr = start;                                         ///////// BUG CORRECTED - ptr not initialized //////////
        while (ptr->rlink != NULL && temp->data > ptr->data) ///////// SYNTAX BUG HERE & instead of &&
        {
            ptr = ptr->rlink;
            key_to_enter_in_website += 5 * ptr->data;
        }
        if (ptr->rlink == NULL && temp->data > ptr->data) ///////// SYNTAX BUG HERE & instead of &&
        {

            temp->llink = ptr; /////// BUG CORRECTED- inserting at the end where ptr is pointing to last node/////
            ptr->rlink = temp; ///////  BUG CORRECTED- inserting at the end where ptr is pointing to last node/////
            key_to_enter_in_website *= 2;
        }
        else
        {
            ptr->llink->rlink = temp; /////  BUG CORRECTED- the link between the left node and the temp is absent//////
            temp->llink = ptr->llink;
            ptr->llink = temp; ////// BUG CORRECTED- MISSING ";" ////////
            temp->rlink = ptr;
            key_to_enter_in_website += (ptr->data) * 7;
        }
    }
}
//////////////////////////////////////// CODE BELOW IS CORRECT,DON'T CHANGE ////////////////////////////////////

void display()
{
    printf("The doubly linked list is:\n");
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d, ", ptr->data);
        ptr = ptr->rlink;
    }
    printf("\n");
}

void reverse(char str[], int length)
{
    int start = 0;
    int end = length - 1;
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}
char *ouritoa(int num, char *str, int base)
{
    int i = 0;
    int isNegative = 0;

    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    // In standard itoa(), negative numbers are handled only with
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = 1;
        num = -num;
    }

    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';

    str[i] = '\0'; // Append string terminator

    // Reverse the string
    reverse(str, i);

    return str;
}

int main()
{
    int *numberArray;
    int a[30];
    numberArray = getArray(a, 30);
    for (int i = 0; i < 30; i++)
    {
        temp = (node *)malloc(sizeof(node));
        temp->data = numberArray[i];
        temp->llink = NULL;
        temp->rlink = NULL;
        order(temp);
    }

    display(); // call if required

    char inp[100] = "\0";
    int j = 0;

    ptr = start;
    while (ptr != NULL)
    {
        // printf("%d---",ptr->data);
        char temp[100];
        ouritoa(ptr->data, temp, 10);
        strcat(inp, temp);

        ptr = ptr->rlink;
    }
    strcat(inp, "\0");
    //printf("%s",inp);

    printf("\n\nThe key for the list is: %u\n", hash(inp));

    // printf("Key: %lld",key_to_enter_in_website);
}

