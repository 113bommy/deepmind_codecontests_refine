#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <cctype> // tolower
#include <ctime>
#include <cmath>

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <stdexcept>

#include <map>
#include <set>
#include <list>
#include <queue>
#include <vector>
#include <string>

#include <limits>
#include <utility>

#include <numeric>
#include <iterator>
#include <algorithm>
#include <functional>

/*
 * g++ -g -std=c++11 -DBUG -D_GLIBCXX_DEBUG -Wall -Wfatal-errors -o cforce{,.cpp}
 * g++ -g -DBUG -D_GLIBCXX_DEBUG -Wall -Wfatal-errors -o cforce{,.cpp}
 *
 * TODO:
 *      C++ dataframe
 *      stl11 -> c++11 standard template lib in c++98
 *      overload >> for map and set, using (insert) iterator
 *      chmod:: consider an algorithm stable to int64 overflow
 *      shortest path algorithm
 *      shortest path in a tree
 *      maximum network flow
 *      partial idx/iter sort
 *      a prime number generator which traverses prime numbers w/ ++
 *      a divisor generator which traverses divisors efficiently
 *      Apply1st ?!
 *      Apply2nd and bind2nd ?!
 *          count_if ( a.begin(), a.end(), a.second < x )
 *      Arbitrary-precision arithmetic / Big Integer / Fraction - rational num
 *      tuple class --> cplusplus.com/reference/tuple
 *      get<1>, get<2>, bind2nd ( foo ( get<2> pair ), val )
 *      isin( const T & val, first, last )
 *      fuinction composition in c++
 *          blogea.bureau14.fr/index.php/2012/11/function-composition-in-c11/
 *          cpp-next.com/archive/2010/11/expressive-c-fun-with-function-composition/
 *      TimeWrapper -- accumulate time of a function call
 *          stackoverflow.com/questions/879408
 *      hash map -- possible hash value & obj % some_big_prime [ b272 ]
 *          lower level can be a simple map to resolve hash collisions
 *      add explicit everywhere necessary
 *      bloom filters
 *      heap -> how to update values in place / increase-key or decrease-key ... IterHeap ?!
 *      median maintaince --> max_heap / min_heap
 *      prim's min spaning tree alg. O ( m log n ) using heap contianing V - X vertices
 *      kruskal algorithm minimum cost spanning tree with union find data structure
 *      unique_ptr
 *      hufman codes
 *      simple arithmatic tests
 *      longest common subsequence using seq. alignment type algorithm
 *      longest common substring ( consequative subsequeance )
 *      Graham scan; en.wikipedia.org/wiki/Graham_scan
 */

/*
 * @recepies
 * ----------------------------------------------
 * odd / even
 *      transform ( x.begin(), x.end(), x.begin(), bind2nd( modulus<int>(), 2 ));
 *      count_if ( x.begin(), x.end(), bind2nd( modulus < int > (), 2));
 * Apply2nd
 *      max_element ( m.begin(), m.end(), Apply2nd < string, int , less < int > > )
 *      sort ( a.begin(), a.end(), Apply2nd < char, int , greater< int > > )
 *      count_if ( m.begin(), m.end(), Apply2nd < string, int, modulus < int > > )
 *      accumulate ( m.begin(), m.end(), 0.0, Apply2nd < int, double, plus < double > > )
 *      accumulate ( m.begin( ), m.end( ), pair < int, double> ( 0 , 0.0 ) , operator+ < int, double > )
 * abs_diff
 *      adjacent_difference ( a.begin(), a.end(), adj_diff.begin( ), abs_diff < int > ( ) )
 *      accumulate ( a.begin(), a.end(), 0, abs_diff < int > ( ) )
 * erase
 *      a.erase ( remove_if ( a.begin( ), a.end( ), bind2nd ( less < int >( ), 0 ) ), a.end( ) )
 *      a.erase ( remove ( a.begin( ), a.end( ), b.begin( ), b.end( ) ), a.end ( ) )
 * binding
 *      bind2nd ( mem_fun_ref (& ClassName::m_func ), arg )  // binds the argument of the object
 * iterator generators
 *      generate_n ( back_inserter ( a ), n, rand );  // calls push_back
 *      generate_n ( inserter( a, a.begin( ) + 5 ), 10, RandInt( 0 , 100 ) )  // calls insert
 *      copy ( foo.begin( ), foo.end( ), insert_iterator < std::list < double > > ( bar, bar.begin( ) + 5 ))
 * copy ( a.begin( ), a.end( ), ostream_iterator < double > ( cout, ", " ))
 * accumulate ( m.begin( ), m.end( ), pair < int, double> ( 0 , 0.0 ) , operator+ < int, double > )
 * transform (numbers.begin(), numbers.end(), lengths.begin(), mem_fun_ref(&string::length));
 */

/*
 * @good read
 * ----------------------------------------------
 *  [ partial ] template specialization
 *      cprogramming.com/tutorial/template_specialization.html
 *  function composition
 *      cpp-next.com/archive/2010/11/expressive-c-fun-with-function-composition
 */

/*
 * @prob set
 * ----------------------------------------------
 *  purification --> c330
 */

/*
 * @limits
 * ----------------------------------------------
 * int                  31    2.14e+09
 * long int             31    2.14e+09
 * unsigned             32    4.29e+09
 * long unsigned        32    4.29e+09
 * size_t               32    4.29e+09
 * long long int        63    9.22e+18
 * long long unsigned   64    1.84e+19
 */

/*
 * issues
 * ----------------------------------------------
 * stackoverflow.com/questions/10281809
 * mem_fun -> func_obj ( pointer to instance, origanal argument )
 * bind1st ( mem_fun ( & ClassName::m_func ), this )    // binds obj of the class
 * bind1st takes 'const T &' as the first argument
 */

/*
 *  typedef / define
 * ----------------------------------------------
 */

typedef          long long int  int64;
typedef unsigned long long int uint64;

#define DOUBLE_INF std::numeric_limits< double >::infinity()
#define DOUBLE_NAN std::numeric_limits< double >::quiet_NaN()

#define DECLARE( X ) \
    typedef       shared_ptr < X >  X ## _shared_ptr; \
    typedef const shared_ptr < X >  X ## _const_shared_ptr;

#ifdef BUG
    #define DEBUG(var) { std::cout << #var << ": " << (var) << std::endl; }
    #define EXPECT(expr) if ( ! (expr) ) std::cerr << "Assertion " \
        << #expr " failed at " << __FILE__ << ":" << __LINE__ << std::endl;
#else
    #define DEBUG(var)
    #define EXPECT(expr)
#endif


#define DBG(v) std::copy( v.begin(), v.end(), std::ostream_iterator < typeof( *v.begin() )> ( std::cout, " " ) )

/*
 * http://rootdirectory.de/wiki/SSTR()
 * usage:
 *      SSTR( "x^2: " << x*x )
 */
#define SSTR( val ) dynamic_cast< std::ostringstream & >( std::ostringstream() << std::dec << val ).str()


/* https://www.quora.com/C++-programming-language/What-are-some-cool-C++-tricks */
// template <typename T, size_t N>
// char (&ArraySizeHelper(T (&array)[N]))[N];
// #define arraysize(array) (sizeof(ArraySizeHelper(array)))

/*
 * forward decleration
 * ----------------------------------------------
 */
class ScopeTimer;

/*
 *  functional utils
 * ----------------------------------------------
 */

template < typename T >
struct abs_diff : std::binary_function < T, T, T >
{
    typedef T value_type;

    inline value_type operator( ) ( const value_type & x, const value_type & y ) const
    {
        return std::abs( x - y );
    }
};

// template < class InputIterator, class T >
// class isin : public std::binary_function < InputIterator, InputIterator, bool >
// {
//     public:
//         typedef T value_type;
//
//         isin ( const InputIterator & first, const InputIterator & last ):
//             m_first ( first ), m_last ( last ) { }
//
//         bool operator ( ) ( const value_type & val ) const
//         {
//             return std::find ( m_first, m_last, val ) != m_last;
//         }
//     private:
//         const InputIterator m_first, m_last;
// }

template < typename value_type, typename cont_type >
class isin : public std::unary_function < value_type, bool >
{
    public:
        isin( const cont_type & vals ): m_vals ( vals ) { };

        bool operator ( ) ( const value_type & x ) const
        {
            return std::find ( m_vals.begin( ), m_vals.end( ), x ) != m_vals.end( );
        }

    private:
        const cont_type m_vals;
};

/*
 * max_element, min_element, count_if ... on the 2nd element
 * eg: max_element ( m.begin(), m.end(), Apply2nd < string, int , less < int > > )
 */
template < class T1, class T2, class BinaryOperation >
class Apply2nd : std::binary_function < typename std::pair < T1, T2 >,
                                        typename std::pair < T1, T2 >,
                                        typename BinaryOperation::result_type >
{
    public:
        typedef T1 first_type;
        typedef T2 second_type;

        typedef typename BinaryOperation::result_type result_type;
        typedef typename std::pair < first_type, second_type > value_type;

        inline result_type operator( ) ( const value_type & x, const value_type & y ) const
        {
            return binary_op ( x.second , y.second );
        }
    private:
        BinaryOperation binary_op;
};

/*
 * algo utils
 * ----------------------------------------------
 */


/**
 * count the number of inversions in a permutation; i.e. how many
 * times two adjacent elements need to be swaped to sort the list;
 * 3 5 2 4 1  -->  7
 */
template < class InputIterator >
typename std::iterator_traits<InputIterator>::difference_type
count_inv ( InputIterator first, InputIterator last )
{
    typedef typename std::iterator_traits<InputIterator>::difference_type difference_type;
    typedef typename std::iterator_traits<InputIterator>::value_type value_type;

    std::list < value_type > l; /* list of sorted values */
    difference_type cnt = 0;

    for ( difference_type n = 0; first != last; ++first, ++n )
    {
        /* count how many elements larger than *first appear before *first */
        typename std::list < value_type >::iterator iter = l.begin( );
        cnt += n;

        for ( ; iter != l.end( ) && * iter <= * first; ++ iter, -- cnt )
            ;
        l.insert( iter, * first );
    }

    return cnt;
}

template < class ForwardIterator, class T >
inline void fill_inc_seq ( ForwardIterator first, ForwardIterator last, T val )
{
    for ( ; first != last; ++first, ++val )
        * first = val;
}

template <class ForwardIterator, class InputIterator >
ForwardIterator remove ( ForwardIterator first, ForwardIterator last, InputIterator begin, InputIterator end )
{
    ForwardIterator result = first;

    for ( ; first != last; ++ first )
        if ( find ( begin, end, *first ) == end )
        {
            *result = *first;
            ++result;
        }

    return result;
}

/* stackoverflow.com/questions/1577475 */
template < class RAIter, class Compare >
class ArgSortComp
{
    public:
        ArgSortComp ( const RAIter & first, Compare comp ):  m_first ( first ), m_comp( comp ) { }
        inline bool operator() ( const size_t & i, const size_t & j ) const
        {
            return m_comp (  m_first[ i ] ,  m_first[ j ] );
        }
    private:
        const RAIter & m_first;
        const Compare m_comp;
};

/*!
 * usage:
 *      vector < size_t > idx;
 *      argsort ( a.begin( ), a.end( ), idx, less < Type > ( ) );
 */
template < class RAIter, class Compare >
void argsort ( const RAIter & first, const RAIter & last, std::vector < size_t > & idx, Compare comp )
{
    const size_t n = last - first;
    idx.resize ( n );

    for ( size_t j = 0; j < n; ++ j )
        idx[ j ] = j ;

    std::stable_sort ( idx.begin( ), idx.end( ), ArgSortComp< RAIter, Compare > ( first, comp ) );
}

template < class RAIter, class Compare >
class IterSortComp
{
    public:
        IterSortComp ( Compare comp ): m_comp ( comp ) { }
        inline bool operator( ) ( const RAIter & i, const RAIter & j ) const
        {
            return m_comp ( * i, * j );
        }
    private:
        const Compare m_comp;
};

/*!
 * usage:
 *      vector < list < Type >::const_iterator > idx;
 *      itersort ( a.begin( ), a.end( ), idx, less < Type > ( ) );
 */
template <class INIter, class RAIter, class Compare>
void itersort ( INIter first, INIter last, std::vector < RAIter > & idx, Compare comp )
{
    /* alternatively: stackoverflow.com/questions/4307271 */
    idx.resize ( std::distance ( first, last ) );
    for ( typename std::vector < RAIter >::iterator j = idx.begin( ); first != last; ++ j, ++ first )
        * j = first;

    std::sort ( idx.begin( ), idx.end( ), IterSortComp< RAIter, Compare > (comp ) );
}


/*
 *  string utils
 * ----------------------------------------------
 */

inline void erase ( std::string & str, const char & ch )
{
    std::binder2nd < std::equal_to < char > > isch ( std::equal_to < char > ( ), ch );
    std::string::iterator iter = std::remove_if ( str.begin(), str.end(), isch );
    str.erase ( iter, str.end() );
}

inline void erase ( std::string & str, const std::string & chrs )
{
    isin < char, std::string > isin_chrs ( chrs );
    std::string::iterator iter = std::remove_if ( str.begin(), str.end(), isin_chrs );
    str.erase ( iter, str.end() );
}

template < typename value_type>
inline std::string val2str ( const value_type & x )
{
    std::ostringstream sout ( std::ios_base::out );
    sout << x;
    return sout.str();
}

template < typename value_type>
inline value_type str2val ( const std::string & str )
{
    std::istringstream iss ( str, std::ios_base::in );
    value_type val;

    iss >> val;
    return val;
}

std::vector< std::string > tokenize ( const std::string & str, const char & sep )
{
    /*!
     * outputs empty tokens and assumes str does not start with sep
     * corner cases:
     *      empty string, one char string,
     *      string starting/ending with sep, all sep, end with two sep
     */

    std::vector < std::string > res;
    std::string::const_iterator follow = str.begin( ),
                                lead   = str.begin( );

    while ( true )
    {
        while ( lead != str.end() && * lead != sep )
            ++ lead;

        res.push_back ( std::string( follow, lead ) );

        if ( lead != str.end ( ) )
            follow = 1 + lead ++ ;
        else
            break;
    }

    return res;
}

/*!
 * chunk a string into strings of size [ at most ] k
 */
void chunk ( const std::string::const_iterator first,
             const std::string::const_iterator last,
             const size_t k,
             const bool right_to_left,
             std::list < std::string > & str_list )
{
    str_list.clear( );

    if ( right_to_left )
        /* chunk from the end of the string */
        for ( std::string::const_iterator i, j = last; j != first; j = i )
        {
            i = first + k < j ? j - k : first;
            str_list.push_back ( std::string ( i, j ) );
        }
    else
        /* chunk from the begining of the string */
        for ( std::string::const_iterator i = first, j; i != last; i = j )
        {
            j = i + k < last ? i + k : last;
            str_list.push_back ( std::string ( i, j ) );
        }
}

/*!
 * next lexicographically smallest string
 * within char set a..z
 */
std::string & operator++( std::string & s )
{
    /* find the first char from right less than 'z' */
    std::string::reverse_iterator j = find_if( s.rbegin( ), s.rend( ),
            std::bind2nd( std::less < char > ( ), 'z' ));

    if ( j != s.rend( ))
    {
        ++ *j;
        std::fill( s.rbegin( ), j, 'a' );
    }
    else
        s.assign( s.length( ) + 1, 'a' );

    return s;
}

/*!
 * getline ( cin, str )
 *      requires ctrl-D
 *      cin >> str; does not pass after space char
 */


/*
 *  number utils
 * ----------------------------------------------
 */


class BigInteger
{
#if ULONG_MAX <= 1 << 32
    typedef long long unsigned val_type;
#else
    typedef long unsigned val_type;
#endif
    const static int WSIZE = 32;
    const static val_type BASE = 1LL << WSIZE;
    public:
    private:
        std::list < val_type > val;  /* val[ 0 ] is most significant */
        bool pos;                    /* true if sign is positive     */
};

/**
 * greatest common divisor - Euclid's alg.
 */
template < typename value_type > inline
value_type gcd ( value_type a, value_type b )
{
    return ! b ? a : gcd( b, a % b );

    // if ( a < 0 )  a = -a ;
    // if ( b < 0 )  b = -b ;
    // if ( a < b )  std::swap ( a, b );

    /* corner case: one of the values is zero */
    // if ( ! b )   return a;

    // for ( value_type r = a % b; r ; r = a % b )
    // {
    //     a = b;
    //     b = r;
    // }

    // return b;
}


/**
 * prime factorization
 */
template < class T >
void prime_factors( T n, std::map < T, size_t > & fac )
{
    for ( T k = 2; n > 1; ++ k )
        if ( ! ( n % k ) )
        {
            size_t & ref = fac[ k ];
            while ( ! ( n % k ) )
            {
                ++ ref;
                n /= k;
            }
        }
}

/* abs diff - safe for unsigned types */
template < class T >
inline T absdiff( T a, T b )
{
    return a < b ? b - a : a - b;
}


namespace
{
    template < class T >
    std::pair < T, T > __extgcd ( const T & x0, const T & y0,
                                  const T & x1, const T & y1,
                                  const T & r0, const T & r1 )
    {
        const T q  = r0 / r1;
        const T r2 = r0 % r1;

        if ( ! ( r1 % r2 ) )
            return std::make_pair < T, T > ( x0 - q * x1, y0 - q * y1 );

        const T x2 = x0 - q * x1;
        const T y2 = y0 - q * y1;

        return __extgcd ( x1, y1, x2, y2, r1, r2 );
    }
}

/**
 * extended euclidean algorithm: a x  +  b y = gcd( a, b)
 * en.wikipedia.org/wiki/Extended_Euclidean_algorithm
 */
template < class value_type > inline
std::pair < value_type, value_type > extgcd ( value_type a, value_type b )
{
    return a % b
        ? __extgcd < value_type > ( 1, 0, 0, 1, a, b )
        : std::make_pair < value_type, value_type > ( 0, 1 );
}


/**
 * modular multiplicative inverse
 * en.wikipedia.org/wiki/Modular_multiplicative_inverse
 */
template < class value_type > inline
value_type modinv ( value_type a, value_type m )
{
    const std::pair < value_type, value_type > coef ( extgcd( a, m ) );

    /* a needs to be coprime to the modulus, or the inverse won't exist */
    if ( a * coef.first + m * coef.second != 1 )
        throw std::runtime_error ( val2str( a ) + " is not coprime to " + val2str( m ));

    /* return a pos num between 1 & m-1 */
    return ( m + coef.first % m ) % m;
}

inline bool isnan ( const double & a )
{
    return ! ( a == a );
}

template < typename value_type >
inline value_type mini ( int n, ... )
{
    va_list vl;
    va_start (vl, n);
    value_type res = va_arg ( vl, value_type );

    for ( int i = 1; i < n; ++i ) {
        const value_type val = va_arg ( vl, value_type );
        res = std::min ( res, val );
    }

    va_end( vl );
    return res;
}

template < typename value_type >
inline value_type maxi ( int n, ... )
{
    va_list vl;
    va_start (vl, n);
    value_type res = va_arg ( vl, value_type );

    for ( int i = 1; i < n; ++i ) {
        const value_type val = va_arg ( vl, value_type );
        res = std::max ( res, val );
    }

    va_end( vl );
    return res;
}

// XXX look this up how is this implemented
template < class T >
inline int sign ( const T & x )
{
    if ( x == T() )
        return 0;
    else if ( x < T() )
        return -1;
    else
        return 1;
}

/*
 * change moduluos from n to m
 */
std::string chmod ( std::string num, const unsigned n, const unsigned m )
{
    const char * digit = "0123456789abcdefghijklmnopqrstuvwxyz";
    std::transform ( num.begin(), num.end(), num.begin(), tolower );

    isin < char, std::string > is_alpha_num ( digit );
    assert ( find_if ( num.begin( ), num.end( ), std::not1 ( is_alpha_num ) ) == num.end( ));

    unsigned long long int val ( 0 );

    if ( n == 10U )
    {
        std::istringstream iss ( num, std::ios_base::in );
        iss >> val;
    }
    else
        for ( std::string::const_iterator iter = num.begin( ); iter != num.end( ); ++ iter )
            val = val * n + ( 'a' <= *iter ? *iter - 'a' + 10U : *iter - '0');

    if ( m == 10U )
    {
        std::ostringstream sout ( std::ios_base::out );
        sout << val;
        return sout.str ( );
    }
    else
    {
        std::string res;
        for ( ; val ; val /= m )
            res.push_back( digit [ val % m ] );

        return res.length( ) ? std::string( res.rbegin( ), res.rend( )) : "0";
    }
}

template < class value_type >  /* a^n mod m */
value_type powmod ( value_type a, const value_type & n, const value_type & m )
{
    if ( a == 1 || ! n )
        return m != 1 ? 1 : 0;

    value_type res = 1;
    for ( value_type k = 1; k <= n; a = a * a % m, k = k << 1 )
        if ( k & n )
            res =  ( res * a ) % m;

    return res;
}

/*
 * Fermat pseudoprime test
 * www.math.umbc.edu/~campbell/Computers/Python/numbthy.py
 * NOTE: since return type is bool, and powmod may break for ints,
 *       the argument is always casted to long long
 */
inline bool is_pseudo_prime ( const long long & a )
{
    /* all the primes less than 1000 ( 168 primes )*/
    const long long p [ ] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,
                              79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,
                              163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,
                              241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,
                              337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,
                              431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,
                              521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,
                              617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,
                              719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,
                              823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,
                              929,937,941,947,953,967,971,977,983,991,997 };

    const size_t n = sizeof( p ) / sizeof ( p[ 0 ] );

    if ( a < p[ n - 1 ] + 1)
        return std::binary_search ( p, p + n , a );

    if ( std::find_if ( p, p + n, std::not1 ( std::bind1st ( std::modulus< long long >( ), a ))) != p + n )
        return false;

    const size_t k = a <    9006401LL ? 3 :
                     a <   10403641LL ? 4 :
                     a <   42702661LL ? 5 :
                     a < 1112103541LL ? 6 : 7;

    for ( size_t j = 0; j < k; ++ j )
        if ( powmod ( p[ j ], a - 1, a ) != 1 )
            return false;

    return true;
}


/*
 * returns a sorted vector of all primes less than or equal to n
 * maximum adj diff of all primes less than 1e5 is 72 ( 114 for 1e6 )
 */
template < typename value_type >
std::vector < value_type > get_primes ( const value_type n )
{
#ifdef BUG
    ScopeTimer scope_timer ( "std::vector < value_type > get_primes ( const value_type n )" );
#endif

    typedef typename std::vector < value_type >::iterator iterator;
    std::vector < value_type > primes;

    for ( value_type k = 2 ; k <= n; ++ k )
        if ( is_pseudo_prime ( k ) )
        {
            const value_type sqrt_k = 1 + static_cast < value_type > ( sqrt ( k + 1 ) );
            iterator iend = upper_bound ( primes.begin( ), primes.end( ), sqrt_k );

            if ( find_if ( primes.begin( ), iend, std::not1 ( std::bind1st ( std::modulus< value_type >( ), k ) ) ) != iend )
                continue;

            primes.push_back ( k );
        }

    return primes;
}

template < class T >
inline std::list < std::pair < T, size_t > > get_prime_fact ( T a )
{
    std::list < std::pair < T, size_t > > fac;

    for ( T k = 2; a > 1; ++ k )
        if ( ! ( a % k ) )  // no need to check if k is prime
        {
            size_t m = 0;
            for ( ; ! ( a % k ) ; ++m, a/= k )
                ;

            fac.push_back ( std::pair < T, size_t > ( k, m ) );
        }
    return fac;
}


template < class T >
T n_choose_k ( T n, T k )
{
    if ( k > n )
        return 0;

    const T lb = std::min ( k, n - k ) + 1;
    const T ub = n - lb + 1;

    T res = 1, j = 2;
    while ( n > ub && j < lb)
    {
        res *= n--;
        while ( j < lb and ! (res % j) )
            res /= j++;
    }

    while ( n > ub )
        res *= n--;

    return res;
}


/**
 * median calculator, using two heaps
 */
template < class InputIter >
inline std::pair < typename InputIter::value_type, typename InputIter::value_type >
median ( InputIter first, InputIter last )
{
    typedef typename InputIter::value_type      value_type;
    typedef std::pair< value_type, value_type > result_type;

    /*
     * max_heap:
     *      - the lower half of the elements
     *      - the biggest of such elements is on the top
     */
    std::vector < value_type > max_heap, min_heap;

    /*
     * comp argument to heap algorithm should provide
     * 'strict weak ordering'; in particular
     *      std::not2 ( std::less < value_type > )
     * does not have such a strict weak ordering;
     */
    std::less    < value_type > max_heap_comp;
    std::greater < value_type > min_heap_comp;

    if ( first == last )  /* corner case: empty vector */
        throw std::runtime_error ( "median of an empty vector is undefined!" );

    InputIter iter = first;
    max_heap.push_back ( * iter );

    for ( ++iter ; iter != last; ++ iter )
        if ( * iter < max_heap.front() )
        {
            max_heap.push_back ( * iter );
            std::push_heap ( max_heap.begin(), max_heap.end(), max_heap_comp );

            if ( min_heap.size() + 1 < max_heap.size() )
            {
                /* max_heap has got too large */
                min_heap.push_back( max_heap.front() );
                std::push_heap( min_heap.begin(), min_heap.end(), min_heap_comp );

                std::pop_heap( max_heap.begin(), max_heap.end(), max_heap_comp );
                max_heap.pop_back();
            }
        }
        else
        {
            min_heap.push_back ( * iter );
            std::push_heap ( min_heap.begin(), min_heap.end(), min_heap_comp );

            if ( max_heap.size() + 1 < min_heap.size() )
            {
                /* min_heap has got too large */
                max_heap.push_back( min_heap.front() );
                std::push_heap( max_heap.begin(), max_heap.end(), max_heap_comp );

                std::pop_heap( min_heap.begin(), min_heap.end(), min_heap_comp );
                min_heap.pop_back();
            }
        }

    DEBUG( max_heap );
    DEBUG( min_heap );

    return min_heap.empty( )  /* corner case: ++first = last */
        ? result_type ( *first, *first )
        : result_type ( max_heap.size() < min_heap.size() ? min_heap.front() : max_heap.front(),
                        min_heap.size() < max_heap.size() ? max_heap.front() : min_heap.front() );
}

/*
 * geometry util
 * ----------------------------------------------
 */

struct xyPoint
{
    double x, y;
    xyPoint ( const double & a = .0, const double & b = .0 ): x ( a ), y( b ) { };
};


struct xyCircle
{
    xyPoint center;
    double radius;
};

std::ostream & operator<< ( std::ostream & out, const xyPoint & p )
{
    out << '(' << p.x << ", " << p.y << ')';
    return out;
}

std::istream & operator>> ( std::istream & ist, xyPoint & p )
{
    ist >> p.x >> p.y;
    return ist;
}

std::ostream & operator<< ( std::ostream & out, const xyCircle & o )
{
    out << "{(" << o.center.x << ", " << o.center.y << ") " << o.radius << '}';
    return out;
}

std::istream & operator>> ( std::istream & ist, xyCircle & o )
{
    ist >> o.center.x >> o.center.y >> o.radius;
    return ist;
}

inline double cartesian_dist ( const xyPoint & a, const xyPoint & b )
{
    const double d = a.x - b.x;
    const double e = a.y - b.y;
    return std::sqrt ( d * d + e * e );
}

class xyLine
{
    public:
        xyLine ( const xyPoint & , const xyPoint & );
        xyLine ( const double slope, const double intercept );

        /*
         * 'signed' orthogonal distance; the sign is useful
         * to compare which side of the line the point is
         */
        inline double orth_dist ( const xyPoint & ) const;
    private:
        double m_slope;
        double m_intercept;
        double m_normfac;   /* normalization factor for orth_dist calc */

        bool   m_vertical;  /* if the line is verticcal                */
        double m_xcross;    /* x axis cross point for vertical line    */
};

xyLine::xyLine ( const xyPoint & a, const xyPoint & b )
{
    if ( a.x == b.x )  /* vertical line */
    {
        m_vertical  = true;
        m_xcross    = a.x;

        m_intercept = DOUBLE_NAN;
        m_slope     = DOUBLE_INF;
        m_normfac   = DOUBLE_NAN;
    }
    else
    {
        m_vertical  = false;
        m_xcross    = DOUBLE_NAN;

        m_slope     = ( b.y - a.y ) / ( b.x - a.x );
        m_intercept = a.y - m_slope * a.x;
        m_normfac   = std::sqrt ( m_slope * m_slope + 1.0 );
    }
}

xyLine::xyLine ( const double slope, const double intercept ):
    m_slope ( slope ),  m_intercept ( intercept )
{
     m_vertical = false;
     m_xcross   = DOUBLE_NAN;
     m_normfac  = std::sqrt ( m_slope * m_slope + 1.0 );
}

double xyLine::orth_dist ( const xyPoint & o ) const /* 'signed' orthogonal distance */
{
    if ( m_vertical )
        return o.x - m_xcross;
    else
        return ( m_slope * o.x - o.y + m_intercept ) / m_normfac;
}

inline double triangle_area ( const xyPoint & a, const xyPoint & b, const xyPoint & c )
{
    const xyLine l ( a, b );
    const double h = std::abs ( l.orth_dist ( c ) );
    const double e = cartesian_dist ( a, b );
    return h * e;
}

/*
 *  operator<< overrides
 * ----------------------------------------------
 */

namespace
{
    /* helper function to output containers */
    template < typename T >
    std::ostream & __output ( std::ostream & out, const T & a )
    {
        typedef typename T::const_iterator const_iterator;
        out << "{ ";

        // does not work for 'pair' value type
        // std::copy ( a.begin( ), a.end( ), std::ostream_iterator < typename T::value_type > ( std::cout, ", " ));

        for ( const_iterator iter = a.begin(); iter != a.end(); ++ iter )
             out << ( iter != a.begin( ) ? ", " : "" ) << *iter ;

        return out << " }";
    }
}

template < typename key_type, typename value_type >
std::ostream & operator<< ( std::ostream & out, const std::pair < key_type, value_type > & p)
{
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}

template < typename key_type, typename value_type, typename comp >
std::ostream & operator<< ( std::ostream & out, const std::map < key_type, value_type, comp > & m )
{
    return __output ( out, m );
}

template < typename value_type >
std::ostream & operator<< ( std::ostream & out, const std::set < value_type > & s )
{
    return __output ( out, s );
}

template < typename value_type >
std::ostream & operator<< ( std::ostream & out, const std::vector < value_type > & a )
{
    return __output ( out, a );
}

template < typename value_type >
std::ostream & operator<< ( std::ostream & out, const std::list < value_type > & a )
{
    return __output ( out, a );
}

template < typename value_type >
std::ostream & operator<< ( std::ostream & out, const std::vector < std::vector < value_type > > & a )
{
    typedef typename std::vector < std::vector < value_type > >::const_iterator const_iterator;

    for ( const_iterator iter = a.begin( ); iter != a.end( ); ++ iter )
        out << '\n' << *iter ;

    return out;
}

/*
 *  operator>> overrides
 * ----------------------------------------------
 */

template < typename key_type, typename value_type >
std::istream & operator>> ( std::istream & in, std::pair < key_type, value_type > & p)
{
    in >> p.first >> p.second;
    return in;
}

template < typename value_type >
std::istream & operator>> ( std::istream & in, std::vector < value_type > & a )
{
    typedef typename std::vector < value_type >::iterator iterator;

    if ( ! a.size( ) )
    {
        size_t n;
        in >> n;
        a.resize( n );
    }

    for ( iterator iter = a.begin(); iter != a.end(); ++ iter )
        in >> * iter;

    return in;
}

/*
 *  readin quick utilities
 * ----------------------------------------------
 */

// template < typename value_type >
// inline void readin ( std::vector < value_type > & a, size_t n = 0, std::istream & in = std::cin )
// {
//     // if ( ! n ) std::cin >> n;
//     if ( ! n ) in >> n ;
//     a.resize ( n );
//     // std::cin >> a;
//     in >> a;
// }

// XXX consider removing
// template < typename key_type, typename value_type >
// inline void readin (std::vector < std::pair < key_type , value_type > > & a, size_t n = 0 )
// {
//     if ( !n ) std::cin >> n;
//     a.resize( n );
//     std::cin >> a;
// }

/*
 *  pair utility
 * ----------------------------------------------
 */

/*
 * accumulate ( m.begin( ), m.end( ), pair < int, double> ( 0 , 0.0 ) , operator+ < int, double > );
 * stackoverflow.com/questions/18640152
 */
template < typename T1, typename T2 >
inline std::pair < T1, T2 > operator+ ( const std::pair < T1, T2 > & a, const std::pair < T1, T2 > & b )
{
    return std::make_pair < T1, T2 > ( a.first + b.first, a.second + b.second );
}

template < typename T1, typename T2 >
inline std::pair < T1, T2 > operator- ( const std::pair < T1, T2 > & a, const std::pair < T1, T2 > & b )
{
    return std::make_pair < T1, T2 > ( a.first - b.first, a.second - b.second );
}

// template < class T1, class T2, class BinaryOperation >
// class Apply2nd : std::binary_function < typename std::pair < T1, T2 >,
//                                         typename std::pair < T1, T2 >,
//                                         typename BinaryOperation::result_type >

namespace
{
    /*!
     * helper template to do the work
     */
    template < size_t J, class T1, class T2 >
    struct Get;

    template < class T1, class T2 >
    struct Get < 0, T1, T2 >
    {
        typedef typename std::pair < T1, T2 >::first_type result_type;

        static       result_type & elm (       std::pair < T1, T2 > & pr ) { return pr.first; }
        static const result_type & elm ( const std::pair < T1, T2 > & pr ) { return pr.first; }
    };

    template < class T1, class T2 >
    struct Get < 1, T1, T2 >
    {
        typedef typename std::pair < T1, T2 >::second_type result_type;

        static       result_type & elm (       std::pair < T1, T2 > & pr ) { return pr.second; }
        static const result_type & elm ( const std::pair < T1, T2 > & pr ) { return pr.second; }
    };
}

template < size_t J, class T1, class T2 >
typename Get< J, T1, T2 >::result_type & get ( std::pair< T1, T2 > & pr )
{
    return Get < J, T1, T2 >::elm( pr );
}

template < size_t J, class T1, class T2 >
const typename Get< J, T1, T2 >::result_type & get ( const std::pair< T1, T2 > & pr )
{
    return Get < J, T1, T2 >::elm( pr );
}

/*
 * graph utils
 * ----------------------------------------------
 */

/*
 * Dijkstra :: single-source shortest path problem for
 * a graph with non-negative edge path costs, producing
 * a shortest path tree
 * en.wikipedia.org/wiki/Dijkstra's_algorithm
 */
template < typename DistType >
void Dijekstra ( const size_t & source,
                 const std::vector < std::list < size_t > > & adj,          // adjacency list
                 const std::vector < std::vector < DistType > > & edge_len, // pair-wise distance for adjacent nodes
                 std::vector < DistType > & dist,  // distance from the source
                 std::vector < size_t > prev )     // previous node in the shortest path tree
{
    // TODO
}

// TODO http://en.wikipedia.org/wiki/Shortest_path_problem
// TODO Graph class, Weighted graph, ...

/*
 *  maximum cardinality matching in a bipartite graph
 *        G = G1 ∪ G2 ∪ {NIL}
 *  where G1 and G2 are partition of graph and NIL is a special null vertex
 *  https://en.wikipedia.org/wiki/Hopcroft-Karp_algorithm
 */
class HopcroftKarp
{
    public:
        HopcroftKarp ( const std::vector < std::list < size_t > > & adj,
                       const std::vector < bool > & tag );

        size_t get_npair ( ) { return npair; };
        std::map < size_t, size_t > get_map ( );

    private:
        bool mf_breadth_first_search ( );  // breadth first search from unpaired nodes in G1
        bool mf_depth_first_search ( const size_t v ); // dfs w/ toggeling augmenting paths

        const std::vector < std::list < size_t > > & m_adj;  // adjacency list for each node
        const std::vector < bool > & m_tag;  // binary tag distinguishing partitions

        size_t npair;
        const size_t NIL;  // special null vertex
        const size_t INF;  // practically infinity distance

        std::vector < size_t > m_g1;    // set of nodes with tag = true
        std::vector < size_t > m_dist;  // dist from unpaired vertices in G1
        std::vector < size_t > m_pair;
};


std::map < size_t, size_t > HopcroftKarp::get_map ( )
{
    std::map < size_t, size_t > m;

    for ( size_t j = 0; j < m_pair.size( ); ++ j )
        if ( m_pair[ j ] != NIL  && m_tag[ j ])
            m[ j ] = m_pair[ j ];

    return m;
}


HopcroftKarp::HopcroftKarp ( const std::vector < std::list < size_t > > & adj,
                             const std::vector < bool > & tag ):
    m_adj ( adj ),
    m_tag ( tag ),
    npair ( 0 ),
    NIL ( adj.size( )),
    INF ( adj.size( ) + 1 ),
    m_dist ( std::vector < size_t > ( adj.size( ) + 1, INF)),
    m_pair ( std::vector < size_t > ( adj.size( ), NIL ))  // initially everything is paired with nil
{
    assert ( m_adj.size() == m_tag.size() );

    for ( size_t j = 0; j < tag.size( ); ++ j )
        if ( tag[ j ] )
            m_g1.push_back ( j );

    while ( mf_breadth_first_search ( ) )
        for ( std::vector < size_t >::const_iterator v = m_g1.begin( ); v != m_g1.end( ); ++ v )
            if ( m_pair[ *v ] == NIL && mf_depth_first_search ( *v ) )
                ++ npair;
}

bool HopcroftKarp::mf_breadth_first_search( )
{
    /* only nodes from g1 are queued */
    std::queue < size_t > bfs_queue;

    /* initialize queue with all unpaired nodes from g1 */
    for ( std::vector < size_t >::const_iterator v = m_g1.begin( ); v != m_g1.end( ); ++v )
        if ( m_pair[ *v ] == NIL )
        {
            m_dist[ *v ] = 0;
            bfs_queue.push ( *v );
        }
        else
            m_dist[ *v ] = INF;

    m_dist[ NIL ] = INF;

    /* find all the shortest augmenting paths to node nil */
    while ( ! bfs_queue.empty() )
    {
        const size_t v = bfs_queue.front( );
        bfs_queue.pop ( );

        if ( m_dist[ v ] < m_dist[ NIL ] )
            for ( std::list < size_t >::const_iterator u = m_adj[ v ].begin( ); u != m_adj[ v ].end( ); ++ u )
                if ( m_dist[ m_pair[ * u ] ] == INF )
                {
                    m_dist[ m_pair[ * u ] ] = m_dist[ v ] + 1;
                    bfs_queue.push ( m_pair[ * u ] );
                }
    }

    return m_dist[ NIL ] != INF;
}


bool HopcroftKarp::mf_depth_first_search( const size_t v )
{
    if ( v == NIL )
        return true;
    else
    {
        for ( std::list < size_t >::const_iterator u = m_adj[ v ].begin( ); u != m_adj[ v ].end( ); ++ u )
            if ( m_dist[ m_pair[ *u ] ] == m_dist[ v ] + 1  && mf_depth_first_search( m_pair[ *u ] ))
            {
                /*
                 * there is an augmenting path to nil from m_pair[ *u ]
                 * and hence there is an augmenting path from v to u and
                 * u to to nil; therefore v and u can be paired together
                 */
                m_pair [ *u ] = v;
                m_pair [  v ] = *u;
                return true;
            }
        m_dist[ v ] = INF;
        return false;
    }
}


/**
 * lazy all pairs shortest path in a tree with only one BFS
 * test case: 'book of evil'
 *      codeforces.com/problemset/problem/337/D
 */
class All_Pairs_Tree_Shortest_Path
{
    public:
        All_Pairs_Tree_Shortest_Path( const std::vector< std::list < size_t > > & adj ):
            n( adj.size( ) ),
            depth( std::vector < size_t > ( n, All_Pairs_Tree_Shortest_Path::INF ) ),
            parent( std::vector < size_t > ( n ) ),
            dist( std::vector < std::vector < unsigned short > > ( n ) )
        {

            /* perform bfs from root node '0' and assign depth to each node */
            /* XXX probably would be worth to set the root as node with highest degree */
            std::queue< size_t > bfs_queue;
            bfs_queue.push( 0 );
            depth[ 0 ]  = 0;
            parent[ 0 ] = 0;

            while ( ! bfs_queue.empty( ) )
            {
                const size_t u = bfs_queue.front( );
                bfs_queue.pop( );

                for ( std::list< size_t >::const_iterator j = adj[ u ].begin( ); j != adj[ u ].end( ); ++ j )
                    if ( depth[ u ] + 1 < depth[ *j ] )
                    {
                        depth[ *j ]  = depth[ u ] + 1;
                        parent[ *j ] = u;
                        bfs_queue.push( *j );
                    }
            }

            /* adjust pair-wise distance to zero along the diagonal */
            for ( size_t j = 1; j < n; ++ j )
                dist[ j ].resize( j, All_Pairs_Tree_Shortest_Path::INF );
        }

        /* interface object function as to lazily look-up distances */
        size_t operator( )( const size_t u, const size_t v )
        {
            if ( u == v )
                return 0;
            else if ( u < v)
                return (*this)( v, u );
            else if ( dist[ u ][ v ] == All_Pairs_Tree_Shortest_Path::INF )
            {
                if ( depth[ u ] < depth[ v ] )
                    /* u is in a lower level than v */
                    dist[ u ][ v ] = 1 + (*this)( u, parent[ v ]);
                else if ( depth[ v ] < depth[ u ] )
                    /* v is in a lower level than u */
                    dist[ u ][ v ] = 1 + (*this)( parent[ u ], v );
                else
                    /* u and v are at the same depth */
                    dist[ u ][ v ] = 2 + (*this)( parent[ u ], parent[ v ] );
           }
            return dist[ u ][ v ];
        }

        /* TODO populate; a method which populates pair-wise distances
         * and returns the matrix */

    private:
            /*
             * constant infinity value for initializing distances
             * even though this is private it will be assigned outside of the class
             */
            static const unsigned short INF;

            const size_t n;                 /* numbert of nodes in the tree */
            std::vector < size_t > depth;   /* distance to root node '0' */
            std::vector < size_t > parent;  /* parent of each node with root node '0' */
            std::vector < std::vector < unsigned short > > dist; /* pair-wise shortest path distance */
};

const unsigned short All_Pairs_Tree_Shortest_Path::INF = std::numeric_limits< unsigned short >::max( );

/*
 *  data-structure utility
 * ----------------------------------------------
 */

template < class T, class Comp = std::less< T > >
class Heap  /* less< T > --> max-heap */
{
    typedef T value_type;
    typedef typename std::vector < value_type >::size_type size_type;
    public:
        /*
         * stackoverflow.com/questions/10387751
         * possible work-around: a memebr pointer to m_val
         * TODO static/friend heapify ( val, & heap )  XXX O( n ) ?!
         * TODO implement insert iterator
         */
        Heap ( ): m_val ( std::vector < value_type > ( ) ) , m_comp ( Comp( ) ){ }

        template < class InputIter >
        Heap ( InputIter first, InputIter last ):
            m_val ( std::vector < value_type > ( ) ) , m_comp( Comp( ) )
        {
            for ( ; first != last ; ++ first )
                m_val.push_back ( * first );

            std::make_heap( m_val.begin( ), m_val.end( ), m_comp );
        }

        /*!
         * to avoid destroying heap property, front( )
         * should always return a 'const' reference
         */
        inline const value_type & front( ) const { return m_val.front( ); }
        inline bool empty( ) const { return m_val.empty( ); }
        inline size_type size( ) const { return m_val.size( );  }

        inline void push ( const value_type & a )
        {
            m_val.push_back( a );
            std::push_heap( m_val.begin( ), m_val.end( ), m_comp );
        }
        inline void pop( )
        {
            std::pop_heap ( m_val.begin( ), m_val.end( ), m_comp );
            m_val.pop_back( );
        }

        // inline void swap( Heap< T, Comp> & other ) { m_val.swap( other.m_val ) };
        // void sort( ) { std::sort_heap ( m_val.begin( ), m_val.end( ), m_comp ); }
        // template < class X, class Y >
        // friend std::ostream & operator<<( std::ostream & out, const Heap < X, Y> & heap );
    private:
        std::vector < value_type > m_val;
        const Comp m_comp;
};

/*
 * boost.org/doc/libs/1_54_0/libs/smart_ptr/shared_ptr.htm
 */
template < class Type >
class shared_ptr
{
    typedef Type value_type;
    public:
        explicit shared_ptr ( value_type * p = NULL ) : ptr ( p ), count ( new size_t ( 1U ) ) { }
        shared_ptr ( const shared_ptr < value_type > & sp ): ptr ( sp.ptr ), count ( sp.count ) { ++ * count; }
        ~ shared_ptr ( ) { release( ); }

        bool operator== ( const shared_ptr < value_type > & sp ) { return ptr == sp.ptr; }
        bool operator!= ( const shared_ptr < value_type > & sp ) { return ptr != sp.ptr; }

        shared_ptr < value_type > & operator= ( const shared_ptr < value_type > & sp )
        {
            if ( this != & sp && ptr != sp.ptr )
            {
                release( );
                ptr   = sp.ptr;
                count = sp.count;
                ++ * count;
            }
            return * this;
        }

        value_type * operator-> ( ) { return ptr ; }
        value_type & operator* ( ) { return *ptr ; }
        const value_type * operator-> ( ) const { return ptr ; }
        const value_type & operator* ( ) const { return *ptr; }

        void swap ( shared_ptr < value_type > & sp )
        {
            if ( this != &sp && ptr != sp.ptr )
            {
                std::swap ( ptr, sp.ptr );
                std::swap ( count, sp.count );
            }
        }

    private:
        void release ( )
        {
            /* stackoverflow.com/questions/615355 */
            -- * count;
            if ( ! * count )
            {
                delete count;
                delete ptr;
                count = NULL;
                ptr   = NULL;
            }
        }
        value_type * ptr;
        size_t     * count;
};

/*!
 * union find data structure with
 *      - lazy unions
 *      - union by rank
 *      - path compression
 */
class UnionFind
{
    public:
        UnionFind( const size_t n ):
            parent ( std::vector < size_t > ( n ) ),   /* initialize each node as its own   */
            rank   ( std::vector < size_t > ( n, 0 ))  /* parent and set all the ranks to 0 */
        {
            for ( size_t j = 0; j < n; ++ j )
                parent[ j ] = j ;
        }

        inline size_t find( const size_t s )
        {
            /*
             * perform path compresion and add shortcut
             * if parent[ s ] is not a root node
             */
            const size_t p = parent[ s ];
            return parent[ p ] == p ? p : parent[ s ] = find( p ) ;
        }

        inline void lazy_union ( size_t i, size_t j )
        {
            /* unions should be done on root nodes */
            i = find( i );
            j = find( j );

            if ( i != j )
            {
                if ( rank [ i ] < rank[ j ] )
                    parent[ i ] = j;
                else
                {
                    parent[ j ] = i;
                    rank[ i ]  += rank[ i ] == rank[ j ];
                }
            }
        }
    private:
        std::vector < size_t > parent;
        std::vector < size_t > rank;
};


// TODO XXX
// template < class NumType >
// unsigned num_hash_func ( const NumType & a )
// {
//     // XXX what will happen in case of overflow?
//     return static_cast < unsigned > ( a % 9973 ) % 9973 ;
// }

/*
 * XXX: HashMap: map< Key, T > data [ 9973 ]
 * data [ num_hash_func ( key ) ][ key ]
 */


/*
 *  testing util
 * ----------------------------------------------
 */

// TODO add a preprocessor which automatically includes the funciton name, or __line__
// and disables if not in debug mode
/* prints the life length of the object when it goes out of scope */
class ScopeTimer
{
    public:
        ScopeTimer ( const std::string & msg = "" ): tic ( clock ( )), m_msg( msg ) { };

        ~ ScopeTimer ( )
        {
            const clock_t toc = clock();
            const uint64 dt   = 1000L * ( toc - tic ) / CLOCKS_PER_SEC;

            const uint64 mil = dt % 1000L;
            const uint64 sec = ( dt / 1000L ) % 60L;
            const uint64 min = ( dt / 60000L ) % 60L;
            const uint64 hrs = ( dt / 3600000L );

            std::cout << '\n' << m_msg << "\n\telapsed time: ";

            if ( hrs )  std::cout << hrs << " hrs, ";
            if ( min )  std::cout << min << " min, ";
            if ( sec )  std::cout << sec << " sec, ";
            std::cout << mil << " mil-sec\n";
        }

    private:
        typedef unsigned long long int  uint64;
        const clock_t tic;
        const std::string m_msg;
};

class RandInt
{
    public:
        RandInt ( int a = 0, int b = 100 ): m ( a ), f ( static_cast < double > ( b - a ) / RAND_MAX ) { }
        inline int operator() ( ) { return m + std::ceil ( f * rand( ) ); }
    private:
        const int m;
        const double f;
};


class RandDouble
{
    public:
        RandDouble ( double a = 0.0, double b = 1.0 ): m ( a ), f ( ( b - a ) / RAND_MAX ) { }
        inline double operator() ( ) { return m + f * rand( ); }
    private:
        const double m, f;
};

class Noisy
{
    public:
        Noisy ( std::string str ): msg ( str )
        {
            std::cout << " Noisy ( " << msg << " )\t@ " << this << std::endl;
        }
        ~Noisy ( )
        {
            std::cout << "~Noisy ( " << msg << " )\t@ " << this << std::endl;
        }
        void beep ( )
        {
            std::cout << " beep ( " << msg << " )\t@ " << this << std::endl;
        }
        void beep ( ) const
        {
            std::cout << " const beep ( " << msg << " )\t@ " << this << std::endl;
        }
    private:
        const std::string msg;
};

DECLARE ( Noisy );


/*
 * ----------------------------------------------
 * ----------------------------------------------
 */

/*
 * -- @@@ -------------------------------------------------
 */

using namespace std;


// struct Comp
// {
//     // bool operator() ( const pair < int, int > & x, const pair < int, int > & y )
//     // {
//     //     return abs( x.first ) + abs( x.second ) < abs( y.first ) + abs( y.second );
//     // }
//
//     // bool operator( ) ( const xyCircle & a, const xyCircle & b )
//     // {
//     //     return a.radius < b.radius;
//     // }
//     //
//     bool operator( ) ( const pair < size_t, size_t > & pr, const size_t & x )
//     {
//         return pr.second < x;
//     }
// };

bool pred( const char a, const char b )
{
    return a == b && a == '/';
}

string a20( )
{
    string path;
    cin >> path;

    string::iterator iter = unique( path.begin(), path.end(), pred );

    if ( *(iter - 1) == '/' )
        -- iter;

    if ( iter == path.begin() )
        return "/";
    else
        return string( path.begin(), iter );
}

uint64 a319()
{
    string str;
    cin >> str;

    const uint64 n = str.length();
    const uint64 m = 1000000007ULL;

    uint64 val = 0;
    for( string::const_iterator iter = str.begin(); iter != str.end(); ++ iter )
        if ( *iter == '1' )
        {
            const uint64 k = iter - str.begin( );
            const uint64 a = powmod( 2ULL, n - k - 1, m );

            val += powmod( 2ULL, k, m ) * (a * a % m) % m;
            val %= m;
        }
    return val;
}

int main ( const int argc, char * argv [ ])
{
    cout << a319 ( );
    // cout << a191( );
    // cout << setprecision( 10 )

    return EXIT_SUCCESS;
}


/**
 * mislav.uniqpath.com/2011/12/vim-revisited/
 * set encoding=utf-8
 * %s/\(.\{60,70\}\) /\1\r/gc
 * %s/ / /gc
 * %s/10\([0-9]\{1,2\}\)/10^\1/gc
 */
