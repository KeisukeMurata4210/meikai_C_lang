# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "getputch.h"

# define NO       15/* トレーニング回数 */
# define KTYPE    16/* ブロック数 */
# define POS_LEN  10/* ポジショントレーニングの文字数 */

/* 練習メニュー */
typedef enum { Term, KeyPos, KeyPosComp, Conversation, InValid } Menu;

/* 各ブロックのキー */
char *kstr[] = {
	"12345",  "67890-^\\",	/* 第１段         */
	"!\"#$%", "&'()=~|",		/* 第１段 [Shift] */
	"qwert",  "yuiop@[",		/* 第２段         */
	"QWERT",  "YUIOP`{",		/* 第２段 [Shift] */
	"asdfg",  "hjkl;:]",		/* 第３段         */
	"ASDFG",  "HJKL+*}",		/* 第３段 [Shift] */
	"zxcvb",  "nm,./\\",		/* 第４段         */
	"ZXCVB",  "NM<>?_",			/* 第４段 [Shift] */
};

/* C言語のキーワードとライブラリ関数 */
char *cstr[] = {
	"auto",		"break",	"case",		"char",		"const",	"continue",
	"default",	"do",		"double",	"else",		"enum",		"extern",
	"float",	"for",		"goto",		"if",		"int",		"long",
	"register",	"return",	"short",	"signed",	"sizeof",	"static",
	"struct",	"switch",	"typedef",	"union",	"unsigned",	"void",
	"volatile",	"while",
	"abort",	"abs",		"acos",		"asctime",	"asin",		"assert",
	"atan",		"atan2",	"atexit",	"atof",		"atoi",		"atol",
	"bsearch",	"calloc",	"ceil",		"clearerr",	"clock",	"cos",
	"cosh",		"ctime",	"difftime",	"div",		"exit",		"exp",
	"fabs",		"fclose",	"feof",		"ferror",	"fflush",	"fgetc",
	"fgetpos",	"fgets",	"floor",	"fmod",		"fopen",	"fprintf",
	"fputc",	"fputs",	"fread",	"free",		"freopen",	"frexp",
	"fscanf",	"fseek",	"fsetpos",	"ftell",	"fwrite",	"getc",
	"getchar",	"getenv",	"gets",		"gmtime",	"isalnum",	"isalpha",
	"iscntrl",	"isdigit",	"isgraph",	"islower",	"isprint",	"ispunct",
	"isspace",	"isupper",	"isxdigit",	"labs",		"ldexp",	"ldiv",
	"localeconv",			"localtime","log",		"log10",	"longjmp",
	"malloc",	"memchr",	"memcmp",	"memcpy",	"memmove",	"memset",
	"mktime",	"modf",		"perror",	"pow",		"printf",	"putc",
	"putchar",	"puts",		"qsort",	"raise",	"rand",		"realloc",
	"remove",	"rename",	"rewind",	"scanf",	"setbuf",	"setjmp",
	"setlocale","setvbuf",	"signal",	"sin",		"sinh",		"sprintf",
	"sqrt",		"srand",	"sscanf",	"strcat",	"strchr",	"strcmp",
	"strcoll",	"strcpy",	"strcspn",	"strerror",	"strftime",	"strlen",
	"strncat",	"strncmp",	"strncpy",	"strpbrk",	"strrchr",	"strspn",
	"strstr",	"strtod",	"strtok",	"strtol",	"strtoul",	"strxfrm",
	"system",	"tan",		"tanh",		"time",		"tmpfile",	"tmpnam",
	"tolower",	"toupper",	"ungetc",	"va_arg",	"va_end",	"va_start",
	"vfprintf", "vprintf",	"vsprintf"
};

/* 英単語 */
char *vstr[] = {
	"Hello!",							/* ����ɂ��́B*/
	"How are you?",						/* �����C�ł����B */
	"Fine thanks.",						/* �͂����C�ł��B */
	"I can't complain, thanks.",		/* �܂��A���Ƃ��B */
	"How do you do?",					/* ���߂܂��āB */
	"Good bye!",						/* ���悤�Ȃ�B */
	"Good morning!",					/* ���͂悤�B */
	"Good afternoon!",					/* ����ɂ��́B */
	"Good evening!",					/* ����΂�́B */
	"See you later!",					/* ���悤�Ȃ�i�܂��ˁj�B */
	"Go ahead, Please.",				/* ����ɂǂ����B */
	"Thank you.",						/* ���肪�Ƃ��B */
	"No, thank you.",					/* ���������\�ł��B */
	"May I have your name?",			/* �����O�́H */
	"I'm glad to meet you.",			/* ���ڂɂ�����Č��h�ł��B */
	"What time is it now?",				/* �����ł����B */
	"It's about seven.",				/* ��̂V�����炢�ł��B */
	"I must go now.",					/* ���������Ȃ�����B */
	"How much?",						/* ��������H */
	"Where is the restroom?",			/* ����􂢂͂ǂ���ł����B */
	"Excuse me.",						/* ���炵�܂��i��l�j�B*/
	"Excuse us.",						/* ���炵�܂��i��l�ȏ�j�B*/
	"I'm sorry.",						/* ���߂�Ȃ����B */
	"I don't know.",					/* �����A�m��Ȃ���B */
	"I have no change with me.",		/* ���K���Ȃ��̂ł��B */
	"I will be back.",					/* �܂��߂��ė��܂��B */
	"Are you going out?",				/* �o������́H */
	"I hope I'm not disturbing you.",	/* ���ז�����Ȃ���΂����̂ł����B*/
	"I'll offer no excuse.",			/* �ى��������͂���܂���B */
	"Shall we dance?",					/* �x��܂��񂩁B */
	"Will you do me a favor?",			/* ������Ƃ��肢�������̂ł����B */
	"It's very unseasonable.",			/* ����͋G�ߊO�ꂾ�ˁB */
	"You are always welcome.",			/* ���ł����}���܂���B */
	"Hold still!",						/* �����Ƃ��āI */
	"Follow me.",						/* �t���ė��āB */
	"Just follow my lead.",				/* �l�̂���Ƃ���ɂ�邾������B */
	"To be honest with you,",			/* �����Ɍ����Ɓc */
};

void pos_training(void)
{
  int i;
  int stage;
  int temp, line;    /* ブロック入力・kstrの添字 */
  int len;           /* 問題のブロックのキー数 */
  int qno, pno;      /* 問題番号・前回の問題番号 */
  int tno, mno;      /* 文字数・ミス回数 */
  clock_t start, end;/* 開始時刻・終了時刻 */

  printf("\n単純ポジショントレーニングを行います。\n");
  printf("練習するブロックを選択してください。\n");
  printf("第1段（1）左 %-8s   （2）右 %-8s\n", kstr[ 0], kstr[ 1]);
  printf("第2段（3）左 %-8s   （4）右 %-8s\n", kstr[ 4], kstr[ 5]);
  printf("第3段（5）左 %-8s   （6）右 %-8s\n", kstr[ 8], kstr[ 9]);
  printf("第4段（7）左 %-8s   （8）右 %-8s\n", kstr[12], kstr[13]);

  /* ブロックを選択させる */
  do {
    printf("番号（練習中止は99）：");
    scanf("%d", &temp);
    if (temp == 99) return;
  } while(temp < 1 || temp > 8);
  line = 4 * ((temp - 1) / 2) + (temp - 1) % 2;/* 右辺は偶数の時1、奇数の時0 →左辺は1357を048(12)に変換する式にすればいい */

  printf("%sの問題を%d回練習します。\n", kstr[line], NO);
  printf("スペースキーで開始します。\n");
  while (getch() != ' ')
    ;
  tno = mno = 0;            /* 文字数・ミス回数をクリア */
  len = strlen(kstr[line]); /* 練習するブロックのキー数 */

  start = clock();
  for (stage = 0; stage < NO; stage++) {
    char str[POS_LEN + 1];
    for (i = 0; i < POS_LEN; i++)     /* 問題文字列を作成 指定した段からランダムに10文字表示される */
      str[i] = kstr[line][rand() % len];
    str[i] = '\0';
    mno += go(str);/* 練習実行 */
  }
}

/* メニュー選択 */
Menu SelectMenu(void)
{
  int ch;
  do {
    printf("\n練習を選択してください。\n");
    printf("（1）単純ポジション （2）複合ポジション\n");
    printf("（3）C言語の単語   （4）英会話   （0）終了：");
    scanf("%d", &ch);
  } while(ch < Term || ch >= InValid);
  return (Menu)ch;
}

int main(void)
{
  Menu menu;
  int cn = sizeof(cstr) / sizeof(cstr[0]);/* C言語の単語数 */
  int vn = sizeof(vstr) / sizeof(vstr[0]);/* 英単語の文書数 */
  init_getputch();
  srand(time(NULL));

  do {
    switch (menu = SelectMenu()){
      case KeyPos:
        pos_training();
        break;
    }
  }while(menu != Term);
}