// @ts-check

/**
 * @module window-desktop
 */

'use strict'

const bindings = require('bindings')
const wd = bindings('window-desktop')

/**
 * @summary Attach a window as wallpaper
 * @function
 * @public
 *
 * @param {import('electron').BrowserWindow} window - Window to attach as wallpaper
 *
 * @example
 * const windowDesktop = require('window-desktop');
 * const currentWindow = require('electron').remote.getCurrentWindow();
 *
 * windowDesktop.attachAsWallpaper(currentWindow);
 */
exports.attachAsWallpaper = function attachAsWallpaper (window) {
  wd.attachAsWallpaper(window.getNativeWindowHandle())
}

/**
 * @summary Attach a window as icons
 * @function
 * @public
 *
 * @param {import('electron').BrowserWindow} window - Window to attach as icons
 *
 * @example
 * const windowDesktop = require('window-desktop');
 * const currentWindow = require('electron').remote.getCurrentWindow();
 *
 * windowDesktop.attachAsIcons(currentWindow);
 */
exports.attachAsIcons = function attachAsIcons (window) {
  wd.attachAsIcons(window.getNativeWindowHandle())
}

/**
 * @summary Detach a window
 * @function
 * @public
 *
 * @param {import('electron').BrowserWindow} window - Window to detach
 *
 * @example
 * const windowDesktop = require('window-desktop');
 * const currentWindow = require('electron').remote.getCurrentWindow();
 *
 * windowDesktop.detachWindow(currentWindow);
 */
exports.detachWindow = function detachWindow (window) {
  wd.detachWindow(window.getNativeWindowHandle())
}