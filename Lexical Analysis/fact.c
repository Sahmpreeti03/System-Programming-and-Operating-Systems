#include <stdio.h>
// roll no 32255
void main()
{
	int n ;
	float tp = 0.0 ;
	scanf( "%d" , &n ) ;
	if( n < 0 )
	{
		printf( "complex" ) ;
	}
	else if( n == 0 )
	{
		printf( "1" ) ;
	}
	else
	{
		int f = 1 , i ;
		for( i = 1 ; i <= n ; i ++ )
		f = f * i ;
		printf( "%d" , f ) ;
	}
}

