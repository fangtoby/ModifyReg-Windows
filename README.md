# ModifyReg-Windows

modify windows reg

		gcc -o modifyReg.exe modifyReg.c

		modifyReg

		input new reg item name

		>hello

		input new reg item software path <C:\Program Files (x86)\Koala\koala.exe>

		>"C:\Program Files (x86)\Koala\koala.exe"

		set success.

快捷键 windows + r

在运行里面输入 regedit 查看注册表 

# Linux 开机启动程序说明

Method 1

		chkconfig smb on

Method 2

		vi /etc/rc.d/rc.local
		#add line you program in the end
		#like /usr/local/samba/sbin/nmbd -D 

