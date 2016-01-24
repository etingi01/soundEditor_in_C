/* <Check.c>
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




/**@file Check.h
 * @brief Ylopoihmeni sinartisi opou elexei kapoies periptwseis opou o xristis mporei na eisagei lathos orismata.
 *
 * @author Rafaela Louka (949790)
 *
 * @bug No known bugs.
 */

#include "Check.h"

void CheckRiff(char **argv){
	int i=2;
	if (strcmp(argv[1],"-chop")==0){
		FILE *fp;
		fp=fopen(argv[i],"r");
		RIFF *r;
		r=(RIFF*)malloc(sizeof(RIFF));
		if (r==NULL){
			printf("System out of memory! \n");
			exit(-1);
		}

		fread(r,sizeof(RIFF),1,fp);
		r->chunkID[4]='\0';
		if ((strcmp(r->chunkID,"RIFF")!=0)){
			printf("Exeis dwsei lathos tipo arxeiou hxou! To programma termatizetai!\n");
			exit(-1);
		}
		fclose(fp);
		free(r);
	}
	else{
		while (argv[i]!='\0'){
			FILE *fp;
			fp=fopen(argv[i],"r");

			RIFF *r;
			r=(RIFF*)malloc(sizeof(RIFF));
			if (r==NULL){
				printf("System out of memory! \n");
				exit(-1);
			}

			fread(r,sizeof(RIFF),1,fp);
			r->chunkID[4]='\0';
			if ((strcmp(r->chunkID,"RIFF")!=0)){
				printf("Exeis dwsei lathos tipo arxeiou hxou! To programma termatizetai!\n");
				exit(-1);
			}

			free(r);
			fclose(fp);
			i++;
		}
	}
}

void CheckFile(char **argv){
	FILE *fp;
	if (argv[2]==NULL){
		printf("Den edwses arxeio hxou!To programma tha termatistei!\n\n");
		exit(-1);
	}
	if ((fp=fopen(argv[2],"r"))==NULL){
		printf("Den einai dinato na anoiksei to prwto arxeio... To programma tha termatistei!\n\n");
		exit(-1);
	}
	fclose(fp);
	int i=3;
	if (strcmp(argv[1],"-chop")!=0){
		while (argv[i]!='\0'){
			if ((fp=fopen(argv[i],"r"))==NULL){
				printf("Den einai dinato na anoiksei to arxeio... To programma tha termatistei!\n\n");
				exit(-1);
			}
			i++;
			fclose(fp);
		}
	}

}

void CheckFilesMonoAndSimilarity(char **argv){

	if (argv[3]==NULL){
		printf("Gia tn epilogi %s prepei na dwseis toulaxiston 2 arxeia hxou!\n\n",argv[1]);
		exit(-1);
	}
}


void CheckPCM(char **argv){

	int i=2;
	if (strcmp(argv[1],"-chop")==0){

		FILE *fp;
		fp=fopen(argv[i],"r");
		RIFF *r;
		r=(RIFF*)malloc(sizeof(RIFF));
		if (r==NULL){
			printf("System out of memory! \n\n");
			exit(-1);
		}
		fread(r,sizeof(RIFF),1,fp);

		FMT_SUB *f;
		f=(FMT_SUB*)malloc(sizeof(FMT_SUB));
		if (f==NULL){
			printf("System out of memory! \n\n");
			exit(-1);
		}
		fread(f,sizeof(FMT_SUB),1,fp);

		r->chunkID[4]='\0';
		f->subchunkID[3]='\0';

		if (f->audioFormat!=1){
			printf("Edwses lathos arxeio hxou. To programma tha termatistei!\n\n");
			exit(-1);
		}

		free(r);
		free(f);
		fclose(fp);

	}
	else{

		while(argv[i]!='\0'){
			FILE *fp;
			fp=fopen(argv[i],"r");
			RIFF *r;
			r=(RIFF*)malloc(sizeof(RIFF));
			if (r==NULL){
				printf("System out of memory! \n\n");
				exit(-1);
			}
			fread(r,sizeof(RIFF),1,fp);

			FMT_SUB *f;
			f=(FMT_SUB*)malloc(sizeof(FMT_SUB));
			if (f==NULL){
				printf("System out of memory!\n\n");
				exit(-1);
			}
			fread(f,sizeof(FMT_SUB),1,fp);

			r->chunkID[4]='\0';
			f->subchunkID[3]='\0';

			if (f->audioFormat!=1){
				printf("Edwses lathos arxeio. To programma tha termatistei!\n\n");
				exit(-1);
			}
			free(r);
			free(f);
			fclose(fp);
			i++;

		}
	}
}
