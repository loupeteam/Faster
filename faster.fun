
{REDUND_ERROR} FUNCTION fasterInit : DINT (* *) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		pTimeStamps : UDINT;
		pTimeDeltas : UDINT;
		pSampleName : UDINT;
		maxSamples : DINT;
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION fasterReset : DINT (* *) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
END_FUNCTION

FUNCTION fasterStart : DINT
END_FUNCTION

{REDUND_ERROR} FUNCTION fasterTimeSinceLast : DINT (* *) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		label : STRING[FASTER_NAME_LENGTH];
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION fasterTimeSinceLabel : DINT (* *) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		previous : STRING[FASTER_NAME_LENGTH];
		label : STRING[FASTER_NAME_LENGTH];
	END_VAR
END_FUNCTION
