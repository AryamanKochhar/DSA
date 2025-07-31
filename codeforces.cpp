#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

    int n;
    cin >> n;
    n%2 == 0 && n!=2 ? cout << "YES" : cout << "NO";
   return 0;
} 
