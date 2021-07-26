#include <iostream>
#define NMAX 101;


void rotate_90_degress(int a[101][101], int n)
{
    // taking the layers
    for (int layer = 0; layer < n; layer++) {
        int first = layer;
        int last = n - 1 - first;

        for (int i = first ; i < last; i++) {
            int off_set = i - first;
            // keeping the first line
            int top = a[first][i];

            // the first line become the left column => left to top
            a[first][i] = a[last - off_set][first];

            // the first column become the last line=> bottom to left
            a[last - off_set][first] = a[last][last - off_set];

            // the last line become the last column => left to bottom
            a[last][last - off_set] = a[i][last];

            // the last column become the first line (the top)
            a[i][last] = top;

        }
    }
}

int main() {
    int n, m;
    std::cin >> n;;
    int a[101][101];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> a[i][j];
        }
    }
    rotate_90_degress(a, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}