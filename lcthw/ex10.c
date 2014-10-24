# include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;

	// go through each string in argv
	// why am I skipping argv[0]?
	// The programs name (./ex10) is at 0, with the rest coming after it
	for(i = 1; i < argc; i++) {
		printf("arg %d: %s\n", i, argv[i]);
	}
	// let's make our own array of strings
	char *avengers[] = {
		"Ironman", "The Hulk",
		"Captain America", "Thor"
	};
	int num_avengers = 4;

	for(i = 0; i < num_avengers; i++) {
		printf("Avenger %d: %s\n", i, avengers[i]);
	}
	return 0;
}
