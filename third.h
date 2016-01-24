/* <third.h>
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




/**@file def.h
 * @brief Protipo sinartisis gia third.c
 *
 *  Sinartisi pou katagrafei se ena kainouria arxeio
 *  to temaxisma tou arxikou arxeiou apo ena deuterolepto
 *  se allo ta opoia dinei o xristis apo tn grammi entolwn.
 *
 * @author Rafaela Louka (949790)
 *
 * @bug No known bugs.
 */
#ifndef THIRD_H_
#define THIRD_H_

#include "def.h"
/** @brief synartisi pou temaxizei ena arxeio hxou apo mia xroniki stigmi se mia alli.
 *
 *
 *	Gia na energopoihthei i synartisi auti tha prepei na dothei apo tn grammi entolwn
 *  i entoli -chop <arxeio hxou .wav> <arxiki xroniki stigmi> <teliki xroniki stigmi>.
 *  To programma tha prepei na pairnei to arxeio hxou kai na to temaxizei apo tin
 *  arxiki xroniki stigmi mexri tin teliki xroniki stigmi kai na dhmiourghtai ena neo
 * 	arxeiou hxou.  To neo arxeio hxou tha onomazetai new-<arxeio hxou .wav>.  To kainourgio
 * 	arxeio hxou tha ginetai me ton orismo enos pinaka samplesNew opou tha apothikeuontai
 * 	mesa ta swsta samples pou eksartontai apo ts xronikes stigmes pou dinei o xristis.
 *	To megethos tou neou arxeio eksartatai apo twn arithmwn twn kanaliwn tou arxeiou(numChannels,
 *	apo ton arithmo twn deigmatwn(sampleRate), apo ta bits tou kathe sample(bitsPerSamples),
 *	kai apo ton xrono pou tha exei to kainourgio arxeio(y-x).
 *	Epishs to programma ipologizei tn sinoliko xrono pou exei to arxeio kai elexei an o xristis
 *	edwse swsta tous xronous eksagwgis. an edwse lathos xronous tote emfanizei minima lathous.
 *
 *
 *  @param argv me voitha sto na diavasw to axeiou hxou .wav kai ts xronikes stigmes pou tha ginei i eksagwgi.
 *  @param argc me voitha sto na elexw an o xristis edwse swsta ta orismata, dhladh an edwse to arxeiou hxou
 *  		    kai ts xronikes periodous. (ginetai elexos an argc<5).
 *
 *  @return void
 */
void ChopTrack(char **argv,int argc);

#endif /* THIRD_H_ */
