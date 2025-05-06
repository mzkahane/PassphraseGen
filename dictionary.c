#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

#define MAX_WORD_LENGTH 6

WordEntry dictionary[WORD_COUNT];
int wordCount = 0; // Track actual number of words

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
