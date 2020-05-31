struct stack
{
	int size;
	char* array;

};

typedef struct stack stack_type;


/* create a new empty stack of characters
 *    RETURN VALUE: a pointer to an stack upon success; NULL if failure */
stack_type* stack_new(void);


/* push a char onto an existing stack
 *    RETURN VALUE: 0 upon success and -1 upon failure */
int stack_push(stack_type*, char);


/* Query the number of elements on a given stack. */
int stack_height(stack_type*);


/* pop the topmost char from an stack; stack_pop (s) can only be called if stack_height (s) > 0 */
char stack_pop(stack_type*);


/* return the topmost char from a stack without altering the stack; stack_top (s) can only be called if stack_height (s) > 0 */
char stack_top(stack_type*);


/* Free all memory associated with this stack. */
void stack_delete(stack_type*);

