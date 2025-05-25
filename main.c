#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "dictionary.h"

static int NUM_DICE = 4;

/*
	Generates a random number 1-6 <count> times. Concatenates them to make a <count> digit number.
*/
int rollDice(int count) {
	int composite = 0;
	srand(time(NULL) * clock());
	
	for (int i = 0; i < count; i++) {
		int roll = rand() % (6 - 1 + 1) + 1;
		// handle place values for concatenation
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
		if (lastNumber && (i == count-1)) {
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
		if (i != count-1) {
			strcat(passphrase, separator);
		}
	}
	
	free(words);
	return passphrase;
}

/*
	Prints the proper usage of the program
*/
void printUsage() {
	printf("USAGE: program [-i length] [-s separator] [-n]\n");
	    printf("  -i length     Number of words in passphrase (default 5)\n");
	    printf("  -s separator  Separator string (default \".\")\n");
	    printf("  -n            Replace the last word with a number\n");
	return;
}

/*
	Helper function. Checks if as string contains a number or not
*/
bool isNumber(const char *str) {
    if (!str || !*str) return false;
    while (*str) {
        if (!isdigit(*str)) return false;
        str++;
    }
    return true;
}

int main (int argc, char* argv[]) {
	// args: -i length, -s separator, -n last number
	int count = 5;
	char* separator = ".";
	bool lastNumber = false;

	if (argc > 6) {
		printf("ERROR: Malformed command.\n");
		printUsage();
		return -1;
	}
	// Parse flags and check for proper values
	for (int i = 1; i < argc; i++) {
		// Handles -i flag and value
		if (strcmp("-i", argv[i]) == 0) {
			if (i + 1 >= argc || argv[i + 1][0] == '-') {
				printf("ERROR: Missing value after -i\n");
				printUsage();
				return -1;
			}
			if (!isNumber(argv[i + 1])) {
				printf("ERROR: Invalid value for -i (must be a number)\n");
				printUsage();
				return -1;
			}
			count = atoi(argv[++i]);
		// Handles -s flag and value
		} else if (strcmp("-s", argv[i]) == 0) {
			if (i + 1 >= argc || argv[i + 1][0] == '-') {
				printf("ERROR: Missing value after -s\n");
				printUsage();
				return -1;
			}
			separator = argv[++i];
		// Handles -n flag	
		} else if (strcmp("-n", argv[i]) == 0) {
			lastNumber = true;
		} else {
			printf("ERROR: Unrecognized argument: %s\n", argv[i]);
			printUsage();
			return -1;
		}
	}

	populateDictionary("words.txt");

	char *passphrase = makePassphrase(count, separator, lastNumber);
	printf("%s\n", passphrase);
	free(passphrase);
	return 0;
}
