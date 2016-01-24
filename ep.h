/* <ep.h>
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
 * @brief Protipo sinartisis gia ep.c
 *
 * Sinartisi pou tha vazei 2 arxeia hxou se ena
 * sto opoio afta tha akougontai taftoxrona.
 * Afto ginetai afairontas ta dedomena tou enos apo ta
 * dedomena tou allou.
 *
 * @author Evanthia Tingiri (948282)
 *
 * @bug No known bugs.
 */
#ifndef EP_H_
#define EP_H_
#include "def.h"

/* @brief Sinartisi pou se ena arxeio hxou vazei dyo na paizoun taftoxrona.
 *
 * H sinartisi afti dexetai MONO 2 arxeia hxou kai ta sinenwnei se ena
 * allo, sto opoio ektelountai TAFTOXRONA. Gia na kalestei kai na
 * ektelestei afti i sinartisi san prwto orisma o xristis prepei
 * na dwsei tin entoli "-ep" kai vevaia alla DYO arxeia hxou, typoy .wav
 * Gia na epitefxthei afto stin ousia, ginetai afairesi tou prwtou
 * kommatiou apo tou defterou.
 *
 * @param argv
 *
 * @return Void
 *
 */
void readFileIn(char **argv);

#endif /* EP_H_ */
