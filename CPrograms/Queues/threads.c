/*

*/
#include<stdio.h>

int main()
{
	int count, i, f, r;
	scanf("%d", &count);
	int calling[count], ideal[count], time = 0;
	for (i = 0; i < count; i++) scanf("%d", &calling[i]);
	for (i = 0; i < count; i++) scanf("%d", &ideal[i]);
	f = 0; r = count - 1;
	while (f < count) {
	    if (calling[f] == ideal[f]) {
	        time++;
	        f++;
	    }
	    else {
	        r = calling[f];
	        for (i = f + 1; i < count; i++) calling[i - 1] = calling[i];
	        calling[count - 1] = r;
	        time++;
	    }
	}
	printf("%d", time);
	return 0;
}
