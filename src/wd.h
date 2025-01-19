#pragma once

#include <napi.h>
#include <windows.h>

namespace wd {
	static int WM_SPAWN_WORKER = 0x052C;

	static HWND shelldll = NULL;
	static HWND workerw = NULL;

	BOOL CALLBACK FindShellDLL(HWND, LPARAM);
	BOOL CALLBACK FindWorkerW(HWND, LPARAM);

	void AttachAsWallpaper(unsigned char*);
	void AttachAsIcons(unsigned char*);
	void DetachWindow(unsigned char*);

	Napi::Value AttachAsWallpaperExport(const Napi::CallbackInfo& info);
	Napi::Value AttachAsIconsExport(const Napi::CallbackInfo& info);
	Napi::Value DetachWindowExport(const Napi::CallbackInfo& info);
}
