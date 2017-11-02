struct vector{
	float x,y,z;
};

void print_vec(struct vector v){
	printf("(%f,%f,%f)\n",v.x,v.y,v.z);
	return;
}

float scalar(struct vector v1, struct vector v2){
	return	v1.x*v2.x +
			v1.y*v2.y +
			v1.z*v2.z;
}

float length(struct vector v1, struct vector v2){

    return sqrtf(powf((v2.x-v1.x),2)+
                 powf((v2.y-v1.y),2)+
                 powf((v2.z-v1.z),2));
}

float scalar_product(struct vector v1, struct vector v2){

    return cosf((v1.x*v2.x) + (v1.y*v2.y) + (v1.z*v2.z)/
                sqrtf(powf(v1.x,2) + powf(v1.y,2) + powf(v1.z,2))*
                sqrtf(powf(v2.x,2) + powf(v2.y,2) + powf(v2.z,2)));
}





