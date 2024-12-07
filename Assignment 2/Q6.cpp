#include <iostream>
using namespace std;


int sparse[5][5], i, j, m, n, ctr = 0;

int** transpose(int ctr, int m, int n){
    int trip[ctr + 1][3];
    trip[0][0] = m;
    trip[0][1] = n;
    trip[0][2] = ctr;
    
    int k = 1;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (sparse[i][j] != 0)
            {
                trip[k][0] = i;
                trip[k][1] = j;
                trip[k][2] = sparse[i][j];
                k++;
            }
        }
    }

    cout << "Triplet form of sparse matrix is:\n";
    cout << '\t' << "Rows" << '\t' << "Columns" << '\t' << "Values" << endl;
    for (i = 0; i <= ctr; i++)
    {
        cout << '\t' << trip[i][0] << '\t' << trip[i][1] << '\t' << trip[i][2] << endl;
    }

    int maxCol = INT_MIN;
    for (int i = 1; i <= ctr; i++) {
        if (trip[i][1] > maxCol)
            maxCol = trip[i][1];
    }
    
    cout << endl;
    cout << "<----------------------------------------->";
    cout << endl;

    // Total matrix
    int total[maxCol + 1][2];
    for (int i = 0; i <= maxCol; i++) {
        total[i][0] = i;
        total[i][1] = 0;
    }

    for (int i = 1; i <= ctr; i++) {
        if (trip[i][1] <= maxCol) {
            total[trip[i][1]][1]++;
        }
    }

    // Printing total matrix 
    cout << "Total Matrix is:\n";
    cout << '\t' << "Rows" << '\t' << "Columns" << endl;
    for (int i = 0; i < maxCol + 1; i++) {
        for (int j = 0; j < 2; j++) {
            cout << '\t' << total[i][j] << '\t';
        }
        cout << endl;
    }

    cout << endl;
    cout << "<----------------------------------------->";
    cout << endl;

    // Incident matrix
    int incident[maxCol + 2][2];
    for (int i = 0; i <= maxCol + 1; i++) {
        incident[i][0] = i;
        incident[i][1] = 0;
    }
    incident[0][1] = 1;
    for (int i = 1; i <= maxCol + 1; i++) {
        incident[i][1] = incident[i - 1][1] + total[i - 1][1];
    }

    // Printing incident matrix
    cout << "Incident Matrix is:\n";
    cout << '\t' << "Rows" << '\t' << "Columns" << endl;
    for (int i = 0; i < maxCol + 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << '\t' << incident[i][j] << '\t';
        }
        cout << endl;
    }

    cout << endl;
    cout << "<----------------------------------------->";
    cout << endl;

    // Transpose matrix creation
    int** answer = new int*[ctr + 1];
    for (int i = 0; i <= ctr; i++) {
        answer[i] = new int[3];
    }

    answer[0][0] = trip[0][1];  // Swapping rows and columns for transpose
    answer[0][1] = trip[0][0];
    answer[0][2] = trip[0][2];

    for (int i = 1; i <= ctr; i++) {
        answer[incident[trip[i][1]][1]][0] = trip[i][1];
        answer[incident[trip[i][1]][1]][1] = trip[i][0];
        answer[incident[trip[i][1]][1]][2] = trip[i][2];
        incident[trip[i][1]][1]++;
    }

    // Printing answer matrix
    cout << "\nAnswer Matrix: \n";
    cout << '\t' << "Rows" << '\t' << "Columns" << '\t' << "Values" << endl;
    for (int i = 0; i <= ctr; i++) {
        cout << '\t' << answer[i][0] << '\t' << answer[i][1] << '\t' << answer[i][2] << endl;
    }

    cout << endl;
    cout << "<----------------------------------------->";
    cout << endl;

    return answer;
}

int main()
{   
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;
    cout << "Enter the elements of the matrix: ";
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> sparse[i][j];
        }
    }

    cout << "Sparse matrix is:\n";
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << "\t" << sparse[i][j];
        }
        cout << "\n";
    }

    cout << endl;
    cout << "<----------------------------------------->";
    cout << endl;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (sparse[i][j] != 0)
                ctr++;
        }
    }

    int** transposedArr = transpose(ctr, m, n);

    // Deallocate memory
    for (int i = 0; i <= ctr; i++) {
        delete[] transposedArr[i];
    }
    delete[] transposedArr;

    return 0;
}
