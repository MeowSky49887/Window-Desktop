#pragma once

#include <napi.h>
#include <windows.h>

namespace ww {
	// Message to Progman to spawn a WorkerW
	static int WM_SPAWN_WORKER = 0x052C;

	// TODO(robin): Use the EnumWindows callback
	// instead of a global
	static HWND workerw = NULL;

	// Window enumerator that will set the
	// window handle for the WorkerW that is the next
	// sibling to SHELLDLL_DefView
	BOOL CALLBACK FindWorkerW(HWND, LPARAM);

	void AttachWindow(unsigned char*);
	void DetachWindow(unsigned char*);

	Napi::Value AttachWindowExport(const Napi::CallbackInfo& info);
	Napi::Value DetachWindowExport(const Napi::CallbackInfo& info);
}  // namespace ww
