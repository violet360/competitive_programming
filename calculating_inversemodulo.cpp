#include <iostream> 
using namespace std; 
  
// Function to calculate modular 
// inverse using D.P 
// it can be used to find nCr%p , nCr = (n! * moduloInverse(n! , p)%p * moduloInverse((n-r)! , p)%p)%p , so modulo inverse can be found by 
// by fermat's theorem pow(n, p) = n mod p , pow(n, p-2) = pow(n, -1) mod p => pow(n, p-2) = modInverse(n, p) but ...... there's is another
// method......
// modularInverse[i] = modularInverse[p % i] * (p - p/i)%p; ----> https://cp-algorithms.com/algebra/module-inverse.html...
void modularInverse(int n, int prime) 
{ 
    int dp[n + 1]; 
    dp[0] = dp[1] = 1; 
    for (int i = 2; i <= n; i++)  
        dp[i] = dp[prime % i] *  
               (prime - prime / i) % prime;     
  
    for (int i = 1; i <= n; i++)  
        cout << dp[i] << ' ';     
} 
  
// Driver code 
int main() 
{ 
    int n = 10, prime = 17; 
    modularInverse(n, prime); 
    return 0; 
} 
