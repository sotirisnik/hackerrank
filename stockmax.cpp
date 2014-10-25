#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

#define MAXN 50001

using namespace std;

int t, n;
long long A[MAXN];
bool sell[MAXN];

int main( ) {

    scanf( "%d", &t );
    
    while ( t-- ) {
    
        scanf( "%d", &n );
        
        for ( int i = 1; i <= n; ++i ) {
            scanf( "%lld", &A[i] );
            sell[i] = 0;
        }
        
        long long ans = 0;
        long long tmp = 0;
        long long MaximTemp = 0;
        long long how = 0;
        
        for ( int i = n; i >= 1; --i )
            if ( MaximTemp < A[i] ) {
                MaximTemp = A[i];
                sell[i] = true;
            }
        
        for ( int i = 1; i <= n; ++i ) {
        
            if ( !sell[i] ) {
                tmp += A[i];
                ++how;
            }else {
                ans += A[i] * how - tmp;
                tmp = 0;
                how = 0;
            }
        
        }

        printf( "%lld\n", ans );
    
    }

    return 0;

}