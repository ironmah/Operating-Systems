#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <stdbool.h>

const char* path1 = "libfunctions1.so";
const char* path2 = "libfunctions2.so";
void (*swap)(int*, int*);
int (*PrimeCount)(int, int);
int (*GCF)(int, int);
void *handle = NULL;
bool first = true;

void Load()
{
        const char *path;
        if(first)
        {
                path = path1;
        }   
        else
        {
        	path = path2;
        }
        handle = dlopen(path, RTLD_LAZY); // loading the library
        if(!handle) 
        {
		fprintf(stderr, "%s\n", dlerror());
		exit(EXIT_FAILURE);
        }
}

void Unload()
{
        dlclose(handle);
}

void loadContext()
{
        Load(); // to load the library
        swap = dlsym(handle, "swap"); // swap = pointer to a function swap in path handle
        PrimeCount = dlsym(handle, "PrimeCount");
        GCF = dlsym(handle, "GCF");
        char* error;
        if((error = dlerror())) //dlerror will return smth if there is an error
        {
		fprintf(stderr, "%s\n", error);
		exit(EXIT_FAILURE);
        }
}

void Change()
{
        Unload();
        first ^= true;
        loadContext();
}

int main()
{
        loadContext(); // to load the library and attach pointers to the needed functions
        int ind = 0;
        while (scanf("%d", &ind) != EOF)
        {
		if(!ind)
		{
			Change();
			printf("Contract was changed. ");
			if(first)
			{
				printf("Now context is first\n");
			}    
			else
			{
				printf("Now context is second\n");
			}
			continue;
		}
		if(ind == 1) 
		{
			int A, B, result;
			scanf("%d %d", &A, &B);
			result = PrimeCount(A, B);
			if (result == -1)
			{
				printf("At least A or B must be non-negative whole numbers\n");
			}
			else
			{
				printf("%d\n", result);
			}
		}
		else if (ind == 2)
		{
			int A, B, result;
			scanf("%d %d", &A, &B);
			result = GCF (A, B);
			if (result == -1)
			{
				printf("Infinity\n");
			}
			else
			{
				printf("%d\n", result);
                        }
		}
		else {
			printf("First digit must be 0, 1 or 2\n");
		}
        }
        Unload();
	return 0;
}
