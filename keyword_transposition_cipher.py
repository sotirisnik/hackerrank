def remove_duplicates( n ):
    
    memo = {}
    
    ret = ""
    
    for i in n:
        if i not in memo:
            ret = ret + i
            memo[i] = 1
            
    return ( ret )
    
def BuildMap( keyword ):
    
    global map
    
    keyword = remove_duplicates( keyword )
    
    Diagram = [ list(keyword) ]
    
    tmp = []
    
    cnt = 0
    
    for i in original:
        if i in keyword:
            continue
        tmp.append( i )
        cnt += 1
        if cnt % len(keyword) == 0:
            Diagram.append( tmp )
            tmp = []
    
    if len(tmp) > 0:
        Diagram.append( tmp )
    
    substitution = ""
    
    sorted_keyword = sorted( set( keyword ) )
    
    for i in range( 0, len( sorted_keyword ) ):
        for j in range( 0, len(keyword) ):
            if sorted_keyword[i] == Diagram[0][j]:
                top = 0
                while top < len(Diagram) and len( Diagram[top] ) >= j+1:
                    substitution += ( Diagram[top][j] );
                    top += 1
                    
    for i in range( 0, 26 ):
        map[ (substitution[i]) ] = original[i]
   
    return ( substitution )

original = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"    
map = {}
map[ (" ") ] = " "

t = int( raw_input() )

for i in range( 0,t ):
    
    BuildMap( raw_input() )
    
    ans = ""
    
    for i in raw_input():
        ans += map[(i)]
    
    print "%s" % ( ans )