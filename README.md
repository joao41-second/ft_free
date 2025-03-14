# Ft_free
This project was created for my laziness the protect the free in complex prograns in c.

The objectiv this project is create the Garbage collector in c this form my prograns not generate leeak or crash due a error the memory alocated.

### To use this tool you must know the basic concepts of :

The language [c](https://www.learn-c.org/) and [Makefile](https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/) use.



# Use basic the tool

The basic use this tool is very simple: 

```
#include "free."

int main()
{
    char *str;
    ft_start_alloc();
    ft_malloc(100,NULL); 
    str = ft_malloc(100,NULL); 
    ft_free_all();
}

```
### But as this working:

The logic is simple if create the linked list where save the pointer for the memory alodted and return this pointer the memory for user.

Is exactly that's what we do and at the end the program we give free the linked list.

##img

## More the use basic not good in long program.
If I don't free something that is in a loop I will stay with that memory until the end of the program,it is not usable.
He was thought in this what create the pockets in linked list.
