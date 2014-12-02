sort
====

Repository of sorting algorithms in C and CUDA.

## Information
> Our program generates and fills arrays in four different ways: 
  > 
  1. arrays with totally random elements
  2. arrays already ordered 
  3. arrays ordered in descending order 
  4. arrays 90% ordered.
	
> Sorting methods implemented
  >
  1. Selection sort
  2. Insertion sort
  3. Shell sort
  4. Quick sort
  5. Heap sort
  6. Merge sort
  7. CUDA Quick sort
  8. CUDA Merge sort
  
## Compiling

``` bash
gcc -c jogador.c -o jogador.o

gcc -c pong.c

gcc pong.o -o pong $(pkg-config --libs allegro-5.0 allegro_image-5.0 allegro_font-5.0 allegro_ttf-5.0 allegro_primitives-5.0) jogador.p

./pong
```

## Instructions

To run the program, type:

```c
./a.out -a $algorithm -n $number_of_elements -s $state [-P]
```
###Parameters

| Param         | Value         | 
| ------------- |:-------------:| 
| -a            | selection     |
                 insertion      |
|                  shell         | 
|               | quick         | 
|               | heap          | 
|               | merge         | 
|               | gpuquick      | 
|               | gpumerge      |    
| -n            | int > 0       |
| -s            | random        |
|               | ascending     |
|               | descending    | 
|               | almost        | 
| -P            |
 
   

 




