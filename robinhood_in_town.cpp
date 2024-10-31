#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define Y cout<<"YES"<<endl
#define N cout<<"NO"<<endl
#define pb push_back
#define faster                    ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int mxm = 1e8+7;
bitset<mxm> mark;
vector<int> primes;
ll linear_Diphontine(ll a, ll b,
                     ll& x, ll& y)
{
    // Base Case
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    // Recursively find the gcd
    else
    {
        ll g = linear_Diphontine(b,
                                 a % b, x, y);
        int x1 = x, y1 = y;
        x = y1;
        y = x1 - (a / b) * y1;
        cout << x << " " << y <<endl;
        return g;
    }
}
///baby step jiant step algo
// Returns minimum x for which a ^ x % m = b % m, a and m are coprime.
int solve(int a, int b, int m)
{
    a %= m, b %= m;
    int n = sqrt(m) + 1;

    int an = 1;
    for (int i = 0; i < n; ++i)
        an = (an * 1ll * a) % m;

    unordered_map<int, int> vals;
    for (int q = 0, cur = b; q <= n; ++q)
    {
        vals[cur] = q;
        cur = (cur * 1ll * a) % m;
    }

    for (int p = 1, cur = 1; p <= n; ++p)
    {
        cur = (cur * 1ll * an) % m;
        if (vals.count(cur))
        {
            int ans = n * p - vals[cur];
            return ans;
        }
    }
    return -1;
}

void sieve()
{

    mark[0] = mark[1] = true;

    for(int i = 2; i*i <= mxm; i++)
    {

        if(!mark[i])
        {
            // cout<< i << "           ";
            for(int j = i*i; j < mxm; j += i)
            {
                mark[j] = true ;

                //    cout << j <<" ";
            }
            //	cout<<endl;
        }
    }
    for(int i=0; i<mxm; i++)
    {
        //  cout <<i << " "<<  mark[i] <<endl;;
    }
    primes.push_back(2);
    // cprimes.push_back(2);
    for(int i = 3; i < mxm; i += 2)
    {
        if(!mark[i])
        {
            primes.push_back(i);
            //  cprimes.push_back(i);
        }
    }
}
void vp(vector<ll>v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
}
int is_it_prime(ll n)
{
    int c=1;
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            c=0;
            return c;
        }
    }
    return c;
}

int parent[100005];
int sz[100005];
void make_parents(int n)
{
    for(int i=1; i<=n; i++)
    {
        parent[i] = i;
        sz[i]=1;
    }
}
int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}
ll phi(ll n)
{
    // Initialize result as n
    ll result = n;

    // Consider all prime factors of n
    // and subtract their multiples
    // from result
    for(ll p = 2; p * p <= n; ++p)
    {

        // Check if p is a prime factor.
        if (n % p == 0)
        {

            // If yes, then update n and result
            while (n % p == 0)
                n /= p;

            result -= result / p;
        }
    }


    if (n > 1)
        result -= result / n;

    return result;
}
ll fact(ll n, ll mod)
{
    ll mul = 1;
    for(int i=1; i<=n; i++)
    {
        mul = (mul * i) % mod;
        mul = mul % mod;
    }
    return mul;
}
ll powerDivideandconquer(ll a, ll b, ll m)
{
    if(b==0)return 1% m;
    ll x = powerDivideandconquer(a,b/2,m);
    x = (x *x) % m;
    if(b%2==1) x = (x*a) % m;
    return x%m;
}
ll modul_inverse(ll b, ll mod)
{
    ll r1 = phi(mod);
    // cout<<r1<<" "<<b<<" "<<mod<<endl;
    ll r2 = powerDivideandconquer(b,r1-1,mod);
    return r2%mod;

}
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
       ll n;
       cin >> n;
       ll ara[n+1];
       ll avg;
       ll sum = 0;
       for (int i = 1; i <=n; i++)
       {
        cin >> ara[i];
        sum += ara[i];
       }
       avg = sum/n;


       sort(ara+1, ara + n + 1);
       ll middle_index = n/2;
       middle_index++;
       ll max_of_1st_half = ara[middle_index];

       if (max_of_1st_half < avg/2)
       {
            cout <<"0" << endl;
            continue;
       }

     ll res = -1;
     if (n <=2 )
     {
        cout << res << endl;
        continue;
     }

        res = (max_of_1st_half * 2 * n)  - sum + 1;




     cout << max(res, 0ll) << endl;


    }

}


