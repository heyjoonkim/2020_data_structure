#ifndef SPARSE
#define SPARSE

typedef struct _e{ 
	int row;
	int col;
	int val;
} Element;

typedef struct _s{
	int rowCount;
	int colCount;
	int valCount;
	Element* data;
} Sparse;

Sparse* create(int row, int col, int* data);
void print(const Sparse*);
void printOriginal(const Sparse*);
void set(Sparse*, int, int, int);

#endif
