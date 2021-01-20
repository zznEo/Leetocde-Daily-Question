#include <cstdio>
#include <cmath>
using namespace std;

inline double max(double a, double b) {
    return a > b? a : b;
}

inline double func(double x) { return x*x; }

double my_sqrt(double (*arr)(double), double n) {
    double head = 0.0, tail  = max(1.0, n), mid = 0.0; //注意0.1开跟的情况
    #define EPS 1e-7
    while(tail - head > EPS) {
        mid = (tail + head) * 0.5;
        if(arr(mid) < n) head = mid;
        else tail = mid;
    }
    #undef EPS
    return head;
}

int main() {
    double n;
    while(~scanf("%lf", &n)) {
        printf("sqrt(%g) = %g\n", n, sqrt(n));
        printf("my_sqrt(%g) = %g\n", n, my_sqrt(func,n));
    }
    return 0;
}
