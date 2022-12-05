int* ptr = (int*) malloc (10 * sizeof(int));
free(ptr)
  
  
int* ptr = (int*) malloc (10 * sizeof(int));

// NOTES
- SIDE NOTES: Compile time is the period when the programming code (such as C#, Java, C, Python) is converted to the machine code (i.e. binary code). Runtime is the period of time when a program is running and generally occurs after compile time. The concept of dynamic memory allocation in c language **enables the C programmer to allocate memory at runtime.** The Garbage value is **a random value at an address in the memory of a computer.** Whenever a variable is defined without giving any value to it, it contains the leftover values from the previous program.
- The “malloc” or “memory allocation” method in C is used to dynamically allocate a single
large block of memory with the specified size. It returns a pointer of type void which can be typecast into a pointer of any form.
- int arr[30];
int * ptr = (int *) malloc
- calloc: The calloc() function in C is **used to allocate a specified amount of memory and then initialize it to zero**
- “free” method in C is used to dynamically de-allocate the memory. The memory allocated
using functions malloc() and calloc() is not de-allocated on their own. Hence the free()
method is used, whenever the dynamic memory allocation takes place. It helps to reduce
wastage of memory by freeing it.
- example:  int* ptr = (int*) malloc (10 * sizeof(int));
free(ptr)
- “realloc” or “re-allocation” method in C is used to dynamically change the memory
allocation of a previously allocated memory. Re-allocation of memory maintains the already present value and new blocks will be initialized with the default garbage value.
- every malloc should have a free statement to free the space and top the computer from getting slow
- example: int* ptr = (int*) malloc (10 * sizeof(int));

free(ptr);

- This above piece of code would allocate a contiguous block of memory the size of 10 integers such that ptr would point to the start of this block. Note that (int*) before malloc typecasts the pointer but this would work without it as well. It’s just good practice to typecast.
  
  //notes for the rest of the topics are in the notion link for which link has been put on a txt file
