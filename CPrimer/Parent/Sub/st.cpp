#include "st.h"

void Parent::a(){
	printf("a\n");
}
void Parent::b(){
	a();
	printf("b\n");
	c();
}
void Parent::c(){
	printf("c\n");
}
