#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

#define MAXN 1000

using namespace std;

char text[MAXN+1];
int s;

int main( ) {
    
    gets( text );
    
    for ( int i = 0; text[i] != '\0'; ++i ) {
    
        if ( text[i] == ' ' ) {
            continue;
        }else if ( text[i] < 'a' ) {
            text[i] += 'a'-'A';
        }
    
        s |= ( 1 <<(text[i]-'a') );
        
    }
    
    if ( s == (1<<26)-1 ) {
        printf( "pangram\n" );
    }else {
        printf( "not pangram\n" );
    }
    
    return 0;

}