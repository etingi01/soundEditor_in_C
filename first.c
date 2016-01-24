/* <first.c>
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

/**@file first.h
 * @brief Ylopoihmeni sinartisi pou emfanizei stin othoni
 * 	  ta ta stoixeia tou header enos arxeiou hxou .wav.
 *
 *  @author Rafaella Louka (949790)
 *   
 *  @bug No known bugs.
 */

#include "first.h"
void printHeader (char **argv, int i){
	/*Elexos an exoun teliwsei ta arxeia pou edwse o xristis*/
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
	/*Diavasma arxeiou*/
	fread(r,sizeof(RIFF),1,fp);
	fread(f,sizeof(FMT_SUB),1,fp);
	fread(d,sizeof(DATA_SUB),1,fp);

	r->chunkID[4]='\0';
	f->subchunkID[3]='\0';
	d->subChunk2ID[4]='\0';
	r->format[4]='\0';
	/*tipwma stoixeiwn header*/
	printf("f->subchunkSize: %d\n\n",f->subchunkSize);
	printf("RIFF_CHUNK_HEADER\n=================\n");
	printf("chunkID: %s\nchunkSize: %d\nformat: %s\n\n",r->chunkID,r->chunkSize,r->format);
	printf("FMT_CHUNK_HEADER\n==================\n");
	printf("subChunkID: %s\nsubChunk1Size: %d\naudioFormat: %d\nnumChannels: %d\nsampleRate: %d\nbyteRate: %d\nblockAlign: %d\nbitsPerSample: %d\n\n",f->subchunkID,f->subchunkSize\
			,f->audioFormat,f->numChannels,f->sampleRate,f->byteRate,f->blockAlign,f->bitsPerSample);
	printf("DATA_SUBCHUNK_HEADER\n====================\n");
	printf("subChunk2ID: %s\nsubChunk2Size: %d\n",d->subChunk2ID,d->subChunk2Size);
	printf("**************************************************************\n\n");
	
	free(r);
	free(f);
	free(d);
	fclose(fp);
	printHeader(argv,(i+1));
}
