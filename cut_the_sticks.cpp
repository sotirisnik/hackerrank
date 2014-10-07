#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

#define MAXN 10001

using namespace std;

int n, cuts;
int A[MAXN];

int main( ) {
    
    scanf( "%d", &n );
    
    for ( int i = 1; i <= n; ++i ) {
        scanf( "%d", &A[i] );
    }
    
    
    while ( true ) {
    
        int Minim = -1;
        
        for ( int j = 1; j <= n; ++j ) {
            if ( A[j] == 0 ) {
                continue;
            }
            if ( Minim == -1 ) {
                Minim = A[j];
            }else {
                Minim = min( Minim, A[j] );
            }
        }
        
        if ( Minim == -1 ) {
            break;
        }
        
        cuts = 0;
        
        for ( int i = 1; i <= n; ++i ) {
            if ( A[i] >= Minim ) {
                A[i] -= Minim;
                ++cuts;
            }
        }
    
        printf( "%d\n", cuts );
    
    }
    
    return 0;

}