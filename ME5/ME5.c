#include <stdio.h>
#include <string.h>

int * polymul(int A[], int B[], int x, int y){
	int i,j;
	static int prod[100];
    for (i = 0; i < x + y - 1; i++)
        {
        prod[i] = 0;
        }
        
    for (i = 0; i < x; i++)
        {
        for (j = 0; j < y; j++)
            {
            prod[i + j] += A[i] * B[j];
            }
        }
    return prod;
}

int main(){
	int *ans, x=0, y=0, A[100], B[100], k;
	char temp; 
  	do { 
      scanf("%d%c", &A[x], &temp); 
      x++; 
  	} while(temp != '\n');
  	
  	char hold; 
  	do { 
      scanf("%d%c", &B[y], &hold); 
      y++; 
  	} while(hold != '\n'); 
	
	ans = polymul(A, B, x, y);

	for(k=0; k<(x+y-1); k++) {
    	printf("%d ", ans[k]);
  	}
	
	return 0;
}
