#include <iostream>
#include <string>

using namespace std;

int reverse( int *arr, int s, int e ) 
{
    int temp( 0 ), result( 0 );
        for( int i( s ); i <= e; i++ ) 
        {
            for ( int j( s + 1 ); j <= e - i + s; j++ ) 
            {
                temp = arr[ j - 1 ];
                arr[ j - 1 ] = arr[ j ];
                arr[ j ] = temp;
            }
        }
    return e - s + 1;
}

int minimun( int *arr, int length, int s ) 
{
    int result = s;
        for ( int i( s ); i < length; i++ )
        {
            if ( arr[ i ] < arr[ result ] ) 
            {
                result = i;
            }
        }
    return result;
}

int reversort( int *arr, int length ) 
{
    int result( 0 ), j;
        for ( int i( 0 ); i < length - 1; i++ ) 
        {
            j = minimun( arr, length, i );
            result += reverse( arr, i,  j );
        }
    return result;
}

int toInt( string list ) 
{
    int i = 0;
    char result[ list.length() + 1 ];
        for( char j: list ) 
        {
            result[ i ] = j;
            i++;
        }
        result[ list.length() ] = '\0';
    return atoi( result );
}

int init( string data, int const length ) 
{
    int result[ length ], j = 0;
    string part( "" );

    for( int i( 0 ); i < data.size(); i++ )
    {
        if ( data[ i ] == ' ' ) {
            result[ j ] = toInt( part );
            part = "";
            j++;
        } else {
            part += data[ i ];
        }
    }

    return reversort( result, length );
}

int main()
{
    int lines( 0 ), i( 0 ), size;
    string data;
    cin >> lines;
    int arr[ lines ];
        while ( i < lines ) 
        {
            cin >> size;
            cin.ignore();
            getline( cin, data );
            arr[ i ] = init( data + ' ', size );
            i++;
        }

        for ( i = 0; i < lines; i++ )
            cout << "Case #" << i + 1 << ": "  << arr[ i ] << endl;
    return 0;
}
