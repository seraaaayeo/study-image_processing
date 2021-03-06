#include "dct.h"

void QDCT(double * input, double * output)
{
	double arrQ35[8][8] = {
			{16, 11, 10, 16, 24, 40, 51, 61},
		{12, 12, 14, 19, 26, 58, 60, 55},
		{14, 13, 16, 24, 40, 57, 69, 56},
		{18, 22, 37, 56, 68, 109, 103, 77},
		{24, 35, 55, 64, 81, 104, 113, 92},
		{49, 64, 78, 87, 103, 121, 120, 101},
		{49, 64, 78, 87, 103, 121, 120, 101},
		{72, 92, 95, 98, 112, 100, 130, 99}
	};
	double arrQ58[8][8] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1 },
	};
	double arrQ28[8][8] = {
			{ 100, 100, 100, 100, 100, 100, 100, 100 },
		{ 100, 100, 100, 100, 100, 100, 100, 100 },
		{ 100, 100, 100, 100, 100, 100, 100, 100 },
		{ 100, 100, 100, 100, 100, 100, 100, 100 },
		{ 100, 100, 100, 100, 100, 100, 100, 100 },
		{ 100, 100, 100, 100, 100, 100, 100, 100 },
		{ 100, 100, 100, 100, 100, 100, 100, 100 },
		{ 100, 100, 100, 100, 100, 100, 100, 100 },
	};
	double arrQ30[8][8] = {
			{72, 92, 95, 98, 112, 100, 130, 99},
		{49, 64, 78, 87, 103, 121, 120, 101},
		{49, 64, 78, 87, 103, 121, 120, 101},
		{24, 35, 55, 64, 81, 104, 113, 92},
		{18, 22, 37, 56, 68, 109, 103, 77},
		{14, 13, 16, 24, 40, 57, 69, 56},
		{12, 12, 14, 19, 26, 58, 60, 55},
		{16, 11, 10, 16, 24, 40, 51, 61} 
	};

	int i, j, Bx, By;
	
	for (By = 0; By < HEIGHT / N; By++)
		for (Bx = 0; Bx < WIDTH / N; Bx++) {
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {
					*(output + (Bx * N) + (By * N * WIDTH) + i * WIDTH + j) =
						(round((*(input + (Bx * N) + (By * N * WIDTH) + i * WIDTH + j)) / arrQ35[i][j])) * arrQ35[i][j];
				}
			}
		}
}
