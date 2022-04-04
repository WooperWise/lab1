const int MAX_INT_VALUE = ...;

void sumInt(void* a1, void* a2, void* res)
{
	int* ia1 = (int*)a1;
	int* ia2 = (int*)a2;
	int* resi = (int*)res;
	*resi = *ia1 + *ia2;
}


f -> g -> h -> ... -> ...

void* sumInt(void* a1, void* a2)
{
	int* ia1 = (int*)a1;
	int* ia2 = (int*)a2;
	int* res = malloc(sizeof(int));
	*res = *ia1 + *ia2;
	return (void*)res;
}

// RingInfo.h

struct RingInfo
{
	size_t size;
	void* (*sum)(void*, void*);
	void* zero;
	void* (*minus)(void*);
	void* (*mult)(void*, void*);
	void* one;
};

struct RingInfo* intRing = ....; // intRing->sum = &sumInt;
void* c = intRing->sum(a,b);

// 1. Создание
struct RingInfo* Create(	
	size_t size,
	void* (*sum)(void*, void*),
	void* zero,
	void* (*minus)(void*),
	void* (*mult)(void*, void*),
	void* one)
{
	struct RingInfo* ringInfo = malloc(sizeof(struct RingInfo));
	ringInfo->size = size;
	ringInfo->sum = sum;
	ringInfo->zero = zero;
	ringInfo->minus = minus;
	ringInfo->mult = mult;
	ringInfo->one = one;
}

struct RingInfo* ringInfo = Create(&sumInt, &minusInt, the_zero, &multInt, the_one);
bool RingInfoEquals(struct RingInfo* r1, struct RingInfo* r2)
{
	return r1->sum = r2->sum;
}

// Vector3.h

struct Vector3;

// 1. Создание
struct Vector3* Zero(struct RingInfo* ringInfo);
struct Vector3* E_1(struct RingInfo* ringInfo); // (1,0,0)
struct Vector3* E_2(struct RingInfo* ringInfo); // (0,1,0)
struct Vector3* E_3(struct RingInfo* ringInfo); // (0,0,1)
struct Vector3* From(struct RingInfo* ringInfo, int* values); // мемоизация НЕ НУЖНА !!!

// 2. Декомпозиция
void* GetX(struct Vector3* vect);
void* GetY(struct Vector3* vect);
void* GetZ(struct Vector3* vect);
// int Get(struct Vector3* vect, int i); 
int GetNorm(); // (????)

// 3. Операции
struct Vector3* Sum(struct Vector3* v1, struct Vector3* v2);
void* Mult(struct Vector3* v1, struct Vector3* v2);
struct Vector3* MultSc(void* scalar, struct Vector3* v);

// Vector3.c

struct Vector3
{
	struct RingInfo* ringInfo;
	void* x;
	void* y;
	void* z;
};

struct Vector3* the_zero;

struct Vector3* Zero(struct RingInfo* ringInfo)
{
	//struct Vector3* zero = malloc(sizeof(struct Vector3));
	if (!the_zero) // мемоизация
	{
		the_zero =  = malloc(sizeof(struct Vector3));
		the_zero->ringInfo = ringInfo;
		the_zero->x = ringInfo->zero;
		the_zero->y = ringInfo->zero;
		the_zero->z = ringInfo->zero;
	}
	return the_zero;
}



void* GetX(struct Vector3* vect)
{
	if (vect)
		return vect->x;
	raise(...);
}

/// <doc Description="ТУТ ИСПОЛЬЗУЕТСЯ АЛГОРИТМ ..."/>
/// <arg1 Description=""/>
///
/// 
struct Vector3* Sum(struct Vector3* vector1, struct Vector3* vector2) // более "семантично"
{
	if (v1->ringInfo != v2->ringInfo) // надежнее через RingInfoEquals(v1->ringInfo,v2->ringInfo)
		/////
	struct Vector3* result = malloc(sizeof(struct Vector3));
	result->ringInfo = v1->ringInfo;
	//result->x = v1->x + v2->x; // НЕ РАБОТАЕТ!!! :'-(
	result->x = result->ringInfo->sum(v1->x,v2->x); // так -- НАМАНА
	result->y = result->ringInfo->sum(v1->y,v2->y); // так -- НАМАНА
	result->z = result->ringInfo->sum(v1->z,v2->z); // так -- НАМАНА
}



// 40 лет назад...
struct Vector3* Sum(struct Vector3* v1, struct Vector3* v2, struct RingInfo* ringInfo);
void Sum(struct Vector3* result, struct Vector3* v1, struct Vector3* v2, struct RingInfo* ringInfo);


//////////////////////////////////////


struct VectorN
{
	struct RingInfo* ringInfo;
	int N;
	void* elements;
};

.... f(Matrix* rowVector1, Matrix* rowVector2)