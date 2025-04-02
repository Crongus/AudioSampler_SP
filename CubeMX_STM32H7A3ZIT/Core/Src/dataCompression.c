/*
 * dataCompression.c
 *
 *  Created on: Feb 24, 2025
 *      Author: l42li
 */

#include "dataCompression.h"

uint16_t *channelDeletor(uint16_t *datain, int size) {
	uint16_t *ret;
	ret = malloc(size/2 * sizeof(uint16_t));
	for (int i = 0; i < size/2; i++) {
		ret[i] = datain[2*i]; // Keep even indexed channels
	}
}

uint16_t *channelRestorer(uint16_t *datain, int size) {
	uint16_t *ret;
	ret = malloc(size*2 * sizeof(uint16_t));
	for (int i = 0; i < size/2 - 1; i++) {
			ret[i] = datain[i];
			ret[i+1] = datain[i];
	}
}

uint16_t *depthReducer(uint16_t *datain, int size) {
	uint16_t *ret;
	ret = malloc(size/2 * sizeof(uint16_t));
	for (int i = 0; i < size/2; i++) {
		ret[i] = (datain[2*i] & 0xFF00) + ((datain[(2*i)+1] & 0xFF00) >> 8);
		//ret[i] = (uint8_t) ((datain[i] & 0xFF00) >> 8);
	}
	return ret;
}

uint16_t *sampleDeletor(uint16_t *datain, int size) {
	uint16_t *ret;
	ret = malloc(size/2 * sizeof(uint16_t));
	for (int i = 0; i < size/2; i++) {
		ret[i] = datain[2*i];
		//dataout[i] = ((i%2)&&(i!=size-1))?datain[i]:0; //Odd numbered clips will be 0, even numbers will stay the same
	}
	return ret;
}

uint16_t *depthExpander(uint16_t *datain, int size) { // every odd datain[i] is being dropped
	uint16_t *ret;
	ret = malloc(size*2 * sizeof(uint16_t));
	for (int i = 0; i < size*2; i+=2) {
		ret[i] = (datain[i] & 0xFF00);
		if (i != size*2 - 1) ret[i+1] = (datain[i] & 0x00FF) << 8;
		else ret[i] = ret[i-1];
	}
	return ret;
}

uint16_t *sampleInterpolator(uint16_t *datain, int size) {
	uint16_t *ret;
	ret = malloc(size*2 * sizeof(uint16_t));
	for (int i = 0; i < size*2; i++) {
		if(i%2 == 0) ret[i] = datain[i/2];
		else ret[i] = (datain[(i/2)-1] + datain[(i/2)+1])/2;
	}
	return ret;
}
