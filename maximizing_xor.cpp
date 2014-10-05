#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

int L, R, ans;

int main( ) {
    
    scanf( "%d %d", &L, &R );
    
    for ( int i = L; i <= R; ++i ) {
        for ( int j = L; j <= R; ++j ) {
            ans = max( ans, i^j );
        }
    }
    
    printf( "%d\n", ans );
    
    return 0;

}