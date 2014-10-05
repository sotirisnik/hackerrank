#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

#define MAXN 100000

using namespace std;

struct state {
    int val;
};

state node[4*MAXN];

int n, q, from, to;
int A[MAXN+1];

state combine( state q1, state q2 ) {

    state ret;
    
    ret.val = min( q1.val, q2.val );
    
    return ( ret );

}

void build( int v, int begin, int end ) {
    
    if ( begin == end ) {
        node[v].val = A[begin];
        return;
    }
    
    int mid = ( begin + end ) / 2;
    
    build( 2*v, begin, mid );
    build( 2*v+1, mid+1, end );
    
    node[v] = combine( node[2*v], node[2*v+1] );
    
}

state query( int v, int x, int y, int qx, int qy ) {

    if ( qx == x && qy == y ) {
        return ( node[v] );
    }
    
    int mid = ( x + y ) / 2;
    
    if ( qy <= mid ) {
        return ( query( 2*v, x, mid, qx, qy ) );
    }else if ( qx > mid ) {
        return ( query( 2*v+1, mid+1, y, qx, qy ) );
    }else {
        state q1 = query( 2*v, x, mid, qx, mid );
        state q2 = query( 2*v+1, mid+1, y, mid+1, qy );
        return ( combine( q1, q2 ) );
    }

}

int main( ) {
    
    scanf( "%d %d", &n, &q );
    
    for ( int i = 1; i <= n; ++i ) {
        scanf( "%d", &A[i] );
    }
    
    build( 1, 1, n );
    
    while ( q-- ) {
    
        scanf( "%d %d", &from, &to );
    
        printf( "%d\n", query( 1, 1, n, from+1, to+1 ).val );
    
    }
    
    return 0;

}