03_Queue_Lab
============

Implement an array-based queue in C++

Note: When you create your project, do NOT add ArrayQueue.ipp to the list of source files, add it to the list of include files. You will see that ArrayQueue.ipp is #included at the bottom of ArrayQueue.h. See ArrayQueue.h for more explanation.

Requirements
------------

1. remove takes O(1) time
2. add takes O(1) time, unless it calls grow (in that case O(n) is okay)
3. grow is only called if the number of items == backingArraySize, and the size of the array is doubled during grow
4. grow takes O(n) time
5. Do not leak memory (make sure grow and the destructor do the right thing)
6. getNumItems is O(1) time
7. add and remove throw excpetions as appropriate
8. You must use the array in a circular fashion. If you don't do this you probably won't be able to get #1, #2 and #3 to all be true.

Reading
=======
"Open Data Structures," Chapter 2, up through section 2.4 (ArrayDequeue). http://opendatastructures.org/ods-cpp/2_Array_Based_Lists.html

Information about the Von Neumann computing model may be helpful. This optional reading is section 2.2 of "Algorithms and Data Structures: A Basic Toolbox" by Melhorn and Sanders. A free copy may be found here: http://www.mpi-inf.mpg.de/~mehlhorn/ftp/Toolbox/Introduction.pdf

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. Remove is implemented in a circular fashion, so Remove should take O(1) time.
2. Add is implemented in a circular fashion, so Add should take O(1) time.
3. The grow function is only called within the add function if the queue is full and it doubles the size.
4. I am not sure how to calculate the runtime, but it is modeled after the example from openDataStructures.
5. Both grow and the destructor do not leave either dangling pointers or memory leaks.  
6. Simply returns the value, no calculations involved.
7. I could not think of an illegal way to use the add function, but the remove function throws and exception if the queue is already empty.  
8. The queue is implemented in a circular fashion.

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.

Using a Stack would require the same private methods and variables implemented in a queue, but the actual implementation would be slightly different.

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?

I still an unsure about how to calculate the runtime of my functions, could you clarify in class on Tuesday?

#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?

First make sure to #include "Queue.h", then to extend it use class ArrayQueue: public Queue.

#### 5. What is the purpose of "templates" in C++?

To provide a data structure that can be compatable with numerous different data types or objects.  

#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?

int* myInts = new Int[10];

#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?

The destructor deletes refrences to memory that do not contain an object or objects that do not contain a pointer in order to conserve memory.  This is not necessary in java because java does not allow access to memory outside of what is allocated in the constructor.
