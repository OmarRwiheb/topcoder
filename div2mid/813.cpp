#include<bits/stdc++.h>
 
using namespace std;
 
const int MX = 1e6 + 1;
 
#define PI 3.14159265
#define sqr(x) ((x)*(x))
#define pr pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define vull vector<unsigned long long>
#define all(v) ((v).begin()), ((v).end())
#define rev(v) ((v).rbegin()), ((v).rend())
#define rep(i, st, en) for(int i = st; i < en; i++)
#define Fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
 
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long int ulli;
 
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
 
 
bool sortbysec(const pair<string, string> &a, const pair<string, string> &b) {
    if(a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
 
}

template<typename T>
void input(vector<T>& v){ for(auto& it : v) cin >> it; }
 
ll binPow(ll b, ll p) {
    if (p == 0) return 1;
    ll sq = binPow(b, p / 2);
    sq *= sq;
 
    if (p & 1)
        sq *= b;
 
    return sq;
}

class LooRollPyramid{
public:
    vector <int> countMissing(int Q, vector <int> A, vector<long long> B){
        vector<int>ans;
        for(int i = 0; i < Q; i++){
            if(B[i] == 0){
                ans.push_back(0);
                continue;
            }
            long double rem = (A[i] + 1) / 2.0;
            rem *= A[i];
            rem -= B[i];
            ull st = 0, en = A[i];
            ull x = -1;
            while(st <= en){
                ull mid = st + (en - st) / 2;
                long double n = (mid + 1) / 2.0;
                n *= mid;
                if(n <= rem){
                    x = rem;
                    x -= n;
                    st = mid + 1;
                }
                else{
                    en = mid - 1;
                }
            }
            ans.push_back(x);
        }
        return ans;
    }
};
