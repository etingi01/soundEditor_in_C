/* <second.c>
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



/**@file second.h
 * @brief Ylopoihmeni sinartisi gia tin metatropi enos
 * 			stereofwnikou arxeiou .wav se monofwniko.
 *
 * @author Evanthia Tingiri (948282)
 *
 * @bug No known bugs
 *
 */

#include "second.h"

void monoChannel(char **argv,int i){
	if (argv[i]=='\0')
		return;
	FILE *fp;
	fp=fopen(argv[i],"r");
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
	DATA *samples =NULL;
	/*Diavasma tou arxeiou*/
	fread(r,sizeof(RIFF),1,fp);
	fread(f,sizeof(FMT_SUB),1,fp);
	fread(d,sizeof(DATA_SUB),1,fp);
	int arithmosSam=(d->subChunk2Size);
	samples=(DATA*)malloc(sizeof(DATA)*(d->subChunk2Size));
	if (samples==NULL){
		printf("System out of memory!\n");
		exit(-1);
	}
	fread(samples,f->bitsPerSample/8, (d->subChunk2Size),fp);
	r->chunkID[4]='\0';
	f->subchunkID[4]='\0';

	printf("SubChunk2 arxiko: %d\n\n",d->subChunk2Size);
	if (f->numChannels==1){
		printf("To arxeio %s einai hdh monofwniko!\n",argv[i]);
		monoChannel(argv,(i+1));
	}
	else{
		char newwav[strlen(argv[i])+4];
		strcpy(newwav,"new-");
		strcat(newwav,argv[i]);
		FILE *fnew;
		fnew=fopen(newwav,"w");
		/*Aparaitites allages afou tha metatrapei se mwnofwniko*/
		f->numChannels=1;
		f->byteRate=f->byteRate/2;
		f->blockAlign=f->blockAlign/2;
		d->subChunk2Size=d->subChunk2Size/2;
		f->subchunkSize=16;

		DATA *samplesNew =NULL;
		samplesNew=(DATA*)malloc(sizeof(DATA)*(arithmosSam));
		int counter=arithmosSam/2;
		int var;
		int dif=2;
		/*Antigrafi mono aristerou kanaliou*/
		for (var=0; var<counter; var++){
			samplesNew[var]=samples[dif];
			dif=dif+2;
		}
		/*Eggrafi tou monofwnikou arxeiou*/
		fwrite(r,sizeof(RIFF),1,fnew);
		fwrite(f,sizeof(FMT_SUB),1,fnew);
		fwrite(d,sizeof(DATA_SUB),1,fnew);
		fwrite(samplesNew,sizeof(DATA)*(f->bitsPerSample/8),arithmosSam/2,fnew);
		free(samplesNew);
		fclose(fnew);
	}
	fclose(fp);
	free(r);
	free(f);
	free(d);
	free(samples);
	monoChannel(argv,(i+1));
}
