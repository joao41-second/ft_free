# Ft_free
This project was created for my laziness the protect the free in complex prograns in c.

The objectiv this project is create the Garbage collector in c this form my prograns not generate leeak or crash due a error the memory alocated.

#### To use this tool you must know the basic concepts of :

The language [c](https://www.learn-c.org/) and [Makefile](https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/) use.



# Use basic the tool

The basic use this tool is very simple: 


    #include "free.h"

    int main()
    {
        char *str;
        ft_start_alloc();
        ft_malloc(100,NULL); 
        str = ft_malloc(100,NULL); 
        ft_add_memory(malloc(10*10), "main");
        ft_free(str); // It not necessary in example,but it can be useful
        ft_free_all();
    }

### But as this working:

The logic is simple if create the linked list where save the pointer for the memory alodted and return this pointer the memory for user.

Is exactly that's what we do and at the end the program we give free the linked list.

##img

## More the use basic not good in long program.
>If I don't free something that is in a loop I will stay with that memory until the end of the program,it is not usable.
He was thought in this what create the `pockets` in linked list.<

The pocket is the concepts what create to give the free in bloks specific the code for example: 


    #include "free.h"

    char* example_all()
    {
        char *str;
        char *str2:
        str2 = ft_malloc(10,NULL); // alocad in pocket example
        str = ft_malloc(5,"main"); // alocad in pocket main the pocket main is standard pocket 
        str[0] = '1';
        str[1] = '2';
        str[2] = '\0';
        return(str);

    }
    int main()
    {
        char *str;
        ft_start_alloc();

        ft_pocket_new("example");  //create a new pocket the new alocations is alocad in pocket "example"
        prinf(example_all()); 
        ft_free_all_pocket("example"); // free the all memory alocad in pocket "example"
        ft_pocket_set("main");
        ft_free_all();
    }
> As seen in the example above we can create pockets with `ft_pocket_new()` as well finalize a pocket used `ft_free_all_pocket`.
> when create a new pocket, this pocket is automatclly selected,soon everything allocated with `ft_malloc(int,NULL)` is alocad in
new_pocket.<p>
> Is posible set the different pocket without finishing the last pocket:
>
> `ft_pocket_set("name_poket");` or `ft_malloc(11,"name_poket")`

