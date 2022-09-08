#
# COMPILER
#
CC := clang
#
# [XOPEN:600 POSIX:200112L] SUSv3 / UNIX 03 / POSIX.1-2001 / XPG6
# [XOPEN:700 POSIX:200809L] SUSv4 / UNIX 08 / POSIX.1-2008 / XPG7
#
PORTABILITY := -D_XOPEN_SOURCE=700 -D_POSIX_C_SOURCE=200809L
#
# CONSISTENCY
#
WARNINGS := #-Wno-long-long -Wall -pedantic -Werror
#
# INSPECTION
#
DEBUG := -g -ggdb
#
# STRUCTURE
#
CCFLAGS := -Iinc $(PORTABILITY) $(WARNINGS) $(DEBUG)

LDFLAGS := 
#
# DEPENDENCIES
#
HEADERS := inc/*.h

SOURCES := src/*.c


urlencode: $(HEADERS) $(SOURCES) main/urlencode.c
	$(CC) $(CCFLAGS) -o $@ $(SOURCES) main/urlencode.c $(LDFLAGS)

clean:
	rm -f urlencode
