#!/bin/bash
#在文件查找文件TARGET_FILE中是否包含由文件SOURCE_FILE的字符。
#echo -e "you input is $@"

SOURCE_FILE=$1
TARGET_FILE=$2
for  i  in  `cat ${SOURCE_FILE}`
do
#	echo -e "\033[41;20mhzq:now search : $i in $2 file  \033[0m"
	grep -inR $i $TARGET_FILE > /dev/null
	if [ $? == 0 ]
	then
#找到了
		echo -e "\033[32m hzq---: \"$i\" ------> \"$TARGET_FILE \"  \033[0m"
	else
		echo -e "\033[31m hzq:---------\"$i\"  has not found in \"$TARGET_FILE \"  \033[0m"
	fi
done
