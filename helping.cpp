#include <iostream>
#include <cmath>

using namespace std;
typedef long long int ll;

// Function to find the count of divisors of a number
ll countDivisors(ll n) {
    ll count = 0;
    for (ll i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            // If the divisors are equal, count only once (i.e., square root)
            if (n / i == i) {
                count++;
            } else {
                // Otherwise, count both divisors
                count += 2;
            }
        }
    }
    return count;
}

int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        // Find the maximum size of the valid interval (count of divisors)
        ll maxIntervalSize = countDivisors(n);

        cout << maxIntervalSize << endl;
    }

    return 0;
}
