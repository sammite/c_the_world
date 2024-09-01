#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// another one I didn't do too well on.

// Leaving some details out, but this is an implementation that I think is ok, and forced me to do some bitwise math.
// There are a ton of error checks I'm skipping specifically because I just wanted to get the logic correct
// but realistically there are probably a bunch of ways this could go wrong with invalid input. 
// We can handwave and say input is not user controlled. ;)
// anyway, I have a lot of other things I need to work on, but wanted to at least bang out a basic
// implementation. Was pretty fun tbh to just play with it.
// overall the smarter option would probably have been
// to just convert the entire IP address to binary and back, rather than going octet by octet. Maybe I'll update it someday.

// goal was to extract a subnet and subnet mask from an ip address string and cidr. 
// not exactly the same as the question I was asked, but similar.

unsigned char getOctet(unsigned char inOctet, int mask) {
   return inOctet << mask; 
}

unsigned char getMasked(unsigned char inOctet, int mask) {
    return inOctet & mask;
}
void printSubnet(char *ipAddr, int cidr) {
    int test_cidr = cidr;
    unsigned char octets[4];
    unsigned char byteVal;
    unsigned char octetMask;
    int sentinel = 0;
    char *token = strtok(ipAddr, ".");
    while( NULL != token) {
        unsigned char byteVal = (unsigned char)atoi(token);
        octets[sentinel] = byteVal;
        sentinel++;
        //printf("%d ", byteVal);
        token = strtok(NULL, ".");
    }
    
        
   // for (int i = 0; i < 4; i++) {
   //     
   //     printf("%d", octets[i]);
   //     if(3 > i) {
   //         printf(".");
   //     }
   // }
    // print the subnet id
    printf("\n");
    for (int i = 0; i < 4; i++) {
        if (test_cidr >= 8) {
            octetMask = 255; 
            byteVal = getMasked(octets[i], octetMask);
            printf("%d", byteVal);
            test_cidr -=8;
        }
        else if (0 == test_cidr) {
            printf("%d", 0);
        } else {
            octetMask = getOctet(255, test_cidr);
            unsigned char byteVal = getMasked(octets[i], octetMask);
            printf("%d", byteVal);
            test_cidr -= test_cidr;
        }
        if (3 > i) {
            printf(".");
        }
        
        
    }     
    printf("\n");
    
    
    // get subnet mask
    for (int i = 0; i < 4; i++) {
        if (cidr >= 8) {
            printf("255");
            cidr -=8;
        }
        else if (0 == cidr) {
            printf("0");
        } else {
            byteVal = getOctet(255, 8 - cidr);
            printf("%d", byteVal);
            cidr -= cidr;
        }
        if (3 > i) {
            printf(".");
        }
        
    }
    printf("\n");
     
}

int main()
{
    char ipAddr[16] = "192.168.192.129";
    int cidr = 31;
    printf("%s/%d\n", ipAddr, cidr);
    printSubnet(ipAddr, cidr); 
     
    
    return 0;
}
