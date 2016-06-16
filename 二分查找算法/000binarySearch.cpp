#include <iostream>
using namespace std;

static int error;
int binarySearch(int a[], int p, int r, int key)
{
	int mid = (p+r)/2;
	if(p > r){
		error = -1;
		return error;
	}

	if(p < r){
		if(a[mid] < key)
			p = mid+1;
		else if(a[mid] > key)
			r = mid-1;
		else
			return mid;
		return binarySearch(a, p, r, key);
	}
	error = -2;
	return error;
}

int main()
{
	int res;
	int a[] = {1, 3, 10, 11, 21, 100, 102};
	res = binarySearch(a, 0, sizeof(a)/sizeof(int)-1, 14);
	if(res == -1)
		cout << "error input" << endl;
	else if(res == -2)
		cout << "no found" << endl;
	else
		cout << "index is " << res << endl;
}
