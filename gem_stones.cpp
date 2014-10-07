#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

#define MAXN 101

using namespace std;

int n, ans;
bool used[MAXN][26];
char text[MAXN+1];

int main( ) {
    
    scanf( "%d", &n );
    
    for ( int i = 0; i < n; ++i ) {
    
        scanf( "%s", text );
        
        for ( int j = 0; text[j] != '\0'; ++j )
            used[i][ text[j]-'a' ] = true;
    
    }
    
    for ( int i = 0; i < 26; ++i ) {
    
        bool ok = true;
    
        for ( int j = 0; j < n && ok; ++j ) {
            if ( !used[j][i] ) {
                ok = false;
            }
        }
        
        if ( ok ) {
            ++ans;
        }
        
    }
    
    printf( "%d\n", ans );
    
    return 0;

}