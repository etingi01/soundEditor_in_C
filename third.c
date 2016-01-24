/* <third.c>
 * Copyright (C) <2013> <Rafaella Louka>
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
 * @brief Ylopoihmeni sinartisi pou 'kovei' ena arxeiou 
 *        hxou .wav apo mia xroniki stigmi se mia alli.
 *
 * @author Rafaela Louka (949790)
 *
 * @bug No known bugs.
 *
 */


#include "third.h"

void ChopTrack(char **argv, int argc){
	FILE *fp;

	fp=fopen(argv[2],"r");
	/*Diavasma xronikwn stigmwn */
	int x=atoi(argv[3]);
	int y=atoi(argv[4]);

	RIFF *r=NULL;
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

	r->chunkID[4]='\0';
	f->subchunkID[4]='\0';
	d->subChunk2ID[4]='\0';
	/*Diavasma arxeiou hxou*/
	fread(r,sizeof(RIFF),1,fp);
	fread(f,sizeof(FMT_SUB),1,fp);
	fread(d,sizeof(DATA_SUB),1,fp);

	int arithmosSam=(d->subChunk2Size);

	fp=fopen(argv[2],"r");

	DATA *samples =NULL;
	/*Dimiourgia pinaka opou tha piasoume ta samples tou arxikou arxeiou hxou*/
	samples=(DATA*)malloc(sizeof(DATA)*(arithmosSam));
	if (samples==NULL){
		printf("System out of memory!\n");
		exit(-1);
	}
	/*Diavasma samples tou arxikou arxeiou hxou */
	fread(samples,f->bitsPerSample/8, arithmosSam,fp);

	int dokimi_seconds=d->subChunk2Size/(f->numChannels*(f->bitsPerSample/8));
	/*Eurisi posa deuterolepta einai to arxiko arxeio pou edwse o xristis */
	int seconds=dokimi_seconds/(f->sampleRate);

	int temp;
	if (x>y){
		temp=x;
		x=y;
		y=temp;
	}
	/*elexos an ta deuterolepta pou edwse o xristis einai mesa sto sinoliko xrono tou arxeiou*/
	if (seconds<=y){
		printf("O xronos ekagwgis pou zitate ipervenei to sinoliko xrono tou arxeiou %s!\n",argv[2]);
		return;
	}

	else{
		char newwav[strlen(argv[2])+5];
		strcpy(newwav,"chop-");
		strcat(newwav,argv[2]);

		FILE *fnew;
		fnew=fopen(newwav,"w");

		int i;
	
		d->subChunk2Size=f->sampleRate*(y-x)*(f->bitsPerSample/8)*f->numChannels;
		/*Grapsimo twn stoixeiwn tou tragoudiou sto kainourgio arxeio*/
		fwrite(r,sizeof(RIFF),1,fnew);
		fwrite(f,sizeof(FMT_SUB),1,fnew);
		fwrite(d,sizeof(DATA_SUB),1,fnew);

		arithmosSam=(d->subChunk2Size);

		int megethos=f->sampleRate*f->numChannels*f->bitsPerSample/8;
		int meg=(y-x)*megethos;

		DATA *samplesNew =NULL;
	
		/*Dimiourgia kainourgiou pinaka pou tha apothikeusoume mesa ta swsta samples g to kainourgio arxeio hxou*/
		if (f->bitsPerSample==8)
			samplesNew=(DATA*)malloc(sizeof(DATA)*(f->bitsPerSample*arithmosSam));
		else
			samplesNew=(DATA*)malloc(sizeof(DATA)*((f->bitsPerSample/8)*arithmosSam));

		if (samplesNew==NULL){
			printf("System out of memory!\n");
			exit(-1);
		}

		int j=0;
	
		/*kathorismos kanourgiwn samples gia to neo arxeio */
		for (i=(f->sampleRate*(x)*f->numChannels*(f->bitsPerSample/8));i<(f->sampleRate*y*f->numChannels*(f->bitsPerSample/8));i++){
			samplesNew[j]=samples[i];
			j++;
		}

		/*Grapsimo kainourgiwn samples ston kainourgio arxeio pou tha dimiourgisoume */
		if (f->bitsPerSample==8)
			fwrite(samplesNew,sizeof(DATA)*meg*f->bitsPerSample,d->subChunk2Size,fnew);
		else
			fwrite(samplesNew,sizeof(DATA)*meg*(f->bitsPerSample/8),d->subChunk2Size,fnew);

		free(samplesNew);
		fclose(fnew);
		free(samples);

	}

	fclose(fp);
	free(r);
	free(f);
	free(d);
}
