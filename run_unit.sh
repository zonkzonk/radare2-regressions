#!/bin/sh

# To run with kcov
# export KCOV="kcov /path/to/output"
# kcov output will be placed in the /path/to/output/index.html

echo "test base64"
${KCOV} ./unit/test_base64
echo "test list"
${KCOV} ./unit/test_list
echo "test str"
${KCOV} ./unit/test_str
echo "test hashtable"
${KCOV} ./unit/test_hashtable
echo "test debruijn"
${KCOV} ./unit/test_debruijn
