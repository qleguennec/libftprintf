#!/bin/bash

RENDU_DIR=$(pwd)/test/lib . util/rendu.sh
make -C test re
if [ "$?" -ne 0 ]; then
	exit 1
fi

CK="\033[0;30m"
RED="\033[0;31m"
GREEN="\033[0;32m"
YELLOW="\033[1;33m"
BLUE="\033[0;34m"
MAGENTA="\033[0;35m"
CYAN="\033[0;36m"
WHITE="\033[0;37m"
END="\033[0m"

OK=$GREEN
NOK=$RED
INFO=$CYAN

echo -e "$INFO"Starting tests$END

set -e
test/test-printf
make fclean

echo -e "$INFO"Starting moulitest$END
cp util/Makefile test/lib/libftprintf
cd test
if [ ! -d "moulitest" ]; then
	git clone http://github.com/yyang42/moulitest.git
fi
echo "FT_PRINTF_PATH = $(pwd)/lib/libftprintf" > moulitest/config.ini
make -C moulitest ft_printf
