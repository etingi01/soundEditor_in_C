/* <prosthesi.h>
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
 * @brief Protipo sinartisis gia prosthesi.c
 *
 * Sinartisi pou se ena kainourgio arxeio tha
 * apothikevei to dosmeno arxeio, alla diakoptomeno.
 *
 * @author Evanthia Tingiri (948282)
 *
 * @bug No known bugs.
 */

#ifndef PROSTHESI_H_
#define PROSTHESI_H_
#include "def.h"

/* @brief Sinartisi pou se ena kainourgio arxeio hxou tha
 * 			apothikevei to dosmeno alla diakoptomeno
 *
 * H sinartisi afti leitourgei gia aperioristo arithmo dosmenwn arxeiwn (anadromiki).
 * Apothikevei ton hxo diakoptomeno. Afto epitigxanetai antigrafontas kanonika kapoia
 * bytes tou arxeiou kai midenizontas ta epomena. Afto ginetai katepanalipsin mexri to
 * telos tou arxeiou.
 *
 * @param argv
 * @param l
 *
 * @return Void
 *
 */
void effect(char **argv, int l);

#endif /* PROSTHESI_H_ */
