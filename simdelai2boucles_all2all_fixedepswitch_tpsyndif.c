#include  <stdio.h>
#include <math.h>
/*#include <unistd.h>*/
#include <fcntl.h>

double g(double x){
	if (x>0) return x;
	else return 0;
}
double sign(double x){
	return x/fabs(x);
}
main(){
	int i, j, k, m, Dstrctx, Dgpistr, Dthagpi, Dctxtha, Dstnctx, Dgpistn;
	double a, error, t, tf, to, temp, itempo, eps, Gm, Gp, control1, control2, control3, ictxmin, mstr0, mstn0, mstr1, mstn1, mtha10, mtha0, mtha1, mgpi0, mgpi10, mgpi1,mctx1, Gstrctx0, Ggpistr0, Gthagpi0, Gctxtha0, Gstnctx0, Ggpistn0, Gstr10, Ggpi10, Gctx10, istr, igpi, ictx, ithal, Gstrctxg0, Ggpistrg0, Gthagpig0, Gctxthag0, Gstnctxg0, Ggpistng0, Gstrg10, Ggpig10, Gctxg10, istrg, igpig, ictxg, ithalg, fstrg[20], fgpig[20], fctxg1[20], fctxg2[20], fthag[20], dt, pi, isstrg, isgpig, isctxg, isthalg, Gstrctxg, Gstrgl, Ggpistrg, Ggpigl, Gthagpig, Gctxthag, Gstnctxg, Ggpistng, Gctxgl, isctxextg, isstn, istn, isstng, istng, fstng[20], itemp, Gstrctxd0, Ggpistrd0, Gthagpid0, Gctxthad0, Gstnctxd0, Ggpistnd0, Gstrd10, Ggpid10, Gctxd10, istrd, igpid, ictxd, ithald, fstrd[20], fgpid[20], fctxd1[20], fctxd2[20], fthad[20], isstrd, isgpid, isctxd, isthald, Gstrctxd, Gstrdl, Ggpistrd, Ggpidl, Gthagpid, Gctxthad, Gctxdl, isctxextd, isstnd, istnd, fstnd[20], Gstnctxd, Ggpistnd, gamma;
	FILE *tab, *tubd, *tubg;
	tubd=fopen("evold.tab","w");
	tubg=fopen("evolg.tab","w");
	tab=fopen("tempscvg.tab","a");

	pi=3.14159265; dt=.1; tf=1000; t=0; temp=0; to=-1;
	Dstrctx=12; Dgpistr=19; Dthagpi=10; Dctxtha=10;Dstnctx=10;Dgpistn=10;	/*Valeur des delais*/
	gamma=0.3; eps=0.3; a=1.85;		/*Dopamine, couplage et diff d'input*/

	/*On fixe les valeurs des activités dans 0/0 et 0/1:*/
	mstr0=1; mstn0=20; mstr1=15; mstn1=60;	mctx1=20;
	mtha0=20; mtha1=30; mgpi0=70; mgpi10=125; mgpi1=40;

	fprintf(tab,"%f %f %f %f %f %f %f %f %f %f %f\n",mstr0,mstr1,mgpi0,mgpi1,mctx1,mtha0,mtha1,mstn0,mstn1,eps,gamma);

	while (mgpi10<130){
	error=0;
	mtha10=g(mtha0+(mtha1-mtha0)*(mgpi0-mgpi10)/(mgpi0-mgpi1));
	Gstrctx0=((mstr1-mstr0)/mctx1); Gstnctx0=(mstn1-mstn0)/mctx1;			/*gains et courants*/
	Ggpistr0=(mgpi0-mgpi1+(1-gamma)*(mgpi10-mgpi0)/gamma)/(mstr1-mstr0);
	Gthagpi0=(mtha1-mtha0)/(mgpi0-mgpi1);
	Ggpistn0=(mgpi10-mgpi0)/(gamma*(mstn1-mstn0));
	Gstr10=0; Ggpi10=0; Gctx10=0;		/*communs aux 2 boucles*/
	Gctxtha0=a/(Gthagpi0*(a*Ggpistr0*Gstrctx0-Ggpistn0*Gstnctx0));

	istr=mstr0/200; istn=mstn0/200;
	igpi=(mgpi0+Ggpistr0*mstr0-Ggpistn0*mstn0)/200;
	ithal=(mtha0+Gthagpi0*mgpi0)/200;
	ictxd=mctx1/200-Gctxtha0*(ithal-Gthagpi0*(igpi+Ggpistn0*istn-Ggpistr0*istr)+mctx1*Gthagpi0*(Ggpistr0*Gstrctx0-(1-gamma)*Ggpistn0*Gstnctx0)/200);

	if(ictxd*200+Gctxtha0*mtha10>0){
		printf("Pas d'état coupé!! \n");
		error=1;
	}
	ictxg=ictxd*(1+eps)/(1-eps);
	Gstrctx0=Gstrctx0;
	Gp=Gctxtha0*Gthagpi0*Ggpistr0*Gstrctx0;
	Gm=Gctxtha0*Gthagpi0*Ggpistn0*Gstnctx0;
	printf("G+: %f   G-: %f   ictx: %f  ctx10 sous seuil de  %f\n", Gp, Gm, ictxd, ictxd+Gctxtha0*mtha10/200);
	itempo=-(ithal-Gthagpi0*(igpi+Ggpistn0*istn-Ggpistr0*istr))/(Gthagpi0*(Ggpistr0*Gstrctx0-(1-gamma)*Ggpistn0*Gstnctx0));
	printf("test:CTX %f STR %f GPI %f THA %f CTX %f STN %f GPI\n", Gstrctx0, Ggpistr0, Gthagpi0, Gctxtha0, Gstnctx0, Ggpistn0);
	printf("istr    %f, istn    %f, igpi    %f, itha    %f, ictx    %f\n", istr, istn, igpi, ithal, ictxd);

	Gstrctxd0=Gstrctx0; Ggpistrd0=Ggpistr0; Gthagpid0=Gthagpi0; Gctxthad0=Gctxtha0;Gstnctxd0=Gstnctx0;Ggpistnd0=Ggpistn0;	/*boucle 1 (de droite)*/
	Gstrd10=Gstr10; Ggpid10=Ggpi10; Gctxd10=Gctx10;
	istrd=istr; igpid=igpi; ithald=ithal; istnd=istn;
	Gstrctxg0=Gstrctx0; Ggpistrg0=Ggpistr0; Gthagpig0=Gthagpi0; Gctxthag0=Gctxtha0;Gstnctxg0=Gstnctx0;Ggpistng0=Ggpistn0;	/*boucle 2 (de gauche)*/
	Gstrg10=Gstr10; Ggpig10=Ggpi10; Gctxg10=Gctx10;
	istrg=istr; igpig=igpi; ithalg=ithal; istng=istn;

	fstng[0]=0; fstrg[0]=0; fgpig[0]=0.333333333; fctxg1[0]=0; fctxg2[0]=0; fthag[0]=0;	/*conditions initiales*/
	fstnd[0]=0; fstrd[0]=0; fgpid[0]=0.333333333; fctxd1[0]=0; fctxd2[0]=0; fthad[0]=0;

	for(i=1; i<20; i++){
		fstrg[i]=fstrg[0];
		fctxg1[i]=fctxg1[0];
		fctxg2[i]=fctxg2[0];
		fgpig[i]=fgpig[0];
		fthag[i]=fthag[0];
		fstng[i]=fstng[0];

		fstrd[i]=fstrd[0];
		fctxd1[i]=fctxd1[0];
		fctxd2[i]=fctxd2[0];
		fgpid[i]=fgpid[0];
		fthad[i]=fthad[0];
		fstnd[i]=fstnd[0];
	}
	Gstrctxd=Gstrctxd0;
	Gstrdl=-Gstrd10;
	Ggpistrd=-Ggpistrd0;
	Ggpidl=-Ggpid10;
	Gthagpid=-Gthagpid0;
	Gctxdl=Gctxd10;
	Gctxthad=Gctxthad0;
	Gstnctxd=Gstnctxd0;
	Ggpistnd=Ggpistnd0;

	Gstrctxg=Gstrctxg0;
	Gstrgl=-Gstrg10;
	Ggpistrg=-Ggpistrg0;
	Ggpigl=-Ggpig10;
	Gthagpig=-Gthagpig0;
	Gctxgl=Gctxg10;
	Gctxthag=Gctxthag0;
	Gstnctxg=Gstnctxg0;
	Ggpistng=Ggpistng0;
	t=0;

while(t<tf){
	if((t>500)&(temp==0)){
		printf("%f \n",ictxd+Gctxtha0*mtha10/200);temp=1;
		ictxg=mctx1/200-Gctxtha0*(ithal-Gthagpi0*(igpi+Ggpistn0*istn-Ggpistr0*istr)+mctx1*Gthagpi0*(Ggpistr0*Gstrctx0-(1-gamma)*Ggpistn0*Gstnctx0)/200);
		ictxd=ictxg*(1+eps)/(1-eps);
	}
/*	if((t>2400)&(t<2401)){
		ictxg=-0.2;
		ictxd=-0.2;
	}*/
	isstng=(Gstnctxg*fctxg1[Dstnctx]+istng);			/*calcul des courants*/
	isstnd=(Gstnctxd*fctxd1[Dstnctx]+istnd);

	isctxg=(Gctxthag*fthag[Dctxtha]+Gctxgl*fctxg1[0]+ictxg);
/*	if((t>500)&(t<500.2)){
		isctxg+=7;
	}*/
	isctxd=(Gctxthad*fthad[Dctxtha]+Gctxdl*fctxd1[0]+ictxd);
/*	if((t>200)&(t<208)){
		isctxd+=0.1;
	}*/

	isstrg=(Gstrctxg*fctxg2[Dstrctx]+Gstrgl*fstrg[0]+istrg);
	isstrd=(Gstrctxd*fctxd2[Dstrctx]+Gstrdl*fstrd[0]+istrd);

	isgpig=(Ggpistrg*fstrg[Dgpistr]+Ggpigl*fgpig[0]+(1-gamma)*Ggpistng*fstng[Dgpistn]+gamma*Ggpistng*fstnd[Dgpistn]+igpig);
	isgpid=(Ggpistrd*fstrd[Dgpistr]+Ggpidl*fgpid[0]+(1-gamma)*Ggpistnd*fstnd[Dgpistn]+gamma*Ggpistnd*fstng[Dgpistn]+igpid);

	isthalg=(Gthagpig*fgpig[Dthagpi]+ithalg);
	isthald=(Gthagpid*fgpid[Dthagpi]+ithald);

	for(k=19;k>0;k--){					/*calcul des frequences*/
		fctxg1[k]=fctxg1[k-1];				/*cortex*/
		fctxd1[k]=fctxd1[k-1];
	};
	fctxd1[0]+=(-fctxd1[0]+g(isctxd))*dt/4;
	fctxg1[0]+=(-fctxg1[0]+g(isctxg))*dt/4;
	for(k=19;k>0;k--){					/*calcul des frequences*/
		fctxg2[k]=fctxg2[k-1];				/*cortex*/
		fctxd2[k]=fctxd2[k-1];
	}
	fctxg2[0]+=(-fctxg2[0]+g(isctxg))*dt;
	fctxd2[0]+=(-fctxd2[0]+g(isctxd))*dt;
	for(k=19;k>0;k--){
		fstng[k]=fstng[k-1];				/*STN*/
		fstnd[k]=fstnd[k-1];
	}
	fstng[0]+=(-fstng[0]+g(isstng))*dt;
	fstnd[0]+=(-fstnd[0]+g(isstnd))*dt;
	for(k=19;k>0;k--){
		fstrg[k]=fstrg[k-1];				/*striatum*/
		fstrd[k]=fstrd[k-1];
	}
		fstrg[0]+=(-fstrg[0]+g(isstrg))*dt;
		fstrd[0]+=(-fstrd[0]+g(isstrd))*dt;
	for(k=19;k>0;k--){
		fgpig[k]=fgpig[k-1];				/*GPi*/
		fgpid[k]=fgpid[k-1];
	}
	fgpig[0]+=(-fgpig[0]+g(isgpig))*dt;
	fgpid[0]+=(-fgpid[0]+g(isgpid))*dt;
	for(k=19;k>0;k--){					/*thalamus*/
		fthag[k]=fthag[k-1];
		fthad[k]=fthad[k-1];
	}
	fthag[0]+=(-fthag[0]+g(isthalg))*dt;
	fthad[0]+=(-fthad[0]+g(isthald))*dt;

	t=t+dt; if(fctxg1[0]>0.00001){to=t*5;}
	fprintf(tubg,"%f  %f  %f  %f  %f  %f  %f\n", t*5, 200*g(isstrg), 200*g(isgpig), 200*fctxg1[0], 200*g(isthalg), 200*g(isstng));
	fprintf(tubd,"%f  %f  %f  %f  %f  %f  %f\n", t*5, 200*g(isstrd), 200*g(isgpid), 200*g(isctxd), 200*g(isthald), 200*g(isstnd));
	}
if(error==0){
	printf("%f  %f  %f  %f  %f  %f  %f\n", Gp, Gm, ictxd, to, mtha10, mgpi10);
	/*printf("Tau: %f\n", to);*/
}
mgpi10=mgpi10+5;
}
}

