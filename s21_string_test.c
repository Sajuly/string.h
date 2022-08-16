#include <check.h>
#include <stdio.h>
#include "s21_string.h"
#include <string.h>
#include <stdlib.h>

START_TEST(task_9_s21_strcmp_test) {
    char str1[] = "Hello world\n\0";
    char str2[] = "Hello world\n\0";
    char str3[] = "a\n\0";
    char str4[] = " \n\0";
    char str5[] = " \0";
    char str6[] = "\n\0";
    char str7[] = "\0";
    ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
    ck_assert_int_eq(s21_strcmp(str3, str4), strcmp(str3, str4));
    ck_assert_int_eq(s21_strcmp(str5, str6), strcmp(str5, str6));
    ck_assert_int_eq(s21_strcmp(str6, str7), strcmp(str6, str7));
    ck_assert_int_eq(s21_strcmp(str1, str7), strcmp(str1, str7));
}
END_TEST

START_TEST(task_10_s21_strncmp_test) {
    char str1[] = "Hello world\n\0";
    char str2[] = "Hello world\n\0";
    char str3[] = "a\n\0";
    char str4[] = " \n\0";
    char str5[] = " \0";
    char str6[] = "\n\0";
    char str7[] = "\0";
    ck_assert_int_eq(s21_strncmp(str1, str2, 3), strncmp(str1, str2, 3));
    ck_assert_int_eq(s21_strncmp(str3, str4, 2), strncmp(str3, str4, 2));
    ck_assert_int_eq(s21_strncmp(str5, str6, 1), strncmp(str5, str6, 1));
    ck_assert_int_eq(s21_strncmp(str6, str7, 1), strncmp(str6, str7, 1));
    ck_assert_int_eq(s21_strncmp(str1, str7, 1), strncmp(str1, str7, 1));
}
END_TEST

START_TEST(task_11_s21_strcpy_test) {
    char str1[] = "Hello world\n\0";
    char str2[] = "Hello world\n\0";
    char str3[] = "a\n\0";
    char str4[] = " \n\0";
    char str5[] = " \0";
    char str6[] = "\n\0";
    char str7[] = "\0";
    ck_assert_pstr_eq(s21_strcpy(str1, str2), strcpy(str1, str2));
    ck_assert_pstr_eq(s21_strcpy(str3, str4), strcpy(str3, str4));
    ck_assert_pstr_eq(s21_strcpy(str5, str6), strcpy(str5, str6));
    ck_assert_pstr_eq(s21_strcpy(str6, str7), strcpy(str6, str7));
    ck_assert_pstr_eq(s21_strcpy(str1, str7), strcpy(str1, str7));
}
END_TEST

START_TEST(task_12_s21_strncpy_test) {
    char str1[] = "Hello world\n\0";
    char str2[] = "Hello world\n\0";
    char str3[] = "a\n\0";
    char str4[] = " \n\0";
    char str5[] = " \0";
    char str6[] = "\n\0";
    char str7[] = "\0";
    ck_assert_pstr_eq(s21_strncpy(str1, str2, 2), strncpy(str1, str2, 2));
    ck_assert_pstr_eq(s21_strncpy(str3, str4, 2), strncpy(str3, str4, 2));
    ck_assert_pstr_eq(s21_strncpy(str5, str6, 1), strncpy(str5, str6, 1));
    ck_assert_pstr_eq(s21_strncpy(str6, str7, 1), strncpy(str6, str7, 1));
    ck_assert_pstr_eq(s21_strncpy(str1, str7, 1), strncpy(str1, str7, 1));
}
END_TEST

START_TEST(part_5_s21_to_upper_test) {
    char* function;
    function = s21_to_upper("Hello, 123!");
    ck_assert_pstr_eq(function, "HELLO, 123!");
    free(function);
    function = s21_to_upper("hello, 123!");
    ck_assert_pstr_eq(function, "HELLO, 123!");
    free(function);
    function = s21_to_upper("HELLO, 123!");
    ck_assert_pstr_eq(function, "HELLO, 123!");
    free(function);
    function = s21_to_upper("");
    ck_assert_pstr_eq(function, "");
    free(function);
    function = s21_to_upper(NULL);
    ck_assert_pstr_eq(s21_to_upper(NULL), NULL);
    free(function);
    function = s21_to_upper("123!");
    ck_assert_pstr_eq(function, "123!");
    free(function);
}
END_TEST

START_TEST(part_5_s21_to_lower_test) {
    char* function;
    function = s21_to_lower("Hello, 123!");
    ck_assert_pstr_eq(function, "hello, 123!");
    free(function);
    function = s21_to_lower("hello, 123!");
    ck_assert_pstr_eq(function, "hello, 123!");
    free(function);
    function = s21_to_lower("HELLO, 123!");
    ck_assert_pstr_eq(function, "hello, 123!");
    free(function);
    function = s21_to_lower("");
    ck_assert_pstr_eq(function, "");
    free(function);
    function = s21_to_lower(NULL);
    ck_assert_pstr_eq(function, NULL);
    free(function);
    function = s21_to_lower("123!");
    ck_assert_pstr_eq(function, "123!");
    free(function);
}
END_TEST

START_TEST(part_5_s21_insert_test) {
    char* function;
    function = s21_insert("13", "2", 1);
    ck_assert_pstr_eq(function, "123");
    free(function);
    function = s21_insert("", "2", 2);
    ck_assert_ptr_null(function);
    free(function);
    function = s21_insert("hello", "", 0);
    ck_assert_pstr_eq(function, "hello");
    free(function);
    function = s21_insert("hello", "", 2);
    ck_assert_pstr_eq(function, "hello");
    free(function);
    function = s21_insert("hello", "", 6);
    ck_assert_ptr_null(function);
    free(function);
    function = s21_insert("", "", 6);
    ck_assert_ptr_null(function);
    free(function);
    function = s21_insert(NULL, "", 0);
    ck_assert_ptr_null(function);
    free(function);
    function = s21_insert("", NULL, 0);
    ck_assert_ptr_null(function);
    free(function);
    function = s21_insert(" 12", NULL, 0);
    ck_assert_ptr_null(function);
    free(function);
    function = s21_insert(NULL, "12 ", 0);
    ck_assert_ptr_null(function);
    free(function);
}
END_TEST

START_TEST(part_5_s21_trim_test_1) {
    char str8[7] = " 1221 ";
    char* function;
    function = s21_trim(str8, NULL);
    ck_assert_pstr_eq(function, "1221");
    free(function);
    function = s21_trim(str8, "");
    ck_assert_pstr_eq(function, "1221");
    free(function);
    function = s21_trim(str8, "7");
    ck_assert_pstr_eq(function, " 1221 ");
    free(function);
    function = s21_trim(str8, "1");
    ck_assert_pstr_eq(function, " 1221 ");
    free(function);
    function = s21_trim("", "12");
    ck_assert_ptr_null(function);
    ck_assert_pstr_eq(function, NULL);
    free(function);
    function = s21_trim("", "");
    ck_assert_ptr_null(function);
    ck_assert_pstr_eq(function, NULL);
    free(function);
    function = s21_trim(NULL, "");
    ck_assert_ptr_null(function);
    ck_assert_pstr_eq(function, NULL);
    free(function);
    function = s21_trim(NULL, NULL);
    ck_assert_ptr_null(function);
    ck_assert_pstr_eq(function, NULL);
    free(function);
    function = s21_trim(" 12321 ", " 12");
    ck_assert_pstr_eq(function, "3");
    free(function);
    function = s21_trim(str8, " 12");
    ck_assert_pstr_eq(function, NULL);
    free(function);
}
END_TEST

START_TEST(part_5_s21_trim_test_2) {
    char* function;
    function = s21_trim(" 13331 ", " 1");
    ck_assert_pstr_eq(function, "333");
    free(function);
}
END_TEST

START_TEST(memchr_test) {
    char src1[15] = "1234567890";
    char src2[3] = {'\0', '\0', '\0'};
    char src3[0];
    void *res1, *res2;

    res1 = s21_memchr(src1, '4', 10);
    res2 = memchr(src1, '4', 10);
    ck_assert_ptr_eq(res1, res2);

    res1 = s21_memchr(src2, '\0', 2);
    res2 = memchr(src2, '\0', 2);
    ck_assert_ptr_eq(res1, res2);

    res1 = s21_memchr(src3, 'w', 10);
    res2 = memchr(src3, 'w', 10);
    ck_assert_ptr_eq(res1, res2);

    res1 = s21_memchr("", 'w', 10);
    res2 = memchr("", 'w', 10);
    ck_assert_ptr_eq(res1, res2);

    ck_assert_ptr_eq(s21_memchr("Hello world\0", 'w', 4), memchr("Hello world\0", 'w', 4));
    ck_assert_ptr_eq(s21_memchr("Hello world\n\0", 'o', 10), memchr("Hello world\n\0", 'o', 10));
    ck_assert_ptr_eq(s21_memchr("a\n\0", 'a', 2), memchr("a\n\0", 'a', 2));
    ck_assert_ptr_eq(s21_memchr(" \n\0", ' ', 2), memchr(" \n\0", ' ', 2));
    ck_assert_ptr_eq(s21_memchr(" \0", '0', 2), memchr(" \0", '0', 2));
    ck_assert_ptr_eq(s21_memchr("\n\0", '\n', 2), memchr("\n\0", '\n', 2));
    ck_assert_ptr_eq(s21_memchr("\0", 'r', 100), memchr("\0", 'r', 100));
}
END_TEST

START_TEST(memcmp_test) {
    char src1[7] = "Abc";
    char dst1[7] = "ABC";
    char src2[3] = "\0";
    char dst2[3] = "\0";
    char src3[6] = "12345";
    char dst3[6] = "12345";
    char str1[] = "Hello world\0";
    char str2[] = "Hello world";
    char str3[] = "a\n\0";
    char str4[] = " \n\0";
    char str5[] = "1\0";
    char str6[] = "\n\0";
    char str7[] = "\0";

    ck_assert_int_eq(s21_memcmp(src1, dst1, 1), memcmp(src1, dst1, 1));
    ck_assert_int_eq(s21_memcmp(src2, dst2, 1), memcmp(src2, dst2, 1));
    ck_assert_int_eq(s21_memcmp(src3, dst3, 5), memcmp(src3, dst3, 5));

    ck_assert_int_eq(s21_memcmp(str1, str2, 12), memcmp(str1, str2, 12));
    ck_assert_int_eq(s21_memcmp(str3, "a\n\0", 3), memcmp(str3, "a\n\0", 3));
    ck_assert_int_eq(s21_memcmp(str4, " \n\0", 4), memcmp(str4, " \n\0", 4));
    ck_assert_int_eq(s21_memcmp(str6, str7, 1), memcmp(str6, str7, 1));
    ck_assert_int_eq(s21_memcmp(str5, "0\n", 1), memcmp(str5, "0\n", 1));
    ck_assert_int_eq(s21_memcmp(str7, "", 1), memcmp(str7, "", 1));
}
END_TEST

START_TEST(memcpy_test) {
    char src1[15] = "qwert";
    char dst1[3] = "123";
    char src2[11];
    char dst2[11] = "1234567890";
    char src3[3];
    char dst3[3] = "123";
    void *res1, *res2;

    res1 = s21_memcpy(src1, dst1, 3);
    res2 = memcpy(src1, dst1, 3);
    ck_assert_pstr_eq(res1, res2);

    res1 = s21_memcpy(src2, dst2, 10);
    res2 = memcpy(src2, dst2, 10);
    ck_assert_pstr_eq(res1, res2);

    res1 = s21_memcpy(src3, dst3, 3);
    res2 = memcpy(src3, dst3, 3);
    ck_assert_pstr_eq(res1, res2);

    char dest[] = "0000";
    char src[] = "1,2,3,4,5";
    char dest1[5];
    char src0[] = "1,2,3,4,5";
    char dest2[] = "1,2,3,4,5";
    char src5[] = "21212121";
    char src6[] = "\0";
    ck_assert_ptr_eq(s21_memcpy(dest, src, 4), memcpy(dest, src, 4));
    ck_assert_ptr_eq(s21_memcpy(dest1, src0, 5), memcpy(dest1, src0, 5));
    ck_assert_ptr_eq(s21_memcpy(dest2, src5, 8), memcpy(dest2, src5, 8));
    ck_assert_ptr_eq(s21_memcpy(dest, src6, 1), memcpy(dest, src6, 1));
}
END_TEST

START_TEST(memmove_test) {
    char src1[15] = "qwert";
    char dst1[3] = "123";
    char src2[11];
    char dst2[11] = "1234567890";
    char src3[3];
    char dst3[3] = "123";
    void *res1, *res2;

    res1 = s21_memmove(src1, dst1, 3);
    res2 = memmove(src1, dst1, 3);
    ck_assert_pstr_eq(res1, res2);

    res1 = s21_memmove(src2, dst2, 10);
    res2 = memmove(src2, dst2, 10);
    ck_assert_pstr_eq(res1, res2);

    res1 = s21_memmove(src3, dst3, 3);
    res2 = memmove(src3, dst3, 3);
    ck_assert_pstr_eq(res1, res2);

    char* dst33 = &dst2[2];
    char* dst4;
    dst4 = dst33 + 3;
    res1 = s21_memmove(dst33, dst4, 2);
    res2 = memmove(dst33, dst4, 2);
    ck_assert_pstr_eq(res1, res2);

    char dest[] = "0000";
    char src[] = "1,2,3,4,5";
    char dest1[5];
    char src0[] = "1,2,3,4,5";
    char dest2[] = "1,2,3,4,5";
    char src5[] = "21212121";
    char src6[] = "\0";
    ck_assert_ptr_eq(s21_memmove(dest, src, 4), memmove(dest, src, 4));
    ck_assert_ptr_eq(s21_memmove(dest1, src0, 5), memmove(dest1, src0, 5));
    ck_assert_ptr_eq(s21_memmove(dest2, src5, 8), memmove(dest2, src5, 8));
    ck_assert_ptr_eq(s21_memmove(dest, src6, 1), memmove(dest, src6, 1));
}
END_TEST

START_TEST(memset_test) {
    char src1[15] = "1234567890";
    char src2[11] = "123";
    char src3[3];
    void *res1, *res2;

    res1 = s21_memset(src1, '1', 11);
    res2 = memset(src1, '1', 11);
    ck_assert_pstr_eq(res1, res2);

    res1 = s21_memset(src2, '\0', 2);
    res2 = memset(src2, '\0', 2);
    ck_assert_pstr_eq(res1, res2);

    res1 = s21_memset(src3, 'w', 2);
    res2 = memset(src3, 'w', 2);
    ck_assert_pstr_eq(res1, res2);
}
END_TEST

START_TEST(strlen_test) {
    size_t res1, res2;

    res1 = s21_strlen("Lol");
    res2 = strlen("Lol");
    ck_assert_int_eq(res1, res2);

    res1 = s21_strlen("");
    res2 = strlen("");
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(strspn_test) {
    size_t res1, res2;

    res1 = s21_strspn("123456789", "312");
    res2 = strspn("123456789", "312");
    ck_assert_int_eq(res1, res2);

    res1 = s21_strspn("", "312");
    res2 = strspn("", "312");
    ck_assert_int_eq(res1, res2);

    res1 = s21_strspn("123456789", "");
    res2 = strspn("123456789", "");
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(strcspn_test) {
    size_t res1, res2;

    res1 = s21_strcspn("123456789", "9876");
    res2 = strcspn("123456789", "9876");
    ck_assert_int_eq(res1, res2);

    res1 = s21_strcspn("", "9876");
    res2 = strcspn("", "9876");
    ck_assert_int_eq(res1, res2);

    res1 = s21_strcspn("123456789", "");
    res2 = strcspn("123456789", "");
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(strcmp_test) {
    char str20[4] = "Kek";
    int res1, res2;

    res1 = s21_strcmp("Lol", str20);
    res2 = strcmp("Lol", str20);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(strncmp_test) {
    char str11[4] = "Lol";
    char str21[4] = "Kek";
    int res1, res2;

    res1 = s21_strncmp(str11, str21, 2);
    res2 = strncmp(str11, str21, 2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(strcpy_test) {
    char str12[4] = "Lol";
    char str22[4] = "Kek";
    char str32[4] = "";
    char str42[1] = "";
    char *result, *result2;

    result = s21_strcpy(str12, str22);
    result2 = strcpy(str12, str22);
    ck_assert_pstr_eq(result, result2);

    result = s21_strcpy(str32, str42);
    result2 = strcpy(str32, str42);
    ck_assert_pstr_eq(result, result2);

//    result = s21_strcpy(NULL, NULL);   todo: на линуксе пишет библ фция, что src не может быть NULL
//    result2 = strcpy(NULL, NULL);
//    ck_assert_pstr_eq(result, result2);
}
END_TEST

START_TEST(strncpy_test) {
    char str12[4] = "Lol";
    char str22[4] = "Kek";
    char str32[4] = "";
    char str42[1] = "";
    char *result, *result2;

    result = s21_strncpy(str12, str22, 2);
    result2 = strncpy(str12, str22, 2);
    ck_assert_pstr_eq(result, result2);

    result = s21_strncpy(str32, str42, 1);
    result2 = strncpy(str32, str42, 1);
    ck_assert_pstr_eq(result, result2);
}
END_TEST

START_TEST(strcat_test) {
    char str10[10] = "Lol";
    char str20[4] = "Kek";
    char str30[4] = "";
    char *result, *result2;

    result = s21_strcat(str10, str20);
    result2 = strcat(str10, str20);
    ck_assert_pstr_eq(result, result2);

    result = s21_strcat(str10, str30);
    result2 = strcat(str10, str30);
    ck_assert_pstr_eq(result, result2);
}
END_TEST

START_TEST(strncat_test) {
    char str0[8] = "Lol";
    char str20[4] = "Kek";
    char str10[8] = "Lol";
    char *result, *result2;

    result = s21_strncat(str0, str20, 2);
    result2 = strncat(str0, str20, 2);
    ck_assert_pstr_eq(result, result2);

    result = s21_strncat(str10, str20, 2);
    result2 = strncat(str10, str20, 2);
    ck_assert_pstr_eq(result, result2);
}
END_TEST

START_TEST(strchr_test) {
    char str1[7] = "School";
    char *result, *result2;
    char str2[50] = "\0";

    result = s21_strchr(str1, 111);
    result2 = strchr(str1, 111);
    ck_assert_pstr_eq(result, result2);

    result = s21_strchr(str2, 1);
    result2 = strchr(str2, 1);
    ck_assert_pstr_eq(result, result2);
}
END_TEST

START_TEST(strrchr_test) {
    char str1[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";
    char *result, *result2;

    result = s21_strrchr(str1, 111);
    result2 = strrchr(str1, 111);
    ck_assert_pstr_eq(result, result2);
}
END_TEST

START_TEST(strpbrk_test) {
    char str1[7] = "School";
    char str2[4] = "Hole";
    char *result, *result2;

    result = s21_strpbrk(str1, str2);
    result2 = strpbrk(str1, str2);
    ck_assert_pstr_eq(result, result2);

    result = s21_strpbrk("", str2);
    result2 = strpbrk("", str2);
    ck_assert_pstr_eq(result, result2);
}
END_TEST

START_TEST(strerror_test) {
    char *src, *src1;
//    char *src2;
    src = s21_strerror(131);
    ck_assert_pstr_eq(src, strerror(131));
    free(src);

    src1 = s21_strerror(70);
    ck_assert_pstr_eq(src1, strerror(70));
    free(src1);
}
END_TEST

START_TEST(strstr_test) {
    char str1[7] = "Lol";
    char str2[4] = "ol";
    char str3[7] = "";
    char str4[4] = "";
    char str5[4] = "";
    char *result, *result2;

    result = s21_strstr(str1, str2);
    result2 = strstr(str1, str2);
    ck_assert_pstr_eq(result, result2);

    result = s21_strstr(str3, str4);
    result2 = strstr(str3, str4);
    ck_assert_pstr_eq(result, result2);

    result = s21_strstr(str5, str1);
    result2 = strstr(str5, str1);
    ck_assert_pstr_eq(result, result2);
}
END_TEST

START_TEST(strtok_test) {
    char str[] = "School-21";
    char *tok1 = s21_strtok(str, "-");
    char *tok2 = strtok(str, "-");
    char *tok3 = s21_strtok(str, "");
    char *tok4 = strtok(str, "");
    char *tok5 = s21_strtok(str, "oo");
    char *tok6 = strtok(str, "oo");
    char *tok7 = s21_strtok(str, "Sc");
    char *tok8 = strtok(str, "Sc");
    char *tok9 = s21_strtok(str, "21");
    char *tok10 = strtok(str, "21");

    ck_assert_pstr_eq(tok1, tok2);
    ck_assert_pstr_eq(tok3, tok4);
    ck_assert_pstr_eq(tok5, tok6);
    ck_assert_pstr_eq(tok7, tok8);
    ck_assert_pstr_eq(tok9, tok10);
}
END_TEST

START_TEST(trim_test) {
    char *str1 = "aboba";
    char *str2 = "ao";
    char *str3 = "abo";
    void *result, *result1;

    result = s21_trim(str1, str2);
    ck_assert_pstr_eq(result, "bob");
    free(result);

    result = s21_trim(str1, str3);
    result1 = NULL;
    ck_assert_ptr_eq(result, result1);
    free(result);
}
END_TEST

START_TEST(insert_test) {
    char *str1 = "Aboba";
    char *str2 = "kek";
    char *result = NULL;

    result = s21_insert(str1, str2, 2);
    ck_assert_pstr_eq(result, "Abkekoba");
    free(result);
}
END_TEST

START_TEST(toupper_test) {
    char *result = s21_to_upper("lol");
    ck_assert_pstr_eq(result, "LOL");
    free(result);
}
END_TEST

START_TEST(tolower_test) {
    char *result = s21_to_lower("LOL");
    ck_assert_pstr_eq(result, "lol");
    free(result);
}
END_TEST

START_TEST(s21_sprintf_test) {
    char c[20];
    int s = -789;
    char strin[5];
    int st = '6';
    char r[100];
    char res[100];
    char st_s[10] = "qwey";
    unsigned int st_u = 1234;

    ck_assert_int_eq(s21_sprintf(c, "%d", s), sprintf(c, "%d", s));
    ck_assert_int_eq(s21_sprintf(c, "%16d", s), sprintf(c, "%16d", s));
    ck_assert_int_eq(s21_sprintf(c, "%+16d", s), sprintf(c, "%+16d", s));
    ck_assert_int_eq(s21_sprintf(c, "%-16d", s), sprintf(c, "%-16d", s));
    ck_assert_int_eq(s21_sprintf(c, "%016d", s), sprintf(c, "%016d", s));
    ck_assert_int_eq(s21_sprintf(c, "% 16d", s), sprintf(c, "% 16d", s));



    ck_assert_int_eq(s21_sprintf(c, "%i", s), sprintf(c, "%i", s));
    ck_assert_int_eq(s21_sprintf(c, "%16i", s), sprintf(c, "%16i", s));
    ck_assert_int_eq(s21_sprintf(c, "%+16i", s), sprintf(c, "%+16i", s));
    ck_assert_int_eq(s21_sprintf(c, "%-16i", s), sprintf(c, "%-16i", s));
    ck_assert_int_eq(s21_sprintf(c, "%016i", s), sprintf(c, "%016i", s));
    ck_assert_int_eq(s21_sprintf(c, "% 16i", s), sprintf(c, "% 16i", s));

    s = 00123;

    ck_assert_int_eq(s21_sprintf(c, "%i", s), sprintf(c, "%i", s));
    ck_assert_int_eq(s21_sprintf(c, "%16i", s), sprintf(c, "%16i", s));
    ck_assert_int_eq(s21_sprintf(c, "%+16i", s), sprintf(c, "%+16i", s));
    ck_assert_int_eq(s21_sprintf(c, "%-16i", s), sprintf(c, "%-16i", s));
    ck_assert_int_eq(s21_sprintf(c, "%016i", s), sprintf(c, "%016i", s));
    ck_assert_int_eq(s21_sprintf(c, "% 16i", s), sprintf(c, "% 16i", s));

    s = 0x123fa;

    ck_assert_int_eq(s21_sprintf(c, "%i", s), sprintf(c, "%i", s));
    ck_assert_int_eq(s21_sprintf(c, "%16i", s), sprintf(c, "%16i", s));
    ck_assert_int_eq(s21_sprintf(c, "%+16i", s), sprintf(c, "%+16i", s));
    ck_assert_int_eq(s21_sprintf(c, "%-16i", s), sprintf(c, "%-16i", s));
    ck_assert_int_eq(s21_sprintf(c, "%016i", s), sprintf(c, "%016i", s));
    ck_assert_int_eq(s21_sprintf(c, "% 16i", s), sprintf(c, "% 16i", s));

    double s1 = -78.8;
    ck_assert_int_eq(s21_sprintf(c, "%f", s1), sprintf(c, "%f", s1));
    ck_assert_int_eq(s21_sprintf(c, "%16f", s1), sprintf(c, "%16f", s1));
    ck_assert_int_eq(s21_sprintf(c, "%+16f", s1), sprintf(c, "%+16f", s1));
    ck_assert_int_eq(s21_sprintf(c, "%-16f", s1), sprintf(c, "%-16f", s1));
    ck_assert_int_eq(s21_sprintf(c, "%016f", s1), sprintf(c, "%016f", s1));
    ck_assert_int_eq(s21_sprintf(c, "% 16f", s1), sprintf(c, "% 16f", s1));

    ck_assert_int_eq(s21_sprintf(strin, "%c", st), sprintf(c, "%c", s));
    ck_assert_int_eq(s21_sprintf(strin, "%-7c", st), sprintf(c, "%-7c", s));

    ck_assert_int_eq(s21_sprintf(res, "%s", st_s), sprintf(res, "%s", st_s));

    unsigned int st_u1 = 123;  //  Беззнаковое десятичное целое число, т е флаги +-' ' не используются???
    unsigned long int st_u11 = 1234;
    unsigned short int st_u12 = 1234;
    ck_assert_int_eq(s21_sprintf(r, "%u", st_u1), sprintf(r, "%u", st_u1));
    ck_assert_int_eq(s21_sprintf(r, "%16.5u", st_u1), sprintf(r, "%16.5u", st_u1));
    ck_assert_int_eq(s21_sprintf(r, "%+16.5lu", st_u11), sprintf(r, "%-16.5lu", st_u11));
    ck_assert_int_eq(s21_sprintf(r, "%-16.5hu", st_u12), sprintf(r, "%-16.5hu", st_u12));

    ck_assert_int_eq(s21_sprintf(r, "%u", st_u), sprintf(r, "%u", st_u));
    ck_assert_int_eq(s21_sprintf(r, "%16.5u", st_u), sprintf(r, "%16.5u", st_u));
    ck_assert_int_eq(s21_sprintf(r, "%+16.5u", st_u), sprintf(r, "%-16.5u", st_u));
    ck_assert_int_eq(s21_sprintf(r, "%-16.5u", st_u), sprintf(r, "%-16.5u", st_u));


    ck_assert_int_eq(s21_sprintf(r, "%s", st_s), sprintf(r, "%s", st_s));

    ck_assert_int_eq(s21_sprintf(r, "%%"), sprintf(r, "%%"));
}
END_TEST

START_TEST(s21_sprintf_July_test_1) {
    char c_21[100];
    char c_lib[100];
    int ds = 43;
    char *stroka = "arriba";
    s21_sprintf(c_21, "Hola amigo %d como estas %s", ds, stroka);
    sprintf(c_lib, "Hola amigo %d como estas %s", ds, stroka);
    ck_assert_pstr_eq(c_21, c_lib);

    s21_sprintf(c_21, "Hola amigo %1d como estas %3s", ds, stroka);
    sprintf(c_lib, "Hola amigo %1d como estas %3s", ds, stroka);
    ck_assert_pstr_eq(c_21, c_lib);

    s21_sprintf(c_21, "Hola amigo %-12.3d como estas %-10s", ds, stroka);
    sprintf(c_lib, "Hola amigo %-12.3d como estas %-10s", ds, stroka);
    ck_assert_pstr_eq(c_21, c_lib);

    s21_sprintf(c_21, "Hola amigo %+.8d como estas %1s", ds, stroka);
    sprintf(c_lib, "Hola amigo %+.8d como estas %1s", ds, stroka);
    ck_assert_pstr_eq(c_21, c_lib);

    s21_sprintf(c_21, "Hola amigo % d como estas %s", ds, stroka);
    sprintf(c_lib, "Hola amigo % d como estas %s", ds, stroka);
    ck_assert_pstr_eq(c_21, c_lib);
}
END_TEST

START_TEST(s21_sprintf_July_test_2) {
char c_21[100];
char c[100];
char c_lib[100];
int ds = 43;
short int dsh = 33;
char* stroka = "";
wchar_t* strokaW = L"a";
s21_sprintf(c_21, "Hola amigo %d como estas %ls", ds, strokaW);
sprintf(c_lib, "Hola amigo %d como estas %ls", ds, strokaW);
ck_assert_pstr_eq(c_21, c_lib);

strokaW = L"abcd";
s21_sprintf(c_21, "Hola amigo %d como estas %ls", ds, strokaW);
sprintf(c_lib, "Hola amigo %d como estas %ls", ds, strokaW);
ck_assert_pstr_eq(c_21, c_lib);

s21_sprintf(c_21, "Hola amigo %hd. como estas %s", dsh, stroka);
sprintf(c_lib, "Hola amigo %hd. como estas %s", dsh, stroka);
ck_assert_pstr_eq(c_21, c_lib);

int d = 43;
//  1.  w>pr>count
ck_assert_int_eq(s21_sprintf(c, "%d", d), sprintf(c, "%d", d));
ck_assert_int_eq(s21_sprintf(c, "%4d", d), sprintf(c, "%4d", d));
ck_assert_int_eq(s21_sprintf(c, "%.3d", d), sprintf(c, "%.3d", d));
ck_assert_int_eq(s21_sprintf(c, "%4.3d", d), sprintf(c, "%4.3d", d));
ck_assert_int_eq(s21_sprintf(c, "%-4.3d", d), sprintf(c, "%-4.3d", d));
ck_assert_int_eq(s21_sprintf(c, "%+4.3d", d), sprintf(c, "%+4.3d", d));
ck_assert_int_eq(s21_sprintf(c, "% 4.3d", d), sprintf(c, "% 4.3d", d));  //  flag space
ck_assert_int_eq(s21_sprintf(c, "%-+4.3d", d), sprintf(c, "%-+4.3d", d));
ck_assert_int_eq(s21_sprintf(c, "%+-4.3d", d), sprintf(c, "%+-4.3d", d));
//  2.  w>(pr=count)
ck_assert_int_eq(s21_sprintf(c, "%d", d), sprintf(c, "%d", d));
ck_assert_int_eq(s21_sprintf(c, "%4d", d), sprintf(c, "%4d", d));
ck_assert_int_eq(s21_sprintf(c, "%.2d", d), sprintf(c, "%.2d", d));
ck_assert_int_eq(s21_sprintf(c, "%4.2d", d), sprintf(c, "%4.2d", d));
ck_assert_int_eq(s21_sprintf(c, "%-4.2d", d), sprintf(c, "%-4.2d", d));
ck_assert_int_eq(s21_sprintf(c, "%+4.2d", d), sprintf(c, "%+4.2d", d));
ck_assert_int_eq(s21_sprintf(c, "% 4.2d", d), sprintf(c, "% 4.2d", d));  //  flag space
ck_assert_int_eq(s21_sprintf(c, "%-+4.2d", d), sprintf(c, "%-+4.2d", d));
ck_assert_int_eq(s21_sprintf(c, "%+-4.2d", d), sprintf(c, "%+-4.2d", d));
//  3.  (w=pr)>count
ck_assert_int_eq(s21_sprintf(c, "%d", d), sprintf(c, "%d", d));
ck_assert_int_eq(s21_sprintf(c, "%4d", d), sprintf(c, "%4d", d));
ck_assert_int_eq(s21_sprintf(c, "%.4d", d), sprintf(c, "%.4d", d));
ck_assert_int_eq(s21_sprintf(c, "%4.4d", d), sprintf(c, "%4.4d", d));
ck_assert_int_eq(s21_sprintf(c, "%-4.4d", d), sprintf(c, "%-4.4d", d));
ck_assert_int_eq(s21_sprintf(c, "%+4.4d", d), sprintf(c, "%+4.4d", d));
ck_assert_int_eq(s21_sprintf(c, "% 4.4d", d), sprintf(c, "% 4.4d", d));  //  flag space
ck_assert_int_eq(s21_sprintf(c, "%-+4.4d", d), sprintf(c, "%-+4.4d", d));
ck_assert_int_eq(s21_sprintf(c, "%+-4.4d", d), sprintf(c, "%+-4.4d", d));

char* s = "55555";
long int dl = 55555;
ck_assert_int_eq(s21_sprintf(c, "%.2s", s), sprintf(c, "%.2s", s));
ck_assert_int_eq(s21_sprintf(c, "%+-4.4ld", dl), sprintf(c, "%+-4.4ld", dl));
}
END_TEST

START_TEST(s21_sprintf_July_test_3) {
    char data1[200];
    char data2[200];
    char *s = "already";
    char *ss = "";
    char *sss = "\0";
    wchar_t* w = L"code";
    int d = 100;
    int da = -55000;
    short int dah = 33;
    float f = 123.4567899;
    unsigned int u = 0x888;
    char c = '!';
    char cc = '\0';
    char ccc = '\n';
    wchar_t o = '!';

    s21_sprintf(data1, "I have %-20s rewritten this code %7.5d times%c\n", s, d, c);
    sprintf(data2, "I have %-20s rewritten this code %7.5d times%c\n", s, d, c);
    ck_assert_pstr_eq(data1, data2);

    s21_sprintf(data1, "I have %15s rewritten this code %-+8d times%5c\n", s, d, c);
    sprintf(data2, "I have %15s rewritten this code %-+8d times%5c\n", s, d, c);
    ck_assert_pstr_eq(data1, data2);

    // wchar_t не работает, исправлять не будем; wchar_t *w = L"code";
    s21_sprintf(data1, "I have %s rewritten this %ls %.4hi times%-3c\n", s, w, dah, c);
    sprintf(data2, "I have %s rewritten this %ls %.4hi times%-3c\n", s, w, dah, c);
    ck_assert_pstr_eq(data1, data2);

    s21_sprintf(data1, "I have %s rewritten this code %- 8i times%c\n", s, da, c);
    sprintf(data2, "I have %s rewritten this code %- 8i times%c\n", s, da, c);
    ck_assert_pstr_eq(data1, data2);

    s21_sprintf(data1, "I have %s rewritten this code %7.6lf times%c\n", ss, f, cc);  //  float
    sprintf(data2, "I have %s rewritten this code %7.6lf times%c\n", ss, f, cc);
    ck_assert_pstr_eq(data1, data2);

    s21_sprintf(data1, "I have %s rewritten this code %.0f times%c\n", sss, f, cc);  //  float
    sprintf(data2, "I have %s rewritten this code %.0f times%c\n", sss, f, cc);
    ck_assert_pstr_eq(data1, data2);

    s21_sprintf(data1, "I have %s rewritten this code %.f times%lc\n", s, f, o);  //  float
    sprintf(data2, "I have %s rewritten this code %.f times%lc\n", s, f, o);
    ck_assert_pstr_eq(data1, data2);

    s21_sprintf(data1, "I have %s rewritten this code %8.6u times%lc\n", s, u, o);
    sprintf(data2, "I have %s rewritten this code %8.6u times%lc\n", s, u, o);
    ck_assert_pstr_eq(data1, data2);

    s21_sprintf(data1, "I have %s rewritten this code %-.8u times%c\n", s, u, ccc);
    sprintf(data2, "I have %s rewritten this code %-.8u times%c\n", s, u, ccc);
    ck_assert_pstr_eq(data1, data2);

    s21_sprintf(data1, "It's %d %% ready%c%c%c\n", d, c, c, c);
    sprintf(data2, "It's %d %% ready%c%c%c\n", d, c, c, c);
    ck_assert_pstr_eq(data1, data2);
}
END_TEST

START_TEST(s21_sprintf_July_test_4) {
    char data1[200];
    char data2[200];
    char *s = "already";
    char *ss = "";
    char *sss = "\0";
    int d = 100;
    int da = -55000;
    float f = 123.4567899;
    float fa = -123.4567899;
    int i = 1245;
    int ia = -1245;
    unsigned int u = 0x888;
    char c = '!';
    char cc = '\0';
    char ccc = '\n';

    s21_sprintf(data1, "I have %15s rewritten this code %-+8d times%5c\n", s, d, c);
    sprintf(data2, "I have %15s rewritten this code %-+8d times%5c\n", s, d, c);
    ck_assert_pstr_eq(data1, data2);

    s21_sprintf(data1, "I have %s rewritten this code %- 8i times%c\n", s, da, c);
    sprintf(data2, "I have %s rewritten this code %- 8i times%c\n", s, da, c);
    ck_assert_pstr_eq(data1, data2);

//    s21_sprintf(data1, "I have %s rewritten this code %-+20.5f times %c\n", s, f, c);  //  float
//    sprintf(data2, "I have %s rewritten this code %-+20.5f times %c\n", s, f, c);
//    ck_assert_pstr_eq(data1, data2);

    s21_sprintf(data1, "I have %s rewritten this code % 7.6lf times%c\n", ss, f, cc);  //  float
    sprintf(data2, "I have %s rewritten this code % 7.6lf times%c\n", ss, f, cc);
    ck_assert_pstr_eq(data1, data2);

    s21_sprintf(data1, "I have %s rewritten this code %.0f times%c\n", sss, f, cc);  //  float
    sprintf(data2, "I have %s rewritten this code %.0f times%c\n", sss, f, cc);
    ck_assert_pstr_eq(data1, data2);

    s21_sprintf(data1, "I have %s rewritten this code %.8u times%c\n", s, u, ccc);
    sprintf(data2, "I have %s rewritten this code %.8u times%c\n", s, u, ccc);
    ck_assert_pstr_eq(data1, data2);

//    ' ' c, d, i, f, s, u
// error: ' ' flag used with '%c' '%u' gnu_printf format [-Werror=format=]
    s21_sprintf(data1, "It's %% ready %c% d% i% f%s%u\n", c, d, i, f, s, u);
    sprintf(data2, "It's %% ready %c% d% i% f%s%u\n", c, d, i, f, s, u);
    ck_assert_pstr_eq(data1, data2);
    //  da<0, fa<0, ia <0
    s21_sprintf(data1, "It's %% ready %c% d% i% f%s%u\n", c, da, ia, fa, s, u);
    sprintf(data2, "It's %% ready %c% d% i% f%s%u\n", c, da, ia, fa, s, u);
    ck_assert_pstr_eq(data1, data2);
//    + c, d, i, f, s, u
    s21_sprintf(data1, "It's %% ready %+c%+d%+i%+f%+s%+u\n", c, d, i, f, s, u);
    sprintf(data2, "It's %% ready %c%+d%+i%+f%s%u\n", c, d, i, f, s, u);
    ck_assert_pstr_eq(data1, data2);
    //  da<0, fa<0, ia <0
    s21_sprintf(data1, "It's %% ready %+c%+d%+i%+f%+s%+u\n", c, da, ia, fa, s, u);
    sprintf(data2, "It's %% ready %c%+d%+i%+f%s%u\n", c, da, ia, fa, s, u);
    ck_assert_pstr_eq(data1, data2);
}
END_TEST

START_TEST(s21_sprintf_July_test_5) {
    char data1[200];
    char data2[200];
    char *s = "already";
    wchar_t *w = L"code";
    short int dah = 33;
    float f = 123.4567899;
    unsigned int u = 0x888;
    char c = '!';
    wchar_t o = '!';

    s21_sprintf(data1, "I have %s rewritten this %ls %.4hi times%-3c\n", s, w, dah, c);
    sprintf(data2, "I have %s rewritten this %ls %.4hi times%-3c\n", s, w, dah, c);
    ck_assert_pstr_eq(data1, data2);

    s21_sprintf(data1, "I have %s rewritten this code % .f times%lc\n", s, f, o);  //  float
    sprintf(data2, "I have %s rewritten this code % .f times%lc\n", s, f, o);
    ck_assert_pstr_eq(data1, data2);

    s21_sprintf(data1, "I have %s rewritten this code %8.6u times%lc\n", s, u, o);
    sprintf(data2, "I have %s rewritten this code %8.6u times%lc\n", s, u, o);
    ck_assert_pstr_eq(data1, data2);
}
END_TEST

char test1[20] = "Hell0 world\0";
char test2[20] = "Hell0 world\n\0";
char test3[10] = "a\n\0";
char test4[10] = " \n\0";
char test5[10] = " \0";
char test6[10] = "\n\0";
char test7[10] = "\0";
//  memchr test
START_TEST(s21_memchr_f) {
    ck_assert_ptr_eq(s21_memchr(test1, 'h', 12), memchr(test1, 'h', 12));
    ck_assert_pstr_eq(s21_memchr(test2, 'l', 12), memchr(test2, 'l', 12));
    ck_assert_pstr_eq(s21_memchr(test3, '\n', 4), memchr(test3, '\n', 4));
    ck_assert_pstr_eq(s21_memchr(test4, '\n', 3), memchr(test4, '\n', 3));
    ck_assert_pstr_eq(s21_memchr(test5, ' ', 3), memchr(test5, ' ', 3));
    ck_assert_pstr_eq(s21_memchr(test6, '\n', 2), memchr(test6, '\n', 2));
    ck_assert_ptr_eq(s21_memchr(test7, ' ', 2), memchr(test7, ' ', 2));
}
END_TEST

//  memcmp test
START_TEST(s21_memcmp_f) {
    char toCompare[] = "Hell0 man";

    ck_assert_int_eq(s21_memcmp(test1, toCompare, 8),
                     memcmp(test1, toCompare, 8));
    ck_assert_int_eq(s21_memcmp(test2, toCompare, 10),
                     memcmp(test2, toCompare, 10));
    ck_assert_int_eq(s21_memcmp(test3, toCompare, 8),
                     memcmp(test3, toCompare, 8));
    ck_assert_int_eq(s21_memcmp(test4, toCompare, 8),
                     memcmp(test4, toCompare, 8));
    ck_assert_int_eq(s21_memcmp(test5, toCompare, 8),
                     memcmp(test5, toCompare, 8));
    ck_assert_int_eq(s21_memcmp(test6, toCompare, 8),
                     memcmp(test6, toCompare, 8));
    ck_assert_int_eq(s21_memcmp(test7, toCompare, 8),
                     memcmp(test7, toCompare, 8));
}
END_TEST

//  memcpy test
START_TEST(s21_memcpy_f) {
    char destination1[] = "Here w0 are\0";
    char result[] = "Here w0 are\0";
    ck_assert_pstr_eq(s21_memcpy(destination1, test1, 8),
                     memcpy(result, test1, 8));

    char destination2[] = "Here w0 are\n\0";
    char result2[] = "Here w0 are\n\0";
    ck_assert_pstr_eq(s21_memcpy(destination2, test2, 8),
                     memcpy(result2, test2, 8));

    char destination3[] = "a\n\0";
    char result3[] = "a\n\0";
    ck_assert_pstr_eq(s21_memcpy(destination3, test3, 2),
                     memcpy(result3, test3, 2));

    char destination4[] = " \n\0";
    char result4[] = " \n\0";
    ck_assert_pstr_eq(s21_memcpy(destination4, test4, 2),
                     memcpy(result4, test4, 2));

    char destination5[] = " \0";
    char result5[] = " \0";
    ck_assert_pstr_eq(s21_memcpy(destination5, test5, 2),
                     memcpy(result5, test5, 2));

    char destination6[] = "\n\0";
    char result6[] = "\n\0";
    ck_assert_pstr_eq(s21_memcpy(destination6, test6, 2),
                     memcpy(result6, test6, 2));

    char destination7[] = "\0";
    char result7[] = "aaa\0";
    ck_assert_pstr_eq(s21_memcpy(destination7, test7, 2),
                     memcpy(result7, test7, 2));
}
END_TEST

//  memmove test
START_TEST(s21_memmove_f) {
    char str1[30] = "teststring";
    char str2[30] = "teststring";
    ck_assert_pstr_eq(s21_memmove(str1 + 2, str1, 10),
                     memmove(str2 + 2, str2, 10));

    char destination2[] = "Here w0 are\n\0";
    char result2[] = "Here w0 are\n\0";
    ck_assert_pstr_eq(s21_memmove(destination2, test2, 8),
                     memmove(result2, test2, 8));

    char destination3[] = "a\n\0";
    char result3[] = "a\n\0";
    ck_assert_pstr_eq(s21_memmove(destination3, test3, 2),
                     memmove(result3, test3, 2));

    char destination4[] = " \n\0";
    char result4[] = " \n\0";
    ck_assert_pstr_eq(s21_memmove(destination4, test4, 2),
                     memmove(result4, test4, 2));

    char destination5[] = " \0";
    char result5[] = " \0";
    ck_assert_pstr_eq(s21_memmove(destination5, test5, 2),
                     memmove(result5, test5, 2));

    char destination6[] = "\n\0";
    char result6[] = "\n\0";
    ck_assert_pstr_eq(s21_memmove(destination6, test6, 2),
                     memmove(result6, test6, 2));

    char destination7[] = "\0";
    char result7[] = "\0";
    ck_assert_pstr_eq(s21_memmove(destination7, test7, 2),
                     memmove(result7, test7, 2));
}
END_TEST

//  memset test
START_TEST(s21_memset_f) {
    char destination[] = "Here w0 are123\0";
    char origin[] = "Here w0 are123\0";
    ck_assert_pstr_eq(s21_memset(destination, '-', 4), memset(origin, '-', 4));

    char destination2[] = "Here w0 are\n\0";
    char origin2[] = "Here w0 are\n\0";
    ck_assert_pstr_eq(s21_memset(destination2, '-', 4), memset(origin2, '-', 4));

    char destination3[] = "a\n\0";
    char origin3[] = "a\n\0";
    ck_assert_pstr_eq(s21_memset(destination3, '-', 2), memset(origin3, '-', 2));

    char destination4[] = " \n\0";
    char origin4[] = " \n\0";
    ck_assert_pstr_eq(s21_memset(destination4, '-', 2), memset(origin4, '-', 2));

    char destination5[] = " \0";
    char origin5[] = " \0";
    ck_assert_pstr_eq(s21_memset(destination5, '-', 1), memset(origin5, '-', 1));

    char destination6[] = "\n\0";
    char origin6[] = "\n\0";
    ck_assert_pstr_eq(s21_memset(destination6, '-', 1), memset(origin6, '-', 1));

    char origin7[] = "\0";
    char destination7[] = "\0";
    ck_assert_pstr_eq(s21_memset(destination7, '-', 1), memset(origin7, '-', 1));
}
END_TEST

// strcat test
START_TEST(s21_strcat_f) {
    char destination[40] = "Here w0 are123\0";
    char origin[40] = "Here w0 are123\0";
    ck_assert_pstr_eq(s21_strcat(destination, test1), strcat(origin, test1));

    char destination2[40] = "Here w0 are\n\0";
    char origin2[40] = "Here w0 are\n\0";
    ck_assert_pstr_eq(s21_strcat(destination2, test2), strcat(origin2, test2));

    char destination3[40] = "a\n\0";
    char origin3[40] = "a\n\0";
    ck_assert_pstr_eq(s21_strcat(destination3, test3), strcat(origin3, test3));

    char destination4[40] = " \n\0";
    char origin4[40] = " \n\0";
    ck_assert_pstr_eq(s21_strcat(destination4, test4), strcat(origin4, test4));

    char destination5[40] = " \0";
    char origin5[40] = " \0";
    ck_assert_pstr_eq(s21_strcat(destination5, test5), strcat(origin5, test5));

    char destination6[40] = "\n\0";
    char origin6[40] = "\n\0";
    ck_assert_pstr_eq(s21_strcat(destination6, test6), strcat(origin6, test6));

    char origin7[40] = "\0";
    char destination7[40] = "\0";
    ck_assert_pstr_eq(s21_strcat(destination7, test7), strcat(origin7, test7));
}
END_TEST

//  strncat test
START_TEST(s21_strncat_f) {
    char destination[40] = "Here w0 are123\0";
    char origin[40] = "Here w0 are123\0";
    ck_assert_pstr_eq(s21_strncat(destination, test1, 4),
                     strncat(origin, test1, 4));

    char destination2[40] = "Here w0 are\n\0";
    char origin2[40] = "Here w0 are\n\0";
    ck_assert_pstr_eq(s21_strncat(destination2, test2, 4),
                     strncat(origin2, test2, 4));

    char destination3[40] = "a\n\0";
    char origin3[40] = "a\n\0";
    ck_assert_pstr_eq(s21_strncat(destination3, test3, 4),
                     strncat(origin3, test3, 4));

    char destination4[40] = " \n\0";
    char origin4[40] = " \n\0";
    ck_assert_pstr_eq(s21_strncat(destination4, test4, 4),
                     strncat(origin4, test4, 4));

    char destination5[40] = " \0";
    char origin5[40] = " \0";
    ck_assert_pstr_eq(s21_strncat(destination5, test5, 4),
                     strncat(origin5, test5, 4));

    char destination6[40] = "\n\0";
    char origin6[40] = "\n\0";
    ck_assert_pstr_eq(s21_strncat(destination6, test6, 4),
                     strncat(origin6, test6, 4));

    char origin7[40] = "\0";
    char destination7[40] = "\0";
    ck_assert_pstr_eq(s21_strncat(destination7, test7, 4),
                     strncat(origin7, test7, 4));
}
END_TEST

//  strchr test
START_TEST(s21_strchr_f) {
    ck_assert_pstr_eq(s21_strchr(test1, 'e'), strchr(test1, 'e'));
    ck_assert_pstr_eq(s21_strchr(test2, 'e'), strchr(test2, 'e'));
    ck_assert_ptr_eq(s21_strchr(test3, 'e'), strchr(test3, 'e'));
    ck_assert_ptr_eq(s21_strchr(test4, 'e'), strchr(test4, 'e'));
    ck_assert_ptr_eq(s21_strchr(test5, 'e'), strchr(test5, 'e'));
    ck_assert_ptr_eq(s21_strchr(test6, 'e'), strchr(test6, 'e'));
    ck_assert_ptr_eq(s21_strchr(test7, 'e'), strchr(test7, 'e'));
}
END_TEST

//  strcmp  test
START_TEST(s21_strcmp_f) {
    char toCompare[] = "Hell0 man";

    ck_assert_int_eq(s21_strcmp(test1, toCompare), strcmp(test1, toCompare));
    ck_assert_int_eq(s21_strcmp(test2, toCompare), strcmp(test2, toCompare));
    ck_assert_int_eq(s21_strcmp(test3, toCompare), strcmp(test3, toCompare));
    ck_assert_int_eq(s21_strcmp(test4, toCompare), strcmp(test4, toCompare));
    ck_assert_int_eq(s21_strcmp(test5, toCompare), strcmp(test5, toCompare));
    ck_assert_int_eq(s21_strcmp(test6, toCompare), strcmp(test6, toCompare));
    ck_assert_int_eq(s21_strcmp(test7, toCompare), strcmp(test7, toCompare));
}
END_TEST

//  strncmp test
START_TEST(s21_strncmp_f) {
    char toCompare[] = "Hell0 man";

    ck_assert_int_eq(s21_strncmp(test1, toCompare, 6),
                     strncmp(test1, toCompare, 6));
    ck_assert_int_eq(s21_strncmp(test2, toCompare, 6),
                     strncmp(test2, toCompare, 6));
    ck_assert_int_eq(s21_strncmp(test3, toCompare, 4),
                     strncmp(test3, toCompare, 4));
    ck_assert_int_eq(s21_strncmp(test4, toCompare, 4),
                     strncmp(test4, toCompare, 4));
    ck_assert_int_eq(s21_strncmp(test5, toCompare, 3),
                     strncmp(test5, toCompare, 3));
    ck_assert_int_eq(s21_strncmp(test6, toCompare, 3),
                     strncmp(test6, toCompare, 3));
    ck_assert_int_eq(s21_strncmp(test7, toCompare, 2),
                     strncmp(test7, toCompare, 2));
}
END_TEST

//  strcpy  test
START_TEST(s21_strcpy_f) {
    char destination[] = "Here w0 are\0";
    char result[] = "Here w0 are\0";
    ck_assert_pstr_eq(s21_strcpy(destination, test1), strcpy(result, test1));

    char destination2[] = "Here w0 are\n\0";
    char result2[] = "Here w0 are\n\0";
    ck_assert_pstr_eq(s21_strcpy(destination2, test2), strcpy(result2, test2));

    char destination3[] = "a\n\0";
    char result3[] = "a\n\0";
    ck_assert_pstr_eq(s21_strcpy(destination3, test3), strcpy(result3, test3));

    char destination4[] = " \n\0";
    char result4[] = " \n\0";
    ck_assert_pstr_eq(s21_strcpy(destination4, test4), strcpy(result4, test4));

    char destination5[] = " \0";
    char result5[] = " \0";
    ck_assert_pstr_eq(s21_strcpy(destination5, test5), strcpy(result5, test5));

    char destination6[] = "\n\0";
    char result6[] = "\n\0";
    ck_assert_pstr_eq(s21_strcpy(destination6, test6), strcpy(result6, test6));

    char destination7[] = "\0";
    char result7[] = "\0";
    ck_assert_pstr_eq(s21_strcpy(destination7, test7), strcpy(result7, test7));
}
END_TEST

//  strncpy test
START_TEST(s21_strncpy_f) {
    char destination[] = "Here w0 are\0";
    char result[] = "Here w0 are\0";
    ck_assert_pstr_eq(s21_strncpy(destination, test1, 4),
                     strncpy(result, test1, 4));

    char destination2[] = "Here w0 are\n\0";
    char result2[] = "Here w0 are\n\0";
    ck_assert_pstr_eq(s21_strncpy(destination2, test2, 8),
                     strncpy(result2, test2, 8));

    char destination3[] = "a\n\0";
    char result3[] = "a\n\0";
    ck_assert_pstr_eq(s21_strncpy(destination3, test3, 2),
                     strncpy(result3, test3, 2));

    char destination4[] = " \n\0";
    char result4[] = " \n\0";
    ck_assert_pstr_eq(s21_strncpy(destination4, test4, 2),
                     strncpy(result4, test4, 2));

    char destination5[] = " \0";
    char result5[] = " \0";
    ck_assert_pstr_eq(s21_strncpy(destination5, test5, 2),
                     strncpy(result5, test5, 2));

    char destination6[] = "\n\0";
    char result6[] = "\n\0";
    ck_assert_pstr_eq(s21_strncpy(destination6, test6, 2),
                     strncpy(result6, test6, 2));

    char destination7[] = "\0";
    char result7[] = "\0";
    ck_assert_pstr_eq(s21_strncpy(destination7, test7, 2),
                     strncpy(result7, test7, 2));
}
END_TEST

//  strcspn test
START_TEST(s21_strcspn_f) {
    char toCompare[] = "0a \n";

    ck_assert_uint_eq(s21_strcspn(test1, toCompare), strcspn(test1, toCompare));
    ck_assert_uint_eq(s21_strcspn(test2, toCompare), strcspn(test2, toCompare));
    ck_assert_uint_eq(s21_strcspn(test3, toCompare), strcspn(test3, toCompare));
    ck_assert_uint_eq(s21_strcspn(test4, toCompare), strcspn(test4, toCompare));
    ck_assert_uint_eq(s21_strcspn(test5, toCompare), strcspn(test5, toCompare));
    ck_assert_uint_eq(s21_strcspn(test6, toCompare), strcspn(test6, toCompare));
    ck_assert_uint_eq(s21_strcspn(test7, toCompare), strcspn(test7, toCompare));
}
END_TEST

//  strlen  test
START_TEST(s21_strlen_f) {
    ck_assert_uint_eq(s21_strlen(test1), strlen(test1));
    ck_assert_uint_eq(s21_strlen(test2), strlen(test2));
    ck_assert_uint_eq(s21_strlen(test3), strlen(test3));
    ck_assert_uint_eq(s21_strlen(test4), strlen(test4));
    ck_assert_uint_eq(s21_strlen(test5), strlen(test5));
    ck_assert_uint_eq(s21_strlen(test6), strlen(test6));
    ck_assert_uint_eq(s21_strlen(test7), strlen(test7));
}
END_TEST

//  strpbrk test
START_TEST(s21_strpbrk_f) {
    char toCompare[] = "aeou";

    ck_assert_pstr_eq(s21_strpbrk(test1, toCompare), strpbrk(test1, toCompare));
    ck_assert_pstr_eq(s21_strpbrk(test2, toCompare), strpbrk(test2, toCompare));
    ck_assert_pstr_eq(s21_strpbrk(test3, toCompare), strpbrk(test3, toCompare));
    ck_assert_ptr_eq(s21_strpbrk(test4, toCompare), strpbrk(test4, toCompare));
    ck_assert_ptr_eq(s21_strpbrk(test5, toCompare), strpbrk(test5, toCompare));
    ck_assert_ptr_eq(s21_strpbrk(test6, toCompare), strpbrk(test6, toCompare));
    ck_assert_ptr_eq(s21_strpbrk(test7, toCompare), strpbrk(test7, toCompare));
}
END_TEST

//  strrchr test
START_TEST(s21_strrchr_f) {
    ck_assert_pstr_eq(s21_strrchr(test1, 'o'), strrchr(test1, 'o'));
    ck_assert_pstr_eq(s21_strrchr(test2, 'l'), strrchr(test2, 'l'));
    ck_assert_pstr_eq(s21_strrchr(test3, '\n'), strrchr(test3, '\n'));
    ck_assert_pstr_eq(s21_strrchr(test4, ' '), strrchr(test4, ' '));
    ck_assert_pstr_eq(s21_strrchr(test5, ' '), strrchr(test5, ' '));
    ck_assert_pstr_eq(s21_strrchr(test6, '\0'), strrchr(test6, '\0'));
    ck_assert_ptr_eq(s21_strrchr(test7, ' '), strrchr(test7, ' '));
}
END_TEST

//  strspn
START_TEST(s21_strspn_f) {
    char sym[] = "el";

    ck_assert_uint_eq(s21_strspn(test1, sym), strspn(test1, sym));
    ck_assert_uint_eq(s21_strspn(test2, sym), strspn(test2, sym));
    ck_assert_uint_eq(s21_strspn(test3, sym), strspn(test3, sym));
    ck_assert_uint_eq(s21_strspn(test4, sym), strspn(test4, sym));
    ck_assert_uint_eq(s21_strspn(test5, sym), strspn(test5, sym));
    ck_assert_uint_eq(s21_strspn(test6, sym), strspn(test6, sym));
    ck_assert_uint_eq(s21_strspn(test7, sym), strspn(test7, sym));
}
END_TEST

//  strstr
START_TEST(s21_strstr_f) {
    char sym[] = "el\0";

    char test8[10] = "\0";
    char sym2[10] = "";

    char test9[10] = "ello";
    char sym3[10] = "elk";

    char test11[10] = "ello";
    char sym5[10] = "elloz";

    ck_assert_pstr_eq(s21_strstr(test1, sym), strstr(test1, sym));
    ck_assert_pstr_eq(s21_strstr(test2, sym), strstr(test2, sym));
    ck_assert_ptr_eq(s21_strstr(test3, sym), strstr(test3, sym));
    ck_assert_ptr_eq(s21_strstr(test4, sym), strstr(test4, sym));
    ck_assert_ptr_eq(s21_strstr(test5, sym), strstr(test5, sym));
    ck_assert_ptr_eq(s21_strstr(test6, sym), strstr(test6, sym));
    ck_assert_ptr_eq(s21_strstr(test7, sym), strstr(test7, sym));
    ck_assert_ptr_eq(s21_strstr(test8, sym2), strstr(test8, sym2));
    ck_assert_ptr_eq(s21_strstr(test9, sym3), strstr(test9, sym3));
    ck_assert_ptr_eq(s21_strstr(test11, sym5), strstr(test11, sym5));
}
END_TEST

// strtok
START_TEST(s21_strtok_f) {
    char dest[] = "Hell0 world\0";
    char orig[] = "Hell0 world\0";
    ck_assert_pstr_eq(s21_strtok(dest, " "), strtok(orig, " "));

    char dest2[] = "Hell0 world\n\0";
    char orig2[] = "Hell0 world\n\0";
    ck_assert_pstr_eq(s21_strtok(dest2, " "), strtok(orig2, " "));

    char dest3[] = "a\n\0";
    char orig3[] = "a\n\0";
    ck_assert_pstr_eq(s21_strtok(dest3, " "), strtok(orig3, " "));

    char dest4[] = " s\0";
    char orig4[] = " s\0";
    ck_assert_pstr_eq(s21_strtok(dest4, " "), strtok(orig4, " "));

    char dest5[] = " \0";
    char orig5[] = " \0";
    ck_assert_ptr_eq(s21_strtok(dest5, " "), strtok(orig5, " "));

    char dest6[] = "\n\0";
    char orig6[] = "\n\0";
    ck_assert_pstr_eq(s21_strtok(dest6, " "), strtok(orig6, " "));

    char dest7[] = "\0";
    char orig7[] = "\0";
    ck_assert_ptr_eq(s21_strtok(dest7, " "), strtok(orig7, " "));

    char dest8[] = "test1/test2/test3/test4";
    char orig8[] = "test1/test2/test3/test4";
    ck_assert_pstr_eq(s21_strtok(dest8, "/"), strtok(orig8, "/"));
    ck_assert_pstr_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
    ck_assert_pstr_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
    ck_assert_pstr_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
    ck_assert_ptr_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));

    char dest9[] = "test1/test2/test3///";
    char orig9[] = "test1/test2/test3///";
    ck_assert_pstr_eq(s21_strtok(dest9, "/"), strtok(orig9, "/"));
    ck_assert_pstr_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
    ck_assert_pstr_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
    ck_assert_ptr_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));

    char dest10[] = "///test1///test2/test3/";
    char orig10[] = "///test1///test2/test3/";
    ck_assert_pstr_eq(s21_strtok(dest10, "/"), strtok(orig10, "/"));
    ck_assert_pstr_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
    ck_assert_pstr_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
    ck_assert_ptr_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
}
END_TEST

//  to_upper test
START_TEST(s21_to_upper_f) {
    char destination[] = "Here w0 are123\0";
    char *test01 = s21_to_upper(destination);
    ck_assert_pstr_eq(test01, "HERE W0 ARE123");
    free(test01);

    char destination2[] = "Here w0 are\n\0";
    char *test02 = s21_to_upper(destination2);
    ck_assert_pstr_eq(test02, "HERE W0 ARE\n");
    free(test02);

    char destination3[] = "a\n\0";
    char *test03 = s21_to_upper(destination3);
    ck_assert_pstr_eq(test03, "A\n");
    free(test03);

    char destination4[] = " \n\0";
    char *test04 = s21_to_upper(destination4);
    ck_assert_pstr_eq(test04, " \n");
    free(test04);

    char destination5[] = " \0";
    char *test05 = s21_to_upper(destination5);
    ck_assert_pstr_eq(test05, " ");
    free(test05);

    char destination6[] = "\n\0";
    char *test06 = s21_to_upper(destination6);
    ck_assert_pstr_eq(test06, "\n");
    free(test06);

    char destination7[] = "\0";
    char *test07 = s21_to_upper(destination7);
    ck_assert_pstr_eq(test07, "");
    free(test07);
}
END_TEST

//  to_lower test
START_TEST(s21_to_lower_f) {
    char destination[] = "HERE W0 ARE123\0";
    char *test01 = s21_to_lower(destination);
    ck_assert_pstr_eq(test01, "here w0 are123");
    free(test01);

    char destination2[] = "HERE W0 ARE\n\0";
    char *test02 = s21_to_lower(destination2);
    ck_assert_pstr_eq(test02, "here w0 are\n");
    free(test02);

    char destination3[] = "A\n\0";
    char *test03 = s21_to_lower(destination3);
    ck_assert_pstr_eq(test03, "a\n");
    free(test03);

    char destination4[] = " \n\0";
    char *test04 = s21_to_lower(destination4);
    ck_assert_pstr_eq(test04, " \n");
    free(test04);

    char destination5[] = " \0";
    char *test05 = s21_to_lower(destination5);
    ck_assert_pstr_eq(test05, " ");
    free(test05);

    char destination6[] = "\n\0";
    char *test06 = s21_to_lower(destination6);
    ck_assert_pstr_eq(test06, "\n");
    free(test06);

    char destination7[] = "\0";
    char *test07 = s21_to_lower(destination7);
    ck_assert_pstr_eq(test07, "");
    free(test07);
}
END_TEST

//  insert test
START_TEST(s21_insert_f) {
    char dest[] = "Hello\0";
    char insert[] = "Man\0";
    char *test01 = s21_insert(dest, insert, 2);
    ck_assert_pstr_eq(test01, "HeManllo\0");
    free(test01);

    char dest2[] = "Hello\n\0";
    char insert2[] = "Man\n\0";
    char *test02 = s21_insert(dest2, insert2, 1);
    ck_assert_pstr_eq(test02, "HMan\nello\n\0");
    free(test02);

    char dest3[] = "a\0";
    char insert3[] = "man\0";
    char *test03 = s21_insert(dest3, insert3, 1);
    ck_assert_pstr_eq(test03, "aman");
    free(test03);

    char dest4[] = " s\0";
    char insert4[] = " s\0";
    char *test04 = s21_insert(dest4, insert4, 1);
    ck_assert_pstr_eq(test04, "  ss");
    free(test04);

    char dest5[100] = "\n\0";
    char insert5[100] = "\n\0";
    char *test05 = s21_insert(dest5, insert5, 1);
    ck_assert_pstr_eq(test05, "\n\n");
    free(test05);

    char dest6[] = " \0";
    char insert6[] = " \0";
    char *test06 = s21_insert(dest6, insert6, 1);
    ck_assert_pstr_eq(test06, "  ");
    free(test06);

    char dest7[] = "\0";
    char insert7[] = "\0";
    char *test07 = s21_insert(dest7, insert7, 1);
    ck_assert_ptr_eq(test07, NULL);
}
END_TEST

//  trim test
START_TEST(s21_trim_f_1) {
    char dest[] = "-=Hello=-\0";
    char *test01 = s21_trim(dest, "-");
    ck_assert_pstr_eq(test01, "=Hello=\0");
    free(test01);

    char dest2[] = "-Hello\n\0";
    char *test02 = s21_trim(dest2, "-");
    ck_assert_pstr_eq(test02, "Hello\n\0");
    free(test02);

    char dest3[] = "a\0";
    char *test03 = s21_trim(dest3, "a");
    ck_assert_pstr_eq(test03, NULL);
    free(test03);

    char dest4[] = " \n\0";
    char *test04 = s21_trim(dest4, "\n");
    ck_assert_pstr_eq(test04, " ");
    free(test04);
}
END_TEST

START_TEST(s21_trim_f_2) {
    char dest5[] = "\n\0";
    char *test05 = s21_trim(dest5, "\0");
    ck_assert_pstr_eq(test05, "\n");
    free(test05);

    char dest6[] = " \0";
    char *test06 = s21_trim(dest6, " ");
    ck_assert_pstr_eq(test06, NULL);
    free(test06);

    char *test07 = s21_trim(dest6, NULL);
    ck_assert_pstr_eq(test07, NULL);
    free(test07);
}
END_TEST

START_TEST(s21_sprintf_test_d) {
    char str1[1000];
    char str2[1000];
    short h = 34;
    long l = 2353423523424;
    int r1 = sprintf(
            str1, "%-25.10d%-30.2d%10.12d%11d%.8d%7.5d%+-25.8d%+10.2ld%-11.8hd", 253,
            335, 1234, 34, 10, 25, 666, l, h);
    int r2 = s21_sprintf(
            str2, "%-25.10d%-30.2d%10.12d%11d%.8d%7.5d%+-25.8d%+10.2ld%-11.8hd", 253,
            335, 1234, 34, 10, 25, 666, l, h);
    ck_assert_pstr_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_i) {
    char str1[1000];
    char str2[1000];
    short h = 34;
    long l = 2353423523424;
    int r1 =
            sprintf(str1, "%+50.i%-10.20i%10.i%12i%7.5i%-10.8i%+10.1li%8.25hi",
                    34567, 225, 5230, 125, 10, 5, l, h);
    int r2 =
            s21_sprintf(str2, "%+50.i%-10.20i%10.i%12i%7.5i%-10.8i%+10.1li%8.25hi",
                        34567, 225, 5230, 125, 10, 5, l, h);
    ck_assert_pstr_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_c) {
    char str1[1000];
    char str2[1000];
    wchar_t c1 = 'T', c2 = 'Z';
    int r1 = sprintf(str1, "%10c%-10c%25c%-30c%25c%8c%2c%8c%lc%-50lc", 'a',
                     'f', 'R', 'Q', 10, 'P', 'L', 20, c1, c2);
    int r2 = s21_sprintf(str2, "%10c%-10c%25c%-30c%25c%8c%2c%8c%lc%-50lc", 'a',
                         'f', 'R', 'Q', 10, 'P', 'L', 20, c1, c2);
    ck_assert_pstr_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_f) {
    char str1[1000];
    char str2[1000];
    int r1 = sprintf(
            str1,
            "%+-10.3f%+10.2f%15.10f%+8.6f%8.10f%-.8f%25.8f%25.f%+10.f%.f",
            2546.4324, 3452.4325, 5678.43256, 456789.243242,
            3456789123.43245, 12345.6788, 4325678.43242,
            34567.2345432, 2.0, 34567.43244);
    int r2 = s21_sprintf(
            str2,
            "%+-10.3f%+10.2f%15.10f%+8.6f%8.10f%-.8f%25.8f%25.f%+10.f%.f",
            2546.4324, 3452.4325, 5678.43256, 456789.243242,
            3456789123.43245, 12345.6788, 4325678.43242,
            34567.2345432, 2.0, 34567.43244);
    ck_assert_pstr_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST



START_TEST(s21_sprintf_test_u) {
    char str1[1000];
    char str2[1000];
    unsigned short h = 115;
    unsigned long l = 123325242342;
    int r1 =
            sprintf(str1, "%u %15u %-20u %10u %-15.10u %20.8u %7.5u %8.10u %-20.12lu %19hu",
                    (unsigned)4321, (unsigned)34567, (unsigned)12346, (unsigned)234542,
                     (unsigned)10, (unsigned)10, (unsigned)5, (unsigned)2432, l, h);
    int r2 = s21_sprintf(
            str2, "%u %15u %-20u %10u %-15.10u %20.8u %7.5u %8.10u %-20.12lu %19hu",
            (unsigned)4321, (unsigned)34567, (unsigned)12346, (unsigned)234542,
                     (unsigned)10, (unsigned)10, (unsigned)5, (unsigned)2432, l, h);
    ck_assert_pstr_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_s) {
    char str1[1000];
    char str2[1000];
    wchar_t s[10] = {'h', 'e', 'l', 'l', 'o'};
    int r1 = sprintf(str1, "%s%23s%-15s%10.s%15.2s%16.8s%7.5s%8s%15ls%15.3ls",
                     "aboba", "helloworld", "ABOBA", "ABOBBAAA", "AAABOBA",
                     "QWERTY", "AAAAABOOOOOBAAA", "ABOBAAAAA", s, s);
    int r2 =
            s21_sprintf(str2, "%s%23s%-15s%10.s%15.2s%16.8s%7.5s%8s%15ls%15.3ls",
                        "aboba", "helloworld", "ABOBA", "ABOBBAAA", "AAABOBA",
                        "QWERTY", "AAAAABOOOOOBAAA", "ABOBAAAAA", s, s);
    ck_assert_pstr_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST


START_TEST(s21_sprintf_test_percent) {
    char str1[1000];
    char str2[1000];
    int r1 = sprintf(str1, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
    int r2 = s21_sprintf(str2, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
    ck_assert_pstr_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST






int main() {
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);

    //  memchr
    TCase *tc_memchr;
    tc_memchr = tcase_create("memchr func");
    suite_add_tcase(s1, tc_memchr);
    tcase_add_test(tc_memchr, s21_memchr_f);

    //  memcmp
    TCase *tc_memcmp;
    tc_memcmp = tcase_create("memcmp func");
    suite_add_tcase(s1, tc_memcmp);
    tcase_add_test(tc_memcmp, s21_memcmp_f);

    //  memcpy
    TCase *tc_memcpy;
    tc_memcpy = tcase_create("memcpy func");
    suite_add_tcase(s1, tc_memcpy);
    tcase_add_test(tc_memcpy, s21_memcpy_f);

    //  memmove
    TCase *tc_memmove;
    tc_memmove = tcase_create("memmove func");
    suite_add_tcase(s1, tc_memmove);
    tcase_add_test(tc_memmove, s21_memmove_f);

    //  memset
    TCase *tc_memset;
    tc_memset = tcase_create("memset func");
    suite_add_tcase(s1, tc_memset);
    tcase_add_test(tc_memset, s21_memset_f);

    //  strcat
    TCase *tc_strcat;
    tc_strcat = tcase_create("strcat func");
    suite_add_tcase(s1, tc_strcat);
    tcase_add_test(tc_strcat, s21_strcat_f);

    //  strncat
    TCase *tc_strncat;
    tc_strncat = tcase_create("strncat func");
    suite_add_tcase(s1, tc_strncat);
    tcase_add_test(tc_strncat, s21_strncat_f);

    //  strchr
    TCase *tc_strchr;
    tc_strchr = tcase_create("strchr func");
    suite_add_tcase(s1, tc_strchr);
    tcase_add_test(tc_strchr, s21_strchr_f);

    //  strcmp
    TCase *tc_strcmp;
    tc_strcmp = tcase_create("strcmp func");
    suite_add_tcase(s1, tc_strcmp);
    tcase_add_test(tc_strcmp, s21_strcmp_f);

    //  strncmp
    TCase *tc_strncmp;
    tc_strncmp = tcase_create("strncmp func");
    suite_add_tcase(s1, tc_strncmp);
    tcase_add_test(tc_strncmp, s21_strncmp_f);

    //  strcpy
    TCase *tc_strcpy;
    tc_strcpy = tcase_create("strcpy func");
    suite_add_tcase(s1, tc_strcpy);
    tcase_add_test(tc_strcpy, s21_strcpy_f);

    //  strncpy
    TCase *tc_strncpy;
    tc_strncpy = tcase_create("strncpy func");
    suite_add_tcase(s1, tc_strncpy);
    tcase_add_test(tc_strncpy, s21_strncpy_f);

    //  strcspn
    TCase *tc_strcspn;
    tc_strcspn = tcase_create("strcspn func");
    suite_add_tcase(s1, tc_strcspn);
    tcase_add_test(tc_strcspn, s21_strcspn_f);

    //  strerror
//    TCase *tc_strerror;
//    tc_strerror = tcase_create("strerror func");
//    suite_add_tcase(s1, tc_strerror);
//    tcase_add_test(tc_strerror, s21_strerror_f);

    //  strlen
    TCase *tc_strlen;
    tc_strlen = tcase_create("strlen func");
    suite_add_tcase(s1, tc_strlen);
    tcase_add_test(tc_strlen, s21_strlen_f);

    //  strpbrk
    TCase *tc_strpbrk;
    tc_strpbrk = tcase_create("strpbrk func");
    suite_add_tcase(s1, tc_strpbrk);
    tcase_add_test(tc_strpbrk, s21_strpbrk_f);

    //  strrchr
    TCase *tc_strrchr;
    tc_strrchr = tcase_create("strrchr func");
    suite_add_tcase(s1, tc_strrchr);
    tcase_add_test(tc_strrchr, s21_strrchr_f);

    //  strspn
    TCase *tc_strspn;
    tc_strspn = tcase_create("strspn func");
    suite_add_tcase(s1, tc_strspn);
    tcase_add_test(tc_strspn, s21_strspn_f);

    //  strstr
    TCase *tc_strstr;
    tc_strstr = tcase_create("strstr func");
    suite_add_tcase(s1, tc_strstr);
    tcase_add_test(tc_strstr, s21_strstr_f);

    //  strtok
    TCase *tc_strtok;
    tc_strtok = tcase_create("strtok func");
    suite_add_tcase(s1, tc_strtok);
    tcase_add_test(tc_strtok, s21_strtok_f);

    //  to_upper
    TCase *tc_to_upper;
    tc_to_upper = tcase_create("to_upper func");
    suite_add_tcase(s1, tc_to_upper);
    tcase_add_test(tc_to_upper, s21_to_upper_f);

    //  to_lower
    TCase *tc_to_lower;
    tc_to_lower = tcase_create("to_lower func");
    suite_add_tcase(s1, tc_to_lower);
    tcase_add_test(tc_to_lower, s21_to_lower_f);

    //  insert
    TCase *tc_insert;
    tc_insert = tcase_create("insert func");
    suite_add_tcase(s1, tc_insert);
    tcase_add_test(tc_insert, s21_insert_f);

    //  trim
    TCase *tc_trim;
    tc_trim = tcase_create("trim func");
    suite_add_tcase(s1, tc_trim);
    tcase_add_test(tc_trim, s21_trim_f_1);
    tcase_add_test(tc_trim, s21_trim_f_2);


    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, task_9_s21_strcmp_test);
    tcase_add_test(tc1_1, task_10_s21_strncmp_test);
    tcase_add_test(tc1_1, task_11_s21_strcpy_test);
    tcase_add_test(tc1_1, task_12_s21_strncpy_test);
    tcase_add_test(tc1_1, part_5_s21_to_upper_test);
    tcase_add_test(tc1_1, part_5_s21_to_lower_test);
    tcase_add_test(tc1_1, part_5_s21_insert_test);
    tcase_add_test(tc1_1, part_5_s21_trim_test_1);
    tcase_add_test(tc1_1, part_5_s21_trim_test_2);

    tcase_add_test(tc1_1, s21_sprintf_test);
    tcase_add_test(tc1_1, s21_sprintf_July_test_1);
    tcase_add_test(tc1_1, s21_sprintf_July_test_2);
    tcase_add_test(tc1_1, s21_sprintf_July_test_3);
    tcase_add_test(tc1_1, s21_sprintf_July_test_4);
    tcase_add_test(tc1_1, s21_sprintf_July_test_5);

    tcase_add_test(tc1_1, memchr_test);
    tcase_add_test(tc1_1, memcmp_test);
    tcase_add_test(tc1_1, memcpy_test);
    tcase_add_test(tc1_1, memmove_test);
    tcase_add_test(tc1_1, memset_test);
    tcase_add_test(tc1_1, strlen_test);
    tcase_add_test(tc1_1, strcmp_test);
    tcase_add_test(tc1_1, strncmp_test);
    tcase_add_test(tc1_1, strcpy_test);
    tcase_add_test(tc1_1, strncpy_test);
    tcase_add_test(tc1_1, strcat_test);
    tcase_add_test(tc1_1, strncat_test);
    tcase_add_test(tc1_1, strchr_test);
    tcase_add_test(tc1_1, strrchr_test);
    tcase_add_test(tc1_1, strpbrk_test);
    tcase_add_test(tc1_1, strerror_test);
    tcase_add_test(tc1_1, strtok_test);
    tcase_add_test(tc1_1, strspn_test);
    tcase_add_test(tc1_1, strcspn_test);
    tcase_add_test(tc1_1, strstr_test);
    tcase_add_test(tc1_1, tolower_test);
    tcase_add_test(tc1_1, toupper_test);
    tcase_add_test(tc1_1, trim_test);
    tcase_add_test(tc1_1, insert_test);

    tcase_add_test(tc1_1, s21_sprintf_test_d);
    tcase_add_test(tc1_1, s21_sprintf_test_i);
    tcase_add_test(tc1_1, s21_sprintf_test_c);
    tcase_add_test(tc1_1, s21_sprintf_test_f);
    tcase_add_test(tc1_1, s21_sprintf_test_u);
    tcase_add_test(tc1_1, s21_sprintf_test_s);
    tcase_add_test(tc1_1, s21_sprintf_test_percent);

    srunner_run_all(sr, CK_ENV);
    srunner_free(sr);

    return 0;
}
