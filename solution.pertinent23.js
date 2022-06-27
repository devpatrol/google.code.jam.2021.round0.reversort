const readline = require( 'readline' ).createInterface( process.stdin, process.stdout );
let max = 0, lines = 0;

const reverse = ( tab = [], i, j ) => (
    ( i !== 0 ? tab.slice( 0, i ) : [] ).concat( tab.slice( i, j + 1 ).reverse() ).concat( j >= tab.length - 1 ? [] : tab.slice( j + 1 ) )
);

const reverseMax = ( tab = [], base = 0 ) => {
    let 
        i = base;
    return tab.forEach( ( el, is ) => ( el < tab[ i ] && is >= base ? i = is : true  ) ) || i;
};

const reverseSort = ( tab = [] ) => {
    tab = tab.map( i => parseInt( i ) );
    let result = 0, max, length = tab.length;
        for ( let i = 0; i < length - 1; i++ ) {
            max = reverseMax( tab, i );
            tab = reverse( tab, i, max );
            result += max - i + 1;
        }
    return result;
};

readline.on( 'close', () => process.exit( 0 ) );
readline.on( 'line', ( data ) => {
    lines++;
    if ( !max ) max = parseInt( data );
    else {
        if ( lines % 2 ) {
            console.log( `Case #${ ( lines - 1 ) / 2  }: ${ reverseSort( data.split( ' ' ) ) }` )
            lines - 1 === max * 2 ? readline.close() : {};
        }
    }
} );