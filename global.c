#include "Faster.h"

BOOL fasterInited = 0;

UDINT fasterIndex = 0;
UDINT fasterMaxChecks = 0;
DINT fasterLastTimeStamp = 0;

DINT *pFasterTimeStamp = 0;
DINT *pFasterDelta = 0;
plcstring (*pFasterName)[FASTER_NAME_LENGTH+1];

DINT internalTimeStamp[FASTER_INTERNAL_SAMPLES];
DINT internalTimeDelta[FASTER_INTERNAL_SAMPLES];
STRING internalName[FASTER_NAME_LENGTH+1][FASTER_INTERNAL_SAMPLES];
