#include<bits/stdc++.h>
using namespace std;

int arr[100001];
int main(void){
   int n;
   cin >> n;
   for(int i = 0; i < n; ++i){
      cin >> arr[i];
   }
   sort(arr, arr+n);
   cout << min(arr[n - 1] - arr[1], arr[n - 2] - arr[0]) << "\n";
}
