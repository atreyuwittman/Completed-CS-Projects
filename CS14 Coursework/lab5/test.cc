#include <iostream>
#include <fstream>
#include <ostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void sift(int a[], int size, int l)
{
  int i,j, x;
  i = l;
  j = 2*i+1;
  x = a[i];
  while (j < size)
  {
    if ( j <size - 1)
      if ( a[j] < a[j+1])
        ++j;
    if (x >= a[j])
      break;
    a[i] = a[j];
    i = j;
    j = 2*i + 1; // sift
  }
  a[i] = x;
}
void make_heap(int a[], int size)
{
  int l = size / 2;
  while (l)
  {
    --l;
    sift(a, size, l);
  }
} 
void heapsort(int a[], int size)
{
  int l = 0, r = size;
  make_heap(a, size);
 
  while ( r > 1)
  {
    int tmp = a[0];
    --r;
    a[0] = a[r];
    a[r] = tmp;
    sift(a, r,0);
  }
}

int main() {
	int a[] = {2, 4, 7, 9, 5, 3, 6};
	heapsort(a, 7);
	for(int i = 0; i < 7; i++){
	    cout << a[i] << " ";
	}
	return 0;
}