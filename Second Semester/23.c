#include<stdio.h>
#define GATEVALUE(TYPE) int(*GateValue)(int,int)
typedef struct _Gate {
	int x1, x2;
	GATEVALUE();
}Gate;
int GateEmptyValue(int x1, int x2) { return x1; }
int GateNotValue(int x1, int x2) { return !x1; }
int GateAndValue(int x1, int x2) { return x1 & x2; }
int GateOrValue(int x1, int x2) { return x1 | x2; }
void CreateEmptyGate(Gate *obj) {
	obj->GateValue = GateEmptyValue;
}
void CreateNotGate(Gate *obj) {
	obj->GateValue = GateNotValue;
}
void CreateAndGate(Gate *obj) {
	obj->GateValue = GateAndValue;
}
void CreateOrGate(Gate *obj) {
	obj->GateValue = GateOrValue;
}
void switchGate(Gate *obj) {
	char in[3];
	scanf("%c,%c,%c", in, in + 1, in + 2);
	int i;
	for (i = 0; i < 3; i++) {
        if(in[i]=='E') CreateEmptyGate(obj + i);
        else if(in[i]=='N') CreateNotGate(obj + i);
        else if(in[i]=='A') CreateAndGate(obj + i);
        else if(in[i]=='O') CreateOrGate(obj + i);
	}
}
void circuit(int *in, Gate *gate, int *result) {
	gate[0].x1 = in[0];
	result[0] = gate[0].GateValue(gate[0].x1, gate[0].x2);
	gate[1].x1 = result[0];
	gate[1].x2 = in[1];
	result[1] = gate[1].GateValue(gate[1].x1, gate[1].x2);
	gate[2].x1 = result[1];
	gate[2].x2 = in[2];
	result[2] = gate[2].GateValue(gate[2].x1, gate[2].x2);
}
int main(int argc, char *argv[]) {
	Gate gate[3];
	int in[3], result[3];
	scanf("%d,%d,%d ", in, in + 1, in + 2);
	switchGate(gate);
	circuit(in, gate, result);
	printf("%d,%d,%d", result[0], result[1], result[2]);
}
