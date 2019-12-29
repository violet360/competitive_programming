#include <iostream> 
using namespace std; 
  
// Function to calculate modular 
// inverse using D.P 
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