#!/bin/bash
#这里所有的操作都是针对regular_express.txt文件
#反向截取，当该行中没有“the”字符，才显示出来。
echo -e "反向截取，当该行中没有“the”字符，才显示出来。"
grep -vn "the" regular_express.txt 
echo " "

echo -e "忽略大小写"
grep -in "the" regular_express.txt 

echo " "
echo "如果我想要搜寻 test 或者 taste 这两个单字,[]里面不论有几个字符，它都只代表一个字符"
 grep -n 't[ae]st' regular_express.txt
echo " "

#搜索 oo
grep -n 'oo' regular_express.txt

#不想oo前面有g
grep -n '[^g]oo' regular_express.txt
#00前面不要有小写字符
grep -n '[^a-z]oo' regular_express.txt 

行首是the
grep -n '^the' regular_express.txt
#开头是小写字母的行
grep -n '^[a-z]' regular_express.txt

#不想要开头是英文字母
grep -n '^[^a-zA-Z]' regular_express.txt
^ 符号, 在 [] 内代表『反向选择』,在 [] 外则代表定位在行首的意义

#以小数点.结尾的行，值得注意的是小数点.得用跳脱字符\
grep -n '\.$' regular_express.txt

#找出空白行
grep -n '\.$' regular_express.txt

#不要空白行也不要#开头的行
grep -v '^$' /etc/syslog.conf | grep -v '^#'
#找出gxxd的四个字符
grep -n 'g..d' regular_express.txt


#查找gog, goog, gooog.... 等等
grep -n 'goo*g' regular_express.txt
#找到有两个o的字符
grep -n 'o\{2\}' regular_express.txt
#找出g后面有2到5个o
grep -n 'go\{2,5\}g' regular_express.txt
#找出两个o以上的
grep -n 'go\{2,\}g' regular_express.txt

