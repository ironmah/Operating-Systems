#include <stdlib.h>
#include <stdbool.h>

void swap (int *a, int *b)
{
        *a += *b;
        *b = *a - *b;
        *a -= *b;
}

int PrimeCount (int A, int B)
{
	// A = 5, B = 13 (5,7,11,13)
	if ((A < 0) && (B < 0))
	{
		return -1;
	}
	if (A > B)
	{
		swap(&A, &B);
	}
	if (A < 0)
        {
                A = 2;
        }
		
	bool* sieve = (bool*)calloc((B + 1), sizeof(bool)); // Memory for B+1 elements, each with the size of the float
        int amount = 0;
	sieve[0] = true;
	// B = 13, A = 5 
	if (B > 0)
	{
		sieve[1] = true;
	}
	// B = 13, A = 5 
	for (int i = 2; i <= B; i++)
	{
		// sieve[0] = true; sieve[1] = true;
		// i = 2; i = 3; 4;5;6;7;8;9;10;11;12;13
		if (sieve[i])
		{
			continue;
		}
		else
		{
			// sieve[2] = false;  sieve[3] = false; sieve[5] = false;
			if (i >= A)
			{
			        amount++; // amount = 1; 2;3;4
			}
			// B = 13
			for (int j = i * 2; j <= B; j += i)
			{
				// j = 2 * 2 = 4; j = 6, 8 , 10, 12; j = 6,9,12; j = 10; 
				sieve[j] = true;
				// sieve[4] = true;
				// sieve[6] = true;
				// sieve[8] = true;
				// sieve[9] = true;
				// sieve[10] = true;
				// sieve[12] = true;
			}
		}
	}
	free(sieve);
	return amount;	// 4
}

int GCF (int A, int B)
{
	// A = -12, B = 16
	A = abs(A);
	B = abs(B);
	// A = 12, B = 16
	if (!A && !B)
	{
		return -1;
	}
	if (A > B)
	{
		swap(&A, &B);
	}
	// !A = 0
	if (!A)
	{
		return B;
	}
	int g = 1;
	// A = 12, B = 16
	for (int i = 2; i <= A; i++)
	{
		//!(A % i) = !0 = 1, !(B % i) = !0 = 1
		if ((!(A % i)) && (!(B % i)))
		{
			g = i;
		}
	}
	return g;
}

