#include "whatever.hpp"

template <typename T>
void    swap(T& a, T& b)
{
    T   tmp;

    tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T   max(T& a, T& b)
{
    if (a > b)
        return (a);
    return (b);
}

template <typename T>
T   min(T& a, T& b)
{
    if (a < b)
        return (a);
    return (b);
}

int main(void)
{
    std::cout << YELLOW << "--- SUBJECT MAIN ----------" << RESET << std::endl;

    int a = 2;
    int b = 3;

    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    
    std::cout << YELLOW << "\n\n--- MY TESTS --------------" << RESET << std::endl;

    char char1 = '%';
    char char2 = 'g';

    ::swap( char1, char2 );
    std::cout << "\33[1;32mchar1\33[1;37m = \'" << char1 << "\'\n\33[1;32mchar2\33[1;37m = \'" << char2 << "\'" << std::endl;
    std::cout << "min( char1, char2 ) = \'" << ::min( char1, char2 ) << "\'" << std::endl;
    std::cout << "max( char1, char2 ) = \'" << ::max( char1, char2 ) << "\'" << std::endl;
    std::cout << std::endl;

    int int1 = 24;
    int int2 = 42;

    ::swap( int1, int2 );
    std::cout << "\33[1;32mint1\33[1;37m = " << int1 << "\n\33[1;32mint2\33[1;37m = " << int2 << std::endl;
    std::cout << "min( int1, int2 ) = " << ::min( int1, int2 ) << std::endl;
    std::cout << "max( int1, int2 ) = " << ::max( int1, int2 ) << std::endl;
    std::cout << std::endl;

    float float1 = 4.2f;
    float float2 = -42.42f;

    ::swap( float1, float2 );
    std::cout << "\33[1;32mfloat1\33[1;37m = " << float1 << "f\n\33[1;32mfloat2\33[1;37m = " << float2 << "f" << std::endl;
    std::cout << "min( float1, float2 ) = " << ::min( float1, float2 ) << "f" << std::endl;
    std::cout << "max( float1, float2 ) = " << ::max( float1, float2 ) << "f" << std::endl;
    std::cout << std::endl;

    double double1 = 4242.42;
    double double2 = 42.4242;

    ::swap( double1, double2 );
    std::cout << "\33[1;32mdouble1\33[1;37m = " << double1 << "\n\33[1;32mdouble2\33[1;37m = " << double2 << std::endl;
    std::cout << "min( double1, double2 ) = " << ::min( double1, double2 ) << std::endl;
    std::cout << "max( double1, double2 ) = " << ::max( double1, double2 ) << std::endl;
    std::cout << std::endl;

    std::string string1 = "world";
    std::string string2 = "hello";

    ::swap( string1, string2 );
    std::cout << "\33[1;32mstring1\33[1;37m = \"" << string1 << "\"\n\33[1;32mstring2\33[1;37m = \"" << string2 << "\"" << std::endl;
    std::cout << "min( string1, string2 ) = \"" << ::min( string1, string2 ) << "\"" << std::endl;
    std::cout << "max( string1, string2 ) = \"" << ::max( string1, string2 ) << "\"\33[0;m" << std::endl;
    std::cout << std::endl;

    return (0);
}
