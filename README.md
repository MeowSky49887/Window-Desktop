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
$ npm install --save window-wallpaper
```

Native binaries for win, mac and linux are prebuilt and downloaded when the module is installed.

Documentation
-------------

**Example**

```js
const WindowWallpaper = require('window-wallpaper');

```
