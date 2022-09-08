/*
 * Syntelos URLENCODE
 * Copyright (C) 2022, John Pritchard, Syntelos
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * (LGPL and GPL) as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the LGPL
 * and GPL for more details.
 *
 * You should have received a copy of the LGPL and GPL along with this
 * program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "urlencode.h"
#include <stdlib.h>
#include <string.h>

char enhex(int nibble){
    if (10 > nibble){

        return ('0'+nibble);
    }
    else {

        return ('A'+(nibble-10));
    }
}

char* urlencode(char *plaintext){
    if (null != plaintext){
        size_t length = strlen(plaintext);
        if (0 < length){
            off_t cnt = length;
            off_t idx;
            char *sp = plaintext;

            for (idx = 0; idx < cnt; idx++, sp++){

                char ch = *sp;
                if (('0' <= ch && ch <= '9')||
                    ('a' <= ch && ch <= 'z')||
                    ('A' <= ch && ch <= 'Z'))
                {
                    continue;
                }
                else {
                    length += 2;
                }
            }

            sp = plaintext;

            char *encoded = calloc(length+1,sizeof(char));
            char *ep = encoded;

            for (idx = 0; idx < cnt; idx++, sp++){

                char ch = *sp;
                if (('0' <= ch && ch <= '9')||
                    ('a' <= ch && ch <= 'z')||
                    ('A' <= ch && ch <= 'Z'))
                {
                    *ep++ = ch;
                }
                else {
                    *ep++ = '%';
                    *ep++ = enhex((ch & 0xF0)>>4);
                    *ep++ = enhex((ch & 0x0F));
                }
            }

            return encoded;
        }
    }
    return null;
}
