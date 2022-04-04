// Vector3_int.h

struct Vector3;

// 1. Создание
struct Vector3* Zero();
struct Vector3* E_1(); // (1,0,0)
struct Vector3* E_2(); // (0,1,0)
struct Vector3* E_3(); // (0,0,1)
struct Vector3* From(int* values); // мемоизация НЕ НУЖНА !!!

// 2. Декомпозиция
int GetX(struct Vector3* vect);
int GetY(struct Vector3* vect);
int GetZ(struct Vector3* vect);
// int Get(struct Vector3* vect, int i); 
int GetNorm(); // (????)

// 3. Операции
struct Vector3* Sum(struct Vector3* v1, struct Vector3* v2);
int Mult(struct Vector3* v1, struct Vector3* v2);
struct Vector3* MultSc(int scalar, struct Vector3* v2);

// Vector3_int.c

struct Vector3
{
	int x;
	int y;
	int z;
};

struct Vector3* the_zero;

struct Vector3* Zero()
{
	//struct Vector3* zero = malloc(sizeof(struct Vector3));
	if (!the_zero) // мемоизация
	{
		the_zero =  = malloc(sizeof(struct Vector3));
		the_zero->x = 0;
		the_zero->y = 0;
		the_zero->z = 0;
	}
	return the_zero;
}



int GetX(struct Vector3* vect)
{
	if (vect)
		return vect->x;
	raise(...);
}