#include <math.h>

double gasdevbis(long *idum, double *v1, double *v3)
{
	float ran1(long *idum);
	static int iset=0;
	static float ggset;
	float fac,rsq;
	if (*idum < 0) iset=0;
	if  (iset == 0) {
		do {
			*v3=2.0*ran1(idum)-1.0;
			rsq=(*v1)*(*v1)+*v3*(*v3);
		} while (rsq >= 1.0 || rsq == 0.0);
		fac=sqrt(-2.0*log(rsq)/rsq);
		ggset=(*v1)*fac;
		iset=1;
		*v1=*v3;
		return *v3*fac;
	} else {
		iset=0;
//	printf("%f\n", ggset);
		*v1=*v3;
		return ggset;
	}
}
