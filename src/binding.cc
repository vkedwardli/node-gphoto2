/* Copyright contributors of the node-gphoto2 project */

#include "./camera.h"
#include "./gphoto.h"

extern "C" {
  NAN_MODULE_INIT(init) {
    Nan::HandleScope scope;
    GPhoto2::Initialize(target);
    GPCamera::Initialize(target);
  }
  #if NODE_MAJOR_VERSION >= 10
  NAN_MODULE_WORKER_ENABLED(gphoto2, init)
  #else
  NODE_MODULE(gphoto2, init)
  #endif
}

template<>
bool HasType(const v8::Value* val, const v8::String* unused) {
  return val->IsString();
}

template<>
bool HasType(const v8::Value* val, const bool* unused) {
  return val->IsBoolean();
}
