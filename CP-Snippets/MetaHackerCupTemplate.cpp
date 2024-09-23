#include<bits/stdc++.h>
#include<vector>
#include <unistd.h>    // for getcwd()
#include <cerrno>      // for strerror()
#include <cstring> 
using namespace std;
typedef long long int ll;
// #define YES cout<<"YES\n";
// #define NO cout<<"NO\n";
#define all(x) (x).begin(), (x).end()
#define _prll(x) for(ll &i : (x)) cout << i << ' ';
#define endl "\n"

//PRAGMA---------------------------------------------------------------------------------
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// --------------------ORDERED SET--------------------------------------------------------
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// ------------------ORDERED MULTISET----------------------------------------
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
//To erase x from ordered set a, use: a.erase(a.find_by_order(a.order_of_key(x)))
//m.order_of_key(x) - to find number of elements smaller than x
//*m.find_by_order(x)  -  to find element present at Xth index 
//---------------------------------------------------------------------------------------

//__builtin_popcount(x), __builtin_popcountll(x)   -  number of ones in the binary representation of x
//__builtin_clzll(x), __builtin_ctzll(x)  -   for counting the number of leading or trailing zeros in a positive number

//-------------------CUSTOM HASH----------------------------------------------
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); }
    size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM);    }
};

//unordered_map<long long, int, custom_hash> safe_map;
//gp_hash_table<long long, int, custom_hash> safe_hash_table;
// DEBUGGER -----------------------------------------------------------------------------
// void __print(int x) {cerr << x;}
// void __print(long x) {cerr << x;}
// void __print(long long x) {cerr << x;}
// void __print(unsigned x) {cerr << x;}
// void __print(unsigned long x) {cerr << x;}
// void __print(unsigned long long x) {cerr << x;}
// void __print(float x) {cerr << x;}
// void __print(double x) {cerr << x;}
// void __print(long double x) {cerr << x;}
// void __print(char x) {cerr << '\'' << x << '\'';}
// void __print(const char *x) {cerr << '\"' << x << '\"';}
// void __print(const string &x) {cerr << '\"' << x << '\"';}
// void __print(bool x) {cerr << (x ? "true" : "false");}

// template<typename T, typename V>
// void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
// template<typename T>
// void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
// void _print() {cerr << "]\n";}
// template <typename T, typename... V>
// void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
// #ifndef ONLINE_JUDGE
// #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
// #else
// #define debug(x...)
// #endif

// //COMPARATORS----------------------------------------------------------------------------
// bool compare(pair<int, int> i, pair<int, int> j) {
//     if (i.first > j.first) return true;
//     else if (i.first == j.first) return i.second < j.second;
//     return false;
// }
// class cmp {
// public:
//     bool operator()(pair<ll , ll> a, pair<ll, ll > b) {
//         return (a.second < b.second);
//     }
// };
//---------------------------------------------------------------------------------------

// Modulo inverse for non-prime numbers modInverse(a,b) = a^(-1)(modb)
// tuple<long long, long long, long long> extendedGCD(long long a, long long b) { if (b == 0) return {a, 1, 0}; auto [gcd, x1, y1] = extendedGCD(b, a % b); long long x = y1, y = x1 - (a / b) * y1; return {gcd, x, y}; }
// Function to find the Modulo Inverse of 'a' modulo 'm' (non prime)
// long long modInverse(long long k, long long H) { auto [gcd, x, y] = extendedGCD(k, H);
//         if (gcd != 1) { return -1; }// Inverse doesn't exist (k and H are not coprime).
//         else { return (x % H + H) % H; } } // m is added to handle negative x
//---------------------------------------------------------------------------------------

long double lmax;
#define mod  1000000007
#define mo 998244353
#define MAXN 100005
#define INF 1000000000000000000
#define inf 1000000000

// #define cout 
// LLONG_MAX, LLONG_MIN
// #define lmax 100000000000000
//FUNCTIONS---------------------------------------------------------------------------------------------------
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll bin(ll a, ll b, ll m = mod) {ll ans = 1; while (b > 0) {if (b & 1) ans = (ans * a) % m; a = (a * a) % m; b = b >> 1;} return ans;}
ll inv(ll a, ll b) {return bin(a, b - 2, b);}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (ll i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (ll j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m = mod) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m = mod) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m = mod) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m = mod) {a = a % m; b = b % m; return (mod_mul(a, inv(b, m), m) + m) % m;}
//------------------------------------------------------------------------------------------------------------

//------------------ SET STACK SIZE FOR LOCAL LARGE INPUTS ---------------------
void *start_routine(void *arg) {
    void (*func)() = (void (*)())arg;
    func();
    return NULL;
}
void run_with_stack_size(void (*func)(), size_t stsize) {
    pthread_t thread;
    pthread_attr_t attr;
    // Initialize thread attributes
    pthread_attr_init(&attr);
    // Set the stack size for the new thread
    pthread_attr_setstacksize(&attr, stsize);
    // Create a new thread with the modified stack size
    if (pthread_create(&thread, &attr, start_routine, (void *)func)) {
        fprintf(stderr, "Failed to create thread\n");
        exit(1);
    }
    // Wait for the thread to complete
    pthread_join(thread, NULL);
    // Destroy the thread attributes
    pthread_attr_destroy(&attr);
}
//--------------------------------------------------------------------------------

void main_(){
    ll test = 1;
    cin >> test;
    ll tt=1;
    while (test--) {
        cout<<"Case #"<<tt++<<": ";
        
    }
}

int main() {
    run_with_stack_size(main_, 1024  * 1024*1024);
    ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
    if (freopen("/Users/samarthgattu/Desktop/CP/code/input.txt", "r", stdin) == NULL) {
        cerr << "Error opening INPUT file!!" << endl;
    }
    if (freopen("/Users/samarthgattu/Desktop/CP/code/output.txt", "w", stdout) == NULL) {
        cerr << "Error opening OUTPUT file!!" << endl;
    }
    main_();
    return 0;
}
