#include <assert.h>
#include "ww.h"
#include "napi.h"

Napi::Object Init(Napi::Env env, Napi::Object exports) {
	exports.Set(Napi::String::New(env, "attachWindow"), Napi::Function::New(env, ww::AttachWindowExport));
	exports.Set(Napi::String::New(env, "detachWindow"), Napi::Function::New(env, ww::DetachWindowExport));
	return exports;
}

NODE_API_MODULE(addon, Init)