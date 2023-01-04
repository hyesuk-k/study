#!/bin/bash

if [[ ${#} = 0 ]]; then
    echo "plz input problem NO. (IN acmicpc) "
    exit 1;
else
    CASE_NUM=${1}
    # 문제 번호 입력 시 
    # CASE_TXT=$(curl -s https://www.acmicpc.net/problem/${CASE_NUM} | sed -n "s/^.*<title>\(.*\)<\/title>.*$/\1/p" )
    #  >> 403 Forbidden
    
    # USE solved ac api
    URL='https://solved.ac/api/v3/problem/show?problemId='${CASE_NUM}
    CASE_TXT=$(curl --request GET  --url ${URL} --header 'Content-Type: application/json')
    CASE_KO_NAME=$(echo $CASE_TXT | jq '.titleKo')
    CASE_KEY=$(echo $CASE_TXT | jq '.tags[0].key' | sed 's/\"//g')
    FILE_NAME=${CASE_NUM}.cc

    echo "// ${CASE_KO_NAME}" >> ${FILE_NAME}
    echo "// CATEGORY : ${CASE_KEY}" >> ${FILE_NAME}

    if [ ! -e $CASE_KEY ];then
        mkdir $CASE_KEY
    fi
    mv ${FILE_NAME} $CASE_KEY

    echo "Done. make ${FILE_NAME}"
fi



