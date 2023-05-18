#include <stdio.h>
#include <stdlib.h>

int isnum(char c){
	if( c >= '0' && c <= '9' ){
		return 1;
	}
	else{
		return 0;
	}
}

int items[100], front = -1, rear = -1;

void enQueue(int value) {
    if (front == -1)
      front = 0;
    rear++;
    items[rear] = value;
  }

void deQueue() {
    front++;
    if (front > rear)
      front = rear = -1;
  }

int main(){
	int x, y, elem=0, count[1000], i, check, j;
	int list[100][100] = {{0}};
	char entry[10], hold[2];
	struct LinkedList* head = NULL;
	
	for (i = 0; i < 100; i++){
		count[i] = 0;
	}
	
	while (elem!=1000){
		fgets(entry, 10, stdin);
		i=0;
		while (i<10){
			if(entry[i]=='(' && isnum(entry[i+1])==1 && entry[i+2]==','){
				x = entry[i+1] - '0';
			}
			else if(isnum(entry[i])==1 && isnum(entry[i+1])==1 && entry[i+2]==','){
				hold[0] = entry[i];
				hold[1] = entry[i+1];
				x = atoi(hold);
			}
			else if(entry[i]==',' && isnum(entry[i+1])==1 && entry[i+2]==')') {
				y = entry[i+1] - '0';
			}
			else if(entry[i]==',' && isnum(entry[i+1])==1 && isnum(entry[i+2])==1) {
				hold[0] = entry[i+1];
				hold[1] = entry[i+2];
				y = atoi(hold);
			} 
			i++;
		}
		count[y] = count[y] + 1;
		
		for (j = 0; j <= 100; j++){
			if(list[x][j]==0){
				list[x][j]==y;
				break;
			}
		}
		
		elem++;
		
		if(entry[0]=='\n'){
			break;
		}
		
	}
	check = elem;	
	
	for (i = 1; i <= elem; i++){
		if (count[i] == 0){
			enQueue(i);
		}
	}
	
	for (j = front; j <= rear; j++)
      printf("%d ", items[j]);
	
	return 0;
}
