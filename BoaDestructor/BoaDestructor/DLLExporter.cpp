//
/*
Selbst definierter Funktionspointer, der zwei Integer übernimmt sowie einen zurückgiebt.
*/

#include <iostream>
#include <stdio.h>

struct  float3
{
	float x;
	float y;
	float z;
	
};

typedef int(*fctptr)(int, int);
typedef float(*fctptrA)(float);


/*
extern "C": nondecortated funktion name
__declspec(dllexport): legt die Funktion nach draußen, damit sie von außen aufgerufen werden kann.

*/


extern "C" __declspec(dllexport) int BlenderCPP(fctptr fctPtr)
{
	return 2 * fctPtr(45, 24);
}


extern "C" __declspec(dllexport) int BlenderCPP2(fctptr fctPtr, int a, int b)
{
	return fctPtr(a,b);
}


extern "C" __declspec(dllexport) float BlenderGetVertices(fctptrA fctptra, float verticesX1, int count)
{
	return fctptra(verticesX1);
}