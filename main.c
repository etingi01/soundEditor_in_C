/* <main.c>
 * Copyright (C) <2013> <Evanthia Tingiri> <Rafaella Louka>
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



/** @file first.h
 *  @file second.h
 *  @file third.h
 *  @file reverse.h
 *  @file fifth.h
 *  @file ep.h
 *  @file prosthesi.h
 *  @file enallagi.h
 *  @file Check.h
 *  @brief Pelatis pou dinei diafora arxeia ixou kai kalei tis leitourgies analoga
 *  		me to pws thelei na tous epeksergastoun.
 *
 * To prwto orisma kathorizei ti leitourgia pou tha ektelesthei.
 *
 * @author Evanthia Tingiri (948282)
 * @author Rafaella Louka (949790)
 *
 * @bug No known bugs.
 */
#include "first.h"
#include "second.h"
#include "third.h"
#include "reverse.h"
#include "fifth.h"
#include "ep.h"
#include "prosthesi.h"
#include "enallagi.h"
#include "Check.h"
int main(int argc, char **argv){
	CheckFile(argv);
	CheckRiff(argv);
	CheckPCM(argv);
	char operation[12];
	strcpy(operation,argv[1]);

	if (strcmp(operation,"-list")==0){
		printHeader(argv,2);
	}else
	if (strcmp(operation,"-mono")==0){
		CheckFilesMonoAndSimilarity(argv);
		monoChannel(argv,2);
	}else
	if (strcmp(operation,"-chop")==0){
		ChopTrack(argv);
	}else
	if (strcmp(operation,"-reverse")==0){
			reverseWav(argv,2);
		}else
	if (strcmp(operation,"-similarity")==0){
		CheckFilesMonoAndSimilarity(argv);
		diavasmaPrwtouArxeiou(argv);
	}else
	if (strcmp(operation,"-ep")==0){
		CheckFilesMonoAndSimilarity(argv);
		readFileIn(argv);
	}else
	if (strcmp(operation,"-pro")==0){
		effect(argv,2);
		}else
	if (strcmp(operation,"-enal")==0){
			CheckFilesMonoAndSimilarity(argv);
			enallages(argv);
	}else
		printf("Den edwses swsti epilogi leitourgiasn!\n\n");
	return 0;
}
