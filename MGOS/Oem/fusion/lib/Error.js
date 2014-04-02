/**
 * Fusion.Error
 *
 * $Id: Error.js 2827 2014-02-08 17:41:35Z jng $
 *
 * Copyright (c) 2007, DM Solutions Group Inc.
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

/*****************************************************************************
 * Class: Fusion.Error
 *
 * General purpose Error object
 */

Fusion.Error = OpenLayers.Class({
    type: null,
    message: null,
    initialize: function(type, message) {
        this.type = type;
        this.message = message;
    },
    
    alert: function() {
        var type = this.typeToString(this.type);
        alert(OpenLayers.i18n('fusionError', {'type':type, 'message': this.message}));
    },
    
    toString: function() {
        var type = this.typeToString(this.type);
        return type + ": " + this.message;
    },
    
    typeToString: function(type) {
        switch (type) {
            case Fusion.Error.FATAL:
                return 'FATAL';
            case Fusion.Error.WARNING:
                return 'WARNING';
            case Fusion.Error.NOTICE:
                return 'NOTICE';
            default:
                return 'UNKNOWN ('+type+')';
        }
    }
});

Fusion.DetailedError = OpenLayers.Class({
    message: null,
    name: null,
    incomplete: true,
    partial: true,
    stack: [],
    url: null,
    useragent: null,
    initialize: function(o) {
        this.message = o.message;
        this.name = o.name || "Error";
        this.incomplete = o.incomplete;
        this.partial = o.partial;
        this.stack = o.stack;
        this.url = o.url;
        this.useragent = o.useragent;
    }
});

Fusion.Error.FATAL = 0;
Fusion.Error.WARNING = 1;
Fusion.Error.NOTICE = 2;


