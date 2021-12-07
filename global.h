extern BOOL fasterInited;
extern DINT *pFasterTimeStamp;
extern DINT *pFasterDelta;
extern plcstring (*pFasterName)[FASTER_NAME_LENGTH+1];
extern UDINT fasterIndex;
extern UDINT fasterMaxChecks;
extern DINT fasterLastTimeStamp;

extern DINT internalTimeStamp[FASTER_INTERNAL_SAMPLES];
extern DINT internalTimeDelta[FASTER_INTERNAL_SAMPLES];
extern STRING internalName[FASTER_NAME_LENGTH+1][FASTER_INTERNAL_SAMPLES];
