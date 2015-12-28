/*************************************************************************
 *  --------->    FILE: Hermite.cpp
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 12/08/2015    TIME:21:07:15
 ************************************************************************/

#include <iostream>
using namespace std;
int hermite( int n, int x ); 
int main() {
    int n, x;
    cin >> n >> x;
    int i;
    for (i = 0; i <= n; i++) {
        cout << hermite(i, x) << " ";
    }
    return 0;
}

int hermite( int n, int x ) {
    int result;
    
    if( n <= 0 )
        result = 1;
    else {
        if(n == 1)
            result = 2 * x;
        else
            result = 2 * x * hermite( n - 1, x ) - 2 * ( n - 1 ) * hermite( n - 2, x );
    }       
    return result;
}
