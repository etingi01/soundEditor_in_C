/* <ep.c>
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


/**@file ep.h
 * @brief Ylopoihmeni sinartisi pou afairei to
 * 			prwto kommati ixou apo to deftero.
 * 			Me afton ton tropo ta dyo arxeia ixou paizontai se
 * 			ena koino arxeio TAFTOXRONA -to ena panw sto allo.
 *
 * @author Evanthia Tingiri (948282)
 *
 * @bug No known bugs.
 */
#include "ep.h"

void readFileIn(char **argv){
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
	samples=(DATA*)malloc(sizeof(DATA)*((d->subChunk2Size)));
	if (samples==NULL){
		printf("System out of memory!\n");
		exit(-1);
	}
	fread(samples,f->bitsPerSample/8, (d->subChunk2Size),fp);
	r->chunkID[4]='\0';
	f->subchunkID[4]='\0';
	FILE *f2;
	RIFF *rs;
	rs=(RIFF*)malloc(sizeof(RIFF));
	if (rs==NULL){
		printf("System out of memory!\n");
		exit(-1);
	}
	FMT_SUB *fs=NULL;
	fs=(FMT_SUB*)malloc(sizeof(FMT_SUB));
	if (fs==NULL){
		printf("System out of memory!\n");
		exit(-1);
	}
	DATA_SUB *ds=NULL;
	ds=(DATA_SUB*)malloc(sizeof(DATA_SUB));
	if (ds==NULL){
		printf("System out of memory!\n");
		exit(-1);
	}
	f2=fopen(argv[3],"r");
	DATA *samples_s = NULL;
	/*Diavasma defterou arxeiou*/
	fread(rs,sizeof(RIFF),1,f2);
	fread(fs,sizeof(FMT_SUB),1,f2);
	fread(ds,sizeof(DATA_SUB),1,f2);
	samples_s=(DATA*)malloc(sizeof(DATA)*((ds->subChunk2Size)));
	if (samples_s==NULL){
		printf("System out of memory!\n");
		exit(-1);
	}
	fread(samples_s,fs->bitsPerSample/8, (ds->subChunk2Size),f2);
	rs->chunkID[4]='\0';
	fs->subchunkID[4]='\0';
	/*Aparaititoi elegxoi gia omoiotita twn arxeiwn*/
	if((f->numChannels!=fs->numChannels)||(f->bitsPerSample!=fs->bitsPerSample)){
		printf("Den mporei na ginei i sinenwsi giati edwses diaforetiko tipo arxeiwn!\n\n");
		return;
	}
	int mal = max(d->subChunk2Size,ds->subChunk2Size);
	int x=0;int y=0;
	DATA *samplesNew = NULL;
	samplesNew=(DATA*)malloc(sizeof(DATA)*mal);
	if (samplesNew==NULL){
		printf("System out of memory!\n");
		exit(-1);
	}
	for (y=0; y<mal; y++){
		samplesNew[y]=0;
	}
	y=0;int j=0;
	while(x<mal){
		/*Ean kapoio apo ta dyo arxeia exei eggrafei sto kainourgio olokliro
		 * ginetai elegxos gia na sinexisei na eggrafetai apo tin arxi.
		 */
		if(y==ds->subChunk2Size)
			y=0;
		if(j==d->subChunk2Size)
			j=0;
		samplesNew[x]=samples[j]-samples_s[y];
		x++;
		y++;
		j++;
	}
	FILE *n;
	char name[strlen(argv[2])+8];
	strcpy(name,"merged-");
	strcat(name,argv[2]);
	n=fopen(name,"w");
	fs->subchunkSize=16;
	ds->subChunk2Size=max(d->subChunk2Size,ds->subChunk2Size);
	/*Eggrafi tou kainourgiou arxeiou*/
	fwrite(rs,sizeof(RIFF),1,n);
	fwrite(fs,sizeof(FMT_SUB),1,n);
	fwrite(ds,sizeof(DATA_SUB),1,n);
	fwrite(samplesNew,sizeof(DATA)*f->bitsPerSample/8,mal,n);
	/*Apeleftherwsi dinamika desmevmenis mnimis*/
	free(r);
	free(f); free(d); free(samples); free(rs); free(fs); free(ds);
	free(samples_s); free(samplesNew);
}
