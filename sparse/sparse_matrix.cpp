#include <iostream>
using namespace std;

// Function to input a sparse matrix and return the triplet representation
void inputSparseMatrix(int &m, int &n, int &ctr, int trip[][3]) {
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;
    
    // Dynamically allocate the sparse matrix
    int **sparse = new int*[m];
    for (int i = 0; i < m; i++) {
        sparse[i] = new int[n];
    }
    
    cout << "Enter the elements of the matrix:\n";
    ctr = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> sparse[i][j];
            if (sparse[i][j] != 0) {
                trip[++ctr][0] = i;
                trip[ctr][1] = j;
                trip[ctr][2] = sparse[i][j];
            }
        }
    }
    
    trip[0][0] = m;
    trip[0][1] = n;
    trip[0][2] = ctr;

    // Deallocate the sparse matrix
    for (int i = 0; i < m; i++) {
        delete[] sparse[i];
    }
    delete[] sparse;
}

// Function to display the triplet representation of a sparse matrix
void displayTriplet(int ctr, int trip[][3]) {
    cout << "Triplet representation of sparse matrix is:\n";
    for (int i = 0; i <= ctr; i++) {
        for (int j = 0; j < 3; j++) {
            cout << trip[i][j] << "\t";
        }
        cout << endl;
    }
}

// Function to transpose a sparse matrix using the total and incident matrix method
void transposeSparseMatrix(int ctr, int trans[][3], int trip[][3]) {
    int m = trip[0][0], n = trip[0][1];
    int count[100] = {0}, index[100] = {0};  // Ensured large enough size

    for (int i = 1; i <= ctr; i++) {
        count[trip[i][1]]++;  // Counting occurrences in columns //incident
    }

    index[0] = 1;
    for (int i = 1; i <= ctr; i++) {
        index[i] = index[i - 1] + count[i - 1];  // Assign index positions
    }

    trans[0][0] = n;
    trans[0][1] = m;
    trans[0][2] = ctr;

    for (int i = 1; i <= ctr; i++) {
        int pos = index[trip[i][1]]++;
        trans[pos][0] = trip[i][1];
        trans[pos][1] = trip[i][0];
        trans[pos][2] = trip[i][2];
    }

    displayTriplet(ctr, trans);
}


// Function to add two sparse matrices
void addSparseMatrices(int ctr1, int trip1[][3], int ctr2, int trip2[][3], int result[][3]) {
    int i = 1, j = 1, k = 1;
    while (i <= ctr1 && j <= ctr2) {
        if (trip1[i][0] < trip2[j][0] || (trip1[i][0] == trip2[j][0] && trip1[i][1] < trip2[j][1])) {
            result[k][0] = trip1[i][0];
            result[k][1] = trip1[i][1];
            result[k][2] = trip1[i][2];
            i++;
        } else if (trip1[i][0] > trip2[j][0] || (trip1[i][0] == trip2[j][0] && trip1[i][1] > trip2[j][1])) {
            result[k][0] = trip2[j][0];
            result[k][1] = trip2[j][1];
            result[k][2] = trip2[j][2];
            j++;
        } else {
            result[k][0] = trip1[i][0];
            result[k][1] = trip1[i][1];
            result[k][2] = trip1[i][2] + trip2[j][2];
            i++;
            j++;
        }
        k++;
    }

    while (i <= ctr1) {
        result[k][0] = trip1[i][0];
        result[k][1] = trip1[i][1];
        result[k][2] = trip1[i][2];
        i++;
        k++;
    }

    while (j <= ctr2) {
        result[k][0] = trip2[j][0];
        result[k][1] = trip2[j][1];
        result[k][2] = trip2[j][2];
        j++;
        k++;
    }

    result[0][0] = trip1[0][0];
    result[0][1] = trip1[0][1];
    result[0][2] = k - 1;

    displayTriplet(result[0][2], result);
}

// Function to multiply two sparse matrices
void multiplySparseMatrices(int ctr1, int trip1[][3], int ctr2, int trip2[][3], int result[][3]) {
    // First transpose the second matrix
    int trans[ctr2 + 1][3];
    transposeSparseMatrix(ctr2, trans, trip2);
    
    int k = 1;  // To track the position in the result triplet
    // Iterate through each non-zero element of the first matrix
    for (int i = 1; i <= ctr1; ) {
        int row = trip1[i][0];  // Current row in trip1
        // Process all elements in the same row
        while (i <= ctr1 && trip1[i][0] == row) {
            // For each element in this row, find matching columns in the transposed second matrix
            for (int j = 1; j <= ctr2; ) {
                int col = trans[j][0];  // Current column in the transposed second matrix
                int sum = 0;
                int tempI = i, tempJ = j;
                
                // Accumulate the product of matching elements from row trip1[i] and col trans[j]
                while (tempI <= ctr1 && trip1[tempI][0] == row && tempJ <= ctr2 && trans[tempJ][0] == col) {
                    if (trip1[tempI][1] == trans[tempJ][1]) {
                        sum += trip1[tempI][2] * trans[tempJ][2];
                    }
                    if (trip1[tempI][1] < trans[tempJ][1]) {
                        tempI++;  // Move in trip1 (first matrix)
                    } else {
                        tempJ++;  // Move in transposed trip2 (second matrix)
                    }
                }
                
                // If sum is non-zero, store it in the result triplet
                if (sum != 0) {
                    result[k][0] = row;
                    result[k][1] = col;
                    result[k][2] = sum;
                    k++;
                }
                
                // Move to the next column in the transposed matrix
                while (j <= ctr2 && trans[j][0] == col) {
                    j++;
                }
            }
            // Move to the next element in the row of the first matrix
            while (i <= ctr1 && trip1[i][0] == row) {
                i++;
            }
        }
    }

    // Store matrix dimensions in result's first row
    result[0][0] = trip1[0][0];
    result[0][1] = trip2[0][1];
    result[0][2] = k - 1;

    // Display the result triplet
    displayTriplet(result[0][2], result);
}


int main() {
    int m1, n1, ctr1, m2, n2, ctr2;

    // First matrix input and triplet representation
    int trip1[100][3];
    inputSparseMatrix(m1, n1, ctr1, trip1);
    displayTriplet(ctr1, trip1);

    // Second matrix input and triplet representation
    int trip2[100][3];
    inputSparseMatrix(m2, n2, ctr2, trip2);
    displayTriplet(ctr2, trip2);

    // Transpose of first matrix
    cout << "Transpose of first matrix:\n";
    int trans[ctr1 + 1][3];
    transposeSparseMatrix(ctr1, trans, trip1);

    // Addition of two matrices
    if (m1 == m2 && n1 == n2) {
        cout << "Addition of two matrices:\n";
        int resultAdd[ctr1 + ctr2 + 1][3];
        addSparseMatrices(ctr1, trip1, ctr2, trip2, resultAdd);
    } else {
        cout << "Matrices cannot be added due to dimension mismatch.\n";
    }

    // Multiplication of two matrices
    if (n1 == m2) {
        cout << "Multiplication of two matrices:\n";
        int resultMul[ctr1 * ctr2 + 1][3];
        multiplySparseMatrices(ctr1, trip1, ctr2, trip2, resultMul);
    } else {
        cout << "Matrices cannot be multiplied due to dimension mismatch.\n";
    }

    return 0;
}