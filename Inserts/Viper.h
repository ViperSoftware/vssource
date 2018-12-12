// General Viper Software header file

// mouse pointer shapes
#define  STD_POINTER         1
#define  CROSSHAIR_POINTER   2
#define  HOURGLASS_POINTER   3
#define  HAND_POINTER        4

#pragma comment (lib, "MfcSubs.lib") // make linker search this lib

void SetCursorShape (int opt);
int C_GetCursorShape(void); 

