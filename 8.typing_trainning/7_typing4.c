# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "getputch.h"

# define NO      15 /* 練習回数 */
# define KTYPE   16 /* ブロック数 */
# define POS_LEN 10 /* ポジショントレーニングの文字数 */

int main(void)
{
  /* 練習メニュー */
  typedef enum {Term, KeyPos, KeyPosComp, Clang, Conversation, InValid} Menu;

  /* 各ブロックのキー */
	char *kstr[] = {"12345",  "67890-^\\",	/* 第1段         */
				          "!\"#$%", "&'() =~|",		/* 第1段 [Shift] */
                  "qwert",  "yuiop@[",		/* 第2段         */
                  "QWERT",  "YUIOP`{",		/* 第2段 [Shift] */
                  "asdfg",  "hjkl;:]",		/* 第3段         */
                  "ASDFG",  "HJKL+*}",		/* 第3段 [Shift] */
                  "zxcvb",  "nm,./\\",		/* 第4段         */
                  "ZXCVB",  "NM<> _",			/* 第4段 [Shift] */
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

  /* 英会話 */
  char *vstr[] = {
    "Hello!",
    "How are you?",
    "Fine thanks.",
    "I can't complain, thanks.",
    "How do you do?",
    "Good bye!",
    "Good morning!",
    "Good afternoon!",
    "Good evening!",
    "See you later!",
    "Go ahead, Please.",
    "Thank you.",
    "No, thank you.",
    "May I have your name?",
    "I'm glad to meet you.",
    "What time is it now?",
    "It's about seven.",
    "I must go now.",
    "How much?",
    "Where is the restroom?",
    "Excuse me.",
    "Excuse us.",
    "I'm sorry.",
    "I don't know.",
    "I have no change with me.",
    "I will be back.",
    "Are you going out?",
    "I hope I'm not disturbing you.",
    "I'll offer no excuse.",
    "Shall we dance?",
    "Will you do me a favor?",
    "It's very unseasonable.",
    "You are always welcome.",
    "Hold still!",
    "Follow me.",
    "Just follow my lead.",
    "To be honest with you,",
  };

  /* 文字列strをタイプ練習（ミス回数を返す） */
  int go(const char *str)
  {
    int i;
    int len = strlen(str); /* 文字数 */
    int mistake = 0;       /* ミス回数 */

    for (i = 0; i < len; i++) {
      printf("%s \r", &str[i]);/* str[i]以降を表示してカーソルを先頭へ戻す */
      fflush(stdout);
      while(getch() != str[i])
        mistake++;
    }
    return mistake;
  }
}