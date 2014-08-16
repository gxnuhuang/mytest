cp $1 $1.back
echo 修改配置文件使其符合数组要求:$1
sed 's/w /,0x/' $1>>mleod_sed1 #替换w 为,0x
sed '$d' mleod_sed1>>mleod_sed2 #删除最后一行
sed '1d' mleod_sed2>>mleod_sed3 #替换w 为,0x

echo  >>mleod_sed4 #在文件末尾追加 回车
echo "{" >>mleod_sed4 #在文件末尾追加 }
echo "0xff,0x00//page0" >>mleod_sed4 #在文件末尾追加 0xff,0x00//page0
cat mleod_sed3 >> mleod_sed4 #在文件末尾追加 文件 mleod_sed3 内容

rm $1  #清除$1文件
touch $1

sed 's/ /,0x/' mleod_sed4>>$1 #替换
rm -rf mleod_sed1 mleod_sed2 mleod_sed3 mleod_sed4 #删除文件

#sed '$d' $1 >> mleod_sed1
echo ,0xfe, >>$1 #在文件末尾追加 ,0xfe,
echo "}" >>$1 #在文件末尾追加 }
echo  >>$1 #在文件末尾追加 回车

