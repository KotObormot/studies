// https://drive.google.com/drive/folders/1wLFlvgpcwOeGn1_Si2HutHUp7PUVRo8b
// https://www.youtube.com/watch?v=YUle4PBVS4c&t=890s

#include <iostream>

// длина лестницы
#define L 3

// зайчик может прыгнуть
#define R 4

// 1 1 1 1
// 1 1 2
// 1 2 1
// 2 1 1
// 2 2

//void put_rabbit( int new_place, int &n)
//{
//	// проверка параметров
//	if ((new_place < 0)|| (new_place > L))
//		return;
//
//	// стоп игра!!!
//	if (new_place == L)
//		n++;
//
//	// собственно рекурсия
//	for (int i = 1; i <= R; i++)
//		put_rabbit( new_place + i, n);
//
//}

// j - количество уже сделанных в этой попытке прыжков
// n - количество правильных решений
void put_rabbit(int new_place, int& n, int j, int ajump[])
{
	// проверка параметров
	if ((new_place < 0) || (new_place > L))
		return;

	// стоп игра!!!
	if (new_place == L)
	{
		n++;
		printf(" n=%2d; ", n);
		for ( int i = 0; i<j; i++)
			printf(" %d ", ajump[i]);
		printf("\n");
	}

	// собственно рекурсия
	for (int i = 1; i <= R; i++)
	{
		ajump[j] = i;
		put_rabbit(new_place + i, n, j+1, ajump);
	}

}

int main()
{
	int n = 0;	// количество решений

	// количество вариантов
	//put_rabbit( 0, n);
	//printf("%d %d %d", R, L, n);

	// напечатать все решения
	int jumps[L+1];
	put_rabbit( 0, n, 0, jumps);
}

