//#include "printf.h"
#include <stdio.h>
#include <locale.h>

#define PREFIX " >>> "
#define print(format, ...) \
	write(1, PREFIX, strlen(PREFIX)); \
	write(1, format, strlen(format)); \
	{ \
	int MAX_PRINT_WIDTH = 40; \
	int r; \
	printf("\nprintf = \t["); \
	r = printf(format, __VA_ARGS__); \
	printf("]%*s(%d)\nft_printf = \t[", MAX_PRINT_WIDTH - r, " ", r); \
	fflush(stdout); \
	r = ft_printf(format, __VA_ARGS__); \
	printf("]%*s(%d)\n", MAX_PRINT_WIDTH - r, " ", r); \
	}

void test_c(void)
{
	print("%c", 'a');
	print("%1c", 'a');
	print("%10c", 'a');
	print("%-10c", 'a');
	print("%*c", 10, 'a');
	print("%-*c", 10, 'a');
	print("%c", '\0');
	print("%5c", '\0');
	print("%-5c", '\0');
	print("%05c", 'a');
}

void test_s(void)
{
	print("%s", "abcde");
	print("%s", 0);
	print("%1s", "abcde");
	print("%10s", "abcde");
	print("%-10s", "abcde");
	print("%*s", 10, "abcde");
	print("%*s", 0, "abcde");
	print("%-*s", 10, "abcde");
	print("hello, %s.", "how are you?");
	print("%-32s", "abc");
	print("%.2s%.7s", "hello", "world");
	print("%.7s%.2s", "hello", "world");
	print("%7.7s%7.7s", "hello", "world");
	print("%10.7s%10.7s", "hello", "world");
	print("%-8.s", NULL);
	print("%3s%3s", "hello", "world");
	print("hello, %s.", NULL);
	print("%2s", NULL);
	print("%-32s", NULL);
	print("%.3s", "NULL");
	print("%-*.*s", -7, -3, "hello");
	print("%.*s", -3, "hello");
	print("%*s", -32, "abc");
	print("%-*s", -32, "abc");
	print("%.*s", 3, "hello");
	print("%.*s", 0, "hello");
	print("%.0s", "hello");
	print("%-*.*s", 7, 3, "hello");
}

void test_x(void)
{
	print("%x", 703710);
	print("%1x", 703710);
	print("%010x", 703710);
	print("%10x", 703710);
	print("%-10x", 703710);
	print("%*x", 10, 703710);
	print("%-*x", 10, 703710);
	print("%10.3x", 703710);
	print("%10.6x", 703710);
	print("%20.10x", 703710);
	print("%.10x", 703710);
	print("%10.x", 703710);
	print("%012.10x", 703710);
	print("%x", -703710215498477);
	print("%1x", -703710215498477);
	print("%010x", -703710215498477);
	print("%10x", -703710215498477);
	print("%-10x", -703710215498477);
	print("%*x", 10, -703710215498477);
	print("%-*x", 10, -703710215498477);
	print("%10.3x", -703710215498477);
	print("%10.6x", -703710215498477);
	print("%20.10x", -703710215498477);
	print("%.10x", -703710215498477);
	print("%10.x", -703710215498477);
	print("%012.10x", -703710215498477);
}

void test_X(void)
{
	print("%X", 703710);
	print("%X", -703710);
	print("%1X", 703710);
	print("%010X", 703710);
	print("%10X", 703710);
	print("%-10X", 703710);
	print("%*X", 10, 703710);
	print("%-*X", 10, 703710);
	print("%10.3X", 703710);
	print("%10.6X", 703710);
	print("%20.10X", 703710);
	print("%.10X", 703710);
	print("%10.X", 703710);
	print("%012.10X", 703710);
	print("%X", -703710215498477);
	print("%1X", -703710215498477);
	print("%010X", -703710215498477);
	print("%10X", -703710215498477);
	print("%-10X", -703710215498477);
	print("%*X", 10, -703710215498477);
	print("%-*X", 10, -703710215498477);
	print("%10.3X", -703710215498477);
	print("%10.6X", -703710215498477);
	print("%20.10X", -703710215498477);
	print("%.10X", -703710215498477);
	print("%10.X", -703710215498477);
	print("%012.10X", -703710215498477);
}

void test_d(void)
{
	print("this %d number", 123);
	print("%d", 123);
	print("%d", -123);
	print("%10d", 123);
	print("%10d", -123);
	print("%010d", 123);
	print("%010d", -123);
	print("%-10d", 123);
	print("%-10d", -123);
	print("%*d", 10, 123);
	print("%*d", 10, -123);
	print("%-*d", 10, 123);
	print("%-*d", 10, -123);
	print("%10.d", 123);
	print("%10.d", -123);
	print("%10.3d", 123);
	print("%10.3d", -123);
	print("%10.6d", 123);
	print("%10.6d", -123);
	print("%20.10d", 123);
	print("%20.10d", -123);
	print("%.10d", 123);
	print("%.10d", -123);
	print("%012.10d", 123);
	print("%012.10d", -123);
	print("%d", -2147483648);
	print("%.20d", -2147483648);
	print("%0-8.5d", 34);
	print("%0-10.5d", -216);
	print("%0-8.3d", -8473);
	print("%d", 0);
	print("%.0d", 0);
	print("%5.0d", 0);
	print("%05d", 43);
	print("%07d", -54);
	print("%03d", 0);
	print("%0-8.5d", 34);
	print("%0-10.5d", -216);
	print("%0-8.5d", 0);
	print("%0-8.3d", 8375);
	print("%0-8.3d", -8473);
	print("%0-3.7d", 3267);
	print("%0-3.7d", -2375);
	print("%0-3.3d", 6983);
	print("%0-3.3d", -8462);
	print("%%d abc == |%d|", 'a' + 'b' + 'c');
}

void test_i(void)
{
	print("%i", 123);
	print("%i", -123);
	print("%10i", 123);
	print("%10i", -123);
	print("%010i", 123);
	print("%010i", -123);
	print("%-10i", 123);
	print("%-10i", -123);
	print("%*i", 10, 123);
	print("%*i", 10, -123);
	print("%-*i", -10, 123);
	print("%-*i", -10, -123);
	print("%-*i", 10, 123);
	print("%-*i", 10, -123);
	print("%10.i", 123);
	print("%10.i", -123);
	print("%10.3i", 123);
	print("%10.3i", -123);
	print("%10.6i", 123);
	print("%10.6i", -123);
	print("%20.10i", 123);
	print("%20.10i", -123);
	print("%.10i", 123);
	print("%.10i", -123);
	print("%012.10i", 123);
	print("%012.10i", -123);
	print("%0*i", -7, -54);
	print("%.*i", -6, -3);
	print("%*i", -14, 94827);
	print("%.*i", 6, -3);
}

void test_u(void)
{
	print("%u", 2147483664);
	print("%1u", 2147483664);
	print("%020u", 2147483664);
	print("%20u", 2147483664);
	print("%-20u", 2147483664);
	print("%*u", 10, 2147483664);
	print("%-*u", 10, 2147483664);
	print("%20.3u", 2147483664);
	print("%20.12u", 2147483664);
	print("%30.20u", 2147483664);
	print("%.20u", 2147483664);
	print("%20.u", 2147483664);
	print("%030.20u", 2147483664);
	print("%u", 3);
	print("%1u", 3);
	print("%010u", 3);
	print("%10u", 3);
	print("%-10u", 3);
	print("%*u", 10, 3);
	print("%-*u", 10, 3);
	print("%10.3u", 3);
	print("%10.6u", 3);
	print("%20.10u", 3);
	print("%.10u", 3);
	print("%10.u", 3);
	print("%012.10u", 3);
	print("%u", 0);
	print("%u", -0);
}

void test_p(void)
{
	int	*c = malloc(sizeof(int));

	print("%p", c);
	print("%20p", c);
	print("%020p", c);
	print("%-20p", c);
	print("%*p", 10, c);
	print("%-*p", 10, c);
	print("%20.3p", c);
	print("%20.10p", c);
	print("%p", NULL);
	print("%5p", NULL);
	print("%2p", NULL);
	print("%.p", NULL);
	print("%5.p", NULL);
	print("%2.p", NULL);
	free(c);
}

void test_perc(void)
{
	print("%%%d", 3);
	print("%-05%, %d", 3);
	print("%d %-05k", 3);
	print("%5%, %d", 3);
	print("%-5%, %d", 3);
	print("%05%, %d", 3);
	print("%*d", -10, 123);
	print("hallo %d test %", 3);
	print("hallo %d test %%", 3);
	print("%-0*.5d", 10, -15);
	print("%-*.5d", 10, -15);
	print("%-0*d", 10, -15);
	print("%-010d", -15);
	print("%010d", -15);
	print("%0*d", 10, -15);
	print("%07.5d", -15);
	print("%7.5d", -15);
	print("%07d", -15);
	print("%.7d", -15);
}

int main(int argc, char **argv)
{
	char* tests = "csxXdiup%";
	int i = 0;
	if (argc == 2)
	{
		tests = argv[1];
	}
	setlocale(LC_ALL, "en_US");
	printf("LET'S GO!\n");

	for (int i = 0; i < strlen(tests); i++)
	{
		if (tests[i] == 'c')
			test_c();
		if (tests[i] == 's')
			test_s();
		if (tests[i] == 'x')
			test_x();
		if (tests[i] == 'X')
			test_X();
		if (tests[i] == 'd')
			test_d();
		if (tests[i] == 'i')
			test_i();
		if (tests[i] == 'u')
			test_u();
		if (tests[i] == 'p')
			test_p();
		if (tests[i] == '%')
			test_perc();
		printf("-----------------------\n");
	}
	printf("FINISHED\n");
	return (0);
}
