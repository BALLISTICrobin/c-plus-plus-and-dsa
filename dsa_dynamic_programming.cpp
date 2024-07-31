
//fibonacci number, time complexity o(n)......Top-down Approach...memorization
//space somplexity o(n)+o(n)[recursion stack + memorization]
/*
#include <iostream>
#include <vector>

std::vector<long long> memo;

long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    if (memo[n] != -1) {
        return memo[n];
    }

    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

int main() {
    int n;
    std::cout << "Enter a positive integer n: ";
    std::cin >> n;

    // Initialize memoization table with -1 values
    memo.assign(n + 1, -1);

    long long result = fibonacci(n);
    std::cout << "Fibonacci(" << n << ") = " << result << std::endl;

    return 0;
}
*/


//fibonacci number, time complexity o(n)......Bottom up approach..tabulation
//space complexity o(n)
/*
// C++ program for Fibonacci Series
// using Dynamic Programming
#include <bits/stdc++.h>
using namespace std;

class GFG {

public:
	int fib(int n)
	{

		// Declare an array to store
		// Fibonacci numbers.
		// 1 extra to handle
		// case, n = 0
		int f[n + 2];
		int i;

		// 0th and 1st number of the
		// series are 0 and 1
		f[0] = 0;
		f[1] = 1;

		for (i = 2; i <= n; i++) {

			// Add the previous 2 numbers
			// in the series and store it
			f[i] = f[i - 1] + f[i - 2];
		}
		return f[n];
	}
};

// Driver code
int main()
{
	GFG g;
	int n = 9;

	cout << g.fib(n);
	return 0;
}

// This code is contributed by SoumikMondal
*/


/*
the code that i've done in my childhood is space optimization
// Fibonacci Series using Space Optimized Method
space complexity o(1);
#include <bits/stdc++.h>
using namespace std;
  
int fib(int n)
{
    int a = 0, b = 1, c, i;
    if (n == 0)
        return a;
    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
  
// Driver code
int main()
{
    int n = 9;
  
    cout << fib(n);
    return 0;
}
*/

