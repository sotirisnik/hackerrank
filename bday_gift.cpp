#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n, x;
double expect_val;

int main( ) {
    
    scanf( "%d", &n );
    
    while ( n-- ) {
        scanf( "%d", &x );
        expect_val += x;
    }
    
    expect_val *= 0.5;
    
    printf( "%.1lf\n", expect_val );
    
    return 0;

}