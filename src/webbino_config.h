/***************************************************************************
 *   This file is part of Webbino                                          *
 *                                                                         *
 *   Copyright (C) 2012-2019 by SukkoPera                                  *
 *                                                                         *
 *   Webbino is free software: you can redistribute it and/or modify       *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation, either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   Webbino is distributed in the hope that it will be useful,            *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with Webbino. If not, see <http://www.gnu.org/licenses/>.       *
 ***************************************************************************/

#ifndef WEBBINOCOMMON_H_
#define WEBBINOCOMMON_H_

#include <Arduino.h>


/* Network device selection: please enable *only one* of the following,
 * corresponding to the network device you will be using
 */
#define WEBBINO_USE_WIZ5100
//~ #define WEBBINO_USE_WIZ5500
//~ #define WEBBINO_USE_ENC28J60
//~ #define WEBBINO_USE_ENC28J60_UIP
//~ #define WEBBINO_USE_ESP8266
//~ #define WEBBINO_USE_ESP8266_STANDALONE
//~ #define WEBBINO_USE_WIFI
//~ #define WEBBINO_USE_WIFI101
//~ #define WEBBINO_USE_FISHINO
//~ #define WEBBINO_USE_DIGIFI

/* Define to enable serving webpages from SD. This will use Arduino's SD
 * library, which only allows DOS-style (i.e. 8+3 characters) file names. This
 * means that you will have to name your pages with a .htm extension, instead of
 * .html. If you don't like this, install the SdFat library and see below.
 */
//~ #define WEBBINO_ENABLE_SD

/* Define to enable serving webpages from SD. This will use the SDFat
 * library (https://github.com/greiman/SdFat). This library allows access to
 * files with long names (LFNs), if properly configured (see SdFatConfig.h in
 * the library sources).
 */
//~ #define WEBBINO_ENABLE_SDFAT

// Define to enable running functions upon request of certain pages
#define ENABLE_PAGE_FUNCTIONS

// Define to enable HTTP Basic Authorization support
//~ #define ENABLE_HTTPAUTH

/* Maximum length of username:password string
 *
 * Only meaningful if ENABLE_HTTPAUTH is enabled
 */
#define MAX_USERPASS_LEN 32

/* By default only the GET HTTP method/verb is supported (i.e.: all requests are
 * implicitly assumed to be GETS). Define this to enable the parsing of the
 * actual method, which will be available in page functions.
 */
//~ #define ENABLE_ALL_METHODS

/* Enable some features that will help implementing REST services. Note that you
 * should probably enable ENABLE_ALL_METHODS with this.
 */
//~ #define ENABLE_REST

/* Define to enable serving webpages from the ESP8266 integrated filesystem on
 * flash (SPIFFS). By default this is always enabled if compiling for ESP8266
 * standalone.
 */
#ifdef WEBBINO_USE_ESP8266_STANDALONE
#define WEBBINO_ENABLE_SPIFFS
#endif

/* By default, only MIME types for html, css, js, png, jpeg, gif and ico files
 * are enabled. Define this to enable some extra types, namely xml, pdf, zip and
 * gz files.
 */
//~ #define ENABLE_EXTRA_MIMETYPES

/* Define to enable support for tag substitutions, i.e.: replace #TAGS#
 * in served pages
 */
#define ENABLE_TAGS

/* Character that delimits tags - Make sure this is a *byte* and not a char
 */
const byte TAG_CHAR = static_cast<byte> ('$');

/* Maximum length of a tag name
 */
#define MAX_TAG_LEN 24

/* Maximum length of a filename in the Flash storage
 */
#define MAX_FLASH_FNLEN 16

/* Maximum length of a get parameter name and value
 */
#define BUF_LEN 32

/* Maximum length of an URL to process
 */
#define MAX_URL_LEN 128

/* TCP port the server will listen on
 *
 * NOTE: Port 80 can not be used with DigiFi
 * NOTE: Currently changing this will have no effect with most cards, FIXME
 */
#define SERVER_PORT 80

/* Name of the index page, i.e. the page requests for / get redirected to.
 */
#ifdef WEBBINO_ENABLE_SD
// Long File Names are not supported, cope with it
#define REDIRECT_ROOT_PAGE "index.htm"
#else
#define REDIRECT_ROOT_PAGE "index.html"
#endif

/* Size of output buffer. This speeds up transmission, by sending clients more
 * than one character at a time. Size it appropriately according to available
 * RAM. Theoretically it could be reduced to 1, but this has not been tested.
 */
#define CLIENT_BUFSIZE 64

/* DEFINE this to DISABLE debug messages
 */
#define WEBBINO_NDEBUG

/* Enable verbose HTTP request parser
 */
#define VERBOSE_REQUEST_PARSER

#endif
