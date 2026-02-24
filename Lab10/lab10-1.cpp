#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int, int> mii;

ll _sieve_size;
bitset<10000010> bs;
vll p;

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < _sieve_size; ++i) {
        if (bs[i]) {
            for (ll j = i * i; j < _sieve_size; j += i) bs[j] = 0;
            p.push_back(i);
        }
    }
}

bool isPrime(ll N) {
    if (N < _sieve_size) return bs[N];
    for (int i = 0; i < (int)p.size() && p[i] * p[i] <= N; ++i) {
        if (N % p[i] == 0) return false;
    }
    return true;
}

vll primeFactors(ll N) {
    vll factors;
    for (int i = 0; i < (int)p.size() && p[i] * p[i] <= N; ++i) {
        while (N % p[i] == 0) {
            N /= p[i];
            factors.push_back(p[i]);
        }
    }
    if (N != 1) factors.push_back(N);
    return factors;
}

int numPF(ll N) {
    int ans = 0;
    for (int i = 0; i < (int)p.size() && p[i] * p[i] <= N; ++i) {
        while (N % p[i] == 0) {
            N /= p[i];
            ++ans;
        }
    }
    return ans + (N != 1);
}

int numDiffPF(ll N) {
    int ans = 0;
    for (int i = 0; i < (int)p.size() && p[i] * p[i] <= N; ++i) {
        if (N % p[i] == 0) ++ans;
        while (N % p[i] == 0) N /= p[i];
    }
    if (N != 1) ++ans;
    return ans;
}

ll sumPF(ll N) {
    ll ans = 0;
    for (int i = 0; i < (int)p.size() && p[i] * p[i] <= N; ++i) {
        while (N % p[i] == 0) {
            N /= p[i];
            ans += p[i];
        }
    }
    if (N != 1) ans += N;
    return ans;
}

int numDiv(ll N) {
    int ans = 1;
    for (int i = 0; i < (int)p.size() && p[i] * p[i] <= N; ++i) {
        int power = 0;
        while (N % p[i] == 0) {
            N /= p[i];
            ++power;
        }
        ans *= (power + 1);
    }
    return (N != 1) ? 2 * ans : ans;
}

ll sumDiv(ll N) {
    ll ans = 1;
    for (int i = 0; i < (int)p.size() && p[i] * p[i] <= N; ++i) {
        ll multiplier = p[i], total = 1;
        while (N % p[i] == 0) {
            N /= p[i];
            total += multiplier;
            multiplier *= p[i];
        }
        ans *= total;
    }
    if (N != 1) ans *= (N + 1);
    return ans;
}

ll EulerPhi(ll N) {
    ll ans = N;
    for (int i = 0; i < (int)p.size() && p[i] * p[i] <= N; ++i) {
        if (N % p[i] == 0) ans -= ans / p[i];
        while (N % p[i] == 0) N /= p[i];
    }
    if (N != 1) ans -= ans / N;
    return ans;
}

int main() {
    sieve(10000000);
    printf("%lld\n", p.back());
    for (ll i = p.back() + 1; ; ++i) {
        if (isPrime(i)) {
            printf("The next prime beyond the last prime generated is %lld\n", i);
            break;
        }
    }
    printf("%d\n", isPrime((1LL << 31) - 1));
    printf("%d\n", isPrime(136117223861LL));
    printf("\n");

    vll r;

    r = primeFactors((1LL << 31) - 1);
    printf("%lld\n", (1LL << 31) - 1);
    for (auto &pf : r) printf("> %lld\n", pf);
    printf("\n");

    r = primeFactors(136117223861LL);
    printf("%lld\n", 136117223861LL);
    for (auto &pf : r) printf("> %lld\n", pf);
    printf("\n");

    r = primeFactors(5000000035LL);
    printf("%lld\n", 5000000035LL);
    for (auto &pf : r) printf("> %lld\n", pf);
    printf("\n");

    r = primeFactors(142391208960LL);
    printf("%lld\n", 142391208960LL);
    for (auto &pf : r) printf("> %lld\n", pf);
    printf("\n");

    r = primeFactors(100000380000361LL);
    printf("%lld\n", 100000380000361LL);
    for (auto &pf : r) printf("> %lld\n", pf);
    printf("\n");

    r = primeFactors((1LL << 31) - 1);
    for (auto &pf : r) printf("> %lld\n", pf);

    r = primeFactors(136117223861LL);
    for (auto &pf : r) printf("> %lld\n", pf);

    r = primeFactors(142391208960LL);
    for (auto &pf : r) printf("> %lld\n", pf);

    r = primeFactors(9999973LL * 9999973LL);
    for (auto &pf : r) printf("> %lld\n", pf);
    printf("\n");

    printf("numPF(%d) = %d\n", 60, numPF(60));
    printf("numDiffPF(%d) = %d\n", 60, numDiffPF(60));
    printf("sumPF(%d) = %lld\n", 60, sumPF(60));
    printf("numDiv(%d) = %d\n", 60, numDiv(60));
    printf("sumDiv(%d) = %lld\n", 60, sumDiv(60));
    printf("EulerPhi(%d) = %lld\n", 36, EulerPhi(36));
    printf("\n");

    printf("numPF(%d) = %d\n", 7, numPF(7));
    printf("numDiffPF(%d) = %d\n", 7, numDiffPF(7));
    printf("sumPF(%d) = %lld\n", 7, sumPF(7));
    printf("numDiv(%d) = %d\n", 7, numDiv(7));
    printf("sumDiv(%d) = %lld\n", 7, sumDiv(7));
    printf("EulerPhi(%d) = %lld\n", 7, EulerPhi(7));

    return 0;
}
