/* <fifth.c>
 * Copyright (C) <2013> <Evanthia Tingiri>
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * Υou should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */


/**@file fifth.h
 * @brief Ylopoihmeni sinartisi gia ti sigkrisi
 * 			dyo arxeiwn .wav
 *
 * @author Evanthia Tingiri (948282)
 *
 * @bug No known bugs.
 */
#include "fifth.h"


void diavasmaPrwtouArxeiou(char **argv){
	if (argv[2]=='\0'){
		printf("Den edwses swsto arxeio!\n");
		return;
	}
	FILE *fp;
	RIFF *r;
	r=(RIFF*)malloc(sizeof(RIFF));
	if (r==NULL){
		printf("System out of memory!\n");
		exit(-1);
	}
	FMT_SUB *f=NULL;
	f=(FMT_SUB*)malloc(sizeof(FMT_SUB));
	if (f==NULL){
		printf("System out of memory!\n");
		exit(-1);
	}
	DATA_SUB *d=NULL;
	d=(DATA_SUB*)malloc(sizeof(DATA_SUB));
	if (d==NULL){
		printf("System out of memory!\n");
		exit(-1);
	}
	fp=fopen(argv[2],"r");
	DATA *samples = NULL;
	/*Diavasma prwtou arxeiou*/
	fread(r,sizeof(RIFF),1,fp);
	fread(f,sizeof(FMT_SUB),1,fp);
	fread(d,sizeof(DATA_SUB),1,fp);
	int sizeFirstFile=(d->subChunk2Size);//To megethos twn dedomenwn tou ixou
	samples=(DATA*)malloc(sizeof(DATA)*sizeFirstFile);
	if (samples==NULL){
		printf("System out of memory!\n");
		exit(-1);
	}
	fread(samples,f->bitsPerSample/8,(d->subChunk2Size),fp);
	r->chunkID[4]='\0';
	f->subchunkID[4]='\0';
	int file=3;
	/*Tha ekteleitai enoso iparxoun dosmena arxeia ixou sti grammi entolwn*/
	while (argv[file]!='\0'){
		readCoFile(argv,file,samples,sizeFirstFile,f);
		file++;
	}
	free(r);
	free(d);
	free(f);
	free(samples);

}
void readCoFile(char **argv, int j, DATA *samples,int sizeFirstFile, FMT_SUB *fmt){
	FILE *fp;
	RIFF *r;
	r=(RIFF*)malloc(sizeof(RIFF));
	if (r==NULL){
		printf("System out of memory!\n");
		exit(-1);
	}
	FMT_SUB *f=NULL;
	f=(FMT_SUB*)malloc(sizeof(FMT_SUB));
	if (f==NULL){
		printf("System out of memory!\n");
		exit(-1);
	}
	DATA_SUB *d=NULL;
	d=(DATA_SUB*)malloc(sizeof(DATA_SUB));
	if (d==NULL){
		printf("System out of memory!\n");
		exit(-1);
	}
	fp=fopen(argv[j],"r");
	DATA *co_samples = NULL;
	fread(r,sizeof(RIFF),1,fp);
	fread(f,sizeof(FMT_SUB),1,fp);
	fread(d,sizeof(DATA_SUB),1,fp);
	/*Aparaititoi elegxoi gia tin taftisi twn arxeiwn gia na mporei na ginei i sigkrisi*/
	if (fmt->bitsPerSample!=f->bitsPerSample){
		printf("To arxeio %s exei diaforetiko arithmo bitsPerSample apo to arxiko, opote den mporei na ginei i sigkrisi\n\n",argv[j]);
		return;
	}
	co_samples=(DATA*)malloc(sizeof(DATA)*(d->subChunk2Size));
	if (co_samples==NULL){
		printf("System out of memory!\n");
		exit(-1);
	}
	fread(co_samples,f->bitsPerSample/8, (d->subChunk2Size),fp);
	r->chunkID[4]='\0';
	f->subchunkID[4]='\0';
	int sizeCoFile=(d->subChunk2Size);
	double lcss,efklides;
	distance(samples, co_samples,sizeFirstFile,sizeCoFile,&lcss,&efklides);
	printf("Distance between %s and %s:\n\n",argv[2],argv[j]);
	printf("Euclidean distance: %.3f\nLCSS distance: %.3f\n",efklides,lcss);
	free(r);
	free(d);
	free(f);
	free(co_samples);
}


void distance(DATA *samples, DATA *co_samples,int sizeFirstFile,int sizeCoFile,double *lcss, double *efklides){
	int** array;
	int i,j;
	/*Dinamiki desmefsi mnimis enos pinaka 2*sizeFirstFile*/
	array = (int**) malloc((sizeFirstFile+1)*sizeof(int*));
	if (array==NULL){
		printf("System out of memory!\n");
		exit(-1);
	}
	for (i = 0; i <( sizeFirstFile+1); i++){
		array[i] = (int*) malloc(2*sizeof(int));
		if (array[i]==NULL){
			printf("System out of memory!\n");
			exit(-1);
		}
	}
	/* Arxikopoihsh aftou tou pinaka me 0.
	 * Aftos o pinakas tha vohthisei stin evresi tou mikous tis lcss.
	 */
	for(i=0; i<=sizeFirstFile; i++){
		for (j=0; j<2; j++)
			array[i][j]=0;
	}

	for(j=1; j<sizeCoFile+1; j++){
		/*Sti defteri stili tou pinaka apothikevontai oi ipologismoi*/
		for(i=1; i<sizeFirstFile+1; i++){
			if(co_samples[j-1]==samples[i-1])
				array[i][1]=array[i-1][0]+1;
			else{
				array[i][1]=max(array[i][0],array[i-1][1]);
			}

		}
		int d;
		/*I defteri stili antigrafetai stin prwti, gia na mporoun na sinexisoun
		 * panw tis meta oi ipologismoi, xwris omws na xathoun ta dedomena tis.
		 */
		for (d=0; d<=sizeFirstFile; d++){
						array[d][0]=array[d][1];
		}
	}
	double an = (array[sizeFirstFile-1][1]*1.0/min(sizeFirstFile,sizeCoFile));
	(*lcss)=1-an;
	int x=0;
	int y=0;
	long int sum=0;
	/*Evresi efklideias apostasis*/
	while ((x<sizeFirstFile)&&(y<sizeCoFile)){
		int s=samples[x];
		int c=co_samples[y];
		sum=sum+((abs(s-c))*(abs(s-c)));
		x++;
		y++;
	}
	(*efklides)=sqrt(sum);
	free(array);
}

int min(int a, int b){
	if (a<b)
		return a;
	else
		return b;
}

int max(int a, int b){
	if (a>b)
		return a;
	else
		return b;
}
