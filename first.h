/* <first.h>
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



/** @file def.h
 * @brief Protipo sinartisis gia first.c
 *
 * Synartisi i opoia tipwnei stin othoni ta stoixeia header enos arxeiou 
 * hxou .wav opou o xristis dinei g eisodo.
 *
 * @author Rafaela Louka (949790)
 *
 * @bug No known bugs.
 */

#ifndef FIRST_H_
#define FIRST_H_

#include "def.h"
/** @brief synartisi pou tipwnei stn othoni ta stoixeia tou header enos arxeiou hxou .wav.
 *
 *
 *  H synartisi auth einai ipeuthini sto tipwma twn stouxeiwn tou header.
 *  Gia na energopoiithei i synartisi auti tha prepei na dwse i entoli -list <arxeio hxou .wav> <arxeio hxou .wav>.
 *  O xristis mporei na dwsei ws eisodo osa arxeia thelei stn morfi pou anefera pio panw.
 *	H pio katw synartisi einai anadromiki kai ekteleitai mexri na teliwsoun ta arxeia hxou pou edwse o xristis.
 *	Arxika i synartisi elexei an teleiwsan ta arxeia eisodou pou edwse o xristis. An teleiwsan tote h sinartisi termatizetai.
 *	An den teleiwsan diavazei ta stoixeia tou header tou arxeiou hxou kai meta ginetai i ektipwsh twn stoixeiwn autwn.
 *	Afou teleiwsei i ektipwsi twn stoixeiwn autwn ginetai i klisi ts sinartisis gia to epomeno arxeio hxou pou edwse o xristis
 *	san eisodo.
 *
 *
 *  @param argv me voitha sto na elexw an teleiwsan ta arxeia hxou .wav pou edwse o xristis.
 *  	   Episis me voitha sto diavasma tou arxeiou.
 *  @param i einai metritis pou se kathe kalesma ts synartisis auksanetai outws wste na pernoume to epomeno arxeio pou tha epeksergastoume.
 *
 *  @reurn void
 */
void printHeader(char **argv, int i);

#endif /* FIRST_H_ */
