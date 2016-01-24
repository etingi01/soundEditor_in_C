/* <enallagi.c>
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



/**@file enallagi.h
 * @brief Ylopoihmeni sinartisi gia ti sinenwsi 2 arxeiwn hxou
 * 			pou tha paizontai enallaks.
 *
 * @author Evanthia Tingiri (948282)
 *
 * @bug No known bugs.
 */

#include "enallagi.h"

void enallages(char **argv){
	FILE *fp;
	fp=fopen(argv[2],"r");
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
	f->subchunkSize=16;

	FILE *fc;
	fc=fopen(argv[3],"r");
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

	DATA *samples_s = NULL;
	/*Diavasma defterou arxeiou*/
	fread(rs,sizeof(RIFF),1,fc);
	fread(fs,sizeof(FMT_SUB),1,fc);
	fread(ds,sizeof(DATA_SUB),1,fc);
	samples_s=(DATA*)malloc(sizeof(DATA)*((ds->subChunk2Size)));
	if (samples_s==NULL){
	   printf("System out of memory!\n");
	   exit(-1);
	}

	fread(samples_s,fs->bitsPerSample/8, (ds->subChunk2Size),fc);
	rs->chunkID[4]='\0';
	fs->subchunkID[4]='\0';
	fs->subchunkSize=16;

	/*H leitourgia afti tha ekteleitai gia arxeia megalitera twn 8 defteroleptwn*/
	if(((d->subChunk2Size/f->byteRate)<8)||((ds->subChunk2Size/fs->byteRate)<8)){
		printf("Edwses arxeia mikrotera twn 8 defteroleptwn!!\n\n");
		return;
	}
	DATA *snew=NULL;
	int size=(ds->subChunk2Size)+(d->subChunk2Size);
	snew=(DATA*)malloc(sizeof(DATA)*((ds->subChunk2Size)+(d->subChunk2Size)));
	if (snew==NULL){
	   printf("System out of memory!\n");
	   exit(-1);
	}

	int i=0; int y=0; int x=0;
	int k=0;int j=0;
	/*Loop opou tha ginetai i enallagi*/
	while(i<size){
		x=0;
		y=0;

		while(x<f->bitsPerSample*f->sampleRate*f->numChannels){
			/*Elegxos apofigis segmentation fault*/
			if((x+k)>d->subChunk2Size){
				break;
			}
		snew[i+x]=samples[x+k];
		x++;
		}
		k=k+x;
		while(y<f->bitsPerSample*f->sampleRate*f->numChannels){
			/*Elegxos apofigis segmentation fault*/
			if((j+y)>ds->subChunk2Size){
				break;
			}
		snew[i+x+y]=samples_s[j+y];
		y++;
		}
		j=j+y;
		if(((j)>ds->subChunk2Size)||(k>d->subChunk2Size)){
			i=i+f->sampleRate*f->numChannels*f->bitsPerSample;
		}else
		i=i+2*f->sampleRate*f->numChannels*f->bitsPerSample;
	}

	f->subchunkSize=16;
	FILE *fd;
	char dia[strlen(argv[2])+10];
	strcpy(dia,"enallagi-");
	strcat(dia,argv[2]);
	fd=fopen(dia,"w");
	/*Eggrafi arxeiou ixou*/
	fwrite(r,sizeof(RIFF),1,fd);
	fwrite(f,sizeof(FMT_SUB),1,fd);
	fwrite(d,sizeof(DATA_SUB),1,fd);
	fwrite(snew,sizeof(DATA)*f->bitsPerSample/8,d->subChunk2Size,fd);
	/*Apeleftherwsi dinamika desmevme