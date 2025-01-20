#include "wd.h"

BOOL CALLBACK wd::FindWorkerW(HWND hwnd, LPARAM param) {
	HWND temp = FindWindowEx(hwnd, NULL, L"SHELLDLL_DefView", NULL);

	if (temp) {
		workerw = FindWindowEx(NULL, hwnd, L"WorkerW", NULL);
		return FALSE;
	}

	return TRUE;
}

void wd::AttachAsWallpaper(unsigned char* handleBuffer) {
	auto handle = *reinterpret_cast<LONG_PTR*>(handleBuffer);
	auto hwnd = (HWND)(LONG_PTR)handle;

	auto progman = FindWindow(L"Progman", NULL);
	auto result = SendMessageTimeout(
		progman,
		WM_SPAWN_WORKER,
		NULL,
		NULL,
		SMTO_NORMAL,
		1000,
		NULL);

	if (!result) {
		
	}

	EnumWindows(&FindWorkerW, reinterpret_cast<LPARAM>(&workerw));

	SetWindowLong(hwnd, GWL_EXSTYLE, WS_EX_LAYERED);
	SetParent(hwnd, workerw);
}

void wd::AttachAsIcons(unsigned char* handleBuffer) {
	auto handle = *reinterpret_cast<LONG_PTR*>(handleBuffer);
	auto hwnd = (HWND)(LONG_PTR)handle;

	auto progman = FindWindow(L"Progman", NULL);
	auto result = SendMessageTimeout(
		progman,
		WM_SPAWN_WORKER,
		NULL,
		NULL,
		SMTO_NORMAL,
		1000,
		NULL);

	if (!result) {
	}

	EnumWindows(&FindWorkerW, reinterpret_cast<LPARAM>(&workerw));

	RECT rect;
	GetWindowRect(hwnd, &rect)

	SetWindowPos(hwnd, workerw, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, 0x0000);
}

void wd::DetachWindow(unsigned char* handleBuffer) {
	LONG_PTR handle = *reinterpret_cast<LONG_PTR*>(handleBuffer);
	HWND hwnd = (HWND)(LONG_PTR)handle;

	SetParent(hwnd, NULL);
}

Napi::Value wd::AttachAsWallpaperExport(const Napi::CallbackInfo& info) {
	auto env = info.Env();

	if (info.Length() < 1) {
		Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
		return env.Null();
	}

	if (!info[0].IsBuffer()) {
		Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
		return env.Null();
	}

	auto windowHandleBuffer = info[0].As<Napi::Buffer<uint8_t>>();

	AttachAsWallpaper(windowHandleBuffer.Data());
	return env.Null();
}

Napi::Value wd::AttachAsIconsExport(const Napi::CallbackInfo& info) {
	auto env = info.Env();

	if (info.Length() < 1) {
		Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
		return env.Null();
	}

	if (!info[0].IsBuffer()) {
		Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
		return env.Null();
	}

	auto windowHandleBuffer = info[0].As<Napi::Buffer<uint8_t>>();

	AttachAsIcons(windowHandleBuffer.Data());
	return env.Null();
}

Napi::Value wd::DetachWindowExport(const Napi::CallbackInfo& info) {
	auto env = info.Env();

	if (info.Length() < 1) {
		Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
		return env.Null();
	}

	if (!info[0].IsBuffer()) {
		Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
		return env.Null();
	}

	auto windowHandleBuffer = info[0].As<Napi::Buffer<uint8_t>>();

	DetachWindow(windowHandleBuffer.Data());
	return env.Null();
}
