<!-- Make sure you edit doc/README.hbs rather than README.md because the latter is auto-generated -->

window-desktop
================

> Node module that allows you to attach a window as desktop's wallpaper or desktops's icons in Windows.

*This module only supports Windows (Tested on Windows 10)*

window-desktop allows you to insert a Window between the wallpaper and the desktop icons in Windows. User input interaction with the window is not possible, therefore this module is suitable if you wish to build a desktop dashboard application such as [Rainmeter](https://rainmeter.net) but use Electron and NodeJS.

Installation
------------

Install `window-desktop` by running:

```sh
$ npm install --save https://github.com/MeowSky49887/window-desktop.git
```

Documentation
-------------

**Example**

```js
const { app, BrowserWindow, globalShortcut } = require('electron');
const WindowDesktop = require('window-desktop');
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
      WindowDesktop.detachWindow(mainWindow);
    } else {
      WindowDesktop.attachAsWallpaper(mainWindow);
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
