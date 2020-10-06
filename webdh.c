#include <stdlib.h> // required for malloc definition
#include "emscripten.h"
#include "./libdh/deephearingAPI.h"

EMSCRIPTEN_KEEPALIVE
void speech_enhancement(float* voice_in, float* voice_out) {

    DH_buffer test = DH_NewBuffer();
    
    DH_SetBuffer(test, voice_in);
    DH_RunProcess(test);


    DH_GetBuffer(test, voice_out);
    DH_DeleteBuffer(test);
}



EMSCRIPTEN_KEEPALIVE
float* create_buffer(int size) {
  return malloc(size * sizeof(float));
}

EMSCRIPTEN_KEEPALIVE
void destroy_buffer(float* p) {
  free(p);
}