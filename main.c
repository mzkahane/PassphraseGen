#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

static int NUM_DICE = 4;

char * getWord(int key) {
	// TODO Add parameter with word-number datastructure (2D-array?)
	// search the array for the given key and return the corresponding word.
	return "test";
}


/*
	Generates a random number 1-6 <count> times. Concatenates them to make a <count> digit number.
*/
int rollDice(int count) {
	int composite = 0;
	srand(time(NULL) * clock());
	
	for (int i = 0; i < count; i++) {
		int roll = rand() % (6 - 1 + 1) + 1;
		// handle placee values for concatenation
		int place = 10;
		while (roll >= place) {
			place *= 10;
		}
		composite = composite * place + roll;
	}
	return composite;
}

/*
	Calls several functions to get the components of, and assemble the passphrase
*/
char * makePassphrase(int count, char * separator, bool lastNumber) {
	char **words = malloc(count * sizeof(char *));
	char numStr[NUM_DICE];
	
	for (int i = 0; i < count; i++) {
		int roll = rollDice(NUM_DICE);
		// instead of finding the matching word, add the number as the word.
		if (lastNumber && (i == count-1)){
			sprintf(numStr, "%d", roll); 
			words[i] = numStr;
		} else {
			words[i] = getWord(roll);
		}
	}
	// find the total length of the password for malloc
	size_t totalLength = 1;
	for (int i = 0; i < count; i++) {
		totalLength += strlen(words[i]) + strlen(separator);
	}

	char * passphrase = (char *)malloc(totalLength * sizeof(char));
	passphrase[0] = '\0';
	for (int i = 0; i < count; i++) {
		strcat(passphrase, words[i]);
		strcat(passphrase, separator);
	}
	
	free(words);
	return passphrase;
}

int main (int argc, char* argv[]) {
	// args: length, -s separator, -n last number
	int count = 5;
	char* separator = ".";
	bool lastNumber = false;

	// TODO turn this into a function
	if (argc > 6) {
		printf("ERROR: Malformed command.\n");
		printf("USAGE: ./diceware.exe [-i _] [-s _] [-n]\n");
		printf("-i  : OPTIONAL follow with how many words you want in the passphrase. Default is 5.\n-s  : OPTIONAL follow with the separator you want between each word. Default is '.'\n-n  : OPTIONAL include if you want the last word to instead be numbers.\n");
		return -1;
	}
	// TODO handle missing/invalid values after flags
	for (int i = 1; i < argc; i++) {
		if (strcmp("-i", argv[i]) == 0) {
			count = atoi(argv[++i]);
			continue;
		} else if (strcmp("-s", argv[i]) == 0) {
			separator = argv[++i];
			continue;
		} else if (strcmp("-n", argv[i]) == 0) {
			lastNumber = true;
			continue;
		} else {
			// TODO print usage
			continue;
		}
	}

	char * passphrase = makePassphrase(count, separator, lastNumber);
	printf("%s\n", passphrase);
	free(passphrase);
	return 0;
}
