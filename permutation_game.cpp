#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>
#include <algorithm>

#define MAXN 15

using namespace std;

int t, n;
int A[MAXN];
bool memo[1<<MAXN][2];

bool check_increasing( int set ) {

    int prev = -1;

    for ( int i = 0; i < n; ++i ) {
    
        if ( set & (1<<i) ) {
            continue;
        }
        
        if ( prev == -1 ) {
            prev = A[i];
        }else {
            if ( prev > A[i] ) {
                return ( false );
            }
            prev = A[i];
        }
        
    }
    
    return ( true );

}

bool best( int set, bool turn ) {

    if ( check_increasing( set ) ) {
        return ( memo[set][turn] = false );
    }
    
    if ( memo[set][turn] ) {
        return ( memo[set][turn] );
    }
    
    bool Best = false;

    for ( int i = 0; i < n; ++i ) {
        if ( !( set & (1<<i) ) ) {
            if ( !best( set | (1<<i), !turn ) ) {
                return ( memo[set][turn] = true );
            }
        }
    }

    memo[set][turn] = Best;
    
    return ( memo[set][turn] );
    
}

int main( ) {

    scanf( "%d", &t );

    while ( t-- ) {
    
        scanf( "%d", &n );
    
        for ( int i = 0; i < n; ++i ) {
            scanf( "%d", &A[i] );
        }
        
        memset( memo, false, sizeof( memo ) );
        
        if ( best( 0, false ) ) {
            printf( "Alice\n" );
        }else {
            printf( "Bob\n" );
        }
     
    }
    
    return 0;

}