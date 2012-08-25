/*
 * main.c
 *
 *  Created on: Aug 22, 2012
 *      Author: timothy
 */

#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

int main()
{
	u32 CurTime[5] = {0};
	int num;
	int i;
	char *lrc, *p;
	Node *first;
	double start, end;
	LrcData Lrc;
	char *lrc_buff ="[00:04.10]Hmm, yeah, yeah\n"
					"[00:09.80]Baby, please try to forgive me\n"
					"[00:19.50]Stay here don't put out the glow\n"
					"[00:29.17]Hold me now don't bother\n"
					"[00:33.75]If every minute it makes me weaker\n"
					"[00:37.25]You can save me from the man that I've become\n"
					"[00:45.79]Oh yeah\n"
					"[03:11.45][02:51.90][01:48.00][00:47.29]Lookin' back on the things I've done\n"
					"[03:14.70][02:55.50][01:52.70][00:52.04]I was tryin' to be someone\n"
					"[03:19.15][02:59.70][01:57.00][00:56.44]I played my part, kept you in the dark\n"
					"[03:24.53][03:05.40][02:47.29][02:02.33][01:01.74]Now let me show you the shape of my heart\n"
					"[01:10.27]Send in this beautiful loneliness that's tragical\n"
					"[01:19.40]So help me I can't win this war\n"
					"[01:26.11]Oh no\n"
					"[01:29.48]Touch me now don't bother\n"
					"[01:34.19]If every second it makes me weaker\n"
					"[01:37.80]You can save me from the man I've become\n"
					"[02:09.00]I'm here with my confession\n"
					"[02:13.49]Got nothing to hide no more\n"
					"[02:17.40]I don't know where to start\n"
					"[02:22.20]But to show you the shape of my heart\n"
					"[02:32.90]I'm lookin' back on things I've done\n"
					"[02:38.05]I never wanna play the same old part\n"
					"[02:43.25]I'll keep you in the dark\n"
					"[03:30.55]show you the shape of my heart";

//	timeData = curr->tv_sec + curr->tv_usec;
	lrc = malloc(STR_LEN);
	first = InitList();
	start = (double)clock();
	while (*lrc_buff) {
		num = 0;
		if (*lrc_buff == '[') {
			lrc_buff++;
			if (*lrc_buff == '0') {
				while (*lrc_buff == '0') {
					CurTime[num++] = ((*lrc_buff - '0') * 10
							+ (*(lrc_buff + 1) - '0') * 60
							+ (*(lrc_buff + 3) - '0') * 10
							+ (*(lrc_buff + 4) - '0')) * 100
							+ (*(lrc_buff + 6) - '0') * 10
							+ (*(lrc_buff + 7) - '0');
					lrc_buff += 10;
				}
				lrc_buff -= 1;
				p = lrc;

				while (*lrc_buff != '\n' && *lrc_buff) {
					*p++ = *lrc_buff++;
				}
				*p = '\0';

				for (i = 0; i < num; i++) {
					Lrc.time = CurTime[i];
					Lrc.str = (char *)lrc;
					first = InsertList(first, Lrc);
				}
			}
			if (*lrc_buff)
				lrc_buff++;
		}
	}
	end = (double)clock();

//	first = DeleteNode(first, 19915.000000, buff);
//	traverselist(first);
	printf("%f\n", (end - start) / 1000);

	DestroyNode(first);

	return 0;
}
