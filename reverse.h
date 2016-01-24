/* <reverse.h>
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
 * @brief Protipo sinartisis gia reverse.c
 *
 * Sinartisi pou se ena kainourgio arxeio tha
 * apothikevei to dosmeno arxeio, alla antistrofo.
 *
 * @author Evanthia Tingiri (948282)
 *
 * @bug No known bugs.
 */

#ifndef REVERSE_H_
#define REVERSE_H_

#include "def.h"


/* @brief Sinartisi pou se ena kainourgio arxeio hxou tha
 * 			apothikevei to dosmeno alla antistrofo.
 *
 * H sinartisi afti leitourgei gia aperioristo arithmo dosmenwn arxeiwn (anadromiki).
 * Apothikevei ton hxo antistrofa. Afto epitigxanetai antigrafontas ta dedomena tou
 * arxeiou ksekinwntas omws apo to telos.
 *
 * @param argv
 * @param i
 *
 * @return Void
 *
 */
void reverseWav(char **argv, int i);


#endif /* REVERSE_H_ */
