#include  <stdio.h>
#include <math.h>
/*#include <unistd.h>*/
#include <fcntl.h>
#include <stdlib.h>
#include "random.h"

double g(double x){
	if (x>0) return x;
	else return 0;
}
double sign(double x){
	return x/fabs(x);
}
int main(){
	int n, n1, nmoy, nunit, nctx, nstr, ngpi, ntha, nstn, ngpe, i, j, k, D, Dstrctx, Dgpistr, Dthagpi,
		Dctxtha, Dgpigpe, Dgpestr, Dgpestn, Dstngpe, Dstnctx, Dgpistn, step;
	long u;

	double t, tf, tf1, tf2, dt, mvt_dur, trampe, t_str, t_mvt, pi, eps, Dopa, pcon[15], sigma[6], tpsmoy, temp1, mctx1,
		temp, gamma, broad, pic, tobruit, I_ctx_mvt,
		Gstrctx0,	Ggpistr0, Gthagpi0, Gctxtha0, Gstnctx0, Ggpistn0, Gstr10, Ggpi10, Gctx10,
		Gstrctxg0, Ggpistrg0, Gthagpig0, Gctxthag0, Ggpigpeg0,
		Ggpestrg0, Ggpestng0, Gstngpeg0, Gstnctxg0, Ggpistng0, Gstrg10, Ggpig10, Gctxg10,
		ictx0, istr0, igpi0, igpe0, istn0, itha0, I_select_str,
		moyctxg, moystrg, moygpig, moystng, moythag, moygpeg,
		fmoystrg, fmoystng, fmoythag, fmoygpeg,
		Gstrctxd0, Ggpistrd0, Gthagpid0, Gctxthad0, Ggpigped0, Ggpestrd0, Ggpestnd0,
		Gstngped0, Gstnctxd0, Ggpistnd0, Gstrd10, Ggpid10, Gctxd10,
		moyctxd, moystrd, moygpid, moystnd, moythad, moygped,
		fmoystrd, fmoystnd, fmoythad, fmoygped,
		n_connect_ctx, n_connect_stn;

	double* v1 = (double*)malloc(1*sizeof(double));
	double* v3 = (double*)malloc(1*sizeof(double));
	double* fmoygpig = (double*)malloc(400*sizeof(double));
	double* fmoygpid = (double*)malloc(400*sizeof(double));
	double* fmoyctxg = (double*)malloc(400*sizeof(double));
	double* fmoyctxd = (double*)malloc(400*sizeof(double));
	double* bgctxg = (double*)malloc(400*sizeof(double));
	double* bgctxd = (double*)malloc(400*sizeof(double));
	double* reststrg = (double*)malloc(400*sizeof(double));
	double* reststng = (double*)malloc(400*sizeof(double));
	double* restgpig = (double*)malloc(400*sizeof(double));
	double* restgpeg = (double*)malloc(400*sizeof(double));
	double* restctxg = (double*)malloc(400*sizeof(double));
	double* restthag = (double*)malloc(400*sizeof(double));
	double* istr = (double*)malloc(400*sizeof(double));
	double* istn = (double*)malloc(400*sizeof(double));
	double* igpi = (double*)malloc(400*sizeof(double));
	double* igpe = (double*)malloc(400*sizeof(double));
	double* icortex = (double*)malloc(400*sizeof(double));
	double* ictx = (double*)malloc(400*sizeof(double));
	double* ithal = (double*)malloc(400*sizeof(double));
	double* istrg = (double*)malloc(400*sizeof(double));
	double* istng = (double*)malloc(400*sizeof(double));
	double* igpig = (double*)malloc(400*sizeof(double));
	double* igpeg = (double*)malloc(400*sizeof(double));
	double* ictxg = (double*)malloc(400*sizeof(double));
	double* ithalg = (double*)malloc(400*sizeof(double));
	double* isstrg = (double*)malloc(400*sizeof(double));
	double* isstng = (double*)malloc(400*sizeof(double));
	double* isgpig = (double*)malloc(400*sizeof(double));
	double* isgpeg = (double*)malloc(400*sizeof(double));
	double* isctxg = (double*)malloc(400*sizeof(double));
	double* isthalg = (double*)malloc(400*sizeof(double));
	double** fstrg = (double**)malloc(20*sizeof(double*));
	double** fstng = (double**)malloc(20*sizeof(double*));
	double** fgpig = (double**)malloc(20*sizeof(double*));
	double** fthag = (double**)malloc(20*sizeof(double*));
	double** fgpeg = (double**)malloc(20*sizeof(double*));
	double** fctxg1 = (double**)malloc(20*sizeof(double*));
	double** fctxg2 = (double**)malloc(20*sizeof(double*));
 	double* fmoygpig_repos = (double*)malloc(400*sizeof(double));
 	double* fmoygpig_mvt = (double*)malloc(400*sizeof(double));
 	double* fmoyctxg_repos = (double*)malloc(400*sizeof(double));
 	double* fmoyctxg_mvt = (double*)malloc(400*sizeof(double));
	double* reststrd = (double*)malloc(400*sizeof(double));
	double* reststnd = (double*)malloc(400*sizeof(double));
	double* restgpid = (double*)malloc(400*sizeof(double));
	double* restgped = (double*)malloc(400*sizeof(double));
	double* restctxd = (double*)malloc(400*sizeof(double));
	double* restthad = (double*)malloc(400*sizeof(double));
	double* istrd = (double*)malloc(400*sizeof(double));
	double* istnd = (double*)malloc(400*sizeof(double));
	double* igpid = (double*)malloc(400*sizeof(double));
	double* igped = (double*)malloc(400*sizeof(double));
	double* ictxd = (double*)malloc(400*sizeof(double));
	double* ithald = (double*)malloc(400*sizeof(double));
	double* isstrd = (double*)malloc(400*sizeof(double));
	double* isstnd = (double*)malloc(400*sizeof(double));
	double* isgpid = (double*)malloc(400*sizeof(double));
	double* isgped = (double*)malloc(400*sizeof(double));
	double* isctxd = (double*)malloc(400*sizeof(double));
	double* isthald = (double*)malloc(400*sizeof(double));
	double* th_str = (double*)malloc(400*sizeof(double));
	double* th_ctx = (double*)malloc(400*sizeof(double));
	double** fstrd = (double**)malloc(20*sizeof(double*));
	double** fstnd = (double**)malloc(20*sizeof(double*));
	double** fgpid = (double**)malloc(20*sizeof(double*));
	double** fthad = (double**)malloc(20*sizeof(double*));
	double** fgped = (double**)malloc(20*sizeof(double*));
	double** fctxd1 = (double**)malloc(20*sizeof(double*));
	double** fctxd2 = (double**)malloc(20*sizeof(double*));
 	double* fmoygpid_repos = (double*)malloc(400*sizeof(double));
 	double* fmoygpid_mvt = (double*)malloc(400*sizeof(double));
 	double* fmoyctxd_repos = (double*)malloc(400*sizeof(double));
 	double* fmoyctxd_mvt = (double*)malloc(400*sizeof(double));
	double** Gstrctxg = (double**)malloc(400*sizeof(double*));
	double** Gstrg1 = (double**)malloc(400*sizeof(double*));
	double** Ggpistrg = (double**)malloc(400*sizeof(double*));
	double** Ggpig1 = (double**)malloc(400*sizeof(double*));
	double** Gthagpig = (double**)malloc(400*sizeof(double*));
	double** Gctxthag = (double**)malloc(400*sizeof(double*));
	double** Ggpigpeg = (double**)malloc(400*sizeof(double*));
	double** Ggpestrg = (double**)malloc(400*sizeof(double*));
	double** Ggpestng = (double**)malloc(400*sizeof(double*));
	double** Gstngpeg = (double**)malloc(400*sizeof(double*));
	double** Gstnctxg = (double**)malloc(400*sizeof(double*));
	double** Gctxg1 = (double**)malloc(400*sizeof(double*));
	double** Ggpistng = (double**)malloc(400*sizeof(double*));
	double** Gstrctxd = (double**)malloc(400*sizeof(double*));
	double** Gstrd1 = (double**)malloc(400*sizeof(double*));
	double** Ggpistrd = (double**)malloc(400*sizeof(double*));
	double** Ggpid1 = (double**)malloc(400*sizeof(double*));
	double** Ggpestrd = (double**)malloc(400*sizeof(double*));
	double** Ggpigped = (double**)malloc(400*sizeof(double*));
	double** Gctxthad = (double**)malloc(400*sizeof(double*));
	double** Ggpestnd = (double**)malloc(400*sizeof(double*));
	double** Gstngped = (double**)malloc(400*sizeof(double*));
	double** Gstnctxd = (double**)malloc(400*sizeof(double*));
	double** Gctxd1 = (double**)malloc(400*sizeof(double*));
	double** Ggpistnd = (double**)malloc(400*sizeof(double*));
	double** Gthagpid = (double**)malloc(400*sizeof(double*));
	char** evolg = (char**)malloc(30*sizeof(char*));
	char** evold = (char**)malloc(30*sizeof(char*));
	char** profilg = (char**)malloc(30*sizeof(char*));
	char** profild = (char**)malloc(30*sizeof(char*));
	char** unitg = (char**)malloc(30*sizeof(char*));
	char** unitd = (char**)malloc(30*sizeof(char*));
	char** inputctx = (char**)malloc(30*sizeof(char*));
	char** unitgpig = (char**)malloc(30*sizeof(char*));
	char** unitgpid = (char**)malloc(30*sizeof(char*));
	char** unitctxg = (char**)malloc(30*sizeof(char*));
	char** unitctxd = (char**)malloc(30*sizeof(char*));

	FILE *tevold, *tevolg, *tprofild, *tprofilg, *tunitg, *tunitd, *tp, *tinput,
		*tunitgpig, *tunitgpid, *tunitctxg, *tunitctxd;
	for(i=0; i<20; i++)
		fstrg[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<20; i++)
		fstng[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<20; i++)
		fgpig[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<20; i++)
		fgpeg[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<20; i++)
		fthag[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<20; i++)
		fctxg1[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<20; i++)
		fctxg2[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<20; i++)
		fstrd[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<20; i++)
		fstnd[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<20; i++)
		fgpid[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<20; i++)
		fgped[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<20; i++)
		fthad[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<20; i++)
		fctxd1[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<20; i++)
		fctxd2[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<400; i++)
		Gstrctxg[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<400; i++)
		Gstrg1[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<400; i++)
		Ggpistrg[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<400; i++)
		Ggpig1[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<400; i++)
		Gthagpig[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<400; i++)
		Gctxthag[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<400; i++)
		Ggpigpeg[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<400; i++)
		Ggpestrg[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<400; i++)
		Ggpestng[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<400; i++)
		Gstngpeg[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<400; i++)
		Gstnctxg[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<400; i++)
		Gctxg1[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<400; i++)
		Ggpistng[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<400; i++)
		Gstrctxd[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<400; i++)
		Gstrd1[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<400; i++)
		Ggpistrd[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<400; i++)
		Ggpid1[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<400; i++)
		Gthagpid[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<400; i++)
		Ggpid1[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<400; i++)
		Gctxthad[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<400; i++)
		Ggpigped[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<400; i++)
		Ggpestrd[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<400; i++)
		Ggpestnd[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<400; i++)
		Gstngped[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<400; i++)
		Gstnctxd[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<400; i++)
		Ggpistnd[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<400; i++)
		Gctxd1[i] = (double*) malloc (400*sizeof(double));
	for(i=0; i<30; i++)
		evolg[i] = (char*) malloc (20*sizeof(char));
	for(i=0; i<30; i++)
		evold[i] = (char*) malloc (20*sizeof(char));
	for(i=0; i<30; i++)
		profilg[i] = (char*) malloc (20*sizeof(char));
	for(i=0; i<30; i++)
		profild[i] = (char*) malloc (20*sizeof(char));
	for(i=0; i<30; i++)
		unitg[i] = (char*) malloc (20*sizeof(char));
	for(i=0; i<30; i++)
		unitd[i] = (char*) malloc (20*sizeof(char));
	for(i=0; i<30; i++)
		unitgpig[i] = (char*) malloc (20*sizeof(char));
	for(i=0; i<30; i++)
		unitgpid[i] = (char*) malloc (20*sizeof(char));
	for(i=0; i<30; i++)
		unitctxg[i] = (char*) malloc (20*sizeof(char));
	for(i=0; i<30; i++)
		unitctxd[i] = (char*) malloc (20*sizeof(char));
	for(i=0; i<30; i++)
		inputctx[i] = (char*) malloc (20*sizeof(char));

	evolg[0]="evolg1.tab"; evold[0]="evold1.tab"; profilg[0]="profilg1.tab"; profild[0]="profild1.tab"; inputctx[0]="inputctx1.tab";
	evolg[1]="evolg2.tab"; evold[1]="evold2.tab"; profilg[1]="profilg2.tab"; profild[1]="profild2.tab"; inputctx[1]="inputctx2.tab";
	evolg[2]="evolg3.tab"; evold[2]="evold3.tab"; profilg[2]="profilg3.tab"; profild[2]="profild3.tab"; inputctx[2]="inputctx3.tab";
	evolg[3]="evolg4.tab"; evold[3]="evold4.tab"; profilg[3]="profilg4.tab"; profild[3]="profild4.tab"; inputctx[3]="inputctx4.tab";
	evolg[4]="evolg5.tab"; evold[4]="evold5.tab"; profilg[4]="profilg5.tab"; profild[4]="profild5.tab"; inputctx[4]="inputctx5.tab";
	evolg[5]="evolg6.tab"; evold[5]="evold6.tab"; profilg[5]="profilg6.tab"; profild[5]="profild6.tab"; inputctx[5]="inputctx6.tab";
	evolg[6]="evolg7.tab"; evold[6]="evold7.tab"; profilg[6]="profilg7.tab"; profild[6]="profild7.tab"; inputctx[6]="inputctx7.tab";
	evolg[7]="evolg8.tab"; evold[7]="evold8.tab"; profilg[7]="profilg8.tab"; profild[7]="profild8.tab"; inputctx[7]="inputctx8.tab";
	evolg[8]="evolg9.tab"; evold[8]="evold9.tab"; profilg[8]="profilg9.tab"; profild[8]="profild9.tab"; inputctx[8]="inputctx9.tab";
	evolg[9]="evolg10.tab"; evold[9]="evold10.tab"; profilg[9]="profilg10.tab"; profild[9]="profild10.tab"; inputctx[9]="inputctx10.tab";
	evolg[10]="evolg11.tab"; evold[10]="evold11.tab"; profilg[10]="profilg11.tab"; profild[10]="profild11.tab"; inputctx[10]="inputctx11.tab";
	evolg[11]="evolg12.tab"; evold[11]="evold12.tab"; profilg[11]="profilg12.tab"; profild[11]="profild12.tab"; inputctx[11]="inputctx12.tab";
	evolg[12]="evolg13.tab"; evold[12]="evold13.tab"; profilg[12]="profilg13.tab"; profild[12]="profild13.tab"; inputctx[12]="inputctx13.tab";
	evolg[13]="evolg14.tab"; evold[13]="evold14.tab"; profilg[13]="profilg14.tab"; profild[13]="profild14.tab"; inputctx[13]="inputctx14.tab";
	evolg[14]="evolg15.tab"; evold[14]="evold15.tab"; profilg[14]="profilg15.tab"; profild[14]="profild15.tab"; inputctx[14]="inputctx15.tab";
	evolg[15]="evolg16.tab"; evold[15]="evold16.tab"; profilg[15]="profilg16.tab"; profild[15]="profild16.tab"; inputctx[15]="inputctx16.tab";
	evolg[16]="evolg17.tab"; evold[16]="evold17.tab"; profilg[16]="profilg17.tab"; profild[16]="profild17.tab"; inputctx[16]="inputctx17.tab";
	evolg[17]="evolg18.tab"; evold[17]="evold18.tab"; profilg[17]="profilg18.tab"; profild[17]="profild18.tab"; inputctx[17]="inputctx18.tab";
	evolg[18]="evolg19.tab"; evold[18]="evold19.tab"; profilg[18]="profilg19.tab"; profild[18]="profild19.tab"; inputctx[18]="inputctx19.tab";
	evolg[19]="evolg20.tab"; evold[19]="evold20.tab"; profilg[19]="profilg20.tab"; profild[19]="profild20.tab"; inputctx[19]="inputctx20.tab";
	evolg[20]="evolg21.tab"; evold[20]="evold21.tab"; profilg[20]="profilg21.tab"; profild[20]="profild21.tab"; inputctx[20]="inputctx21.tab";
	evolg[21]="evolg22.tab"; evold[21]="evold22.tab"; profilg[21]="profilg22.tab"; profild[21]="profild22.tab"; inputctx[21]="inputctx22.tab";
	evolg[22]="evolg23.tab"; evold[22]="evold23.tab"; profilg[22]="profilg23.tab"; profild[22]="profild23.tab"; inputctx[22]="inputctx23.tab";
	evolg[23]="evolg24.tab"; evold[23]="evold24.tab"; profilg[23]="profilg24.tab"; profild[23]="profild24.tab"; inputctx[23]="inputctx24.tab";
	evolg[24]="evolg25.tab"; evold[24]="evold25.tab"; profilg[24]="profilg25.tab"; profild[24]="profild25.tab"; inputctx[24]="inputctx25.tab";
	evolg[25]="evolg26.tab"; evold[25]="evold26.tab"; profilg[25]="profilg26.tab"; profild[25]="profild26.tab"; inputctx[25]="inputctx26.tab";
	evolg[26]="evolg27.tab"; evold[26]="evold27.tab"; profilg[26]="profilg27.tab"; profild[26]="profild27.tab"; inputctx[26]="inputctx27.tab";
	evolg[27]="evolg28.tab"; evold[27]="evold28.tab"; profilg[27]="profilg28.tab"; profild[27]="profild28.tab"; inputctx[27]="inputctx28.tab";
	evolg[28]="evolg29.tab"; evold[28]="evold29.tab"; profilg[28]="profilg29.tab"; profild[28]="profild29.tab"; inputctx[28]="inputctx29.tab";
	evolg[29]="evolg30.tab"; evold[29]="evold30.tab"; profilg[29]="profilg30.tab"; profild[29]="profild30.tab"; inputctx[29]="inputctx30.tab";

	unitg[0]="unitg1.tab"; unitd[0]="unitd1.tab";	unitgpig[0]="unitgpig1.tab"; unitgpid[0]="unitgpid1.tab";	unitctxg[0]="unitctxg1.tab"; unitctxd[0]="unitctxd1.tab";
	unitg[1]="unitg2.tab"; unitd[1]="unitd2.tab";	unitgpig[1]="unitgpig2.tab"; unitgpid[1]="unitgpid2.tab";	unitctxg[1]="unitctxg2.tab"; unitctxd[1]="unitctxd2.tab";
	unitg[2]="unitg3.tab"; unitd[2]="unitd3.tab";	unitgpig[2]="unitgpig3.tab"; unitgpid[2]="unitgpid3.tab";	unitctxg[2]="unitctxg3.tab"; unitctxd[2]="unitctxd3.tab";
	unitg[3]="unitg4.tab"; unitd[3]="unitd4.tab";	unitgpig[3]="unitgpig4.tab"; unitgpid[3]="unitgpid4.tab";	unitctxg[3]="unitctxg4.tab"; unitctxd[3]="unitctxd4.tab";
	unitg[4]="unitg5.tab"; unitd[4]="unitd5.tab";	unitgpig[4]="unitgpig5.tab"; unitgpid[4]="unitgpid5.tab";	unitctxg[4]="unitctxg5.tab"; unitctxd[4]="unitctxd5.tab";
	unitg[5]="unitg6.tab"; unitd[5]="unitd6.tab";	unitgpig[5]="unitgpig6.tab"; unitgpid[5]="unitgpid6.tab";	unitctxg[5]="unitctxg6.tab"; unitctxd[5]="unitctxd6.tab";
	unitg[6]="unitg7.tab"; unitd[6]="unitd7.tab";	unitgpig[6]="unitgpig7.tab"; unitgpid[6]="unitgpid7.tab";	unitctxg[6]="unitctxg7.tab"; unitctxd[6]="unitctxd7.tab";
	unitg[7]="unitg8.tab"; unitd[7]="unitd8.tab";	unitgpig[7]="unitgpig8.tab"; unitgpid[7]="unitgpid8.tab";	unitctxg[7]="unitctxg8.tab"; unitctxd[7]="unitctxd8.tab";
	unitg[8]="unitg9.tab"; unitd[8]="unitd9.tab";	unitgpig[8]="unitgpig9.tab"; unitgpid[8]="unitgpid9.tab";	unitctxg[8]="unitctxg9.tab"; unitctxd[8]="unitctxd9.tab";
	unitg[9]="unitg10.tab"; unitd[9]="unitd10.tab";	unitgpig[9]="unitgpig10.tab"; unitgpid[9]="unitgpid10.tab";	unitctxg[9]="unitctxg10.tab"; unitctxd[9]="unitctxd10.tab";
	unitg[10]="unitg11.tab"; unitd[10]="unitd11.tab";	unitgpig[10]="unitgpig11.tab"; unitgpid[10]="unitgpid11.tab";	unitctxg[10]="unitctxg11.tab"; unitctxd[10]="unitctxd11.tab";
	unitg[11]="unitg12.tab"; unitd[11]="unitd12.tab";	unitgpig[11]="unitgpig12.tab"; unitgpid[11]="unitgpid12.tab";	unitctxg[11]="unitctxg12.tab"; unitctxd[11]="unitctxd12.tab";
	unitg[12]="unitg13.tab"; unitd[12]="unitd13.tab";	unitgpig[12]="unitgpig13.tab"; unitgpid[12]="unitgpid13.tab";	unitctxg[12]="unitctxg13.tab"; unitctxd[12]="unitctxd13.tab";
	unitg[13]="unitg14.tab"; unitd[13]="unitd14.tab";	unitgpig[13]="unitgpig14.tab"; unitgpid[13]="unitgpid14.tab";	unitctxg[13]="unitctxg14.tab"; unitctxd[13]="unitctxd14.tab";
	unitg[14]="unitg15.tab"; unitd[14]="unitd15.tab";	unitgpig[14]="unitgpig15.tab"; unitgpid[14]="unitgpid15.tab";	unitctxg[14]="unitctxg15.tab"; unitctxd[14]="unitctxd15.tab";
	unitg[15]="unitg16.tab"; unitd[15]="unitd16.tab";	unitgpig[15]="unitgpig16.tab"; unitgpid[15]="unitgpid16.tab";	unitctxg[15]="unitctxg16.tab"; unitctxd[15]="unitctxd16.tab";
	unitg[16]="unitg17.tab"; unitd[16]="unitd17.tab";	unitgpig[16]="unitgpig17.tab"; unitgpid[16]="unitgpid17.tab";	unitctxg[16]="unitctxg17.tab"; unitctxd[16]="unitctxd17.tab";
	unitg[17]="unitg18.tab"; unitd[17]="unitd18.tab";	unitgpig[17]="unitgpig18.tab"; unitgpid[17]="unitgpid18.tab";	unitctxg[17]="unitctxg18.tab"; unitctxd[17]="unitctxd18.tab";
	unitg[18]="unitg19.tab"; unitd[18]="unitd19.tab";	unitgpig[18]="unitgpig19.tab"; unitgpid[18]="unitgpid19.tab";	unitctxg[18]="unitctxg19.tab"; unitctxd[18]="unitctxd19.tab";
	unitg[19]="unitg20.tab"; unitd[19]="unitd20.tab";	unitgpig[19]="unitgpig20.tab"; unitgpid[19]="unitgpid20.tab";	unitctxg[19]="unitctxg20.tab"; unitctxd[19]="unitctxd20.tab";
	unitg[20]="unitg21.tab"; unitd[20]="unitd21.tab";	unitgpig[20]="unitgpig21.tab"; unitgpid[20]="unitgpid21.tab";	unitctxg[20]="unitctxg21.tab"; unitctxd[20]="unitctxd21.tab";
	unitg[21]="unitg22.tab"; unitd[21]="unitd22.tab";	unitgpig[21]="unitgpig22.tab"; unitgpid[21]="unitgpid22.tab";	unitctxg[21]="unitctxg22.tab"; unitctxd[21]="unitctxd22.tab";
	unitg[22]="unitg23.tab"; unitd[22]="unitd23.tab";	unitgpig[22]="unitgpig23.tab"; unitgpid[22]="unitgpid23.tab";	unitctxg[22]="unitctxg23.tab"; unitctxd[22]="unitctxd23.tab";
	unitg[23]="unitg24.tab"; unitd[23]="unitd24.tab";	unitgpig[23]="unitgpig24.tab"; unitgpid[23]="unitgpid24.tab";	unitctxg[23]="unitctxg24.tab"; unitctxd[23]="unitctxd24.tab";
	unitg[24]="unitg25.tab"; unitd[24]="unitd25.tab";	unitgpig[24]="unitgpig25.tab"; unitgpid[24]="unitgpid25.tab";	unitctxg[24]="unitctxg25.tab"; unitctxd[24]="unitctxd25.tab";
	unitg[25]="unitg26.tab"; unitd[25]="unitd26.tab";	unitgpig[25]="unitgpig26.tab"; unitgpid[25]="unitgpid26.tab";	unitctxg[25]="unitctxg26.tab"; unitctxd[25]="unitctxd26.tab";
	unitg[26]="unitg27.tab"; unitd[26]="unitd27.tab";	unitgpig[26]="unitgpig27.tab"; unitgpid[26]="unitgpid27.tab";	unitctxg[26]="unitctxg27.tab"; unitctxd[26]="unitctxd27.tab";
	unitg[27]="unitg28.tab"; unitd[27]="unitd28.tab";	unitgpig[27]="unitgpig28.tab"; unitgpid[27]="unitgpid28.tab";	unitctxg[27]="unitctxg28.tab"; unitctxd[27]="unitctxd28.tab";
	unitg[28]="unitg29.tab"; unitd[28]="unitd29.tab";	unitgpig[28]="unitgpig29.tab"; unitgpid[28]="unitgpid29.tab";	unitctxg[28]="unitctxg29.tab"; unitctxd[28]="unitctxd29.tab";
	unitg[29]="unitg30.tab"; unitd[29]="unitd30.tab";	unitgpig[29]="unitgpig30.tab"; unitgpid[29]="unitgpid30.tab";	unitctxg[29]="unitctxg30.tab"; unitctxd[29]="unitctxd30.tab";

	tp=fopen("parameters.tab","w");
	dt=.1; tf1=1000; tf2=1000; tpsmoy=5;	gamma=0.3;																	//temps de simulation, gamma
	eps=0.; I_select_str=.002; I_ctx_mvt=0.1; /*.06; */ trampe=10; mvt_dur=100; t_str=20; t_mvt=500+mvt_dur/2;	//(mvt)
	pi=3.14159265; u=-3;	temp=0; mctx1=20; step=1;
	(*v1)=(2.0*ran1(&u)-1.0);
	(*v3)=(2.0*ran1(&u)-1.0);
	n=100; n1=n; nmoy=20; nunit=20;
	nctx=n; nstr=n1; ngpi=n1; ngpe=n1; ntha=n1; nstn=n1;		/*nombre de neurones et proba de connection*/
	broad=floor(n/10); tobruit=10; pic=tobruit*0; //*n/10;  //
//	pcon[1]=1; pcon[2]=1; pcon[3]=1; pcon[4]=1; pcon[5]=1; pcon[6]=1; pcon[7]=1; pcon[8]=1; pcon[9]=1; pcon[10]=1; pcon[11]=1; pcon[12]=1; pcon[13]=1;
	pcon[1]=1/(1+nctx/10010.0);/*ctx-str*/ pcon[2]=1/(1+nctx/101.0);/*ctx-stn*/ pcon[3]=0.5;/*ctx-ctx*/ pcon[4]=1/(1+nstr/500.3);/*str-gpi*/ pcon[5]=0.5;/*str-gpe*/
	pcon[6]=0.5;/*str-str*/ pcon[7]=1/(1+ngpi/500.3);/*gpi-tha*/ pcon[8]=0.5;/*gpi-gpi*/ pcon[9]=0.5;/*gpe-gpi*/ pcon[10]=0.5;/*gpe-stn*/
	pcon[11]=0.5;/*stn-gpe*/ pcon[12]=1/(1+nstn/806.5);/*stn-gpi*/ pcon[13]=1/(1+ntha/1000.1);/*tha-ctx*/
	for(i=0;i<nctx;i++){
		bgctxg[i]=0; bgctxd[i]=0;
	}
	Dstrctx=12;  Dgpistr=19; Dthagpi=10; Dctxtha=10;Dstnctx=10;Dgpistn=10;	/*Valeur des delais*/
	Dgpigpe=0; Dgpestr=0; Dgpestn=0; Dstngpe=0;
	 ictx0=-0.1;  igpi0=-1.35; itha0=0.17;  istn0=0.08;  //-.13
//	 ictx0=-0.12;  igpi0=-1.35; itha0=0.185;  istn0=0.08;  //-.13
//	igpi0=-.09; ictx0=-.08;  /*-.06; -0.12;*/ itha0=0.25; istn0=0.05; igpe0=0;   /*input currents*/
	sigma[1]=0.05; /* ctx */ sigma[2]=0.005; /* str */ sigma[3]=0.05; /* gpi */ sigma[4]=0.05; /* tha */ sigma[5]=0.02; /* stn */ sigma[6]=0.0; /* gpe */
	for(i=0;i<nstr;i++){
		th_str[i]=.04+0.01*gasdevbis(&u, v1, v3) ; //0.0175 +0.01*gasdevbis(&u, v1, v3) .035  0.01; //0188
	}
	for(i=0;i<nstr;i++){
		th_ctx[i]=0.0; //+.02*gasdevbis(&u, v1, v3);
	}
	Ggpistr0=10.5; //12.14; //14; //
//	Gthagpi0=0.3; Gctxtha0=0.969; Gstnctx0=2; Ggpistn0=4.9;	/*Paramètres*/
//	Gthagpi0=0.2; Gctxtha0= 1.25; Gstnctx0=0.8; Ggpistn0=17.9;	/*Paramètres*/
	Gthagpi0=0.2; Gctxtha0= 1.25; Gstnctx0=0.8; Ggpistn0=18;	/*Paramètres*/
	Gstr10=0; Ggpi10=0; Gctx10=0;

	Ggpistrd0=Ggpistr0; Gthagpid0=Gthagpi0; Gctxthad0=Gctxtha0;Gstnctxd0=Gstnctx0;Ggpistnd0=Ggpistn0;	/*boucle 1 (de droite)*/
	Gstrd10=Gstr10; Ggpid10=Ggpi10; Gctxd10=Gctx10;
	Ggpigped0=0; Ggpestrd0=0; Ggpestnd0=0; Gstngped0=0.;
	Ggpistrg0=Ggpistr0; Gthagpig0=Gthagpi0; Gctxthag0=Gctxtha0;Gstnctxg0=Gstnctx0;Ggpistng0=Ggpistn0;	/*boucle 2 (de gauche)*/
	Gstrg10=Gstr10; Ggpig10=Ggpi10; Gctxg10=Gctx10;
	Ggpigpeg0=0; Ggpestrg0=0; Ggpestng0=0; Gstngpeg0=0.;

	for(i=0;i<nctx;i++) {									/*définition des connections présentes*/
		for(j=0;j<nstn;j++) {
			Gstnctxd[j][i]=Gstnctxd0*(1+sign(pcon[2]-ran1(&u)))/2;       // ctx-stn
			Gstnctxg[j][i]=Gstnctxg0*(1+sign(pcon[2]-ran1(&u)))/2;
		}
		for(j=0;j<nctx;j++) {
			Gctxd1[j][i]=Gctxd10*(1+sign(pcon[3]-ran1(&u)))/2;			//ctx_ctx
			Gctxg1[j][i]=Gctxg10*(1+sign(pcon[3]-ran1(&u)))/2;
		}
	}
	for(i=0;i<nstr;i++) {
		for(j=0;j<ngpi;j++) {
			Ggpistrd[j][i]=-Ggpistrd0*(1+sign(pcon[4]-ran1(&u)))/2;		//str-gpi
			Ggpistrg[j][i]=-Ggpistrg0*(1+sign(pcon[4]-ran1(&u)))/2;
		}
		for(j=0;j<ngpe;j++) {
			Ggpestrd[j][i]=-Ggpestrd0*(1+sign(pcon[5]-ran1(&u)))/2;		//str-gpe
			Ggpestrg[j][i]=-Ggpestrg0*(1+sign(pcon[5]-ran1(&u)))/2;
		}
		for(j=0;j<nstr;j++) {
			Gstrd1[j][i]=-Gstrd10*(1+sign(pcon[6]-ran1(&u)))/2;			//str-str
			Gstrg1[j][i]=-Gstrg10*(1+sign(pcon[6]-ran1(&u)))/2;
		}
	}
	for(i=0;i<ngpi;i++) {
		for(j=0;j<ntha;j++) {
			Gthagpid[j][i]=-Gthagpid0*(1+sign(pcon[7]-ran1(&u)))/2;		//gpi-tha
			Gthagpig[j][i]=-Gthagpig0*(1+sign(pcon[7]-ran1(&u)))/2;
		}
		for(j=0;j<nstr;j++) {
			Ggpid1[j][i]=-Ggpid10*(1+sign(pcon[8]-ran1(&u)))/2;			//gpi-gpi
			Ggpig1[j][i]=-Ggpig10*(1+sign(pcon[8]-ran1(&u)))/2;
		}
	}
	for(i=0;i<ngpe;i++) {
		for(j=0;j<ngpi;j++) {
			Ggpigped[j][i]=-Ggpigped0*(1+sign(pcon[9]-ran1(&u)))/2;		//gpe-gpi
			Ggpigpeg[j][i]=-Ggpigpeg0*(1+sign(pcon[9]-ran1(&u)))/2;
		}
		for(j=0;j<nstn;j++) {
			Gstngped[j][i]=-Gstngped0*(1+sign(pcon[10]-ran1(&u)))/2;		//gpe-stn
			Gstngpeg[j][i]=-Gstngpeg0*(1+sign(pcon[10]-ran1(&u)))/2;
		}
	}
	for(i=0;i<nstn;i++) {
		for(j=0;j<ngpe;j++) {
			Ggpestnd[j][i]=Ggpestnd0*(1+sign(pcon[11]-ran1(&u)))/2;		//stn-gpe
			Ggpestng[j][i]=Ggpestng0*(1+sign(pcon[11]-ran1(&u)))/2;
		}
		for(j=0;j<ngpi;j++) {
			Ggpistnd[j][i]=Ggpistnd0*(1+sign(pcon[12]-ran1(&u)))/2;		//stn-gpi
			Ggpistng[j][i]=Ggpistng0*(1+sign(pcon[12]-ran1(&u)))/2;
		}
	}
	for(i=0;i<ntha;i++) {
		for(j=0;j<nctx;j++) {
			Gctxthad[j][i]=Gctxthad0*(1+sign(pcon[13]-ran1(&u)))/2;		//tha-ctx
			Gctxthag[i][j]=Gctxthag0*(1+sign(pcon[13]-ran1(&u)))/2;
		}
	}

  for(D=0;D<11;D+=step){           //Calcul pour différent taux de dopa.
	Dopa=1; //-0.1*D;
	if(D>0){Dopa=1-0.1*D;}
	tf=tf1; if(D>4){tf=tf2;}
//	Gstrctx0=1.6/(1+exp(-2*(Dopa-1))); //1.6/(1+exp(-1.8*(Dopa-1))); //.8*Dopa; //.97/(1+exp(-2*(Dopa-.2))); //1.1/(1+exp(-2*(Dopa-.5))); //
    Gstrctx0=1.6/(1+exp(-2*(Dopa-.6)));
    printf("G  %f\n",Gstrctx0);
	Gstrctxd0=Gstrctx0;
	Gstrctxg0=Gstrctx0;
	for(i=0;i<nctx;i++) {									/*définition des connections présentes*/
		for(j=0;j<nstr;j++) {
			Gstrctxd[j][i]=Gstrctxd0*(1+sign(pcon[1]-ran1(&u)))/2;
			Gstrctxg[j][i]=Gstrctxg0*(1+sign(pcon[1]-ran1(&u)))/2;
		}
	}

	for(i=0;i<n;i++){
		istr[i]=-th_str[i]+.04*(1-1.1/(1+exp(-3*(Dopa-1)))); //    istr0=0.005+0.03*(1-1.1/(1+0.1*exp(-3*(Dopa-1))));
//1.2*.022*(1-2/(1+exp(-3*(Dopa-1)))); //0.06*(1-1.1/(1+0.1*exp(-3*(Dopa-1))));  //-th_str[i]+0.06*(1-1.1/(1+0.1*exp(-5*(Dopa-1)))); //0.005
		igpi[i]=igpi0; ictx[i]=ictx0-th_ctx[i]; ithal[i]=itha0; istn[i]=istn0; igpe[i]=igpe0;
		istrd[i]=istr[i]; igpid[i]=igpi[i]; ithald[i]=ithal[i]; istnd[i]=istn[i]; igped[i]=igpe[i];ictxd[i]=ictx[i];
		istrg[i]=istr[i]; igpig[i]=igpi[i]; ithalg[i]=ithal[i]; istng[i]=istn[i]; igpeg[i]=igpe[i];ictxg[i]=ictx[i];
//		if(Dopa>0.95){
			icortex[i]=I_ctx_mvt; /*-Gctxtha0*(ithal[i]-Gthagpi0*(igpi[i]+Ggpistn0*istn[i]-Ggpistr0*istr[i])+mctx1*Gthagpi0*(Ggpistr0*Gstrctx0-(1-gamma)*Ggpistn0*Gstnctx0)/200);*/
//		}
	}

	if(D<1){ i=0;
		fprintf(tp, " n  %d, eps  %f, gamma  %f, u  %ld, tpsmoy  %f temps total  %f ms\n", n, eps, gamma, u, tpsmoy, 5*tf);
		fprintf(tp, " bruit: ctx  %f, str  %f, gpi  %f, tha  %f, stn  %f, gpe  %f\n", sigma[1], sigma[2], sigma[3], sigma[4], sigma[5], sigma[6]);
		fprintf(tp, "connections: %f  %f  %f  %f  %f  %f  %f\n", pcon[1], pcon[2], pcon[3], pcon[4], pcon[5], pcon[6], pcon[7]);
		fprintf(tp, "courants: %f  %f  %f  %f  %f  %f\n", istr[i], igpi[i], ictx[i], ithal[i], istn[i], igpe[i]);
		fprintf(tp, "gains:  %f  %f  %f  %f  %f  %f  \n", Gstrctx0, Ggpistr0, Gthagpi0, Gctxtha0, Gstnctx0, Ggpistn0);
		fprintf(tp, "bruit corrélé: largeur: %f   puissance: %f  tps car correl: %f\n", broad, pic, tobruit);
	}

	tinput=fopen(inputctx[D],"w");
	tevold=fopen(evold[D],"w");
	tevolg=fopen(evolg[D],"w");
	tprofild=fopen(profild[D],"w");
	tprofilg=fopen(profilg[D],"w");
	tunitd=fopen(unitd[D],"w");
	tunitg=fopen(unitg[D],"w");
	tunitgpid=fopen(unitgpid[D],"w");	tunitctxd=fopen(unitctxd[D],"w");
	tunitgpig=fopen(unitgpig[D],"w");	tunitctxg=fopen(unitctxg[D],"w");
	fprintf(tprofilg,"%d  %d  %d  %d  %d  %d  %d  %d\n", nstr, ngpi, nctx, ntha, nstn, ngpe, ngpi, nctx);
	fprintf(tprofild,"%d  %d  %d  %d  %d  %d  %d  %d\n", nstr, ngpi, nctx, ntha, nstn, ngpe, ngpi, nctx);

	for(i=0;i<n;i++){									/*conditions initiales*/
		fstng[0][i]=0; fstrg[0][i]=0; fgpig[0][i]=0.33; fctxg1[0][i]=0; fctxg2[0][i]=0; fthag[0][i]=0;	/*conditions initiales*/
		fstnd[0][i]=0; fstrd[0][i]=0; fgpid[0][i]=0.33; fctxd1[0][i]=0; fctxd2[0][i]=0; fthad[0][i]=0;

		isstng[i]=0; isstrg[i]=0; isgpig[i]=0.33; isctxg[i]=0; isthalg[i]=0;
		isstnd[i]=0; isstrd[i]=0; isgpid[i]=0.33; isctxd[i]=0; isthald[i]=0;

		for(k=1; k<20; k++){
			fstrg[k][i]=fstrg[0][i];			fstrd[k][i]=fstrd[0][i];
			fctxg1[k][i]=fctxg1[0][i];			fctxd1[k][i]=fctxd1[0][i];
			fctxg2[k][i]=fctxg2[0][i];			fctxd2[k][i]=fctxd2[0][i];
			fgpig[k][i]=fgpig[0][i];			fgpid[k][i]=fgpid[0][i];
			fthag[k][i]=fthag[0][i];			fthad[k][i]=fthad[0][i];
			fstng[k][i]=fstng[0][i];			fstnd[k][i]=fstnd[0][i];
			fgpeg[k][i]=fgpeg[0][i];			fgped[k][i]=fgped[0][i];
		}
		restctxg[i]=0;		restctxd[i]=0;
		reststrg[i]=0;		reststrd[i]=0;
		restgpig[i]=0;		restgpid[i]=0;
		reststng[i]=0;		reststnd[i]=0;
		restthag[i]=0;		restthad[i]=0;
		restgpeg[i]=0;		restgped[i]=0;
		fmoygpig_mvt[i]=0; fmoygpid_mvt[i]=0;
		fmoyctxg_mvt[i]=0; fmoyctxd_mvt[i]=0;
	}
	t=0; temp=0; temp1=0;
	printf("fin conditions initiales\n");

while(t<tf){
	if((t>500)&(t<500.1)){printf("t=500\n");}
	if((t>1000)&(t<1000.1)){printf("t=1000\n");}
	if((t>2500)&(t<2500.1)){printf("t=2500\n");}
	if((t>5000)&(t<5000.1)){printf("t=5000\n");}
	if((t>10000)&(t<10000.1)){printf("t=10000\n");}
	if((t>15000)&(t<15000.1)){printf("t=15000\n");}


	for(i=0;i<nctx;i++){
		bgctxg[i]+=(-bgctxg[i]+pic*sigma[1]*gasdevbis(&u, v1, v3))*dt/tobruit; //*gasdevbis(&u, v1, v3)
		bgctxd[i]+=(-bgctxd[i]+pic*sigma[1]*gasdevbis(&u, v1, v3))*dt/tobruit;  //*gasdevbis(&u, v1, v3))
	}
	for(i=0;i<n;i++){
		j=0;																											//calcul des courants
		if((t>500)&(t<500.2)){															//courants de mouvement
				istrg[i]+=I_select_str;
				istrd[i]-=I_select_str;
			}
		if((t>500+t_str)&(t<500.2+t_str)){															//courants de mouvement
				istrg[i]-=I_select_str;
				istrd[i]+=I_select_str;
			}
		if(i<nctx) {																							//cortex
			ictxg[i]=ictx[i];
			ictxd[i]=ictx[i];
/*			if((t>500)&(t<500+trampe))															//courants de mouvement
					ictxg[i]+=(t-500)*icortex[i]/trampe;
			if((t>500+trampe)&(t<mvt_dur+500-trampe))															//courants de mouvement
					ictxg[i]+=icortex[i];
			if((t>mvt_dur+500-trampe)&(t<mvt_dur+500))
					ictxg[i]+=(mvt_dur+500+trampe-t)*icortex[i]/trampe;	*/
			if((t>500)&(t<mvt_dur+500)){
				ictxg[i]+=icortex[i]*pow(cos((t-t_mvt)*pi/mvt_dur),2);//exp(-pow((t-t_mvt)/20,2));
				ictxd[i]+=icortex[i]*pow(cos((t-t_mvt)*pi/mvt_dur),2)*(1+eps)/(1-eps);
			}

			if((i<1)&(t>700)&(t<700.1)) {
					fprintf(tp,"mouvement: ictxg= %f   ictd  %f\n", ictxg[i], ictxd[i]);
			}


/*				if(t<500+trampe){															// Courant sur le cortex pendant le mouvement
					ictxg[i]=ictx0+(t-500)*(icortex[i]-ictx0)/trampe;
				}
				if((t>=500+trampe)&(t<mvt_dur+500)){
					ictxg[i]=icortex[i]+0.04;
				}
				if(t>mvt_dur+500){
					ictxg[i]=ictx[i]+(mvt_dur+500+trampe-t)*(icortex[i]+.05-ictx[i])/trampe;
				}
				ictxd[i]=(ictxg[i]-ictx0)*(1+eps)/(1-eps)+ictx0;
			}*/

			isctxg[i]=ictxg[i]+sigma[1]*gasdevbis(&u, v1, v3)/2;
			isctxd[i]=ictxd[i]+sigma[1]*gasdevbis(&u, v1, v3)/2;
			for(j=0;j<nctx;j++){
				isctxg[i]+=bgctxg[j]*exp(-pow(fmod(i-j,nctx),2)/pow(broad,2))/(broad*pow(2*pi,.5));
				isctxd[i]+=bgctxd[j]*exp(-pow(fmod(i-j,nctx),2)/pow(broad,2))/(broad*pow(2*pi,.5));
			}
			if(i==1){
				fprintf(tinput,"%f  %f  %f  %f  %f\n", t*5,isctxd[i]+0.12, isctxg[i]+0.12, istrd[i]+sigma[2]*gasdevbis(&u, v1, v3), istrg[i]+sigma[2]*gasdevbis(&u, v1, v3));
			}
			for(j=0;j<n;j++) {																								//calcul des courants
				if(j<nctx) {
					isctxg[i]+=Gctxg1[i][j]*fctxg1[0][j]/(nctx*pcon[3]);
					isctxd[i]+=Gctxd1[i][j]*fctxd1[0][j]/(nctx*pcon[3]);
				}
				if(j<ntha) {
					isctxg[i]+=Gctxthag[i][j]*fthag[Dctxtha][j]/(ntha*pcon[13]);
					isctxd[i]+=Gctxthad[i][j]*fthad[Dctxtha][j]/(ntha*pcon[13]);
				}
/*				if((t>300)&(t<300.5)){																//Stimulation cortex
					isctxg[i]+=.4;
				}*/
			}
		}
		if(i<nstr) {
			isstrg[i]=istrg[i]+sigma[2]*gasdevbis(&u, v1, v3);			//striatum
			isstrd[i]=istrd[i]+sigma[2]*gasdevbis(&u, v1, v3);
			for(j=0;j<n;j++) {
				if(j<nctx) {
					isstrg[i]+=Gstrctxg[i][j]*fctxg2[Dstrctx][j]/(nctx*pcon[1]);
					isstrd[i]+=Gstrctxd[i][j]*fctxd2[Dstrctx][j]/(nctx*pcon[1]);
				}
				if(j<nstr) {
					isstrg[i]+=Gstrg1[i][j]*fstrg[0][j]/(nstr*pcon[6]);
					isstrd[i]+=Gstrd1[i][j]*fstrd[0][j]/(nstr*pcon[6]);
				}
			}
		}
		if(i<nstn) {
			isstng[i]=istng[i]+sigma[5]*gasdevbis(&u, v1, v3);
			isstnd[i]=istnd[i]+sigma[5]*gasdevbis(&u, v1, v3);
/*			if(t<12000){																						//SHF
				isstng[i]+=-5*pow(cos(4*t),2);
				isstnd[i]+=-5*pow(cos(4*t),2);
			}*/
			for(j=0;j<n;j++) {
				if(j<nctx) {
					isstng[i]+=Gstnctxg[i][j]*fctxg1[Dstnctx][j]/(nctx*pcon[2]);			//calcul des courants
					isstnd[i]+=Gstnctxd[i][j]*fctxd1[Dstnctx][j]/(nctx*pcon[2]);			//calcul des courants
				}
				if(j<ngpe) {
					isstng[i]+=Gstngpeg[i][j]*fgpeg[Dstngpe][j]/(ngpe*pcon[10]);
					isstnd[i]+=Gstngped[i][j]*fgped[Dstngpe][j]/(ngpe*pcon[10]);
				}
			}
		}
		if(i<ngpe) {
			isgpeg[i]=igpeg[i]+sigma[6]*gasdevbis(&u, v1, v3);
			isgped[i]=igped[i]+sigma[6]*gasdevbis(&u, v1, v3);
			for(j=0;j<n;j++) {
				if(j<nstn) {
					isgpeg[i]+=Ggpestng[i][j]*fstng[Dgpestn][j]/(nstn*pcon[11]);
					isgped[i]+=Ggpestnd[i][j]*fstnd[Dgpestn][j]/(nstn*pcon[11]);
				}
				if(j<nstr) {
					isgpeg[i]+=Ggpestrg[i][j]*fstrg[Dgpestr][j]/(nstr*pcon[5]);
					isgped[i]+=Ggpestrd[i][j]*fstrd[Dgpestr][j]/(nstr*pcon[5]);
				}
			}
		}
		if(i<ngpi) {
			isgpig[i]=igpig[i]+sigma[3]*gasdevbis(&u, v1, v3);
			isgpid[i]=igpid[i]+sigma[3]*gasdevbis(&u, v1, v3);
/*			if(t<12000){																				//SHF
				isgpig[i]+=.7;
				isgpid[i]+=.7;
			}*/
			for(j=0;j<n;j++) {
				if(j<ngpe) {
					isgpig[i]+=Ggpigpeg[i][j]*fgpeg[2][j]/(ngpe*pcon[9]);
					isgpid[i]+=Ggpigped[i][j]*fgped[2][j]/(ngpe*pcon[9]);
				}
				if(j<ngpi) {
					isgpig[i]+=Ggpig1[i][j]*fgpig[0][j]/(ngpi*pcon[8]);
					isgpid[i]+=Ggpig1[i][j]*fgpid[0][j]/(ngpi*pcon[8]);
				}
				if(j<nstr) {
					isgpig[i]+=Ggpistrg[i][j]*fstrg[Dgpistr][j]/(nstr*pcon[4]);
					isgpid[i]+=Ggpistrd[i][j]*fstrd[Dgpistr][j]/(nstr*pcon[4]);
				}
				if(j<nstn) {
					isgpig[i]+=((1-gamma)*Ggpistng[j][i]*fstng[Dgpistn][j]+gamma*Ggpistng[i][j]*fstnd[Dgpistn][j])/(nstn*pcon[12]);
					isgpid[i]+=((1-gamma)*Ggpistnd[j][i]*fstnd[Dgpistn][j]+gamma*Ggpistnd[i][j]*fstng[Dgpistn][j])/(nstn*pcon[12]);
				}
			}
		}
		if(i<ntha) {
			isthalg[i]=ithalg[i]+sigma[4]*gasdevbis(&u, v1, v3);
			isthald[i]=ithald[i]+sigma[4]*gasdevbis(&u, v1, v3);
			for(j=0;j<ngpi;j++) {
				isthalg[i]+=Gthagpig[i][j]*fgpig[Dthagpi][j]/(ngpi*pcon[7]);
				isthald[i]+=Gthagpid[i][j]*fgpid[Dthagpi][j]/(ngpi*pcon[7]);
			}
		}

		for(k=19;k>0;k--){
			if(i<nctx) {
				fctxg1[k][i]=fctxg1[k-1][i];				//cortex
				fctxd1[k][i]=fctxd1[k-1][i];
				fctxg2[k][i]=fctxg2[k-1][i];				//cortex
				fctxd2[k][i]=fctxd2[k-1][i];
			}
			if(i<nstn) {
				fstng[k][i]=fstng[k-1][i];				//STN
				fstnd[k][i]=fstnd[k-1][i];
			}
			if(i<nstr) {
				fstrg[k][i]=fstrg[k-1][i];				//striatum
				fstrd[k][i]=fstrd[k-1][i];
			}
			if(i<ngpi) {
				fgpig[k][i]=fgpig[k-1][i];				//GPi
				fgpid[k][i]=fgpid[k-1][i];
			}
			if(i<ngpe) {
				fgpeg[k][i]=fgpeg[k-1][i];				//GPe
				fgped[k][i]=fgped[k-1][i];
			}
			if(i<ntha) {
				fthag[k][i]=fthag[k-1][i];
				fthad[k][i]=fthad[k-1][i];
			}
		}
		if(i<nctx) {
			if((t>300)&(t<500)){
				restctxg[i]+=g(isctxg[i]/2000);		restctxd[i]+=g(isctxd[i]/2000);
			}
			if((t>530)&(t<mvt_dur+500+trampe-20)){
				fmoyctxg_mvt[i]+=g(isctxg[i]*dt/((mvt_dur+500+trampe-550))); fmoyctxd_mvt[i]+=g(isctxd[i]*dt/((mvt_dur+500+trampe-550)));
			}
			fctxg1[0][i]+=(-fctxg1[0][i]+g(isctxg[i]))*dt/4;					//calcul des frequences
			fctxd1[0][i]+=(-fctxd1[0][i]+g(isctxd[i]))*dt/4;
			fctxg2[0][i]+=(-fctxg2[0][i]+g(isctxg[i]))*dt;
			fctxd2[0][i]+=(-fctxd2[0][i]+g(isctxd[i]))*dt;
		}
		if(i<nstn) {
			if((t>300)&(t<500)){
				reststng[i]+=g(isstng[i]/2000);		reststnd[i]+=g(isstnd[i]/2000);
			}
				fstng[0][i]+=(-fstng[0][i]+g(isstng[i]))*dt;
				fstnd[0][i]+=(-fstnd[0][i]+g(isstnd[i]))*dt;
		}
		if(i<nstr) {
			if((t>300)&(t<500)){
				reststrg[i]+=g(isstrg[i]/2000);		reststrd[i]+=g(isstrd[i]/2000);
			}
			fstrg[0][i]+=(-fstrg[0][i]+g(isstrg[i]))*dt;
			fstrd[0][i]+=(-fstrd[0][i]+g(isstrd[i]))*dt;
		}
		if(i<ngpi) {
			if((t>300)&(t<500)){
				restgpig[i]+=g(isgpig[i]/2000);		restgpid[i]+=g(isgpid[i]/2000);
			}
			if((t>530)&(t<mvt_dur+500+trampe-20)){
				fmoygpig_mvt[i]+=g(isgpig[i]*dt/((mvt_dur+trampe-50))); fmoygpid_mvt[i]+=g(isgpid[i]*dt/((mvt_dur+trampe-50)));
			}
			fgpig[0][i]+=(-fgpig[0][i]+g(isgpig[i]))*dt;
			fgpid[0][i]+=(-fgpid[0][i]+g(isgpid[i]))*dt;
		}
		if(i<ngpe) {
			if((t>300)&(t<500)){
				restgpeg[i]+=g(isgpeg[i]/2000);		restgped[i]+=g(isgped[i]/2000);
			}
			fgpeg[0][i]+=(-fgpeg[0][i]+g(isgpeg[i]))*dt;
			fgped[0][i]+=(-fgped[0][i]+g(isgped[i]))*dt;
		}
		if(i<ntha) {
			if((t>300)&(t<500)){
				restthag[i]+=g(isthalg[i]/2000);	restthad[i]+=g(isthald[i]/2000);
			}
			fthag[0][i]+=(-fthag[0][i]+g(isthalg[i]))*dt;
			fthad[0][i]+=(-fthad[0][i]+g(isthald[i]))*dt;
		}
	}
	i=1;
	fmoystrg+=g(isstrg[i])/tpsmoy; fmoystng+=g(isstng[i])/tpsmoy;
	fmoythag+=g(isthalg[i])/tpsmoy; fmoygpeg+=g(isgpeg[i])/tpsmoy;
	fmoystrd+=g(isstrd[i])/tpsmoy; fmoystnd+=g(isstnd[i])/tpsmoy;
	fmoythad+=g(isthald[i])/tpsmoy; fmoygped+=g(isgped[i])/tpsmoy;

	for(i=0;i<n;i++){
		if(i<nctx){
			fmoyctxg[i]+=g(isctxg[i])/tpsmoy;		fmoyctxd[i]+=g(isctxd[i])/tpsmoy;
		}
		if(i<ngpi){
			fmoygpig[i]+=g(isgpig[i])/tpsmoy;		fmoygpid[i]+=g(isgpid[i])/tpsmoy;
		}
	}
	if((temp1>tpsmoy-1)){													//fichiers unit: activité unitaire dans GPi et ctx pour nunit neurones
		temp1=0; 				//calcul des moyennes temporelles d'activités et ecriture dans unitg et unitd.
		fprintf(tunitg,"%f  %f  %f  %f  %f  %f  %f\n", t*5, 200*g(fmoystrg), 200*g(fmoygpig[1]), 200*g(fmoyctxg[1]), 200*g(fmoythag), 200*g(fmoystng), 200*g(fmoygpeg));
		fprintf(tunitd,"%f  %f  %f  %f  %f  %f  %f\n", t*5, 200*g(fmoystrd), 200*g(fmoygpid[1]), 200*g(fmoyctxd[1]), 200*g(fmoythad), 200*g(fmoystnd), 200*g(fmoygped));
		fmoystrg=0; fmoystng=0; fmoystrd=0; fmoystnd=0;
		fmoythag=0; fmoygpeg=0; fmoythad=0; fmoygped=0;
		fprintf(tunitgpig,"\n%f	 ",5*t); fprintf(tunitctxg,"\n%f	 ",5*t);
		fprintf(tunitgpid,"\n%f	 ",5*t); fprintf(tunitctxd,"\n%f	 ",5*t);
		for(i=0; i<n; i++){														//fichiers unit: activité unitaire dans GPi et ctx pour nunit neurones
			fprintf(tunitgpig,"%f	 ", 200*g(fmoygpig[i]));	fprintf(tunitctxg,"%f	 ", 200*g(fmoyctxg[i]));
			fprintf(tunitgpid,"%f	 ", 200*g(fmoygpid[i]));	fprintf(tunitctxd,"%f	 ", 200*g(fmoyctxd[i]));
			fmoyctxg[i]=0;			fmoygpig[i]=0;
			fmoyctxd[i]=0;			fmoygpid[i]=0;
		}
	}

	moyctxg=0; moystrg=0; moystng=0; 				//calcul des moyennes de population des
	moygpig=0; moythag=0; moygpeg=0; 				//activités et ecriture dans evolg et evold.
	moyctxd=0; moystrd=0; moystnd=0; 				//(moyennes à partir des inputs seuillés=FR)
	moygpid=0; moythad=0; moygped=0;
	for(i=0;i<nmoy;i++){
		j=floor(nctx/nmoy)*i; moyctxg+=g(isctxg[j])/nmoy; moyctxd+=g(isctxd[j])/nmoy;
		j=floor(nstr/nmoy)*i; moystrg+=g(isstrg[j])/nmoy; moystrd+=g(isstrd[j])/nmoy;
		j=floor(nstn/nmoy)*i; moystng+=g(isstng[j])/nmoy; moystnd+=g(isstnd[j])/nmoy;
		j=floor(ngpi/nmoy)*i; moygpig+=g(isgpig[j])/nmoy; moygpid+=g(isgpid[j])/nmoy;
		j=floor(ntha/nmoy)*i; moythag+=g(isthalg[j])/nmoy; moythad+=g(isthald[j])/nmoy;
		j=floor(ngpe/nmoy)*i; moygpeg+=g(isgpeg[j])/nmoy; moygped+=g(isgped[j])/nmoy;
	}
	fprintf(tevolg,"%f  %f  %f  %f  %f  %f  %f\n", t*5, 200*moystrg, 200*moygpig, 200*moyctxg, 200*moythag, 200*moystng, 200*moygpeg);
	fprintf(tevold,"%f  %f  %f  %f  %f  %f  %f\n", t*5, 200*moystrd, 200*moygpid, 200*moyctxd, 200*moythad, 200*moystnd, 200*moygped);

	t=t+dt; temp1+=1;
}
	for(i=0;i<n;i++){						//profil d'activité au temps final, ecrit dans profilg et profild
		fprintf(tprofilg,"%f  %f  %f  %f  %f  %f  %f  %f\n", 200*reststrg[i], 200*restgpig[i], 200*restctxg[i], 200*restthag[i], 200*reststng[i], 200*restgpeg[i], 200*fmoygpig_mvt[i], 200*fmoyctxg_mvt[i]);
		fprintf(tprofild,"%f  %f  %f  %f  %f  %f  %f  %f\n", 200*reststrd[i], 200*restgpid[i], 200*restctxd[i], 200*restthad[i], 200*reststnd[i], 200*restgped[i], 200*fmoygpid_mvt[i], 200*fmoyctxd_mvt[i]);
	}
	fclose(tunitg);
	fclose(tunitgpig);	fclose(tunitctxg);
	fclose(tevolg);
	fclose(tprofilg);
	fclose(tunitd);
	fclose(tunitgpid);	fclose(tunitctxd);
	fclose(tevold);
	fclose(tprofild);
	fclose(tinput);
}
fclose(tp);
	for(i=0; i<20; i++){
		free(fstrg[i]);
		free(fstng[i]);
		free(fgpig[i]);
		free(fgpeg[i]);
		free(fthag[i]);
		free(fctxg1[i]);
		free(fctxg2[i]);
		free(fstrd[i]);
		free(fstnd[i]);
		free(fgpid[i]);
		free(fgped[i]);
		free(fthad[i]);
		free(fctxd1[i]);
		free(fctxd2[i]);
		}
	for(i=0; i<400; i++){
		free(Gstrctxg[i]);
		free(Gstrg1[i]);
		free(Ggpistrg[i]);
		free(Ggpig1[i]);
		free(Gthagpig[i]);
		free(Gctxthag[i]);
		free(Ggpigpeg[i]);
		free(Ggpestrg[i]);
		free(Ggpestng[i]);
		free(Gstngpeg[i]);
		free(Gstnctxg[i]);
		free(Gctxg1[i]);
		free(Ggpistng[i]);
		free(Gstrctxd[i]);
		free(Gstrd1[i]);
		free(Ggpistrd[i]);
		free(Ggpid1[i]);
		free(Gthagpid[i]);
		free(Gctxthad[i]);
		free(Ggpigped[i]);
		free(Ggpestrd[i]);
		free(Ggpestnd[i]);
		free(Gstngped[i]);
		free(Gstnctxd[i]);
		free(Ggpistnd[i]);
		free(Gctxd1[i]);
		}
/*	for(i=0; i<11; i++){
	//	free(evolg[i]);
		free(evold[i]);
		free(profilg[i]);
		free(profild[i]);
		free(unitg[i]);
		free(unitd[i]);
		}*/

free(v1);
free(v3);
	free(bgctxg);
	free(bgctxd);
	free(reststrg);
	free(reststng);
	free(restgpig);
	free(restgpeg);
	free(restctxg);
	free(restthag);
	free(istr);
	free(istn);
	free(igpi);
	free(igpe);
	free(ictx);
	free(ithal);
	free(istrg);
	free(istng);
	free(igpig);
	free(igpeg);
	free(ictxg);
	free(ithalg);
	free(isstrg);
	free(isstng);
	free(isgpig);
	free(isgpeg);
	free(isctxg);
	free(isthalg);
	free(fstrg);
	free(fstng);
	free(fgpig);
	free(fthag);
	free(fgpeg);
	free(fctxg1);
	free(fctxg2);
 	free(fmoygpig_repos);
 	free(fmoygpig_mvt);
 	free(fmoyctxg_repos);
 	free(fmoyctxg_mvt);
	free(reststrd);
	free(reststnd);
	free(restgpid);
	free(restgped);
	free(restctxd);
	free(restthad);
	free(istrd);
	free(istnd);
	free(igpid);
	free(igped);
	free(ictxd);
	free(ithald);
	free(isstrd);
	free(isstnd);
	free(isgpid);
	free(isgped);
	free(isctxd);
	free(isthald);
	free(fstrd);
	free(fstnd);
	free(fgpid);
	free(fthad);
	free(fgped);
	free(fctxd1);
	free(fctxd2);
 	free(fmoygpid_repos);
 	free(fmoygpid_mvt);
 	free(fmoyctxd_repos);
 	free(fmoyctxd_mvt);
	free(Gstrctxg);
	free(Gstrg1);
	free(Ggpistrg);
	free(Ggpig1);
	free(Gthagpig);
	free(Gctxthag);
	free(Ggpigpeg);
	free(Ggpestrg);
	free(Ggpestng);
	free(Gstngpeg);
	free(Gstnctxg);
	free(Gctxg1);
	free(Ggpistng);
	free(Gstrctxd);
	free(Gstrd1);
	free(Ggpistrd);
	free(Ggpid1);
	free(Ggpestrd);
	free(Ggpigped);
	free(Gctxthad);
	free(Ggpestnd);
	free(Gstngped);
	free(Gstnctxd);
	free(Gctxd1);
	free(Ggpistnd);
	free(Gthagpid);
	free(evolg);
	free(evold);
	free(profilg);
	free(profild);
	free(unitg);
	free(unitd);

return -1;
}

