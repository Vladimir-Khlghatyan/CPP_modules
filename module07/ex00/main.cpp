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
    std::cout << "--- SUBJECT MAIN ----------\n" << std::endl;

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

    
    std::cout << "\n\n--- MY TESTS --------------\n" << std::endl;

    char char1 = '%';
    char char2 = 'g';

    ::swap( char1, char2 );
    std::cout << "char1 = \'" << char1 << "\'\nchar2 = \'" << char2 << "\'" << std::endl;
    std::cout << "min( char1, char2 ) = \'" << ::min( char1, char2 ) << "\'" << std::endl;
    std::cout << "max( char1, char2 ) = \'" << ::max( char1, char2 ) << "\'" << std::endl;
    std::cout << std::endl;

    int int1 = 24;
    int int2 = 42;

    ::swap( int1, int2 );
    std::cout << "int1 = " << int1 << "\nint2 = " << int2 << std::endl;
    std::cout << "min( int1, int2 ) = " << ::min( int1, int2 ) << std::endl;
    std::cout << "max( int1, int2 ) = " << ::max( int1, int2 ) << std::endl;
    std::cout << std::endl;

    float float1 = 4.2f;
    float float2 = -42.42f;

    ::swap( float1, float2 );
    std::cout << "float1 = " << float1 << "f\nfloat2 = " << float2 << "f" << std::endl;
    std::cout << "min( float1, float2 ) = " << ::min( float1, float2 ) << "f" << std::endl;
    std::cout << "max( float1, float2 ) = " << ::max( float1, float2 ) << "f" << std::endl;
    std::cout << std::endl;

    double double1 = 4242.42;
    double double2 = 42.4242;

    ::swap( double1, double2 );
    std::cout << "double1 = " << double1 << "\ndouble2 = " << double2 << std::endl;
    std::cout << "min( double1, double2 ) = " << ::min( double1, double2 ) << std::endl;
    std::cout << "max( double1, double2 ) = " << ::max( double1, double2 ) << std::endl;
    std::cout << std::endl;

    std::string string1 = "world";
    std::string string2 = "hello";

    ::swap( string1, string2 );
    std::cout << "string1 = \"" << string1 << "\"\nstring2 = \"" << string2 << "\"" << std::endl;
    std::cout << "min( string1, string2 ) = \"" << ::min( string1, string2 ) << "\"" << std::endl;
    std::cout << "max( string1, string2 ) = \"" << ::max( string1, string2 ) << "\"" << std::endl;
    std::cout << std::endl;

    return (0);
}












