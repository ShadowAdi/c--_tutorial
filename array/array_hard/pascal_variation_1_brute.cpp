#include <iostream>
using namespace std;

int fibonanic(int n) {
	if(n == 1) {
		return n;
	}
	return n * fibonanic(n - 1);
}

int nCr(int r, int c) {
	int rAns	= fibonanic(r);
	int cAns	= fibonanic(c);
	int ncAns = fibonanic(r - c);
	return rAns / (cAns * (ncAns));
}

int nCrBetter(int n, int c) {
	long long res = 1;
	for(int i = 0; i < c; i++) {
		res = res * (n - i);
		res = res / (i + 1);
	}
	return res;
}


int pascalTriangle(int r, int c) {
	int element = nCrBetter(r - 1, c - 1);
	return element;
}


int pascalTriangleVariant2(int n) {
	for(int c = 1; c <= n; c++) {
		cout << nCrBetter(n - 1, c - 1) << " ";
	}
	cout << " n";
}



int pascalTriangleVariant2Optimal(int n) {
	long long ans = 1;
	cout << ans << " "; // printing 1st element
	for(int i = 1; i < n; i++) {
		ans = ans * (n - i);
		ans=ans/i;
		cout<<ans<<" ";
	}
	cout<<endl;
}


int main() {
	int n = 5;
	pascalTriangleVariant2Optimal(n);
	return 0;
}