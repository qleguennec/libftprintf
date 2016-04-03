#!/bin/bash

PROJECT=$(make -s get-PROJECT)

if [ -z "$RENDU_DIR" ]; then
	RENDU_DIR="/tmp/$PROJECT"
else
	RENDU_DIR="$RENDU_DIR/$PROJECT"
fi

if [ -d "$RENDU_DIR" ]; then
	rm -rf $RENDU_DIR
fi

mkdir -p $RENDU_DIR
if [ -z "$MAKEFILE_DIR" ]; then
	MAKEFILE_DIR="./"
fi

CPY=(auteur includes src "$MAKEFILE_DIR/Makefile" src.mk lib)

for DIR in ${CPY[@]}; do
	cp -r $DIR $RENDU_DIR 2> /dev/null
done

[ -n "$MAKE" ] && make -C $RENDU_DIR $MAKE
ls -la $RENDU_DIR
