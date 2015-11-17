#!/bin/sh
#
# Copyright (C) 2011-2015  pancake <pancake@nopcode.org>
# Copyright (C) 2011-2012  Edd Barrett <vext01@gmail.com>
# Copyright (C) 2012       Simon Ruderich <simon@ruderich.org>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

cd `dirname $0` 2>/dev/null

radare2 -v
if [ $? != 0 ]; then
	echo "Cannot find radare2"
	exit 1
fi

# Statistics.
TESTS_TOTAL=0
TESTS_SUCCESS=0
TESTS_FAILED=0
TESTS_BROKEN=0
TESTS_FIXED=0
TESTS_FATAL=0

# Let tests.sh know the complete test suite is run, enables statistics.
R2_SOURCED=1

control_c() {
  echo
  exit 1
}
trap control_c 2

. ./tests.sh

radare2 > /dev/null
if [ $? != 0 ]; then
  echo "Cannot find radare2"
  exit 1
fi


R=$PWD
# Run all tests.
T="t"; [ -n "$1" ] && T="$1"
if [ -f "$T" -a -x "$T" ]; then
  BDIR=`dirname $T`
  FILE=`basename $T`
  cd $BDIR
  . ./$FILE
else
cd $T || die "t/ doesn't exist"
for file in * ; do
   [ "$file" = '*' ] && break
   if [ -d "$file" ]; then
      cd $file
      for file2 in *; do
         [ "$file2" = '*' ] && break
         TEST_NAME=$(echo "${file2}" | sed 's/.sh$//')
	 NAME=`basename $file2`
         TEST_NAME=$file
         if [ -f "${file2}" ]; then
           . ./${file2}
         fi
      done
      cd ..
   elif [ ! -x "$file" ]; then	# Only run files marked as executable.
      print_found_nonexec "$file"
   else
      NAME=`basename $file`
      TEST_NAME=$NAME
      . ./${file}
   fi
done
fi

if [ -z "${NOREPORT}" ]; then
	print_report
fi

# Save statistics
cd $R
V=`radare2 -v 2>/dev/null| grep ^rada| awk '{print $5}'`
touch stats.csv
grep -v "^$V" stats.csv > .stats.csv
echo "$V,${TESTS_SUCCESS},${TESTS_FIXED},${TESTS_BROKEN},${TESTS_FAILED},${TESTS_FATAL},${FAILED}" >> .stats.csv
sort .stats.csv > stats.csv
rm -f .stats.csv

# Exit codes, as documented in README.md
if [ "${TESTS_FATAL}" -gt 0 ]; then
  echo "ESSENTIAL TEST HAS FAILED"
  exit 1
elif [ "${TESTS_FAILED}" -gt 0 ]; then
  exit 2
else
  exit 0
fi
