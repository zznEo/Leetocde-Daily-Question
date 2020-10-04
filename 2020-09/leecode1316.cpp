#include <bits/stdc++.h>
using namespace std;

#if 1
class Solution {
public:
    int distinctEchoSubstrings(string text) {
        if(text.empty())
            return 0;
        text = "0" + text;
        Hash.resize(text.size(), 0);
        for(int i = 1;i < text.size();i++){
            Hash[i] = (Hash[i-1]*p + (text[i] - 'a' + 1)) % mod;
        }
        for(int i = 1;i < text.size();i++){
            for(int j = i + 1;j < text.size();j++){
                if((j - i + 1) % 2 == 1)
                    continue;
                int mid = (j + i) / 2;
                long long l = ((Hash[mid] % mod - Hash[i - 1] % mod*QuickPow(p, mid - i + 1) % mod)% mod + mod) % mod;
                long long r = ((Hash[j] % mod - Hash[mid + 1 - 1] % mod*QuickPow(p, j - (mid + 1) + 1) % mod)% mod + mod) % mod;
                if(i == 4 && j == 413){
                    cout << "***********" << endl;
                    cout << l << " " << r << endl;
                    cout << vis[l] << endl;
                    cout << "***********" << endl;
                }
                if(l == r && l == 56090){
                    cout << "-----------" << endl;
                    cout << i << " " << j << endl;
                    cout << "-----------" << endl;
                }
                if(l == r && vis[l] == 0){
                    cout << i << " " << j << " " << l << endl;
                    vis[l] = 1;
                    ans++;
                }
            }
        }
        return ans;
    }
private:
    long long QuickPow(long long a, long long x){
        long long ret = 1;
        a %= mod;
        while(x){
            if(x & 1)
                ret  = ret * a % mod;
            a = a * a % mod;
            x >>= 1;
        }
        return ret % mod;
    }
private:
    long long mod = 196613;
    long long p = 24593;
    vector<long long> Hash;
    int ans = 0;
    int vis[800000] = {0};
};
#endif

#if 0
class Solution 
{
public: 
    long long mod = 786433;
    long long p = 393241;
    long long quickpow(long long a, long long b)
    {
        long long ans = 1;
        a %= mod;
        while (b)
        {
            if (b % 2) ans = (ans * a) % mod;
            b /= 2;
            a = (a * a) % mod;
        }
        return ans;

    }
    int distinctEchoSubstrings(string text) 
    {
        text = "0" + text;
        long long n = text.size();
        for (long long i = 1;i < n;i++)
        {
            Hash[i] = (Hash[i - 1] * p + text[i]) % mod;
        }
        long long ans = 0;
        for (long long i = 1;i < n;i++)
        {
            for (long long j = i + 1;j < n;j++)
            {
                if ((j - i + 1) % 2) continue;

                long long mid = (i + j) / 2;
                long long l = (Hash[mid] + mod - (Hash[i - 1]  * quickpow(p, mid - i + 1) % mod)) % mod;
                long long r = (Hash[j] + mod -( Hash[mid]  * quickpow(p, j - mid ) % mod)) % mod;
                if(i == 4 && j == 413){
                    cout << "***********" << endl;
                    cout << l << " " << r << endl;
                    cout << b[l] << endl;
                    cout << "***********" << endl;
                }
                if(l == r && l == 56090){
                    cout << "-----------" << endl;
                    cout << i << " " << j << endl;
                    cout << "-----------" << endl;
                }
                if(l == r && b[l] == 0){
                    cout << i << " " << j << " " << l << endl;
                    b[l] = 1;
                    ans++;
                }
            }
        }
        return ans;
    }
    long long Hash[800000] = { 0 };
    long long b[800000] = { 0 };
};
#endif

Solution s1;
void test() {
    //cout << s1.distinctEchoSubstrings("tiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtiduxtidux") << endl;
    //cout << s1.distinctEchoSubstrings("yexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzltyexodmnzlt") << endl;
    cout << s1.distinctEchoSubstrings("tkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnra") << endl;
}

int main(){
    test();
    system("pause");
    return 0;
}