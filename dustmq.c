#include <stdio.h>
#include <math.h>

int main() {
	typedef struct {
		int x1, y1;
		int x2, y2;
		int x3, y3;
	} Point;
	
	Point point;
	
	scanf("%d", &point.x1);
	scanf("%d", &point.y1);
	scanf("%d", &point.x2);
	scanf("%d", &point.y2);
	scanf("%d", &point.x3);
	scanf("%d", &point.y3);
	
	if ((point.x1 < -10000 || point.x1 > 10000) ||
    	(point.x2 < -10000 || point.x2 > 10000) ||
    	(point.x3 < -10000 || point.x3 > 10000) ||
    	(point.y1 < -10000 || point.y1 > 10000) ||
    	(point.y2 < -10000 || point.y2 > 10000) ||
    	(point.y3 < -10000 || point.y3 > 10000)) {
    		
		return 0;
	}
	
	int side[3];
	
	side[0] = sqrt(pow(point.x2 - point.x1, 2) + pow(point.y2 - point.y1, 2));
	side[1] = sqrt(pow(point.x3 - point.x2, 2) + pow(point.y3 - point.y2, 2));
	side[2] = sqrt(pow(point.x1 - point.x3, 2) + pow(point.y1 - point.y3, 2));
	
	int i, j;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2 - i; j++) {
			if (side[j] > side[j + 1]) {
				int temp = side[j];
				side[j] = side[j + 1];
				side[j + 1] = temp;
			}
		}
	}
	
	if (side[0] + side[1] > side[2]) {
		printf("true");
	} else {
		printf("false");
	}

	return 0;
}
