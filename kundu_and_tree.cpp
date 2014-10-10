#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <list>
#include <memory.h>
#include <algorithm>

#define MAXN 100000
#define MODN 1000000007

using namespace std;

int n, from, to, teamid;
char color;
vector < list<int> > adj(MAXN+1);
bool visited[MAXN+1];
int group[MAXN+1], cnt[MAXN+1];
long long memo[MAXN+1][4];

long long best( int i, int how ) {

    if ( how > 3 ) {
        return 0;
    }

    if ( i == teamid+1 ) {
        if ( how == 3 ) {
            return 1;
        }
        return ( 0 );
    }

    if ( memo[i][how] != -1 ) {
        return ( memo[i][how] );
    }
    
    long long c1 = best( i + 1, how );
    long long c2 = cnt[i] * best( i + 1, how + 1 );

    memo[i][how] = ( c1 + c2 ) % MODN;
    
    return ( memo[i][how] );
    
}

void dfs( int u ) {

    visited[u] = true;
    
    group[u] = teamid;
    
    ++cnt[ teamid ];
    
    for ( list<int>::iterator pos = adj[u].begin(); pos != adj[u].end(); ++pos ) {
        if ( !visited[*pos] ) {
            dfs( *pos );
        }
    }

}

int main( ) {
    
    scanf( "%d", &n );
    
    for ( int i = 1; i < n; ++i ) {
    
        scanf( "%d %d %c", &from, &to, &color );
    
        if ( color == 'r' ) {
            continue;
        }
        
        adj[from].push_back( to );
        adj[to].push_back( from );
        
    }
    
    for ( int i = 1; i <= n; ++i )
        if ( !visited[i] ) {
            ++teamid;
            dfs( i );
        }
    
    memset( memo, -1, sizeof( memo ) );
    
    printf( "%lld\n", best( 0, 0 ) );
        
    return 0;

}