//C++ Code (Without STL lower_bound):

#include<bits/stdc++.h>
using namespace std;
int Lower_bound(int a[], int n, int x) {
    int left = 0;
    int right = n;
    while (left < right) {
        int middle = (left + right) / 2;
        if (x <= a[middle]) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }
    return left;
}

int main() {
   int x, n;
   cin >> x >> n;
   int a[n];
   for (int i = 0; i < n; ++i) {
       cin >> a[i];
   }
   int limit = Lower_bound(a, n, x);
   for (int i = 0; i < limit; ++i) {
       cout << a[i] << " ";
   }
  
}
