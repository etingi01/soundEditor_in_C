/* <prosthesi.c>
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



/**@file prosthesi.h
 * @brief Ylopoihmeni sinartisi gia tin ektelesi enos arxeiou
 * 			diakoptomena, me pafseis.
 *
 * @author Evanthia Tingiri (948282)
 *
 * @bug Se sxolia einai i entoli free(samples) giati gia ena
 * 		parakseno logo, otan itan energopoihmeni, an kai
 * 		den ipirxe provlima sti metaglwtisi den mporouse na
 * 		ektelestei i leitourgia kata tin ektelesi.
 *
 */

#include "prosthesi.h"

void effect(char **argv, int l){
	if (argv[l]=='\0'){
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

	fp=fopen(argv[l],"r");
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
	f->subchunkSize=16;

	DATA *samplesN = NULL;
	samplesN=(DATA*)malloc(sizeof(DATA)*((d->subChunk2Size)));
	if (samplesN==NULL){
	   printf("System out of memory!\n");
	   exit(-1);
	}

	int i=0;
	byte j=0;
	byte x=0;
	int y=0;
	int k=0;
	while(i<d->subChunk2Size){
		int x=0;
		/*Antigrafi kapoiwn bytes*/
		while(x<f->sampleRate*f->numChannels){
		samplesN[i+x]=samples[i+x];
		x++;
		}
		int y=0;
		/*Midenismos kapown bytes*/
		while(y<f->sampleRate*f->numChannels){
		samplesN[i+x+y]=0;
		y++;
		}
		i=i+2*f->sampleRate*f->numChannels;
	}
	FILE *fd;
	char dia[strlen(argv[l])+14];
	strcpy(dia,"diakoptomeno-");
	strcat(dia,argv[l]);
	fd=fopen(dia,"w");
	/*Eggrafi sto kainourgio arxeio*/
	fwrite(r,sizeof(RIFF),1,fd);
	fwrite(f,sizeof(FMT_SUB),1,fd);
	fwrite(d,sizeof(DATA_SUB),1,fd);
	fwrite(samplesN,sizeof(DATA)*f->bitsPerSample/8,(d->subChunk2Size),fd);
	fclose(fd);
	fclose(fp);
	free(r);
	free(f);
	free(d);
//	free(samples);
	free(samplesN);
	effect(argv,(l+1));
}
