<!-- Make sure you edit doc/README.hbs rather than README.md because the latter is auto-generated -->

window-wallpaper
================

> Node module that allows you to attach a window as wallpaper in Windows.

*This module only supports Windows (Tested on Windows 10)*

window-wallpaper allows you to insert a Window between the wallpaper and the desktop icons in Windows. User input interaction with the window is not possible, therefore this module is suitable if you wish to build a desktop dashboard application such as [Rainmeter](https://rainmeter.net) but use Electron and NodeJS.

Installation
------------

Install `window-wallpaper` by running:

```sh
$ npm install --save https://github.com/MeowSky49887/Window-Wallpaper.git
```

Native binaries for win, mac and linux are prebuilt and downloaded when the module is installed.

Documentation
-------------

**Example**

```js
const { app, BrowserWindow, globalShortcut } = require('electron');
const WindowWallpaper = require('window-wallpaper');
const path = require('path');

let mainWindow;
let isAttachedAsWallpaper = false; // State to track attachment status

app.on('ready', () => {
  mainWindow = new BrowserWindow({
    frame: false,
    fullscreen: true,
    webPreferences: {
      preload: path.join(__dirname, 'renderer.js'),
      nodeIntegration: true,
      contextIsolation: false,
    },
  });

  mainWindow.loadURL('https://www.youtube.com/');

  // Register a global shortcut for F11
  globalShortcut.register('F11', () => {
    if (isAttachedAsWallpaper) {
      WindowWallpaper.detachWindow(mainWindow);
    } else {
      WindowWallpaper.attachWindow(mainWindow);
    }
    isAttachedAsWallpaper = !isAttachedAsWallpaper; // Toggle the state
  });

  // Handle the case when the app quits
  app.on('will-quit', () => {
    globalShortcut.unregisterAll();
  });
});

app.on('window-all-closed', () => {
  if (process.platform !== 'darwin') {
    app.quit();
  }
});

```
