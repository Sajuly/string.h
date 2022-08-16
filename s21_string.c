#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include "s21_string.h"
#include <limits.h>

t_buffer * create_buffer(int size, int increment_size) {
    t_buffer *t = (t_buffer *)malloc(sizeof(t_buffer));
    t->size = size;
    t->increment = increment_size;
    t->str = (char *)calloc(size, sizeof(char));
    return t;
}

void reset_buffer(t_buffer *bufer) {
    s21_memset(bufer->str, 0, bufer->size);
}

void destroy_buffer(t_buffer *buffer) {
    free(buffer->str);
    free(buffer);
}

void increase_buffer(t_buffer *buffer) {
    buffer->size += buffer->increment;
    buffer->str = (char *)realloc(buffer->str, buffer->size);
}

t_spisok *s21_sozdat_spisok() {
    t_spisok *spisok = (t_spisok *) malloc(sizeof(t_spisok));
    spisok->first_element = NULL;
    spisok->last_element = NULL;
    spisok->this_element = NULL;
    return spisok;
}

void s21_spisok_dobavit_element(t_spisok *this_spisok, t_element *element_format) {
    if (this_spisok->first_element == NULL) {
        this_spisok->first_element = element_format;
        this_spisok->last_element = this_spisok->first_element;
    } else {
        this_spisok->last_element->next_element = element_format;
        this_spisok->last_element = element_format;
    }
}

t_element *s21_sozdat_element_format() {
    t_element *new_element = (t_element*) malloc(sizeof(t_element));
    new_element->format = (t_format){
            .type = TYPE_STR,
            .flags = 0,
            .width = -1,
            .precision = -1,
            .length = 0,
            .spec = 0
    };
    new_element->format.words = (char*) calloc(WORDS_CALLOC, sizeof(char));
    new_element->next_element = NULL;
    return new_element;
}

void s21_clean_spisok(t_spisok *this_spisok) {
    t_element *this_element = this_spisok->first_element;
//    t_element *element_for_delete;
    while (this_element != NULL) {
        t_element* element_for_delete = this_element;
        this_element = this_element->next_element;
        free(element_for_delete->format.words);
        free(element_for_delete);
    }
    free(this_spisok);
}

t_element *s21_give_first_element(t_spisok *this_spisok) {
    this_spisok->this_element = this_spisok->first_element;

    return this_spisok->this_element;
}

t_element *s21_give_next_element(t_spisok *this_spisok) {
    if (this_spisok->this_element == NULL) {
        return NULL;
    }
    this_spisok->this_element = this_spisok->this_element->next_element;

    return this_spisok->this_element;
}

t_spisok *parser(const char *str) {
    int len = s21_strlen(str);
    int status = END;
    int word_inc = 0;
    int a = WORDS_CALLOC;
    int skip = 0;

    t_spisok *spisok_format = s21_sozdat_spisok();

    t_element *element = s21_sozdat_element_format();

    for (int i = 0; i < len; i++) {
        switch (str[i]) {
            case '%': if (status ==BEGIN) {
                    status = SPECIFIER;
                }
                if (status == END) {
                    status = BEGIN;
                    s21_spisok_dobavit_element(spisok_format, element);
                    element = s21_sozdat_element_format();
                    element->format.type = TYPE_FORMAT;
                    word_inc = 0;
                    a = WORDS_CALLOC;
                }
                break;
            case '+':
            case '-':
            case ' ': if (status == BEGIN) {
                    status = FLAGS;
                }
                break;
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9': if (status == BEGIN || status == FLAGS) {
                    status = WIDTH;
                }
                break;
            case '.': if (status == BEGIN || status == FLAGS || status == WIDTH) {
                    status = PRECISION;
                    element->format.precision = 0;
                    skip = 1;
                }
                break;
            case '0':
                break;
            case 'l':
            case 'h': if (status == BEGIN || status == FLAGS || status == WIDTH || status == PRECISION) {
                    status = LENGTH;
                }
                break;
            case 'c':
            case 'd':
            case 'i':
            case 'f':
            case 's':
            case 'u': if (status == BEGIN || status == FLAGS || status == WIDTH
            || status == PRECISION || status ==LENGTH) {
                    status = SPECIFIER;
                }
                break;
        }

        if (status == FLAGS) {
            if (str[i] == '+') {
                element->format.flags |= FLAG_PLUS;
            }
            if (str[i] == '-') {
                element->format.flags |= FLAG_MINUS;
            }
            if (str[i] == ' ') {
                element->format.flags |= FLAG_SPACE;
            }
        }

        element->format.words[word_inc] = str[i];
        word_inc++;
        if (word_inc > a -1) {
            a = word_inc+WORDS_CALLOC;
            element->format.words = (char*) realloc(element->format.words, a);
        }

        if (status == WIDTH) {
            if (element->format.width < 0) {
                element->format.width  = 0;
            }
            element->format.width = element->format.width*10 + (str[i]-'0');  // перевод в число
        }

        if (status == PRECISION && skip == 0) {
            element->format.precision = element->format.precision*10 + (str[i]-'0');  // перевод в число
        }
        skip = 0;

        if (status == LENGTH) {
            element->format.length = str[i];
        }

        if (status == SPECIFIER) {
            element->format.spec = str[i];
            status = END;
            s21_spisok_dobavit_element(spisok_format, element);
            element = s21_sozdat_element_format();
            word_inc = 0;
            a = WORDS_CALLOC;
        }
    }
    s21_spisok_dobavit_element(spisok_format, element);
    return spisok_format;
}

int width_string(t_buffer *buffer, t_format format) {
    int len = s21_strlen(buffer->str);
    if (len < format.width) {
        while (format.width > buffer->size) {
            increase_buffer(buffer);
        }
        if (format.flags & FLAG_MINUS) {
            for (int i =0; i < format.width-len; i++) {
                buffer->str[len + i] = ' ';
            }
        } else {
            t_buffer *tmp = create_buffer(buffer->size, buffer->increment);
            s21_strcpy(tmp->str, buffer->str);
            reset_buffer(buffer);

            for (int i =0; i < format.width-len; i++) {
                buffer->str[i]= ' ';
            }
            s21_strcat(buffer->str, tmp->str);
            destroy_buffer(tmp);
        }
        len = format.width;
        buffer->str[len] = '\0';
    }
    return len;
}

int intToStr(t_buffer *buffer, long int num, t_format format) {
    int divide = 0;
    int add_znak = 0;
    int len = 0;
    int isNegative = 0;
    long int copyOfNumber;

    copyOfNumber = num;
    if (num < 0) {
        isNegative = 1;
        num = -num;
        add_znak = 1;
    }
    while (copyOfNumber != 0) {
        len++;
        copyOfNumber /= 10;
    }

    if (format.precision > len) {
        len = format.precision;
    }

    if (format.flags & (FLAG_PLUS | FLAG_SPACE)) {
        add_znak = 1;
    }
    len +=add_znak;

    while (len > buffer->size) {
        increase_buffer(buffer);
    }

    s21_memset(buffer->str, '0', len-1);

    for (divide = 0; divide < len; divide++) {
        int modResult = num % 10;
        num    = num / 10;
        buffer->str[len- (divide + 1)] = modResult + '0';
    }

    if (isNegative) {
        buffer->str[0] = '-';
    } else if (format.flags & FLAG_PLUS) {
        buffer->str[0] = '+';
    } else if (format.flags & FLAG_SPACE) {
        buffer->str[0] = ' ';
    }
    return width_string(buffer, format);
}
//  d,i
int IntegertoString(t_buffer *buffer, va_list args, t_format format) {
    long int num = 0;

    reset_buffer(buffer);

    if (format.length == 'h') {
        num = (short)va_arg(args, int);
    } else if (format.length == 'l')  {
        num = va_arg(args, long int);
    } else {
        num = va_arg(args, int);;
    }

    return intToStr(buffer, num, format);
}

//  for f
int floatToString(t_buffer *buffer, va_list args, t_format format) {
    long double fl;
    reset_buffer(buffer);
    if (format.length == 'l')  {
        fl = va_arg(args, double);
    } else {
        fl = va_arg(args, double);
    }
    long int i_part = (long int)fl;  // Извлекаем целую часть
    long double f_part = fl - (long double)i_part;   // Извлечь плавающую часть
    if (f_part < 0) {
        f_part = -f_part;
    }
    t_format int_format = {
        .type = TYPE_FORMAT,
        .flags = format.flags,
        .width = 0,
        .precision = -1,
        .length = format.length,
        .spec = format.spec
    };
    t_format float_format = {
        .type = TYPE_FORMAT,
        .flags = 0,
        .width = 0,
        .precision = -1,
        .length = format.length,
        .spec = format.spec
    };
    t_buffer *int_part = create_buffer(buffer->size, buffer->increment);
    t_buffer *float_part = create_buffer(buffer->size, buffer->increment);

    int int_length = 0;
    int float_length = 0;

    int_length = intToStr(int_part, i_part, int_format);  // преобразовать целую часть в строку

    int precision = format.precision;
    if (precision < 0) {
        precision = 6;
    }

    if (precision != 0) {  // проверка опции отображения после точки
        f_part = round(f_part * pow(10, precision));
        float_length = intToStr(float_part, (long int)f_part, float_format);
    }

    while (int_length + float_length + 1 > buffer->size) {
        increase_buffer(buffer);
    }

    s21_strcat(buffer->str, int_part->str);
    if (float_length >0) {
        s21_strcat(buffer->str, ".");
        s21_strcat(buffer->str, float_part->str);
    }

    destroy_buffer(int_part);
    destroy_buffer(float_part);

    return width_string(buffer, format);
}

int UnsignedIntegertoString(t_buffer *buffer, va_list args, t_format format) {
    unsigned long int num = 0;

    reset_buffer(buffer);

    if (format.length == 'h') {
        num = va_arg(args, unsigned int);
    } else if (format.length == 'l')  {
        num = va_arg(args, unsigned long int);
    } else {
        num = va_arg(args, unsigned int);
    }

    int divide = 0;
    int add_znak = 0;
    int len = 0;
    long int copyOfNumber;

    copyOfNumber = num;

    while (copyOfNumber != 0) {
        len++;
        copyOfNumber /= 10;
    }

    if (format.precision > len) {
        len = format.precision;
    }

    if (format.flags & (FLAG_SPACE)) {
        add_znak = 1;
    }
    len +=add_znak;

    while (len > buffer->size) {
        increase_buffer(buffer);
    }

    s21_memset(buffer->str, '0', len-1);

    for (divide = 0; divide < len; divide++) {
        int modResult = num % 10;
        num    = num / 10;
        buffer->str[len- (divide + 1)] = modResult + '0';
    }

    if (format.flags & FLAG_SPACE) {
        buffer->str[0] = ' ';
    }
    return width_string(buffer, format);
}

int precision_string(t_buffer *buffer, t_buffer *input_buffer, t_format format) {
    int len = s21_strlen(input_buffer->str);

    if (format.precision == -1) {
        s21_strcat(buffer->str, input_buffer->str);
    } else {
        if (len > format.precision) {
            len = format.precision;
        }
        s21_strncpy(buffer->str, input_buffer->str, len);
    }
    return len;
}

int string_output(t_buffer *buffer, va_list args, t_format format) {
    char *null_str = "(null)";
    char *simple_str = va_arg(args, char*);
    reset_buffer(buffer);
    t_buffer *internal_buffer = create_buffer(buffer->size, buffer->increment);

    int cnt = 0;
    if (simple_str == NULL) {
        simple_str = null_str;
    }
    s21_strcpy(internal_buffer->str, simple_str);

    cnt = precision_string(buffer, internal_buffer, format);
    cnt = width_string(buffer, format);

    destroy_buffer(internal_buffer);
    return cnt;
}

int string_output_wide(t_buffer *buffer, va_list args, t_format format) {
    wchar_t *null_str = L"(null)";
    wchar_t *wide_str = va_arg(args, wchar_t*);
    int cnt = 0;
    reset_buffer(buffer);

    t_buffer *input_buffer = create_buffer(buffer->size, buffer->increment);

    if (wide_str == NULL) {
        wide_str = null_str;
    }

    char *p_str = input_buffer->str;
    int counter = 0;

    while (*wide_str != '\0') {
        *p_str = (char)*wide_str;
        wide_str++;
        p_str++;
        counter++;
        if (counter >= input_buffer->size) {
            increase_buffer(input_buffer);
        }
    }
    *p_str = '\0';

    cnt = precision_string(buffer, input_buffer, format);
    cnt = width_string(buffer, format);

    destroy_buffer(input_buffer);
    return cnt;
}

int char_output(t_buffer *buffer, va_list args, t_format format) {
    char c_tmp;
    int cnt = 0;

    if (format.length == 'l') {
        c_tmp = (char)va_arg(args, wchar_t);
    } else {
        c_tmp = va_arg(args, int);
    }

    reset_buffer(buffer);
    buffer->str[0] = '$';

    cnt = width_string(buffer, format);
    if (format.flags & FLAG_MINUS) {
        buffer->str[0] = c_tmp;
    } else {
        buffer->str[cnt - 1] = c_tmp;
    }

    return cnt;
}

int s21_sprintf(char *str, const char *format, ...) {
    va_list args;
    va_start(args, format);
    str[0] = '\0';
    int counter = 0;
    int part_cnt = 0;
    t_buffer *buffer = create_buffer(1000, 500);
    t_spisok * gotovo_spisok = parser(format);
    t_element *element = s21_give_first_element(gotovo_spisok);

    while (element != NULL) {
        if (element->format.type == TYPE_STR) {
            part_cnt = s21_strlen(element->format.words);
            s21_memcpy(str + counter, element->format.words, part_cnt);
            counter += part_cnt;
        } else {
            switch (element->format.spec) {
                case 's':
                    if (element->format.length == 'l') {
                        part_cnt = string_output_wide(buffer, args, element->format);
                    } else {
                        part_cnt = string_output(buffer, args, element->format);
                    }
                    s21_memcpy(str + counter, buffer->str, part_cnt);
                    counter +=part_cnt;
                    break;
                case '%':
                    s21_memcpy(str + counter, "%", 1);
                    counter++;
                    break;
                case 'c':
                    part_cnt = char_output(buffer, args, element->format);
                    s21_memcpy(str + counter, buffer->str, part_cnt);
                    counter+=part_cnt;
                    break;
                case 'd':
                case 'i':
                    part_cnt = IntegertoString(buffer, args, element->format);
                    s21_memcpy(str + counter, buffer->str, part_cnt);
                    counter+=part_cnt;
                    break;
                case 'u':
                    part_cnt = UnsignedIntegertoString(buffer, args, element->format);
                    s21_memcpy(str + counter, buffer->str, part_cnt);
                    counter+=part_cnt;
                    break;
                case 'f':
                    part_cnt = floatToString(buffer, args, element->format);
                    s21_memcpy(str + counter, buffer->str, part_cnt);
                    counter+=part_cnt;
                    break;
            }
        }
        element = s21_give_next_element(gotovo_spisok);
    }
    s21_clean_spisok(gotovo_spisok);
    *(str+counter) = '\0';
    destroy_buffer(buffer);
    va_end(args);
    return counter;
}

void *s21_memchr(const void *str, int c, size_t n) {
    void *t = NULL;
    if (str) {
        const char *info = (const char *)str;
        for (size_t i = 0; i < n && t == NULL; i++) {
            if (info[i] == c)
                t = (void *) &info[i];
        }
    }
    return t;
}

int s21_memcmp(const void *str1, const void *str2, size_t n) {
    const unsigned char *info1 = (const unsigned char *)str1;
    const unsigned char *info2 = (const unsigned char *)str2;
    int t = 0;
    for (size_t i = 0; i < n && t == 0; i++) {
        if (info1[i] != info2[i])
            t = (int)info1[i] - (int)info2[i];
    }
    return t;
}

void *s21_memcpy(void *dest, const void *src, size_t n) {
    char *dest1 = (char *)dest;
    const char *src1 = (const char *)src;
    for (size_t i = 0; i < n; i++) {
        dest1[i] = src1[i];
    }
    return dest;
}

void *s21_memmove(void *dest, const void *src, size_t n) {
    char *dest1 = (char *)dest;
    const char *src1 = (const char *)src;
    unsigned char temp[n];
        for (size_t i = 0; i < n; i++) {
            temp[i] = src1[i];
        }
        for (size_t i = 0; i < n; i++) {
            dest1[i] = temp[i];
        }
    return dest;
}

void *s21_memset(void *str, int c, size_t n) {
    unsigned char *arr = str;
    unsigned int i = 0;
    while (i < n) {
        arr[i] = c;
        i++;
    }
    return (arr);
}

char *s21_strcat(char *dest, const char *src) {
    size_t destlen = s21_strlen(dest);
    size_t srclen = s21_strlen(src);
    size_t i = 0;
    for (; i < srclen; i++) {
        dest[destlen + i] = src[i];
    }
    dest[destlen + i] = '\0';
    return dest;
}

char *s21_strncat(char *dest, const char *src, size_t n) {
    char *start = dest;
    if (n) {
        while (*dest)
            dest++;
        while ((*dest++ = *src++) != '\0') {
            if (--n == 0) {
                *dest = '\0';
                break;
            }
        }
    }
    return start;
}

char *s21_strchr(const char *str, int c) {
    const char *t = str;
    for (; *t != (char)c; ++t) {
        if (*t == '\0') {
            t = NULL;
            break;
        }
    }
    return (char *)t;
}

size_t s21_strcspn(const char *str1, const char *str2) {
    size_t t = s21_strlen(str1);
    for (size_t i = 0; i < s21_strlen(str1); i++) {
        for (size_t j = 0; j < s21_strlen(str2); j++) {
            if (str1[i] == str2[j]) {
                t = i;
                i = s21_strlen(str1);
                break;
            }
        }
    }
    return t;
}

char* s21_strerror(int errnum) {
    char* result[] = ARRERROR;
    char* resnum = (char*)calloc(70, sizeof(char));
    int max;

    if (result[0][0] == 'U')
        max = 107;
    else
        max = 133;
    if (errnum >= 0 && errnum < max) {
        s21_strcpy(resnum, result[errnum]);
    } else {
        char num[10] = {0};
        if (errnum < 0) {
            num[0] = '-';
            errnum *= -1;
        }
        s21_strcpy(resnum, "Unknown error: ");
        int i;
        for (i = 8; errnum != 0; errnum /= 10, i--) {
            num[i] = errnum % 10 + '0';
        }
        if (num[0] == '-') {
            resnum[15] = '-';
        }
        s21_strcat(resnum, num + i + 1);
    }
    return resnum;
}

size_t s21_strlen(const char *str) {
    size_t length = 0;
    for (; *(str+length); length++)
        continue;
    return length;
}


char *s21_strpbrk(const char *str1, const char *str2) {
    char *t = NULL;
    int i = 0;
    for (; str1[i] && t == NULL; i++) {
        for (int j = 0; str2[j] && t == NULL; j++) {
            if (str1[i] == str2[j])
                t = (char *)&str1[i];
        }
    }
    return t;
}

char *s21_strrchr(const char *s, int c) {
    const char *last = NULL;
    do {
        if (*s == (char)c)
            last = s;
    } while (*s++);
    return (char *)last;
}

size_t s21_strspn(const char *str1, const char *str2) {
    const char *p;
    const char *a;
    size_t count = 0;
    for (p = str1; *p != '\0'; ++p) {
        for (a = str2; *a != '\0'; ++a) {
            if (*p == *a) {
                break;
            }
        }
        if (*a == '\0') {
            return count;
        }
        ++count;
    }
    return count;
}

char *s21_strstr(const char *haystack, const char *needle) {
    char *t = NULL;
    size_t l1, l2;
    l2 = s21_strlen(needle);
    if (!l2) {
        t = (char *)haystack;
    }
    l1 = s21_strlen(haystack);
    while (l1 >= l2 && t == NULL) {
        l1--;
        if (!s21_memcmp(haystack, needle, l2)) {
            t = (char *)haystack;
        }
        haystack++;
    }
    return t;
}

char *s21_strtok(char *str, const char *delim) {
    static char *p = NULL;
    if (str != NULL) {
        p = str;
    }
    if (p != NULL) {
        str = p + s21_strspn(p, delim);
        p = str + s21_strcspn(str, delim);
    if (p == str) {
        str = NULL;
    }
    p = *p ? *p = 0, p+1 : 0;
    } else if (p == NULL) {
        str = NULL;
    }
    return str;
}

int s21_strcmp(const char *str1, const char *str2) {
    for (; *str1 && *str1 == *str2; str1++, str2++) {}
    return (*str1 - *str2);
}

int s21_strncmp(const char *str1, const char *str2, size_t n) {
    const char* end = str1+n;
    int result = 0;
    for (; result == 0 && str1 != end && (*str1 || *str2); result = *(str1++)-*(str2++)) {}
    return result;
}

char* s21_strcpy(char * dest, const char * src) {
    char * address = dest;
    if ((dest == NULL) && (src == NULL)) {
        address = NULL;
    } else {
        int i = 0;
        while (*src != '\0') {
        *dest++ = *src++;
        i++;
        }
        dest[i] = '\0';
    }
    return address;
}

char* s21_strncpy(char * dest, const char * src, size_t n) {
    char* tmp = dest;
    while (n--) {
        if (*src != '\0') {
            *dest++ = *src++;
        } else {
            *dest++ = '\0';
        }
    }
    return tmp;
}

void *s21_to_upper(const char *str) {
    char* string;
    if (str != NULL) {
        int lenStr = s21_strlen(str) + 1;
        int i = 0;
        string = (char*)calloc(lenStr, sizeof(char));
        while (i < lenStr) {
            if (str[i] >= 'a' && str[i] <= 'z') {
                string[i] = str[i] - 32;
            } else {
                string[i] = str[i];
            }
            ++i;
        }
    } else {
        string = NULL;
    }
    return string;
}

void* s21_to_lower(const char* str) {
    char* string;
    if (str != NULL) {
        int lenStr = s21_strlen(str) + 1;
        int i = 0;
            string = (char*)calloc(lenStr, sizeof(char));
            while (i < lenStr) {
                if (str[i] >= 'A' && str[i] <= 'Z') {
                    string[i] = str[i] + 32;
                } else {
                    string[i] = str[i];
                }
                ++i;
            }
    } else {
        string = NULL;
    }
    return string;
}

void* s21_insert(const char* src, const char* str, size_t start_index) {
    char* len;
    int flage = -1;
    size_t lenSrc;
    if (src == NULL || str == NULL) {
    len = NULL;
    flage = 0;
    }
    if (flage == -1) {
        lenSrc = s21_strlen(src);
        if (lenSrc < start_index) {
            len = NULL;
            flage = 1;
        }
    }
    char* result = NULL;
    size_t allStrLen = 0;
    if (flage == -1) {
        size_t lenStr;
        lenStr = s21_strlen(str);
        allStrLen = lenSrc + lenStr;
        result = (char*)calloc((lenSrc + lenStr), sizeof(char));
        for (int i = 0; i < (int)start_index; i++) {
            result[i] = src[i];
        }
        s21_strcat(result, str);
        for (int i = 0; i + start_index + lenStr < lenSrc + lenStr; i++) {
            result[i + start_index + lenStr] = src[i + start_index];
        }
    }
    return allStrLen != 0 || len != NULL ? result : NULL;
}

void* s21_trim(const char *src, const char *trim_chars) {
    char *ret = NULL;
    if (trim_chars == NULL || s21_strlen(trim_chars) == 0)
        trim_chars = " ";
    if (src != NULL) {
        for (; *src != '\0' ; src++) {
            if (!s21_strchr(trim_chars, *src))
                break;
        }
        size_t end = 0;
        for (size_t i = s21_strlen(src) ; i > 0 ; --i) {
            if (s21_strchr(trim_chars, src[i]))
                end = i;
            else
                break;
        }
        if (*src) {
            ret = calloc((end + 1), sizeof(char));
            ret = s21_strncpy(ret, src, end);
        }
    }
    return (ret);
}
