#!/bin/bash

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

set -e

echo -e "$INFO"Starting moulitest$END
cd test
if [ ! -d "moulitest" ]; then
	git clone http://github.com/yyang42/moulitest.git
fi
sed -i'' 's/\/\/ test->debug/test->debug/g' moulitest/ft_printf_tests/tests/*.spec.c
echo "FT_PRINTF_PATH = /tmp/libftprintf" > moulitest/config.ini
make -s -C moulitest ft_printf
