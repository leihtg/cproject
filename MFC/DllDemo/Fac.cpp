#include "Fac.h"
int Fun(int a){
	int n=1;
	for(int i=1;i<=a;i++){
		n*=i;
	}
	return n;
}