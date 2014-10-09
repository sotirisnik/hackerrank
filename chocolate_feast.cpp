#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

int t, money_left, choco_price, m, cnt, total;

int main( ) {
    
    scanf( "%d", &t );
    
    while ( t-- ) {
    
        scanf( "%d %d %d", &money_left, &choco_price, &m );

        total = cnt = 0;
    
        int how = money_left / choco_price;
        
        money_left -= how*choco_price;
        
        cnt += how;
        total += how;
        
        while ( cnt >= m ) {
            cnt -= m-1;
            total += 1;
        }
      
        printf( "%d\n", total );

    }
        
    return 0;

}