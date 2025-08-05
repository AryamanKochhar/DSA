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

vector<char> inqu(vector<char> Q, int y) {
  int n=Q.size();

  for(int i=0;i<n;i++){
    while(y>0){
    if(Q[i]=='B' && Q[i+1]=='G'){
      swap(Q[i],Q[i+1]);
    }
    y--;
  }
  }
  return Q;


}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
  int x=0,y=0;
  // Your code here
  cin>>x;
  cin>>y;
  vector<char> Q;
  for(int i=0;i>x;i++){
    char c;
    cin >> c;
    Q.push_back(c);
  }

   return 0;
}
