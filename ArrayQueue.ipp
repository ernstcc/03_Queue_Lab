//You will need this so you can make a string to throw in
// remove
#include <string>

//Syntax note: This uses the pre-processor to create a constant
// You could also use "const static" to make a constant, as in Java.
// Notice, however, that START_SIZE is NOT a variable! Instead, any
// place that the pre-processor sees "START_SIZE" it will replace it with
// 10 ... so this is like a global "find and replace".
#define START_SIZE 10

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this ArrayQueue() method belongs to the
// ArrayQueue<T> class.
	
template <class T>
ArrayQueue<T>::ArrayQueue(){
	//T* backingArray = new T[START_SIZE];
	backingArray = new T[START_SIZE];
	backingArraySize = START_SIZE;
	numItems = 0;
	front = 0; 
}

template <class T>
ArrayQueue<T>::~ArrayQueue() {
	delete[] backingArray;
}

template <class T>
void ArrayQueue<T>::add(T toAdd){
// ACTUALLY ADD TO ARRAY!
	if (numItems == backingArraySize) {
		grow();
	//	int end = (front+numItems) % backingArraySize;
//		backingArray[end] = toAdd;
//		numItems++;
		}
//	else {
		int end = (front+numItems) % backingArraySize;
		backingArray[end] = toAdd;
		numItems++;
		//front++;
//	}
}

template <class T>
T ArrayQueue<T>::remove(){
// REMOVE FROM ARRAY!
//	if (numItems == 0) {
//		throw (std::string) "Improper!";
		//throw (std::string) "Improper!";
//	}
//	else {
		T x = backingArray[front];
		front = (front + 1) % backingArraySize;
		numItems--;
		if (backingArraySize >= 3*numItems) grow();
		return x;
//	}
}

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){
	return numItems;
}

template <class T>
void ArrayQueue<T>::grow(){
	//T* b(std::max(1, 2*numItems));
	int size = 0;
	
	if (1 > 2*numItems){
		size = 1;
		}
	else if (2*numItems > 1) {
		size = 2*START_SIZE;
		}
	T* b = new T[size];
	//backingArraySize = size;
	for (int k = 0; (k < numItems); k++){
		b[k] = backingArray[(front+k) % backingArraySize];
		}
	//backingArray = b;

// not constant time
// old array too small,  make new array(twice as big) copy old data into array
// running time n
}


