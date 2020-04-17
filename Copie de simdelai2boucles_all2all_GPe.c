#include  <stdio.h>
#include <math.h>
/*#include <unistd.h>*/
#include <fcntl.h>

double g(double x){
	if (x>0) return x;
	else return 0;
}

main(){
	int i, j, k, m, Dstrctx, Dgpistr, Dthagpi, Dctxtha, Dgpigpe, Dgpestr, Dgpestn, Dstngpe, Dstnctx, Dgpistn;
	double t, tf, tps_mvt, eps, Gp, Gm, Gstrctxg0, Ggpistrg0, Gthagpig0, Gctxthag0, Ggpigpeg0, Ggpestrg0, Ggpestng0, Gstngpeg0, Gstnctxg0, Ggpistng0, Gstrg10, Ggpig10, Gctxg10, istrg, igpig, igpeg, ictxg, ithalg, fstrg[20], fgpig[20], fgpeg[20], fctxg1[20], fctxg2[20], fthag[20], dt, pi, isstrg, isgpig, isgpeg, isctxg, isthalg, Gstrctxg, Gstrgl, Ggpistrg, Ggpigl, Gthagpig, Gctxthag, Ggpigpeg, Ggpestrg, Ggpestng, Gstngpeg, Gstnctxg, Ggpistng, Gctxgl, isctxextg, isstng, istng, fstng[20], itemp, Gstrctxd0, Ggpistrd0, Gthagpid0, Gctxthad0, Ggpigped0, Ggpestrd0, Ggpestnd0, Gstngped0, Gstnctxd0, Ggpistnd0, Gstrd10, Ggpid10, Gctxd10, istrd, igpid, igped, ictxd, ithald, fstrd[20], fgpid[20], fgped[20], fctxd1[20], fctxd2[20], fthad[20], isstrd, isgpid, isgped, isctxd, isthald, Gstrctxd, Gstrdl, Ggpistrd, Ggpidl, Gthagpid, Ggpigped, Ggpestrd, Ggpestnd, Gstngped, Gctxthad, Gctxdl, isctxextd, isstnd, istnd, fstnd[20], Gstnctxd, Ggpistnd, gamma;
	FILE *tubd, *tubg;

	pi=3.14159265; dt=.1; tf=1000; t=0;	tps_mvt=100; gamma=0.4;	eps=0;								/*couplage*/
	Dstrctx=12; Dgpistr=19; Dthagpi=10; Dctxtha=10;Dstnctx=10;Dgpistn=10;	/*Valeur des delais*/
	Dgpigpe=0; Dgpestr=0; Dgpestn=0; Dstngpe=0;

	Gstrctxd0=.8; Ggpistrd0=12.14; Gthagpid0=0.3; Gctxthad0=.969;Gstnctxd0=2;Ggpistnd0=4.9;	/*boucle 1 (de droite)*/
	Ggpigped0=0; Ggpestrd0=0; Ggpestnd0=0; Gstngped0=0;
	Gstrd10=0; Ggpid10=0; Gctxd10=0;
	istrd=0.0; igpid=-0.09; ictxd=-0.128; ithald=0.25; istnd=0.1; igped=0;

	Gstrctxg0=.8; Ggpistrg0=12.14; Gthagpig0=0.3; Gctxthag0=.969;Gstnctxg0=2;Ggpistng0=4.9;	/*boucle 2 (de gauche)*/
	Ggpigpeg0=0; Ggpestrg0=0; Ggpestng0=0; Gstngpeg0=0.;
	Gstrg10=0; Ggpig10=0; Gctxg10=0;
	istrg=0.0; igpig=-0.09; ictxg=-0.128; ithalg=0.25; istng=0.1; igpeg=0;
//	istrg=0.0; igpig=0.2; ictxg=-0.02; /*ictxd*(1+eps)/(1-eps);*/ ithalg=0.3; istng=0.1; igpeg=0.;

	Gp=Gctxthad0*Gthagpid0*Ggpistrd0*Gstrctxd0;
	Gm=Gctxthad0*Gthagpid0*Ggpistnd0*Gstnctxd0;
	printf("G+: %f   G-: %f\n", Gp, Gm);

	tubd=fopen("evold.tab","w");
	tubg=fopen("evolg.tab","w");

	fstng[0]=0; fstrg[0]=0; fgpig[0]=0.333333333; fctxg1[0]=0; fctxg2[0]=0; fthag[0]=0;	/*conditions initiales*/
	fstnd[0]=0; fstrd[0]=0; fgpid[0]=0.333333333; fctxd1[0]=0; fctxd2[0]=0; fthad[0]=0;

	for(i=1; i<20; i++){
		fstrg[i]=fstrg[0];
		fctxg1[i]=fctxg1[0];
		fctxg2[i]=fctxg2[0];
		fgpig[i]=fgpig[0];
		fthag[i]=fthag[0];
		fstng[i]=fstng[0];
		fgpeg[i]=fgpeg[0];

		fstrd[i]=fstrd[0];
		fctxd1[i]=fctxd1[0];
		fctxd2[i]=fctxd2[0];
		fgpid[i]=fgpid[0];
		fthad[i]=fthad[0];
		fstnd[i]=fstnd[0];
		fgped[i]=fgped[0];
	}
	Gstrctxd=Gstrctxd0;
	Gstrdl=-Gstrd10;
	Ggpistrd=-Ggpistrd0;
	Ggpidl=-Ggpid10;
	Gthagpid=-Gthagpid0;
	Gctxdl=Gctxd10;
	Gctxthad=Gctxthad0;
	Ggpestrd=-Ggpestrd0;
	Ggpigped=-Ggpigped0;
	Ggpestnd=Ggpestnd0;
	Gstngped=-Gstngped0;
	Gstnctxd=Gstnctxd0;
	Ggpistnd=Ggpistnd0;

	Gstrctxg=Gstrctxg0;
	Gstrgl=-Gstrg10;
	Ggpistrg=-Ggpistrg0;
	Ggpigl=-Ggpig10;
	Gthagpig=-Gthagpig0;
	Gctxgl=Gctxg10;
	Gctxthag=Gctxthag0;
	Ggpestrg=-Ggpestrg0;
	Ggpigpeg=-Ggpigpeg0;
	Ggpestng=Ggpestng0;
	Gstngpeg=-Gstngpeg0;
	Gstnctxg=Gstnctxg0;
	Ggpistng=Ggpistng0;

while(t<tf){
	isstng=(Gstnctxg*fctxg1[Dstnctx]+Gstngpeg*fgpeg[Dstngpe]+istng);			/*calcul des courants*/
	isstnd=(Gstnctxd*fctxd1[Dstnctx]+Gstngped*fgped[Dstngpe]+istnd);

	if((t>500)&(t<500.2)){
		istrg+=.0005;
		istrd-=.0005;
	}
	if((t>500+tps_mvt/5)&(t<500.2+tps_mvt/5)){
		istrg-=.0005;
		istrd+=.0005;
	}
	isctxg=(Gctxthag*fthag[Dctxtha]+Gctxgl*fctxg1[0]+ictxg);
	isctxd=(Gctxthad*fthad[Dctxtha]+Gctxdl*fctxd1[0]+ictxd);

	if((t>500)&(t<500+tps_mvt)){
		isctxg+=.1*pow(cos((t-(500+tps_mvt/2))*pi/tps_mvt),2);
		isctxd+=.1*pow(cos((t-(500+tps_mvt/2))*pi/tps_mvt),2);
		}

	isstrg=(Gstrctxg*fctxg2[Dstrctx]+Gstrgl*fstrg[0]+istrg);
	isstrd=(Gstrctxd*fctxd2[Dstrctx]+Gstrdl*fstrd[0]+istrd);

	isgpig=(Ggpistrg*fstrg[Dgpistr]+Ggpigpeg*fgpeg[2]+Ggpigl*fgpig[0]+(1-gamma)*Ggpistng*fstng[Dgpistn]+gamma*Ggpistng*fstnd[Dgpistn]+igpig);
	isgpid=(Ggpistrd*fstrd[Dgpistr]+Ggpigped*fgped[2]+Ggpidl*fgpid[0]+(1-gamma)*Ggpistnd*fstnd[Dgpistn]+gamma*Ggpistnd*fstng[Dgpistn]+igpid);

	isgpeg=(Ggpestrg*fstrg[Dgpestr]+Ggpestng*fstng[Dgpestn]+igpeg);
	isgped=(Ggpestrd*fstrd[Dgpestr]+Ggpestnd*fstnd[Dgpestn]+igped);

	isthalg=(Gthagpig*fgpig[Dthagpi]+ithalg);
	isthald=(Gthagpid*fgpid[Dthagpi]+ithald);
	//if(t/dt<20){printf("%f, %f, %f, %f, %f \n",isgpid,isgped, fgped[0], Ggpidl*fgpid[0], (1-gamma)*Ggpistnd*fstnd[delain]);}*/

	for(k=19;k>0;k--){					/*calcul des frequences*/
		fctxg1[k]=fctxg1[k-1];				/*cortex*/
		fctxd1[k]=fctxd1[k-1];
	}
	fctxg1[0]+=(-fctxg1[0]+g(isctxg))*dt/4;
	fctxd1[0]+=(-fctxd1[0]+g(isctxd))*dt/4;
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
	for(k=19;k>0;k--){
		fgpeg[k]=fgpeg[k-1];				/*GPe*/
		fgped[k]=fgped[k-1];
	}
	fgpeg[0]+=(-fgpeg[0]+g(isgpeg))*dt;
	fgped[0]+=(-fgped[0]+g(isgped))*dt;
	for(k=19;k>0;k--){					/*thalamus*/
		fthag[k]=fthag[k-1];
		fthad[k]=fthad[k-1];
	}
	fthag[0]+=(-fthag[0]+g(isthalg))*dt;
	fthad[0]+=(-fthad[0]+g(isthald))*dt;

	t=t+dt;
	fprintf(tubg,"%f  %f  %f  %f  %f  %f  %f  %f  %f\n", t*5, 200*g(isstrg), 200*g(isgpig), 200*g(isctxg), 200*g(isthalg), 200*g(isstng), 200*g(isgpeg), 200*.07*pow(cos((t-(500+tps_mvt/2))*pi/tps_mvt),2), 200*istrg);
	fprintf(tubd,"%f  %f  %f  %f  %f  %f  %f  %f  %f\n", t*5, 200*g(isstrd), 200*g(isgpid), 200*g(isctxd), 200*g(isthald), 200*g(isstnd), 200*g(isgped), 200*.07*pow(cos((t-(500+tps_mvt/2))*pi/tps_mvt),2), 200*istrd);
}
}

