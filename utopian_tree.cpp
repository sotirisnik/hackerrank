#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

int t, n, height;
bool moonset;

int main( ) {
    
    scanf( "%d", &t );
  
    while ( t-- ) {
        scanf( "%d", &n );
    
        moonset = false;
    
        height = 1;
        
        while ( n-- ) {
        
            if ( moonset ) {
                height += 1;
            }else {
                height *= 2;
            }
            
            moonset = !moonset;
            
        }
        
        printf( "%d\n", height );
        
    }
    
    return 0;

}