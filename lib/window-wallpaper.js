// @ts-check

/**
 * @module window-wallpaper
 */

'use strict'

const bindings = require('bindings')
const ww = bindings('window-wallpaper')

/**
 * @summary Attach a window as wallpaper
 * @function
 * @public
 *
 * @param {import('electron').BrowserWindow} window - Window to attach as wallpaper
 *
 * @example
 * const electronWallpaper = require('window-wallpaper');
 * const currentWindow = require('electron').remote.getCurrentWindow();
 *
 * electronWallpaper.attachWindow(currentWindow);
 */
exports.attachWindow = function attachWindow (window) {
  ww.attachWindow(window.getNativeWindowHandle())
}

/**
 * @summary Detach a window
 * @function
 * @public
 *
 * @param {import('electron').BrowserWindow} window - Window to detach
 *
 * @example
 * const electronWallpaper = require('window-wallpaper');
 * const currentWindow = require('electron').remote.getCurrentWindow();
 *
 * electronWallpaper.attachWindow(currentWindow);
 */
exports.detachWindow = function detachWindow (window) {
  ww.detachWindow(window.getNativeWindowHandle())
}