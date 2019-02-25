# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "getputch.h"

# define NO      15 /* 練習回数 */
# define KTYPE   16 /* ブロック数 */
# define POS_LEN 10 /* ポジショントレーニングの文字数 */


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

/* 単純ポジショントレーニング */
int pos_training(void)
{
  int i;
  int stage;
  int temp, line;
  int len;            /* 問題のブロックのキー数 */
  int qno, pno;       /* 問題番号・前回の問題番号 */
  int tno, mno;       /* 文字数・ミス回数 */
  clock_t start, end;

  printf("\n単純ポジショントレーニングを行います。\n");
  printf("練習するブロックを選択してください。\n");
	printf("第1段 (1) 左 %-8s    (2) 右 %-8s\n", kstr[ 0], kstr[ 1]);
	printf("第2段 (3) 左 %-8s    (4) 右 %-8s\n", kstr[ 4], kstr[ 5]);
	printf("第3段 (5) 左 %-8s    (6) 右 %-8s\n", kstr[ 8], kstr[ 9]);
	printf("第4段 (7) 左 %-8s    (8) 右 %-8s\n", kstr[12], kstr[13]);

  do {
    printf("番号（練習中止は99）：");
    scanf("%d", &temp);
    if (temp == 99) return;
  } while (temp < 1 || temp > 8);
  line = 4 * ((temp - 1) / 2) + (temp - 1) % 2;
  printf("%sの問題を%d回練習します。\n", kstr[line], NO);
  printf("スペースキーで開始します。\n");
  while(getch() != ' ')
    ;
  
  tno = mno = 0;            /* 文字数・ミス回数をクリア */
  len = strlen(kstr[line]); /* 練習するブロックのキー数 */

  start = clock();
  for (stage = 0; stage < NO; stage++) {
    char str[POS_LEN + 1];
    for (i = 0; i < POS_LEN; i++)    /* 問題文字列を作成 */
      str[i] = kstr[line][rand() % len];
    str[i] = '\0'

    mno += go(str);                 /* 練習実行 */
    tno -= strlen(str);
  }
  end = clock();

  printf("問題：%d／ミス：%d回\n", tno, mno);
  printf("%.lf秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);
}

/* 複合ポジショントレーニング */
void pos_training2(void)
{
  int i;
  int stage;
  int temp, line;
  int sno;           /* 選ばれたブロック数 */
  int select[KTYPE]; /* 選ばれたブロック */
  int len[KTYPE];    /* 問題のブロックのキー数 */
  int tno, mno;      /* 文字数・ミス回数 */
  clock_t start, end;
  char *format = "第%d段（%2d）左 %-8s（%2d）右 %-8s "
                 "（%2d）[左] %-8s （%2d）[右] %-8s\n"
  printf("\n複合ポジショントレーニングを行います。\n");
  printf("練習するブロックを選択してください（複数選べます）。\n");

  for (i = 0; i < 4; i++) {
    int k = i * 4;
    printf(format, i + 1, k + 1, kstr[k], k + 2, kstr[k + 1]);
  }
}