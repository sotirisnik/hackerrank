#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

int t;
long long k, ans;

int main( ) {
    
    scanf( "%d", &t );
    
    while ( t-- ) {
    
        scanf( "%d", &k );
        
        ans = ( k / 2 ) * ( k - ( k / 2 ) );
            
        printf("%lld\n", ans );
        
    
    }
    
    return 0;

}