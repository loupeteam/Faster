/*
 * File: fastCapture.c
 * Copyright (c) 2023 Loupe
 * https://loupe.team
 * 
 * This file is part of Faster, licensed under the MIT License.
 */
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Faster.h"
	#include "global.h"
	#include "string.h"

#ifdef __cplusplus
	};
#endif
signed long fasterInit(unsigned long pTimeStamps, unsigned long pTimeDeltas, unsigned long pSampleName, signed long maxSamples){
	
	if( (!pTimeStamps || !pTimeDeltas || !pSampleName) && maxSamples > FASTER_INTERNAL_SAMPLES ){
		fasterMaxChecks = FASTER_INTERNAL_SAMPLES;
	}
	else{
		fasterMaxChecks = maxSamples;	
	}
	
	pFasterTimeStamp = pTimeStamps ? pTimeStamps : &internalTimeStamp;
	pFasterDelta = pTimeDeltas ? pTimeDeltas : &internalTimeDelta;
	pFasterName = pSampleName ? pSampleName : &internalName;


	
}
DINT fasterStart(){
	return fasterLastTimeStamp = AsIOTimeStamp();
}

DINT fasterReset(){
	fasterIndex = 0;	
	return fasterTimeSinceLast("Start");
}

DINT fasterTimeSinceLast(plcstring* name)
{	
	if( fasterIndex < 0 || fasterIndex >= fasterMaxChecks ){
		return AsIOTimeStamp();
	}
	if(name){
		strcpy(&pFasterName[fasterIndex],name);
	}
	pFasterTimeStamp[fasterIndex] = AsIOTimeStamp();
	if( fasterIndex > 0 ){	
		pFasterDelta[fasterIndex] = pFasterTimeStamp[fasterIndex] - fasterLastTimeStamp;
	}
	fasterLastTimeStamp = pFasterTimeStamp[fasterIndex];
	return pFasterDelta[fasterIndex++];	
}

DINT fasterTimeSinceLabel(plcstring* prev, plcstring* name)
{	
	if (!prev || !name) return 0;
	
	if( fasterIndex < 0 || fasterIndex >= fasterMaxChecks ){
		return AsIOTimeStamp();
	}
	if(name){
		strcpy(&pFasterName[fasterIndex],name);
	}
	pFasterTimeStamp[fasterIndex] = AsIOTimeStamp();
	if( fasterIndex > 0 ){	
		
		int searchIndex = fasterIndex;
		while(--searchIndex){
			if( !strcmp( prev,  pFasterName[searchIndex] ) ){
				break;
			}
		}
		pFasterDelta[fasterIndex] = pFasterTimeStamp[fasterIndex] - pFasterTimeStamp[searchIndex];
	}
	fasterLastTimeStamp = pFasterTimeStamp[fasterIndex];
	return pFasterDelta[fasterIndex++];	
}
