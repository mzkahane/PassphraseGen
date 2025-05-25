#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

#define MAX_WORD_LENGTH 6

int wordCount = 0;

WordEntry dictionary[WORD_COUNT];
//int wordCount = 0; // Track actual number of words

void populateDictionary(const char *filename) {
	FILE *file = fopen(filename, "r");
	if (file == NULL) {
		perror("Error opening file!");
		exit(EXIT_FAILURE);
	}

	while (fscanf(file, "%d %s", &dictionary[wordCount].number, dictionary[wordCount].word) == 2) {
		wordCount++;
		if(wordCount >= WORD_COUNT) {
			break; // Prevent overflow
		}
	}

	fclose(file);
}

char * getWord(int number) {
	int low = 0;
	int high = wordCount - 1; //(sizeof(dictionary) / sizeof(dictionary[0])) - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if(dictionary[mid].number == number) {
			return dictionary[mid].word;
		}

		if (dictionary[mid].number < number) {
			low = mid + 1;
		}

		else {
			high = mid - 1;
		}
	}

	printf("No word was found for the dice roll: %d\n", number);
	return NULL;
}
