/* <fifth.h>
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



/** @file def.h
 * @brief Protipo sinartisis gia fifth.c
 *
 * Sinartisi pou tha elegxei tin omoiotita enos
 * h perissoterwn arxeiwn me ena allo (to deftero
 * orisma tou xristi sti grammi entolwn) San prwto orisma
 * o xristis tha prepei na dwsei tin entoli "-similarity"
 *
 * @author Evanthia Tingiri (948282)
 *
 * @bug No known bugs.
 */
#ifndef FIFTH_H_
#define FIFTH_H_
#include "def.h"

/* @brief Sinartisi pou diavazei to prwto arxeio pou tha sigkrithei me
 * 			ola ta ipoloipa.
 *
 * H sinartisi afti diavazei to prwto arxeio hxou me to opoio
 * tha ginoun oles oi ipoloipes sigkriseis gia tin evresi tis
 * efklideias apostasis kai tou lcss. Afti i sinartisi tha kalei
 * kai tin epomeni opou tha diavazetai to arxeio pou tha sigkrithei.
 *
 * @param argv
 *
 * @return Void
 *
 */
void diavasmaPrwtouArxeiou(char **argv);


/* @brief Sinartisi pou diavazei to epomeno arxeio pou tha sigkrithei me to prwto.
 *
 * H sinartisi afti diavazei to epomeno sigkrisimo arxeio ixou. Kai etsi kalei ti
 * sinartisi pou tha ipologisei tin efklideia apostasi kai tin apostasi lcss.
 *
 * @param argv
 * @param j To orisma sti grammi entolwn tou trexontos sigkrisimou arxeiou
 * @param samples Ta dedomena tou prwtou arxeiou hxou me ta opoia tha ginei i sigkrisi
 * @param sizeFirstFile To megethos twn dedomenwn tou prwtou arxeiou
 * @param fmt FMT SUB-CHUNK tou prwtou arxeiou hxou.
 *
 * @return Void
 *
 */
void readCoFile(char **argv, int j, DATA *samples,int sizeFirstFile, FMT_SUB *fmt);


/* @brief Sinartisi pou sigkrinei dyo arxeia ixou gia na vrei tis apostaseis tous.
 *
 * H sinartisi afti vriskei to megethos tis megistis koinis ipoakolouthias
 * twn dedomenwn twn 2 arxeiwn ixou, xrisimopoiwntas enan dinamika
 * desmevmeno pinaka 2*sizeFirstFile. Vriskei episis tin efklideia apostasi.
 *
 * @param samples Ta dedomena tou prwtou arxeiou hxou me ta opoia tha ginei i sigkrisi
 * @param co_samples Ta dedomena tou arxeiou hxou pou tha sigkrithei me to prwto
 * @param sizeFirstFile To megethos twn dedomenwn tou prwtou arxeiou
 * @param sizeCoFile To megethos twn dedomenwn tou arxeiou pou tha sigkrithei me to prwto
 * @param lcss Deiktis double gia tin epistrofi tis apostasis lcss.
 * @param efklides Deiktis double gia tin epistrofi tis efklideias apostasis.
 *
 * @return Void
 *
 */
void distance(DATA *samples, DATA *co_samples,int sizeFirstFile,int sizeCoFile,double *lcss, double *efklides);


/* @brief Sinartisi pou sigkrinei dyo arithmous kai epistrefei ton megalitero.
 *
 * @param a
 * @param b
 *
 * @return Int
 *
 */
int max(int a, int b);


/* @brief Sinartisi pou sigkrinei dyo arithmous kai epistrefei ton mikrotero.
 *
 * @param a
 * @param b
 *
 * @return Int
 *
 */
int min(int a, int b);
#endif /* FIFTH_H_ */
