#include <stdio.h>
#include <stdlib.h>
typedef char byte;
void print(byte *head,int size) {
	int i, j;
	for (i = 0; i<size; i++){
		for (j = 128; j; j >>= 1)
			printf(j&head[i] ? "1 " : "0 ");
		printf("\n");
	}
}
void f1(byte **mem, int *size) {
	byte buffer[50] = { 0 };
	int count = 0, i;
	for (;; count++) {
		scanf("%d", buffer + count);
		if (buffer[count] == -1) break;
	}
	*mem = (byte*)realloc(*mem, sizeof(byte)*(*size + count));
	for (i = 0; i < count; i++)
		(*mem)[*size + i] = buffer[i];
	*size += count;
	printf("size=%dbytes\n", count);
	print(buffer, count);
}
void read(char *name, byte **mem, int *size) {
	FILE *pFile;
	pFile = fopen(name, "rb");
	if (pFile == NULL) exit(-1);
	fseek(pFile, 0, SEEK_END);	//step 1
	*size = ftell(pFile);		//step 2
	rewind(pFile);				//step 3
	*mem = (byte*)malloc(sizeof(byte) * *size);
	fread(*mem, sizeof(byte), *size, pFile);
	fclose(pFile);
}
void f2(byte **mem, int *size) {
	free(*mem);
	char fileName[20] = { 0 };
	scanf("%s", fileName);
	read(fileName, mem, size);
}
void f4(byte *mem, int size) {
	int bit, value;
	scanf("%d%d", &bit, &value);
	if (value == 0) mem[bit / 8] &= ~(1 << (bit % 8));
	else mem[bit / 8] |= 1 << (bit % 8);
	print(mem, size);
}
int main() {
	byte *mem = NULL;
	int size = 0;
	int select = 0;
	while (select != 5) {
		scanf("%d", &select);
		if (select == 1) f1(&mem, &size);
		else if (select == 2) f2(&mem, &size);
		else if (select == 3) print(mem, size);
		else if (select == 4) f4(mem, size);
	}
}
