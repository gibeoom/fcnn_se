#include <stdlib.h> // required for malloc definition
#include "emscripten.h"
#include "./libdh/deephearingAPI.h"

DH_buffer buffer;

EMSCRIPTEN_KEEPALIVE
void init() {
    buffer = DH_NewBuffer();
}

EMSCRIPTEN_KEEPALIVE
void delete() {
    DH_DeleteBuffer(buffer);
}

EMSCRIPTEN_KEEPALIVE
void speech_enhancement(float* voice_in, float* voice_out) {
    DH_SetBuffer(buffer, voice_in);
    DH_RunProcess(buffer);
    DH_GetBuffer(buffer, voice_out);
}



EMSCRIPTEN_KEEPALIVE
float* create_buffer(int size) {
  return malloc(size * sizeof(float));
}

EMSCRIPTEN_KEEPALIVE
void destroy_buffer(float* p) {
  free(p);
}
