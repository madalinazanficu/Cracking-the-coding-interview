#include <iostream>

// take O(1) extra storage complexity 
// O (n ^ 2) time complexity
void nulifyline(int a[101][101], int i, int m)
{
    for (int j = 0; j < m; j++) {
        a[i][j] = 0;
    }
}

void nulifycolumn(int a[101][101], int j, int n)
{
    for(int i = 0; i < n; i++) {
        a[i][j] = 0;
    }
}

void set_zeros(int a[101][101], int n, int m)
{
    // verific daca prima linie sau coloana a matricii contine 0
    int row_has_zero = false;
    int column_has_zero = false;

    // the column 0
    for (int i = 0; i < n; i++) {
        if (a[i][0] == 0) {
            column_has_zero = true;
        }
    }
    // the line 0
    for (int i = 0; i < m; i++) {
        if (a[0][i] == 0) {
            row_has_zero = true;
        }
    }

    // use the first line/ first column to keep track of the zeros
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i][j] == 0) {
                a[0][j] = 0;
                a[i][0] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i][0] == 0) {
            nulifyline(a, i, m);
        }
    }
    for (int j = 0; j < m; j++) {
        if (a[0][j] == 0) {
            nulifycolumn(a, j, n);
        }
    }
    // daca prima linie avea 0
    if (row_has_zero) {
        nulifyline(a, 0, m);
    }
    if (column_has_zero) {
        nulifycolumn(a, 0, n);
    }
}


int main () {
    int n, m;
    std::cin >> n >> m;
    int a[101][101];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> a[i][j];
        }
    }
    set_zeros(a, n, m);
    std::cout << "\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}