#include <iostream>

using namespace std;

class ArraySizeException
{
public:
    const char* what()
    {
        return "Неправильний розмір масиву! Потрібен масив 4x4.";
    }
};

class ArrayDataException
{
private:
    int row;
    int col;

public:
    ArrayDataException(int r, int c)
    {
        row = r;
        col = c;
    }

    const char* what()
    {
        return "У масиві знаходяться неправильні дані.";
    }

    int getRow()
    {
        return row;
    }

    int getCol()
    {
        return col;
    }
};

class ArrayValueCalculator
{
public:
    int doCalc(const char* arr[][4], int rows)
    {
        if (rows != 4)
        {
            throw ArraySizeException();
        }

        int sum = 0;

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                int number = 0;
                int k = 0;

                while (arr[i][j][k] != '\0')
                {
                    if (arr[i][j][k] < '0' ||
                        arr[i][j][k] > '9')
                    {
                        throw ArrayDataException(i, j);
                    }

                    number = number * 10 +
                        (arr[i][j][k] - '0');

                    k++;
                }

                sum += number;
            }
        }

        return sum;
    }
};

int main()
{
    system("chcp 65001");
    const char* array[4][4] =
    {
        {"1", "2", "3", "4"},
        {"5", "6", "7", "8"},
        {"9", "10", "11", "12"},
        {"13", "14", "15", "16"}
    };

    ArrayValueCalculator calculator;

    try
    {
        int result = calculator.doCalc(array, 4);

        cout << "Сума всіх елементів: "
            << result << endl;
    }
    catch (ArraySizeException& e)
    {
        cout << "ArraySizeException: "
            << e.what() << endl;
    }
    catch (ArrayDataException& e)
    {
        cout << "ArrayDataException: "
            << e.what() << endl;

        cout << "Помилка у комірці: ["
            << e.getRow() << "]["
            << e.getCol() << "]" << endl;
    }
}