#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int ret;

	printf("call main\n");
	ret = system("./a.out");
	printf("main ret:%d\n", ret);
	return 0;
}
