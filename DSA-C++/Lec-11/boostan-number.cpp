#include <iostream>
using namespace std;

// Function to calculate sum of digits of a number
int count_sum(int n) {
    int digit = 0;
    while (n > 0) {
        int y = n % 10;
        digit += y;
        n = n / 10;
    }
    return digit;
}

// Function to calculate sum of prime factors (sum of digits of each prime factor)
int print_prime_factors(int n) {
    int sum = 0;

    // Count factors of 2
    while (n % 2 == 0) {
        // cout << 2 << " ";
        sum += 2;
        n = n / 2;
    }

    // Count odd factors
    for (int i = 3; i <= n; i += 2) {
        while (n % i == 0) {
            // cout << i << " ";
            sum += count_sum(i);
            n = n / i;
        }
    }

    return sum;
    // all prime factors get summed
}

int main() {
    int n;
    cin >> n;

    int y = count_sum(n);
    cout << y << endl;

    int x = print_prime_factors(n);
    cout << x << endl;

    int ans = (x == y) ? 1 : 0;
    cout << ans;

    return 0;
}
