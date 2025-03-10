#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector< pair<int, int> >
using namespace std;

const int MAX = 1e6;

/**
 * What is the Sieve of Erastosthenes?
 * The Sieve of Erastosthenes is an algorithm that helps us to calculate
 * how many primes there are in a specefic range. from 1 to N.
 */


 /**
  * This method precalculates all primes in a specified range. 
  * It receives two parameters.
  * sieve: the vector where all primes will be stored.
  * n: The number up to which the primes will be calculated. 
  */
void primeSieve( vec& sieve, int n ){// Complexity = O( N Log N )
    sieve[1] = 0; // Mark 1 as prime

    for( int i = 2; i <= n; i++ ){
        if( !sieve[i] ){ // If it is equal to 0, mark it as prime and all its multiplies mark them as non-prime
            //sieve[i] = 0; is prime
            for( int j =  i*i ; j <= n; j+=i ){
                //Mark j as non-prime
                sieve[j] = 1;
            }
        }
    }

}

int32_t main(){
    int n;
    vec sieve( MAX, 0 );
    primeSieve( sieve, MAX );
    cout<<"Enter a range"<<endl;
    while( cin>>n ){
        cout<<"Primes"<<endl;
        
        for( int i = 0; i <= n; i++ ){
            if( !sieve[i] ) cout<<i<<"|";
        }

        cout<<endl;
    }

    return 0;
}