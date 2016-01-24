/* <def.h>
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



/*
 * def.h
 *
 *  Created on: Apr 13, 2013
 *      Author: etingi01
 */

#ifndef DEF_H_
#define DEF_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef unsigned char byte;
typedef unsigned short int word;
typedef unsigned int dword;

typedef struct riff{
	byte chunkID[4];
	dword chunkSize;
	byte format[4];
}__attribute__((packed))RIFF;

typedef struct fmt_sub{
	byte subchunkID[4];
	dword subchunkSize;
	word audioFormat;
	word numChannels;
	dword sampleRate;
	dword byteRate;
	word blockAlign;
	word bitsPerSample;
}__attribute__((packed))FMT_SUB;

typedef struct data_sub{
	byte subChunk2ID[4];
	dword subChunk2Size;

}__attribute__((packed)) DATA_SUB;

typedef	byte DATA;



#endif /* DEF_H_ */
