#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char * makePassphrase(int count, char * separator, bool lastNumber) {
	for (int i = 0; i < count; i++) {
		int roll = getDiceRolls();
	}
}

int main (int argc, char* argv[]) {
	// args: length, -s separator, -n last number
	int count = 0;
	char* separator = "";
	bool lastNumber = false;

	if (argc < 2 || argc > 6) {
		printf("ERROR: Malformed command.\n");
		printf("USAGE: ./diceware.exe [-i _] [-s _] [-n]\n");
		printf("-i  : OPTIONAL follow with how many words you want in the passphrase. Default is 5.\n-s  : OPTIONAL follow with the separator you want between each word. Default is '.'\n-n  : OPTIONAL include if you want the last word to instead be numbers.\n");
		return -1;
	}

	for (int i = 1; i < argc; i++) {
		if (strcmp("-i", argv[i]) == 0) {
			printf("found -i flag!\n");
			count = atoi(argv[++i]);
			printf("Value is %d\n", count);
			continue;
		}

		if (strcmp("-s", argv[i]) == 0) {
			printf("found -s flag!\n");
			separator = argv[++i];
			printf("Value is %s\n", separator);
			continue;
		}

		if (strcmp("-n", argv[i]) == 0) {
			printf("found -n flag!\n");
			lastNumber = true;
			continue;
		}
	}

	char * passphrase = makePassphrase(count, separator, lastNumber);
	return 0;
}
