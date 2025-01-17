#include "ww.h"

BOOL CALLBACK ww::FindWorkerW(HWND hwnd, LPARAM param) {
	HWND shelldll = FindWindowEx(hwnd, NULL, L"SHELLDLL_DefView", NULL);

	if (shelldll) {
		workerw = FindWindowEx(NULL, hwnd, L"WorkerW", NULL);
		return FALSE;
	}

	return TRUE;
}

void ww::AttachWindow(unsigned char* handleBuffer) {
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
		// TODO(robin): GetLastError() and handle properly
	}

	// TODO(robin): Handle return value of EnumWindows
	EnumWindows(&FindWorkerW, reinterpret_cast<LPARAM>(&workerw));

	// Update style of the Window we want to attach
	SetWindowLong(hwnd, GWL_EXSTYLE, WS_EX_LAYERED);
	SetParent(hwnd, workerw);
}

void ww::DetachWindow(unsigned char* handleBuffer) {
	LONG_PTR handle = *reinterpret_cast<LONG_PTR*>(handleBuffer);
	HWND hwnd = (HWND)(LONG_PTR)handle;

	// TODO(robin): Remove the style update we applied

	SetParent(hwnd, workerw);
}

Napi::Value ww::AttachWindowExport(const Napi::CallbackInfo& info) {
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

	AttachWindow(windowHandleBuffer.Data());
	return env.Null();
}

Napi::Value ww::DetachWindowExport(const Napi::CallbackInfo& info) {
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