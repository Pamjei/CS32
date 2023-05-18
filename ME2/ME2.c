#include <stdio.h>
#include <string.h>

void initial(int i, int n, int arr[1000])
{   
    for(i = 0; i < n; i++)
        arr[i] = 0;
}

int main()
{
	int n, t, x, y, i, stax[1000];
	
	scanf("%d", &n);
	scanf("%d", &t);
	initial(i, n-t, stax);
	i =0;
	while(i<n-t){
		scanf("%d %d", &x, &y);
		stax[x] = stax[x] + 1;
		i++;
	}
	printf("NO REALLOCATION");
	
	return 0;
}
