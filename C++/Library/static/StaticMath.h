/*************************************************************************
 *  --------->    FILE: staticMath.h
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 08/31/2015    TIME:16:26:48
 ************************************************************************/

#ifndef _STATICMATH_H
#define _STATICMATH_H
class StaticMath {
public:    
    StaticMath(void);
    ~StaticMath(void);
    static double add(double a, double b);
    static double sub(double a, double b);
    static double mul(double a, double b);
    static double div(double a, double b);

};
#endif

