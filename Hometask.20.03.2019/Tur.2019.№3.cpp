// n = 10
     // Source matrix: 
//5
//45   31   27   11   41   45   42
//27   36   41    4    2    3   42   32   21   16   18   45   47   26
//21   38   19   12   17   49   35   44    3
//11   22   33   23
//14   41   11    3   18   47   44   12    7   37    9   23   41   29   28   16   35   40
//42   38    6   40   42   14   48   46    5   40   29   20    0    6    1   43   48   29
//23   34
//4    6   40   16
   // Sorted matrix:
//5
//31   27   45   41   45   42   11
//27   36   41    4    2    3   42   32   21   16   18   45   47   26
//21   19   17   38   35   44   49    3   12
//11   22   33   23
//14   41   11    3   18   47   44   12    7   37    9   23   41   29   28   16   35   40
//42   38    6   40   42   14   48   46    5   40   29   20    0    6    1   43   48   29
//23   34
//4    6   40   16

#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
	char esc = 'y';
	while (esc == 'y' || esc == 'Y')
	{
		int n = InPutDimention();
		
        int* dimentions = nullptr;
		try
		{
			dimentions = AllocateMemoryInt(n);
		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
		}

		RandomArray(dimentions,n,20);

		int** matrix = nullptr;
		try
		{
			matrix = AllocateMemory(n, dimentions);
		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
		}

		RandomMatrix(matrix, n, dimentions);
		DisplayMatrix(matrix, n,dimentions);

		GetSorted(matrix, n, dimentions, QuickSort, GettingKeys);
		DisplayMatrix(matrix, n, dimentions);

		cout << "Press y ot Y to continue";
		cin >> esc;
		system("cls");

	}

	return 0;
}
