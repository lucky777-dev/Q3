#include <lucky.h>
#include <stdio.h>

void status () {
	printf("<lucky.h loaded!>\n");
}

int askInt(const char* msg) {
	printf("%s", msg);
	int result;
	scanf("%d", &result);
	return result;
}

int askIntRange(const char* msg, int min, int max) {
	printf("%s", msg);
	int result;
	scanf("%d", &result);
	while(result < min || result > max) {
		printf("Please enter a valid integer between '%d' and '%d': ", min, max);
		scanf("%d", &result);
	}
	return result;
}

int askIntGreater(const char* msg, int limit) {
	printf("%s", msg);
	int result;
	scanf("%d", &result);
	while(result <= limit) {
		printf("Please enter a number greater than '%d': ", limit);
		scanf("%d", &result);
	}
	return result;
}

int askIntSmaller(const char* msg, int limit) {
	printf("%s", msg);
	int result;
	scanf("%d", &result);
	while(result >= limit) {
		printf("Please enter a number smaller than '%d': ", limit);
		scanf("%d", &result);
	}
	return result;
}

bool askYN(const char* msg) {
	printf("%s (y/n): ", msg);
	char result;
	scanf("%c", &result);
	while(result != 'y' && result != 'Y' && result != 'n' && result != 'N') {
		printf("Please enter 'y' or 'n': ");
		scanf("%c", &result);
	}
	return (result == 'y' || result == 'Y');
}
