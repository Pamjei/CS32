#include <stdio.h>
#include <stdlib.h>

/* dumodoble */

char stack[200];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int prio(char operation)
{
	if (operation == '^'){
		return 0;
	}
	else if (operation == '*'|| operation == '/'){
		return 1;
	}
	else if (operation == '+'|| operation == '-'){
		return 2;
	}
	else{
		return 3;
	}
}

int isnum(char c){
	if( c >= '0' && c <= '9' ){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	char in[200], post[200], item, x;
	int i=0, j=0;
	scanf("%s",in);
	push('T');
	item = in[0];
    while(item != '\0'){
    	if( item == '(') {
    		push(item);
		}
		else if(isnum(item) == 1) {
			post[j++]=item;
	 	}
		else if( item == ')'){
            while( stack[top] != '('){
            	post[j++]=pop();
			}    
            x=pop();
		}
		else{
			while( prio(stack[top]) <= prio(item) ){
                post[j++]=pop();
			}  
            push(item);
        }
		item=in[i++];
	}
	
	while( stack[top] != 'T'){     /* Pop from stack till empty */
        post[j++]=pop();}
    post[j]='\0';          /* Make postfix as valid string */
    printf("\nPostfix Expression =  %s\n",post);
	return 0;
}
