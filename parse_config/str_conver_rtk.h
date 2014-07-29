#ifndef __STR_CONVER_RTK_H
#define __STR_CONVER_RTK_H

#include"common_rtk.h"

/*function declare*/
int RTK_strcmp(const char *s1, const char *s2);
char * RTK_config_get_line(char *s, int size, FILE *stream, int *line,
				  char **_pos);
char * RTK_strchr(const char *s, int c);
size_t RTK_strlen(const char *s);
char * RTK_strrchr(const char *s, int c);

/* getopt - only used in main.c */
int getopt(int argc, char *const argv[], const char *optstring);
extern char *optarg;
extern int optind;
#endif



