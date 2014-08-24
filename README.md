mytest
======

管理自己编写的一些应用程序或者脚本工具命令的应用

添加shell_dir记录shell脚本编写
添加编译ti-sdk-am335x-evm-05.06.00.00里的wifi驱动的build_wifi.sh脚本
添加make_modules来记录编译内核非源码目录的模块，测试解决insmod的unknown symbol in module or invalid parameter错误。（将mod1编译完之后，拷贝其生成的Module.symvers到mod2的目录下，再编译mod2即可）
添加wine_dir目录，记录wine软件的学习过程。wine_dir目录下的×,reg文件可解决linux下wine安装的软件字体模糊不清的问题，在终端输入regedit，打开regedit，将*.reg文件导入注册表就行了。
