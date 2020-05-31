#include "queue.h"
#include "stack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void evaluatePostfix();
void infixToPostfix();

queue_type *queue; 
stack_type *stack;
int main()
{	
	queue = queue_new();
	stack = stack_new();

	printf("This program does the following three things:\n");
	printf("1) Converts an infix expression to a postfix expression\n"
			"2) Evaluates a postfix expression\n\n");
	int answer;
	do {
		printf("Which one do you want to perform?\n");
		scanf("%d", &answer); 
	} while (answer > 4 || answer < 0);

	
	if (answer == 1)
	{
		infixToPostfix();
	}
	else if (answer == 2)
	{
		evaluatePostfix();
	}
	
		
	
	return 0;
}

void infixToPostfix()
{
	char express[100];

	printf("\nPlease type in an infix expression.\n");
        scanf("%*c");
	scanf("%[^\n]", express);


	int y = strlen(express);

	int x;

	for (x = 0; x < y; x++)
	{
		char cc = express[x];
		if(cc == ' ')
		{
			continue;
		}
		else if(cc >= '0' && cc <= '9')
		{
			queue_enqueue(queue, cc);
		
		}
		else if(cc == '(')
		{
			stack_push(stack, cc);
		}
		else if(cc >= '*' && cc <= '/')
		{
			if(cc == '*' || cc == '/')
			{
				char flag = 'Y';
				while(flag == 'Y' && stack_height(stack) != 0)
				{
					if(stack_top(stack) == '*' || stack_top(stack) == '/')
					{
						queue_enqueue(queue, stack_pop(stack));
						continue;
					}
					
					stack_push(stack, cc);
					flag = 'N';
				}

				 if(flag == 'Y')
                                {
                                        stack_push(stack, cc);

                                }

			}
			else if(cc == '+' || cc == '-')
			{
				
				char flag = 'Y';
				while(flag == 'Y' && stack_height(stack) != 0){
					
                                        if(stack_top(stack) == '*' || stack_top(stack) == '/' || stack_top(stack) == '-' || stack_top(stack) == '+')
                                        {
                                                queue_enqueue(queue, stack_pop(stack));
                                                continue;
                                        }

                                        stack_push(stack, cc);
                                        flag = 'N';
                                }
				
	
				if(flag == 'Y')
				{
					stack_push(stack, cc);

				}
			
			}
			else{
				printf("\nInvalidNotationFormat - Not the correct character");
				exit(0);
			}
		}
		else if(cc == ')')
		{
			char flag = 'Y';
			do{
				if(stack_top(stack) == '(')
				{
					stack_pop(stack);
					flag = 'N';		
				}
				else
				{
					queue_enqueue(queue, stack_pop(stack));
				}
				
		 	
			}while(flag == 'Y' && stack_height(stack) != 0);
			
			if(flag != 'N')
			{
				printf("\nInvalidNotationFormat - There is no left Pararenthesis");
				exit(0);
			}
			
			while( stack_height(stack) != 0)
			{
				queue_enqueue(queue, stack_pop(stack));
			}	
				
		}
		else
		{
			printf("\nInvalidNotationFormat - Not the correct character");
                        exit(0);		

		}

	}

	              
         
        

	while( stack_height(stack) != 0)
        {
		queue_enqueue(queue, stack_pop(stack));     
        }
	printf("\n%s\n", queue->array);

	stack_delete(stack);
	queue_delete(queue);
}

void evaluatePostfix()
{
	char express[100];

        printf("\nPlease type in a postfix expression.\n");
        scanf("%*c");
        scanf("%[^\n]", express);
 
	
	int y = strlen(express);

        int x;

        for (x = 0; x < y; x++)
        {
                char cc = express[x];
		
		 if(cc == ' ')
                {
                        continue;
                }
		else if((cc >= '0' && cc <= '9') || cc == '(')
                {
         
                        stack_push(stack, cc - '0');
                }
		else if(cc >= '*' && cc <= '/')
                {
			
		
			char f1;
			char f2;
			int answer;
			
			if(stack->size < 2)
			{
				printf("InvalidNotationFormat! Not enough values on the stack");
				exit(0);
			}
			f1 = stack_pop(stack);
			f2 = stack_pop(stack);

			if(cc == '+')
			{
						
				answer = (int)f2 + (int)f1;
					
				stack_push(stack, answer);		
			}
			else if(cc == '-')
			{
				answer = (int)f2 - (int)f1;

                                
			
				stack_push(stack, answer);
		
			}
			else if(cc == '*')
			{
				answer = (int)f2 * (int)f1;

					
                               
			
				stack_push(stack,answer);
			}
			else if(cc == '/')
			{
				answer = (int)f2 / (int)f1;
				stack_push(stack, answer);
			}
			
			
				
		}	
	}

	if(stack->size > 1)
	{
		printf("InvalidNotationFormat! More than one value on the stack.");
		exit(0);
	}
	
	printf("\n%d", (int)stack_pop(stack));
	stack_delete(stack);
        queue_delete(queue);
}

