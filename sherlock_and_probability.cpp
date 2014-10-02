#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>

#define MAXN 100000

using namespace std;

int t;
long long n, k, ones, pairs;
int F[MAXN+1];
char text[MAXN+1];

long long gcd( long long a, long long b ) {
    if ( b == 0 ) {
        return ( a );
    }
    return ( gcd( b, a % b ) );
}

long long range_sum( int i, int j ) {

    if ( i > j ) {
        return 0;
    }

    return ( F[j] - F[i-1] );
}

int main( ) {
    
    scanf( "%d", &t );
    
    while ( t-- ) {
    
        scanf( "%lld %lld %s", &n, &k, text );
        
        F[1] = text[0]-'0';
        
        ones = ( text[0]-'0' );
        
        for ( int i = 2; i <= n; ++i ) {
            F[i] = F[i-1] + (text[i-1]-'0');
            ones += ( text[i-1]-'0' );
        }
        
        pairs = 0;
        
        for ( int i = 1; i <= n; ++i ) {
        
            if ( text[i-1] != '1' ) {
                continue;
            }
        
            int from = i;
            int to1 = min( i+k, n );
            int to2 = max( 1LL, i-k );
            
            pairs += range_sum( from+1, to1 );
            pairs += range_sum( to2, from-1 );
            
        }
        
        long long GCD = gcd( pairs+ones, n*n );
        
        printf( "%lld/%lld\n", (pairs+ones) / GCD, (n*n) / GCD );
        
    }
    
    return 0;

}