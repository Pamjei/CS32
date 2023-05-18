#include <stdio.h>
#include <stdlib.h>

void init(int i, int n, int arr[1000])
{   
    for(i = 0; i < n; i++)
        arr[i] = 0;
}

int main(){
	int i, n, k, arr[1000], hash, x, y;
	scanf("%d %d\n", &n, &k);
	init(i, n, arr);
    for(i=0; i<n; i++){
    	if (scanf("%d", &x) == 1){
    		y =x;
    		hash = x%n;
    		if(arr[hash] == 0){
    			arr[hash] = y;
			}
			else{
				while(arr[hash] != 0){
					x = x-k;
					hash = x%n;
				}
				arr[hash]= y;
			}
		}
	}
	
	for(i=0; i<n; i++){
		if(arr[i]==0){
			printf("e\n");
		}
		else{
			printf("%d\n", arr[i]);
		}
	
	}
	return 0;
}
