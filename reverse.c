/* <reverse.c>
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



/**@file reverse.h
 * @brief Ylopoihmeni sinartisi gia tin antistrofi tou ixou.
 *
 * @author Evanthia Tingiri (948282)
 *
 * @bug No known bugs
 *
 */

#include "reverse.h"


void reverseWav(char **argv, int i){
	if (argv[i]=='\0'){
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
	fp=fopen(argv[i],"r");
	DATA *samples = NULL;
	/*Diavasma arxeiou*/
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
	/*Kathorismos onomasias kainourgiou arxeiou*/
	char newwav[strlen(argv[i])+8];
	strcpy(newwav,"reverse-");
	strcat(newwav,argv[i]);
	FILE *fnew;
	fnew=fopen(newwav,"w");
	DATA *Newsamples =NULL;
	f->subchunkSize=16;
	Newsamples=(DATA*)malloc(sizeof(DATA)*((d->subChunk2Size)));
	int max=(d->subChunk2Size);
	int j=0;
	/*Antigrafi twn bytes tou arxeiou alla ksekinwntas apo to telos*/
	while(max>=0){
			Newsamples[j]=samples[max];
			max--;
			j++;
	}
	/*eggrafi tou arxeiou*/
	fwrite(r,sizeof(RIFF),1,fnew);
	fwrite(f,sizeof(FMT_SUB),1,fnew);
	fwrite(d,sizeof(DATA_SUB),1,fnew);
	fwrite(Newsamples,sizeof(DATA)*f->bitsPerSample/8,(d->subChunk2Size),fnew);
	free(r);
	free(f);
	free(d);
	free(samples);
	free(Newsamples);
	reverseWav(argv,(i+1));

}
