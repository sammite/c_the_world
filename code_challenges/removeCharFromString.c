// Got asked this and, well didn't do amazing, haha.
// here is what I banged out later. Still bad but I think it mostly works.
// technically you might want to realloc after this point but given that in the example (and potentially other scenarios)
// it is being allocated on the stack, that is potentially better left to the caller.
// I looked at some other cleaner implementations and there are some neat ways to do this. But this is how I did it without copying. :)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// removes all instances of a character from string without allocating more memory.
// N^2 sadly, maybe I'll revisit someday and get it knocked down.
// compiled with: gcc -g -Wall -Wextra basic.c -o runme
// usage: ./runme <string in quotes> <char>
void removeCharFromString(char nope, char *targStr)
{

    int len = strlen(targStr);
    char temp;
    for (int i = 0; i <= len; i++)
    {
        for (int j = i; j <= len; j++)
        {
            if (nope == targStr[j])
            {

                if (targStr[j + 1] != len && targStr[j + 1] != '\0')
                {
                    temp = targStr[j];
                    targStr[j] = targStr[j + 1];
                    targStr[j + 1] = temp;
                }
            }
        }
    }
    for (int i = 0; i < len; i++) {
        if (nope == targStr[i]) {
            printf("found nope at %i\n", i);
            targStr[i] = '\0';
            break;
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        exit(1);
    }
    char *inputStr = argv[1];
    char *inputNope = argv[2];
    removeCharFromString(*inputNope, inputStr);

    printf("%s\n\n", inputStr);
}

