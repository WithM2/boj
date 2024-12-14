#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1

int main() {
	char sent[1000001] = { 0 };
	int len = 0;
	int cnt = 1;
	while (TRUE) {
		scanf("%c", &sent[len]);
		if (sent[len] == '\n') break;
		len++;
	}
	if (len == 1) {
		if (sent[0] == ' ') cnt--;
		printf("%d", cnt);
		return 0;
	}
	for (int i = 1; i < len - 1; i++) {
		if (sent[i] == ' ') {
			while (TRUE) {
				i++;
				if (i == len) {
					cnt--;
					break;
				}
				else if (sent[i] != ' ') break;
			}
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}