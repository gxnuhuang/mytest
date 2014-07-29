uts_len := 64
define filechk_utsrelease.h
	if [ `echo -n "$(KERNELRELEASE)" | wc -c ` -gt $(uts_len) ]; then \
	  echo '"$(KERNELRELEASE)" exceeds $(uts_len) characters' >&2;    \
	  exit 1;                                                         \
	fi;                                                               \
	(echo \#define UTS_RELEASE \"$(KERNELRELEASE)\";)
endef

define filechk_version.h
	(echo \#define LINUX_VERSION_CODE $(shell                             \
	expr $(VERSION) \* 65536 + 0$(PATCHLEVEL) \* 256 + 0$(SUBLEVEL));    \
	echo '#define KERNEL_VERSION(a,b,c) (((a) << 16) + ((b) << 8) + (c))';)
endef

version.h:
	echo \#define huang 123 $(shell date) >version.h; 
