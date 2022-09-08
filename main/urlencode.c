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
#include <stdio.h>

int main(int argc, char **argv){

    if (1 < argc){

        char *out = urlencode(argv[1]);

        if (null != out){
            fprintf(stdout,"%s\n",out);

            return 0;
        }
        else {
            fprintf(stderr,"%s error encoding input '%s'.\n",argv[0],argv[1]);
            return 1;
        }
    }
    else {
        fprintf(stderr,"usage: %s <url>\n",argv[0]);
        return 1;
    }
}
