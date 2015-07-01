#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

#define MAXN 40

using namespace std;

struct state {
    int x, y, cost;
    state( ) { }
    state( int x, int y, int cost ) : x(x), y(y), cost(cost) { }
};

bool operator <(const state &a , const state &b ) {
    return ( a.cost > b.cost );
}

int row, col, start_x, start_y, goal_x, goal_y;
char maze[MAXN+1][MAXN+1];
priority_queue < state > q;
int P[MAXN][MAXN];
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};
vector < pair<int,int> > path;

bool valid( int x, int y ) {
    return ( x >= 0 && y >= 0 && x < row && y < col );
}

void construct_path( int x, int y ) {

    if ( P[x][y] != -1 ) {
        construct_path( x - dx[ P[x][y] ], y - dy[ P[x][y] ] );
    }
    
    path.push_back( make_pair( x, y ) );

}

int manhattan( int x, int y ) {
    return ( abs( x - row + 1 ) + abs( y - col + 1 ) );
}

int main( ) {

    scanf( "%d %d %d %d %d %d", &start_x, &start_y, &goal_x, &goal_y, &row, &col );
    
    for ( int i = 0; i < row; ++i ) {
        scanf( " %s", maze[i] );
    }
    
    q.push( state( start_x, start_y, 0 ) );
    P[start_x][start_y] = -1;
    
    maze[goal_x][goal_y] = '-';
    maze[start_x][start_y] = '%';
    
    while ( !q.empty() ) {
    
        state top = q.top();
        q.pop();
        
        if ( top.x == goal_x && top.y == goal_y ) {
            break;
        }
        
        for ( int k = 0; k < 4; ++k ) {
            int next_x = top.x + dx[k];
            int next_y = top.y + dy[k];
            if ( valid( next_x, next_y ) ) {
                if ( maze[next_x][next_y] == '-' ) {
                    maze[next_x][next_y] = '%';
                    P[next_x][next_y] = k;
                    q.push( state( next_x, next_y, top.cost + 1 + manhattan( next_x, next_y ) ) );
                }
            }
        }
    
    }
    
    construct_path( goal_x, goal_y );
    
    printf( "%d\n", path.size() - 1 );
    
    for ( int i = 0; i < path.size(); ++i ) {
        printf( "%d %d\n", path[i].first, path[i].second );
    }
    
    return 0;

}