#ifndef __DEEPHEARINGAPI
#define __DEEPHEARINGAPI

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#if defined(__cplusplus)
extern "C" {
#endif

/*
 *  API for 16kHz Sample Rate Deephearing Speech Enhancement Engine.
 */
 
/*
 *  Boxed Buffer Type.
 */
typedef void* DH_buffer;

/* 
 *  Get New Deep Hearing Buffer 
 */
DH_buffer DH_NewBuffer();

/* 
 *  Delete Deep Hearing Buffer 
 */
void DH_DeleteBuffer(DH_buffer buf);

/* 
 *  Run Deep Hearing Process 
 */
void DH_RunProcess(DH_buffer buf);

/* 
 *  Set Deep Hearing Input Buffer
 *  
 *  input:
 *      inputData: float Array[INPUT_SIZE]
 */
void DH_SetBuffer(DH_buffer buf, float* inputData);

/* 
 *  Set Deep Hearing Input Buffer
 *  
 *  output:
 *      output:  float Array[INPUT_SIZE]
 */
void DH_GetBuffer(DH_buffer buf, float* output_buffer);

#if defined(__cplusplus)
} /* extern "C" */
#endif
#endif