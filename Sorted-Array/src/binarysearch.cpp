#include<bits/stdc++.h>
using namespace std;
int search(int a[], int n, int x) {
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
   cout<<"Enter x to search for it: \n";
   cin >> x ;
   cout <<" Enter n for size of array: \n";
   cin >> n;
 
   int a[n];
   cout <<" Enter "<<n<<" SORTED elements to fillup the array : \n";
   for (int i = 0; i < n; ++i) {
       cin >> a[i];
   }
   int output = search(a, n, x);
       cout<<" --------------------------------------\n\n";
   for (int i = 0; i < output; ++i) {
       cout << a[i] <<endl;
       cout<<" --------------------------------------\n\n";
   }
  
}
