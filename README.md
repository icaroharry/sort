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
  

## Requirements

NVIDIA CUDA Toolkit 6.0
Compiled with NVCC v6.0.1, GCC and G++

Follow these instructions to set up your environment:
[prosciens’s tutorial to set up CUDA 6 compiler environment on Debian testing/sid](http://prosciens.com/prosciens/how-to-install-nvidia-cuda-6-and-compile-all-the-samples-in-debian-testing-x86_64/
 "prosciens’s instructions")

Our CUDA sorting code requires devices with CUDA compute capability 3.5 or higher, in order to use
the Dinamic Parallelism technology, read more about it here:

[NVIDIA blog describing Dinamic Parallelism in Kepler GPUs](http://blogs.nvidia.com/blog/2012/09/12/how-tesla-k20-speeds-up-quicksort-a-familiar-comp-sci-code/ "NVIDIA blog")

## Compiling

Run the MAKEFILE

## Instructions

To run the program, type:

```c
./a.out -a $algorithm -n $number_of_elements -s $state [-P]
```
###Parameters

> 1. -a sorting algorithm 
2. -n number of elements
3. -s array state
4. -P print results

| Param         | Value         | 
| ------------- |:-------------:| 
| -a            | selection     |
|               |  insertion    |
|               |   shell       | 
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

###Tested

CUDA code tested on a GeForce GT 740M

  | GeForce GT 740M                             | Features                        |
  | ------------------------------------------- |:-------------------------------:|
  | CUDA Driver Version / Runtime Version       | 6.5 / 6.0                       |
  | CUDA Capability Major/Minor version number: | 3.5                             |
  | Total amount of global memory:              | 2048 MBytes (2147352576 bytes)  |
  | ( 2) Multiprocessors, (192) CUDA Cores/MP:  | 384 CUDA Cores                  |

