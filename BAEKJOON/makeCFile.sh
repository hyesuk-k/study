#!/bin/bash

if [[ ${#} = 0 ]]; then
    echo "plz input problem NO. (IN acmicpc) "
    exit 1;
else
    CASE_NUM=${1}
    # 문제 번호 입력 시 
    CASE_TXT=$(curl -s https://www.acmicpc.net/problem/${CASE_NUM} | sed -n "s/^.*<title>\(.*\)<\/title>.*$/\1/p" )

    FILE_NAME=${CASE_NUM}.cc

    echo "// ${CASE_TXT}" >> ${FILE_NAME}

    echo "Done. make ${FILE_NAME}"
fi



