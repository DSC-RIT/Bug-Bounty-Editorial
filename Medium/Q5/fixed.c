/*
PROBLEM STATEMENT:
    1. Agent Bowman is trying to encrpt his messages in PigLatin. He is encoding according to the following rule:
        If the word is 'How', it is encrypted as 'owHa'
        If the word is 'Nice', it is enrypted as 'iceNa'
        If the word is 'Binod', it is encrypted as 'inodBa', 
        and so on.
    2. He created 2 functions PigLatinGenerator() which directly gives the piglatin word and BowmansPigLatinGenerator() which also gives the same piglatin words as desired.
    3. He puts the words in piglatin form from PigLatinGenerator() and BowmansPigLatinGenerator() into 'thegreatstring'
        and uses a final hash() function to encode it so that it is unreadable by the enemy.
    4. Correct the bugs as Agent Bowman needs and he just might make you an Avenger and give you the password!

INSTRUCTIONS
    1. You are not supposed to touch the HASH function IT IS ARE ABSOLUTELY CORRECT
    2. Please DON'T TOUCH THE HEADER FILES.
    3. Don't completely alter the code structure. Small changes are allowed.

INPUT
    1. This is already handled for you. You DON'T NEED TO WORRY ABOUT THIS.

OUPUT
    1. A TABLE WITH THE FOLLOWING STRUCTURE where the outputs from PigLatinGenerator() and BowmansPigLatinGenerator() are the same.
    #########################################################################################
    #       Output from PigLatinGenerator() #       Output from BowmansPigLatinGenerator()  #
    #       atmanBa                         #       atmanBa                                 #
    #       sIa                             #       sIa                                     #
    #       ctuallyAa                       #       ctuallyAa                               #
    #       ...                             #       ...                                     #
    #       ...                             #       ...                                     #
    #       -Bowman                         #       -Bowman                                 #       //This line is fine. It is his name -Bowman
    #########################################################################################
    You don't have to worry about the table being misaligned as long as your get the desired output

    2. A KEY, WHICH TAKES YOU TO THE NEXT LEVEL.
        KEY: 128970964
    
ANSWER

    #########################################################################################
    #       Output from PigLatinGenerator() #       Output from BowmansPigLatinGenerator()  #
    #       atmanBa                         #       atmanBa                                 #
    #       sIa                             #       sIa                                     #
    #       ctuallyAa                       #       ctuallyAa                               #
    #       amesJa                          #       amesJa                                  #
    #       ondBa                           #       ondBa                                   #
    #       ndThatsCoolAa                   #       ndThatsCoolAa                           #
    #       -Bowman                         #       -Bowman                                 #
    #########################################################################################

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"

char thegreatstring[100];
int track = 0, count = 0;

void PigLatinGenerator(char myarr[]);
void BowmansPigLatinGenerator(char myarr[]);
char *BowmansPigLatinPointerString(char arr[]);
void copyToTheGreatString(char *ptr);

void main() //DO NOT TOUCH THE MAIN FUNCTION IT IS CORRECT
{
    //Start of Correct Code - The below code is correct. Do not change it.
    printf("#########################################################################################\n");
    printf("#\tOutput from PigLatinGenerator() #\tOutput from BowmansPigLatinGenerator()\t#\n");

    printf("#\t");
    PigLatinGenerator("Batman");
    printf("\t\t\t\t#\t");
    BowmansPigLatinGenerator("Batman");
    printf("\t\t\t\t\t#\n");

    printf("#\t");
    PigLatinGenerator("Is");
    printf("\t\t\t\t#\t");
    BowmansPigLatinGenerator("Is");
    printf("\t\t\t\t\t#\n");

    printf("#\t");
    PigLatinGenerator("Actually");
    printf("\t\t\t#\t");
    BowmansPigLatinGenerator("Actually");
    printf("\t\t\t\t#\n");

    printf("#\t");
    PigLatinGenerator("James");
    printf("\t\t\t\t#\t");
    BowmansPigLatinGenerator("James");
    printf("\t\t\t\t\t#\n");

    printf("#\t");
    PigLatinGenerator("Bond");
    printf("\t\t\t\t#\t");
    BowmansPigLatinGenerator("Bond");
    printf("\t\t\t\t\t#\n");

    printf("#\t");
    PigLatinGenerator("AndThatsCool");
    printf("\t\t\t#\t");
    BowmansPigLatinGenerator("AndThatsCool");
    printf("\t\t\t\t#\n");

    printf("#\t");
    printf("-Bowman");
    printf("\t\t\t\t#\t");
    printf("-Bowman\t\t\t\t\t#\n");
    printf("#########################################################################################\n");

    printf("\nKEY: ");

    printf("%u", hash(thegreatstring));
    //End of Correct Code - The above code is correct. Do not change it.
}

void PigLatinGenerator(char myarr[80]) //This function displays the piglatin output and stores it in 'thegreatstring'
{
    int a = strlen(myarr);
    char c = myarr[0];
    for (int i = 1; i < a; i++)
    {
        thegreatstring[track++] = myarr[i]; //Here it is storing the piglatin word into 'thegreatstring'
        printf("%c", myarr[i]);             ////////// SYNTAX BUG HERE `%d` instead of `%c`
    }
    thegreatstring[track++] = c;
    thegreatstring[track++] = 'a';
    printf("%ca", c);
}

char *BowmansPigLatinPointerString(char arr[]) //This function creates a piglatin char string and returns it
{
    int i = 0;
    int n = strlen(arr);                         ////////// SYNTAX BUG HERE `strlength()` instead of `strlen()`
    char *temp = malloc((n + 1) * sizeof(char)); //Bug Here - Incorrect Code has n instead of n+1
    char c = arr[0];
    for (i = 1; i < n; i++) //Bug Here - Incorrect Code has n+2 instead of n and starts from 0 instead of 1
    {
        *(temp + ((i - 1) * sizeof(char))) = arr[i]; //Not a bug just unwanted use of sizeof(). Both *(temp+i-1) and *(temp + ((i-1)*sizeof(char))) are correct here
    }
    *(temp + n - 1) = c; //Bug Here - Incorrect Code has n instead of n-1
    *(temp + n) = 'a';   //Bug Here - Incorrect Code has n+1 instead of n
    *(temp + n + 1) = '\0';
    return temp;
}

void BowmansPigLatinGenerator(char mynewarr[80]) //This function creates a piglatin char string by calling BowmansPigLatinPointerString() function
{
    char *st = BowmansPigLatinPointerString(mynewarr);
    copyToTheGreatString(st); //Bug Here - Incorrect Code has mynewarr instead of st
    printf("%s", st);         //Bug Here - Incorrect Code has mynewarr instead of st
    free(st);
}

void copyToTheGreatString(char *ptr)
{
    for (int i = 0; *(ptr + i) != '\0'; i++)
    {
        thegreatstring[track++] = *(ptr + i);
    }
}

