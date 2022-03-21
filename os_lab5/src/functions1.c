#include <stdlib.h>
#include <stdbool.h>

void swap (int *a, int *b)
{
		// a = 3, b = 5
        *a += *b; // a = 3 + 5 = 8
        *b = *a - *b; // b = 8 - 5 = 3
        *a -= *b; // a = 8 - 3 = 5
}

int PrimeCount (int A, int B)
{
	// 7, 5, 3, 2
	// A = 7, B = -5
	if ((A < 0) && (B < 0))
	{
		return -1;
	}
	if (A > B)
	{
		swap(&A, &B);
	}
	// A = -5, B = 7
	if (A < 0)
	{
		A = 0;
	}
	// A = 0, B = 7
	int amount = 0;
	bool prime = true;
	for (int i = A; i <= B; i++)
	{
		if (i > 1)
		{
			// i = 2; 3; 4; 5; 6; 7
			for (int j = 2; j * j <= i; j++)
			{
				// j = 2; 3;
				if (!(i % j))
				{
					prime = false;
					break;
				}
			}
			if (prime)
			{
				amount++; // 1; 2; 3; 4
			}
			prime = true;
		}
	}
	return amount;
}

int GCF (int A, int B)
{
	// A = 16, B = 12 
	if (!A && !B)
	{
		return -1;
	}
	A = abs(A);
	B = abs(B);
	if (A < B)
	{
		swap(&A, &B);
	}
	while (B)
	{
		// A = 16, B = 12
		A %= B; // A = 16 % 12 = 4 ; A = 12%4 = 0
		swap(&A, &B); // A = 12 , B = 4; B = 0, A = 4
	}
	return A; // 4
}
