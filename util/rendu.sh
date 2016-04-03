#!/bin/bash

if [ -z "$RENDU_DIR" ]; then
	RENDU_DIR="/tmp/libprintf"
fi

if [ -d "$RENDU_DIR" ]; then
	rm -rf $RENDU_DIR
fi

mkdir -p $RENDU_DIR
if [ -f "util/Makefile" ]; then
	MAKEFILE="util/Makefile"
else
	MAKEFILE="MAKEFILE"
fi

CPY=(auteur includes src $MAKEFILE src.mk)

for DIR in ${CPY[@]}; do
	cp -r $DIR $RENDU_DIR
done

[ -n "$MAKE" ] && make -C $RENDU_DIR $MAKE
ls -la $RENDU_DIR
