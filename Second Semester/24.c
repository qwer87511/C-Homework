#include <stdio.h>
#define ShapeText(TYPE) \
        char name[10];\
        float (*perimeter)(struct TYPE*);
#define PI 4
typedef struct _Shape { // Shape 物件，沒有欄位
	ShapeText(_Shape);
} Shape;
typedef struct _Circle {
	ShapeText(_Circle);
	float radius;
} Circle;
typedef struct _Rectangle {
	ShapeText(_Rectangle);
	float length, width;
} Rectangle;
typedef struct _Square {
	ShapeText(_Square);
	float length;
} Square;
typedef struct _Triangle {
	ShapeText(_Triangle);
	float length[3];
} Triangle;

float CirclePerimeter(Circle *obj) { return 2 * PI * obj->radius; }
float RectanglePerimeter(Rectangle *obj) { return (obj->length + obj->width) * 2; }
float SquarePerimeter(Square *obj) { return obj->length * 4; }
float TrianglePerimeter(Triangle *obj) { return obj->length[0] + obj->length[1] + obj->length[2]; }

void CircleNew(Circle *obj) {
	scanf("%f", &(obj->radius));
	obj->perimeter = CirclePerimeter;
}
void RectangleNew(Rectangle *obj) {
	scanf("%f %f", &(obj->length), &(obj->width));
	obj->perimeter = RectanglePerimeter;
}
void SquareNew(Square *obj) {
	scanf("%f", &(obj->length));
	obj->perimeter = SquarePerimeter;
}
void TriangleNew(Triangle *obj) {
	scanf("%f %f %f", &(obj->length[0]), &(obj->length[1]), &(obj->length[2]));
	obj->perimeter = TrianglePerimeter;
}

void input(char *in, int *sum, Circle c[10], Rectangle r[10], Square s[10], Triangle t[10]) {
	int i;
	int sum_c = 0, sum_r = 0, sum_s = 0, sum_t = 0;
	scanf("%d", sum);
	for (i = 0; i < *sum; i++) {
		scanf(" %s", in+i);
		switch (in[i])
		{
		case 'C':
			CircleNew(c + sum_c++);
			break;
		case 'R':
			RectangleNew(r + sum_r++);
			break;
		case 'S':
			SquareNew(s + sum_s++);
			break;
		case 'T':
			TriangleNew(t + sum_t++);
			break;
		}
	}
}
void output(char *in, int sum, Circle c[10], Rectangle r[10], Square s[10], Triangle t[10]) {
	int sum_c = 0, sum_r = 0, sum_s = 0, sum_t = 0;
	int i;
	float res = 0;
	Shape *o;
	for (i = 0; i < sum; i++) {
		switch (in[i])
		{
		case 'C':
			o = (Shape*)&(c[sum_c++]);
			break;
		case 'R':
			o = (Shape*)&(r[sum_r++]);
			break;
		case 'S':
			o = (Shape*)&(s[sum_s++]);
			break;
		case 'T':
			o = (Shape*)&(t[sum_t++]);
			break;
		}
		printf("%G\n", o->perimeter(o));
		res += o->perimeter(o);
	}
	printf("%.0f", res);
}
int main() {
	int sum, sum_c = 0, sum_r = 0, sum_s = 0, sum_t = 0;
	char in[10]="\0";
	Circle c[10];
	Rectangle r[10];
	Square s[10];
	Triangle t[10];
	input(in, &sum, c, r, s, t);
	output(in, sum, c, r, s, t);
}

