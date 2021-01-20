#include <cstdio>
#include <cmath>
using namespace std;

inline double F(double x, double n) { return x*x - n; }

inline double f(double x) { return 2.0*x; }

double NewTon(double(*F)(double, double), double(*f)(double), double n) {
    double x = 1.0;
    #define EPS 1e-7
    while(fabs(F(x, n)) > EPS) {
        x -= F(x, n) / f(x);
    }
    #undef EPS
    return x;
}

double my_sqrt(double n) {
    return NewTon(F, f, n);
}

int main() {
    double n;
    while(~scanf("%lf", &n)) {
        printf("sqrt(%g) = %g\n", n, sqrt(n));
        printf("my_sqrt(%g) = %g\n", n, my_sqrt(n));
    }
    return 0;
}