/*************************************************************************
 *  --------->    FILE: error.cpp
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 12/08/2015    TIME:11:06:19
 ************************************************************************/
#include <iostream>
using namespace std;
double H(double ,int );
int main()
{
    double x;
    int n;
    int i;
    cin>>n>>x;
    for(i=0;i<=n;i++)
        cout<<H(x,i)<<endl;
    return 0;

}
double H(double x,int n)
{
    double result;
    if(n==0)
        return(1);
    else if(n==1)
        return(2*x);
    else
        return(2*x*H(x,(n-1))-2*(n-1)*H(x,(n-2)));

}
