#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void signal_handler(int signal)
{
	printf("exit main\n");
	exit(0);
}

int main(int argc, char *argv[])
{
	struct sigaction act;

	act.sa_handler = signal_handler;
	sigaction(SIGINT, &act, NULL);
#if 1
	while (1) {
		sleep(1);
		printf("main loop\n");
	}
#endif
	printf("main done\n");
	return 0;
}
