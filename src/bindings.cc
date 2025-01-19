#include <assert.h>
#include "wd.h"
#include "napi.h"

Napi::Object Init(Napi::Env env, Napi::Object exports) {
	exports.Set(Napi::String::New(env, "attachAsWallpaper"), Napi::Function::New(env, wd::AttachAsWallpaperExport));
	exports.Set(Napi::String::New(env, "attachAsIcons"), Napi::Function::New(env, wd::AttachAsIconsExport));
	exports.Set(Napi::String::New(env, "detachWindow"), Napi::Function::New(env, wd::DetachWindowExport));
	return exports;
}

NODE_API_MODULE(addon, Init)