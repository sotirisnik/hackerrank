#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>

#define MAXN 10000

using namespace std;

int t, len, ans;
char text[MAXN+1];

int main( ) {
    
    scanf( "%d", &t );
    
    while ( t-- ) {
        
        scanf( "%s", text );
        
        len = strlen( text );
        
        ans = 0;
        
        int i = 0;
        int j = len-1;
        
        while ( i < j ) {
            
            if ( text[i] > text[j] ) {
                ans += text[i] - text[j];
            }else {
                ans += text[j] - text[i];
            }
            
            ++i;
            --j;
            
        }
        
        printf( "%d\n", ans );
        
    }
    
    return 0;

}