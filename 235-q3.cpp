#include<bits/stdc++.h>
using namespace std;

int main() {
   int x, n;
   cin >> x >> n;
   vector<int> a(n);
  
   /*
   vectors are just like arrays with added advantages. There dynamically
   allocated like lists(whose size can change) and also have indexes like arrays.
   */
   for (int i = 0; i < n; ++i) {
       cin >> a[i];
   }
   vector<int> :: iterator it; // unlike array, iterators can also be used to traverse an vector.

   /*
   lower_bound() returns an iterator to the elements in the given range which does no compare less(i.e which means is greater than or equal to :))
   than the given value. The range given should be already sorted for lower_bound() to work. In plain words it
   returns an iterator to the lower bound of the given element in a sorted range.
   */
  
   it = lower_bound(a.begin(), a.end(), x);
   /*
   lower bound has returned the position of the element which is greater than or equal to the x.
   Therefore, the numbers less than x will be till that position excluding that number.
   */
   for (int i = 0; i < (it - a.begin()); ++i) {
   /*
   it - a.begin because 'it' is a pointer and its value corresponds to an address.
   Therefore subtracting the starting address of the vector will give us the distance of that pointer from the starting address,
   which would be needed to display the numbers smaller than the given number ('x')
   */
       cout << a[i] << " ";
   }  
}