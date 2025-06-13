#include <iostream>
#include <vector>
using namespace std;

void markRow(vector<vector<int>>& matrix, int n, int m, int i) {
	for(int j = 0; j < m; j++) {
		if(matrix[i][j] != 0) {
			matrix[i][j] = -1;
		}
	}
}

void markCol(vector<vector<int>>& matrix, int n, int m, int j) {
	for(int i = 0; i < n; i++) {
		if(matrix[i][j] != 0) {
			matrix[i][j] = -1;
		}
	}
}


vector<vector<int>> setMatrixZero(vector<vector<int>>& matrix) {
	int n = matrix.size();
	int m = matrix[0].size();
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(matrix[i][j] == 0) {
				markCol(matrix, n, m, j);
				markRow(matrix, n, m, i);
			}

		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(matrix[i][j] == -1) {
				matrix[i][j] = 0;
			}
		}
	}

	return matrix;
}

vector<vector<int>> setMatrixZeroBetter(vector<vector<int>>& matrix) {
	int n = matrix.size();
	int m = matrix[0].size();

	int rows[n] = {0};
	int cols[m] = {0};

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(matrix[i][j] == 0) {
				rows[i] = 1;
				cols[j] = 1;
			}
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if (rows[i] || cols[j])
			{
				matrix[i][j]=0;
			}
		}
	}
	return matrix;
}

int main() {
	vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
	vector<vector<int>> ans = setMatrixZeroBetter(matrix);

	cout << "The Final matrix is: ";
	for(auto it : ans) {
		for(auto ele : it) {
			cout << ele << " ";
		}
		cout << "\n";
	}
	return 0;
}