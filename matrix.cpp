#include <iostream>
using namespace std;

void makeMatrix(int rows, int cols);

int main()
{
    int rows;
    int cols;

    do
    {
        cout << "Number of rows: \n";
        cin >> rows;
        if (rows <= 0)
            cout << "Number of rows can't be negative number or 0. Please enter positive number. ";

    } while (rows <= 0);

    do
    {
        cout << "Number of columns: \n";
        cin >> cols;

        if (cols <= 0)
            cout << "Number of columns can't be negative number or 0. Please enter positive number. ";

    } while (cols <= 0);
    makeMatrix(rows, cols);

    return 0;
}

void makeMatrix(int rows, int cols)
{
    int MATRIX[rows][cols];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            MATRIX[i][j] = 0;

    int top = 0;
    int left = 0;
    int right = cols - 1;
    int bottom = rows - 1;

    int MATRIX_DIMENSION = rows * cols;
    for (int i = 0; i < rows; i++)
    {
        for (int j = cols - 1; j >= 0; j--)
        {
            if (MATRIX[bottom][j])
                continue;

            else
                MATRIX[bottom][j] = MATRIX_DIMENSION--;
        }
        bottom--;

        for (int j = rows - 1 - i; j >= 0; j--)
        {
            if (MATRIX[j][left])
                continue;

            else
                MATRIX[j][left] = MATRIX_DIMENSION--;
        }
        left++;

        for (int j = 0; j <= cols; j++)
        {
            if (MATRIX[top][j])
                continue;

            else
                MATRIX[top][j] = MATRIX_DIMENSION--;
        }
        top++;

        for (int j = rows + i; j < rows - 1; j++)
        {
            if (MATRIX[j][right])
                continue;

            else
                MATRIX[j][right] = MATRIX_DIMENSION--;
        }
        right--;
    }
    cout << '\n';

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << MATRIX[i][j] << '|';
        cout << '\n';
    }
}
