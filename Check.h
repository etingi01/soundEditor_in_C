/* <Check.h>
 * Copyright (C) <2013><Rafaella Louka>
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
 * @brief Ylopoihmenes sinartiseis pou kanei kapoious elexous
 *
 *  @author Rafaella Louka (949790)
 *   
 *  @bug No known bugs.
 */

#ifndef CHECK_H_
#define CHECK_H_

#include "def.h"

/** @brief synartisti pou elexei an to arxeio hxou pou edwse o xristis san eisodo einai swsto.
 *
 *
 *  H pio katw sinartisi einai ipeuthini ston elexo an to arxeio pou edwse o xristis einai o tipos
 *  pou tha eprepe.  Pio sigkekrimena elexei an to chunkID tou arxeiou einai to swsto diladi einai
 *  RIFF.  H pio katw sinartisi einai xwrismeni se 2 meroi. To prwto meros einai gia tn leitourgia -chop
 *  opou ginetai o pio panw elexos mono mia fora giati stn chop ena arxeio mporeis na dwseis gia na ginei
 *  to temaxisma tou.
 *  To deutero meros einai gia oles tis alles leitourgies opou episis ginetai o pio panw elexos.
 *  To deutero meros tis sinartisis ekteleitai mexri na elextoun ola ta arxeia ta opoia edwse o xristis.
 *
 *
 *  @param argv me voitha ston elexo an einai swstos o tipos tou arxeiou tou opiou dothike.
 *
 */
void CheckRiff(char **argv);




/** @brief synartisti pou elexei an o xristis edwse arxeio kathws kai an to arxeio pou edwse iparxei.
 *
 *
 *	h synartisi auti einai ipeuthini ston elexo an o xristis edwse toulaxiston ena arxeio hxou.
 *	An den edwse tote tou emfanizei minima lathous kai to programma termatizetai.
 *	Episis i synartisi elexei an to arxeio pou edwse o xristis einai swsto diladi an iparxei.
 *	An den iparxei tote tou emfanizei minima kai to programma termatizetai.
 *
 *
 *  @param argv me voitha sto na kanw tous pio panw elexous.
 *
 */
void CheckFile(char **argv);



/** @brief synartisti pou elexei an to arxeio poy edwse o xristis einai swsto.
 *
 *
 *  H synartisi auti einai ipeuthini ston elexo an o tipos tou arxeiou pou edwse o xristis einai swsto.
 *  Pio sigkekrimena elexei an to audioFormat isoutai me 1. An den isoute me 1 tote to programma tipwnwei
 *  stn othoni minima lathous kai to programma termatizetai.
 *  Opws kai stn CheckRiff to programma einai xwrismeno se 2 meroi. To prwto meros einai gia tn leitourgia chop
 *  enw to allo meros einai gia ts ipolipes leitourgies.
 *
 *
 *  @param argv me voitha sous pio panw elexous.
 *
 */
void CheckPCM(char **argv);


/** @brief synartisti pou elexei an o xristis edwse toulaxiston 2 arxeia hxou.
 *
 *
 *  H synartisi auti einai ipeuthini ston elexo an o xristis edwse toulaxiston 2 arxeia hxou
 *  H synartisi auti isxuei gia ts leitourgies similarity kai mono opou gia na leitourgeisoun
 *  autes oi synartiseis tha prepei o xristis na exei dwsei toulaxiston 2 arxeia hxou .wav.
 *
 *
 *  @param argv me voitha ston pio panw elexo.
 *
 */
void CheckFilesMonoAndSimilarity(char **argv);

#endif /* CHECK_H_ */
