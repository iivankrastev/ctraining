#include <stdio.h>
#include <math.h>
#include "vector.h"

void print_vec(struct vector v);
float scalar(struct vector v1, struct vector v2);
float length(struct vector v1, struct vector v2);
float scalar_product(struct vector v1, struct vector v2);

int main(void){

	struct vector vec1,vec2;
	vec1.x=1.0f;
	vec1.y=2.0f;
	vec1.z=3.0f;

	vec2.x=10.0f;
	vec2.y=20.0f;
	vec2.z=30.0f;

	/*print_vec(vec);*/
	/*printf("%f\n",scalar(vec1,vec2));*/
    /*printf("%f\n",length(vec1,vec2));*/
    printf("%f\n",scalar_product(vec1,vec2));

	return 0;
}
