#ifndef DICTIONARY_H
#define DICTIONARY_H

#define WORD_COUNT 1296

typedef struct {
	char word[5];
	int number;
} WordEntry;

// Declare dictionary array
extern WordEntry dictionary[WORD_COUNT];

void populateDictionary(const char *filename);

char * getWord(int number);

#endif // DICTIONARY_H
