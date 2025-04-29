#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

static int NUM_DICE = 4;

char * getWord(int key) {
	// TODO Add parameter with word-number datastructure (2D-array?)
	// search the array for the given key and return the corresponding word.
	return "test";
}

int rollDice(int count) {
	// Get random number 1-6 <count> times. add up to make a <count>-digit number.
	return 4321;
}

/*
  Calls several functions to get the components of, and assemble the passphrase
*/
char * makePassphrase(int count, char * separator, bool lastNumber) {
	char * words[count];
	
	for (int i = 0; i < count; i++) {
		// instead of finding the matching word, add the number as the word.
		int roll = rollDice(NUM_DICE);
		if (lastNumber && (i == count-1)){
			char numStr[NUM_DICE];
			sprintf(numStr, "%d", roll); 
			words[i] = numStr;
		} else {
			words[i] = getWord(roll);
		}
	}

	char * passphrase;
	for (int i = 0; i < count; i++) {
		strcat(passphrase, words[i]);
		strcat(passphrase, separator);
	}

	return passphrase;
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
	printf("%s\n", passphrase);
	return 0;
}
