#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <set>
#include <algorithm>

#define MAXN 10000

using namespace std;

char text[MAXN+1];
multiset <char> s1, s2;
int t, len, mid;

int main( ) {
    
    scanf( "%d", &t );
    
    while ( t-- ) {
        
        scanf( "%s", text );
     
        len = strlen( text );
        
        if ( len & 1 ) {
            printf( "-1\n" );
            continue;
        }
        
        mid = len / 2;
        
        int cnt1 = 0;
        int cnt2 = 0;
        
        s1.clear();
        s2.clear();
        
        for ( int i = 0; i < mid; ++i ) {
            s1.insert( text[i] );
            s2.insert( text[len-i-1] );
        }
        
        for ( multiset<char>::iterator pos = s1.begin(); pos != s1.end(); ++pos ) {
            if ( s2.find( *pos ) != s2.end() ) {
                multiset<char>::iterator tmp = s2.find( *pos );
                s2.erase( tmp );
            }
        }
        
        printf( "%d\n", s2.size() );
        
    }
    
    return 0;

}