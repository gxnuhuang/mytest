# ~/.bashrc: executed by bash(1) for non-login shells.
# see /usr/share/doc/bash/examples/startup-files (in the package bash-doc)
# for examples

# If not running interactively, don't do anything
case $- in
    *i*) ;;
      *) return;;
esac

# don't put duplicate lines or lines starting with space in the history.
# See bash(1) for more options
HISTCONTROL=ignoreboth

# append to the history file, don't overwrite it
shopt -s histappend

# for setting history length see HISTSIZE and HISTFILESIZE in bash(1)
HISTSIZE=1000
HISTFILESIZE=2000

# check the window size after each command and, if necessary,
# update the values of LINES and COLUMNS.
shopt -s checkwinsize

# If set, the pattern "**" used in a pathname expansion context will
# match all files and zero or more directories and subdirectories.
#shopt -s globstar

# make less more friendly for non-text input files, see lesspipe(1)
[ -x /usr/bin/lesspipe ] && eval "$(SHELL=/bin/sh lesspipe)"

# set variable identifying the chroot you work in (used in the prompt below)
if [ -z "${debian_chroot:-}" ] && [ -r /etc/debian_chroot ]; then
    debian_chroot=$(cat /etc/debian_chroot)
fi

# set a fancy prompt (non-color, unless we know we "want" color)
case "$TERM" in
    xterm-color) color_prompt=yes;;
esac

# uncomment for a colored prompt, if the terminal has the capability; turned
# off by default to not distract the user: the focus in a terminal window
# should be on the output of commands, not on the prompt
#force_color_prompt=yes

if [ -n "$force_color_prompt" ]; then
    if [ -x /usr/bin/tput ] && tput setaf 1 >&/dev/null; then
	# We have color support; assume it's compliant with Ecma-48
	# (ISO/IEC-6429). (Lack of such support is extremely rare, and such
	# a case would tend to support setf rather than setaf.)
	color_prompt=yes
    else
	color_prompt=
    fi
fi

if [ "$color_prompt" = yes ]; then
    PS1='${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$ '
else
    PS1='${debian_chroot:+($debian_chroot)}\u@\h:\w\$ '
fi
unset color_prompt force_color_prompt

# If this is an xterm set the title to user@host:dir
case "$TERM" in
xterm*|rxvt*)
    PS1="\[\e]0;${debian_chroot:+($debian_chroot)}\u@\h: \w\a\]$PS1"
    ;;
*)
    ;;
esac

# enable color support of ls and also add handy aliases
if [ -x /usr/bin/dircolors ]; then
    test -r ~/.dircolors && eval "$(dircolors -b ~/.dircolors)" || eval "$(dircolors -b)"
    alias ls='ls --color=auto'
    #alias dir='dir --color=auto'
    #alias vdir='vdir --color=auto'

    alias grep='grep --color=auto'
    alias fgrep='fgrep --color=auto'
    alias egrep='egrep --color=auto'
fi

# some more ls aliases
alias ll='ls -alF'
alias la='ls -A'
alias l='ls -CF'

# Add an "alert" alias for long running commands.  Use like so:
#   sleep 10; alert
alias alert='notify-send --urgency=low -i "$([ $? = 0 ] && echo terminal || echo error)" "$(history|tail -n1|sed -e '\''s/^\s*[0-9]\+\s*//;s/[;&|]\s*alert$//'\'')"'

# Alias definitions.
# You may want to put all your additions into a separate file like
# ~/.bash_aliases, instead of adding them here directly.
# See /usr/share/doc/bash-doc/examples in the bash-doc package.

if [ -f ~/.bash_aliases ]; then
    . ~/.bash_aliases
fi

# enable programmable completion features (you don't need to enable
# this, if it's already enabled in /etc/bash.bashrc and /etc/profile
# sources /etc/bash.bashrc).
if ! shopt -oq posix; then
  if [ -f /usr/share/bash-completion/bash_completion ]; then
    . /usr/share/bash-completion/bash_completion
  elif [ -f /etc/bash_completion ]; then
    . /etc/bash_completion
  fi
fi

#add by hzq

alias hwindows='sudo  mount.cifs //172.16.31.133/D /home/gxnuhuang/windows_D/ -o username=gxnuhuang,password=h,uid=1000,gid=1000'
alias hsamba='sudo /etc/init.d/smbd restart 
	      sudo /etc/init.d/nmbd restart'
# default PATH is /usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games
#export PATH="$PATH:/home/gxnuhuang/ti-sdk-am335x-evm-05.06.00.00/linux-devkit/bin:/home/gxnuhuang/hbin"
export PATH="/home/gxnuhuang/ti-sdk-am335x-evm-05.06.00.00/linux-devkit/bin:/home/gxnuhuang/hbin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games"
alias hcmd='
		echo "-----------------------build uboot-am335x----------------------"
		echo "make CROSS_COMPILE=arm-arago-linux-gnueabi ARCH=arm distclean"
		echo "make O=am335x CROSS_COMPILE=arm-arago-linux-gnueabi- ARCH=arm am335x_evm"
		echo "------------------------build kernel-am335x--------------------"
		echo "make ARCH=arm CROSS_COMPILE=arm-arago-linux-gnueabi- mrproper"
		echo "make ARCH=arm CROSS_COMPILE=arm-arago-linux-gnueabi- am335x_evm_defconfig"
		echo "make ARCH=arm CROSS_COMPILE=arm-arago-linux-gnueabi- menuconfig"
		echo "make ARCH=arm CROSS_COMPILE=arm-arago-linux-gnueabi- uImage"
		echo "make ARCH=arm CROSS_COMPILE=arm-arago-linux-gnueabi- modules"
	   '
alias huboot='make O=am335x CROSS_COMPILE=arm-arago-linux-gnueabi- ARCH=arm am335x_evm'
alias hnfs='
			sudo exportfs -r
			sudo /etc/init.d/nfs-kernel-server stop
			sudo /etc/init.d/nfs-kernel-server start	
			'
alias hcommd='gedit /data_h/commom_cmd/com_cmd.txt'
#end by hza
QMAKESPEC=/home/gxnuhuang/ti-sdk-am335x-evm-05.06.00.00/linux-devkit/arm-arago-linux-gnueabi/usr/share/qtopia/mkspecs/linux-g++;export QMAKESPEC; # ADDED BY INSTALLER - DO NOT EDIT OR DELETE THIS COMMENT - AB1C36D0-2B62-930A-B1CF-1B15CF69BE47 4E0F9702-85E7-E8F2-252A-A4CC926009BC
