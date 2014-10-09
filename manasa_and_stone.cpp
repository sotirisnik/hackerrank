#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <set>
#include <algorithm>

using namespace std;

int t, n, a, b;
set <int> s;

int main( ) {

	scanf( "%d", &t );
	
	while ( t-- ) {
	
		scanf( "%d %d %d", &n, &a, &b );
		
		s.clear();
				
		for ( int i = 0; i < n; ++i ) {
			s.insert( a*i + (n-i-1)*b );
		}
		
		set<int>::iterator pos = s.begin();
	
		printf( "%d", *pos );
		
		for ( ++pos; pos != s.end(); ++pos ) {
			printf( " %d", *pos );
		}
	
		putchar( '\n' );
	
	}

	return 0;

}