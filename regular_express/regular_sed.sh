#!/bin/bash
注意：ed 后面接的动作,请务必以 '' 两个单引号括住！
删除2到5行
nl /etc/passwd | sed '2,5d'
删除第2行
nl /etc/passwd | sed '2d'
删除第3到最后一行
nl /etc/passwd | sed '3,$d'
在第二行后(亦是加在第三行)加上『drink tea?』字样
nl /etc/passwd | sed '2a drink tea'
在第二行后面加入两行字,例如『Drink tea or .....』和『drink
nl /etc/passwd | sed '2a Drink tea or .....\
> huang'
将第2到5行的内容取代为No 2-5 number
nl /etc/passwd | sed '2,5c No 2-5 number'
仅列出第5-7行
nl /etc/passwd | sed -n '5,7p'

sed 's/要被叏代癿字符串/新癿字符串/g'
查找包含MAN的行，并且删除有#的行
cat /etc/man.config | grep 'MAN'| sed 's/#.*$//g'
删除空白行
sed '/^$/d'
-i 选项可以讥你癿 sed 直接去修改后面接癿档案内容而丌是由屏幕输出
sed -i 's/\.$/\!/g' regular_express.txt
在最后一行添加  # This is a test 直接作用与文件
sed -i '$a # This is a test' regular_express.txt

