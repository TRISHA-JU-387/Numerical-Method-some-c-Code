#include <iostream>
#include <vector>
using namespace std;

void PrintMatrix(const vector<vector<float>>& a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++)
          cout << a[i][j]/a[i][i]<< " ";
        cout << endl;
    }
}

int PerformOperation(vector<vector<float>>& a, int n) {
    int flag = 0;

    // Performing elementary operations
    for (int i = 0; i < n; i++) {
        if (a[i][i] == 0) {
            int c = 1;
            while ((i + c) < n && a[i + c][i] == 0)
                c++;
            if ((i + c) == n) {
                flag = 1;
                break;
            }
            for (int j = i, k = 0; k <= n; k++)
                swap(a[j][k], a[j+c][k]);
        }

        for (int j = 0; j < n; j++) {
            if (i != j) {
                float pro = a[j][i] / a[i][i];
                for (int k = 0; k <= n; k++)
                    a[j][k] = a[j][k] - (a[i][k]) * pro;
            }
        }
    }
    return flag;
}

void PrintResult(const vector<vector<float>>& a, int n, int flag) {
    cout << "Result is : ";

    if (flag == 2)
      cout << "Infinite Solutions Exist" << endl;
    else if (flag == 3)
      cout << "No Solution Exists" << endl;

    else {
        cout << "Solution: ";
        for (int i = 0; i < n; i++)
            cout << a[i][n] / a[i][i] << " ";
    }
}


int CheckConsistency(const vector<vector<float>>& a, int n, int flag) {
    flag = 3;
    for (int i = 0; i < n; i++) {
        float sum = 0;
        for (int j = 0; j < n; j++)
            sum += a[i][j];
        if (sum == a[i][n])
            flag = 2;
    }
    return flag;
}


void InputMatrix(vector<vector<float>>& a, int n) {
    cout << "Enter the augmented matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;

    vector<vector<float>> a(n, vector<float>(n + 1));


    InputMatrix(a, n);

    int flag = 0;


    flag = PerformOperation(a, n);

    if (flag == 1)
        flag = CheckConsistency(a, n, flag);


    cout << "Final Augmented Matrix is : " << endl;
    PrintMatrix(a, n);
    cout << endl;


    PrintResult(a, n, flag);

    return 0;
}
