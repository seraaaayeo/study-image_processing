#include "Bspline.h"

void BDown(unsigned char * input, unsigned char * output)

{
	int x1, x2, x3, x4;
	int y1, y2, y3, y4;
	double tx, ty, dx, dy;
	double p1, p2, p3, p4;
	double v1, v2, v3, v4, v;

	double org_size = 512;
	double new_size = 400;
	double ratio = new_size / org_size;
	double delta = org_size / new_size;

	unsigned char * temp;
	temp = (unsigned char*)malloc(sizeof(unsigned char)*DOWNSIZE*DOWNSIZE);

	for (int i = 0; i < DOWNSIZE; i++) {
		for (int j = 0; j < DOWNSIZE; j++) {
			dy = i * delta;	//(dx, dy) = (0,0) ~ (보간할 점의 x좌표, y좌표)거리
			dx = j * delta;

			//	보간할 점에 영향을 끼치는 주변 16개의 픽셀값 설정	//
			//	x방향 4개 설정	//
			x2 = (int)(dx);		//x2를 보간된 점에 가장 가까운 왼쪽 픽셀로 잡음

			if (x2 == 0)
				x1 = 0;
			else
				x1 = x2 - 1;
			if (x2 == WIDTH - 1) {
				x3 = WIDTH - 1;
				x4 = WIDTH - 1;
			}
			else {
				x3 = x2 + 1;
				x4 = x2 + 2;
			}
			tx = dx - x2;

			//	y방향 4개 설정	//
			y2 = (int)(dy);
			if (y2 == 0)
				y1 = 0;
			else
				y1 = y2 - 1;
			if (y2 == HEIGHT - 1) {
				y3 = HEIGHT - 1;
				y4 = HEIGHT - 1;
			}
			else {
				y3 = y2 + 1;
				y4 = y2 + 2;
			}
			ty = dy - y2;

			//	x방향으로 4개의 점을 보간하여 4개의 보간점 생성	//
			p1 = *(input + y1 * WIDTH + x1);
			p2 = *(input + y1 * WIDTH + x2);
			p3 = *(input + y1 * WIDTH + x3);
			p4 = *(input + y1 * WIDTH + x4);

			v1 = findPoint(p1, p2, p3, p4, tx);
			p1, p2, p3, p4 = 0;

			p1 = *(input + y2 * WIDTH + x1);
			p2 = *(input + y2 * WIDTH + x2);
			p3 = *(input + y2 * WIDTH + x3);
			p4 = *(input + y2 * WIDTH + x4);

			v2 = findPoint(p1, p2, p3, p4, tx);
			p1, p2, p3, p4 = 0;

			p1 = *(input + y3 * WIDTH + x1);
			p2 = *(input + y3 * WIDTH + x2);
			p3 = *(input + y3 * WIDTH + x3);
			p4 = *(input + y3 * WIDTH + x4);

			v3 = findPoint(p1, p2, p3, p4, tx);
			p1, p2, p3, p4 = 0;

			p1 = *(input + y4 * WIDTH + x1);
			p2 = *(input + y4 * WIDTH + x2);
			p3 = *(input + y4 * WIDTH + x3);
			p4 = *(input + y4 * WIDTH + x4);

			v4 = findPoint(p1, p2, p3, p4, tx);

			//	생성된 4개의 보간점을 y방향으로 한 번 더 보간	//
			v = findPoint(v1, v2, v3, v4, ty);

			*(temp + i * DOWNSIZE + j) = (unsigned char)(v + 0.5);
		}
	}

	for (int i = 0; i < DOWNSIZE; i++) {
		for (int j = 0; j < DOWNSIZE; j++) {
			*(output + i * WIDTH + j) = *(temp + i * DOWNSIZE + j);
		}
	}

}