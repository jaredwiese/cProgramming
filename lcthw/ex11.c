#include <stdio.h>

int main(int argc, char *argv[])
	{
		// go through each string in argv

		int i = 0;
		while(i < argc) {
			printf("arg %d: %s\n", i, argv[i]);
			i++;
		}

		// let's make our own array of strings
		char *avengers[] = {
			"Ironman", "The Hulk",
			"Captain America", "Thor",
		};

		int num_avengers = 4;
		i = 0; // watch for this, DON'T FORGET TO INITIALIZE, or you will meet Loki
		while(i < num_avengers) {
			printf("Avenger %d: %s\n", i, avengers[i]);
			i++;
		}
		return 0;
}
