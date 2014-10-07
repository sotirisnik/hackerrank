#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

#define MAXN 100001

using namespace std;

int cnt[26];
char text[MAXN+1];

int main( ) {
    
    scanf( "%s", text );
    
    for ( int i = 0; text[i] != '\0'; ++i ) {
        cnt[ text[i]-'a' ] = 1 - cnt[ text[i]-'a' ];
    }
    
    int how = 0;
    
    for ( int i = 0; i < 26 && how < 2; ++i )
        if ( cnt[i] )
            ++how;
    
    if ( how <= 1 ) {
        printf( "YES\n" );
    }else {
        printf( "NO\n" );
    }
    
    return 0;

}