#ifndef EX12_FILES_HEADER_FILE
#define EX12_FILES_HEADER_FILE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define IF_FILE_NULL(file) \
    if ((file) == NULL)    \
    exit(1)

/*----------------------------------------------------------------
fopen - open file stream
fopen(<file name>, <mode>)
modes: r - read; w - write; a - append => binary: rb; wb; ab
for r/a | rb/ab check if file == NULL

fopen returns FILE *
NEVER CHANGE VALUE OF FILE *

--example:--
FILE *fp = fopen("file1.txt", "w");
if (fp == NULL)
{
    exit(1);
}
...
fclose(fp);

IMPORTANT FUNCTIONS:
int(char) fgetc(<file*>); if error || end of file => EOF
fputc(int(char) ch, <file*>); if error => EOF

int feof(<file*>) !=0 if file end
int ferror(<file*>) != 0 if find error

fgets(<buff[]>, sizeof(buff) - 1, <file*>); stops at: size == sizeof(buff) - 1; \n; EOF
fputs(<buff[]>, <file*>); fputs do not add \n | \0

fprintf(<file*>, standart printf);
fscanf(<file*>, standart scanf);

FOR BINARY DATA:
size_t fread(void *buff, size, num, <file*>); - read from <file*> num count of objects with size == size in buff
size_t fwrite(void *buff, size, num, <file*>); - write
if size_t == num => successful read/write

fseek(<file*>, <offset>, <start>); -> <start> = SEEK_SET (start); SEEK_CUR (current); SEEK_END (end);
ftell(<file*>) -> return current possition or -1 if error

rewind(<file*>) -> return to start of file
fflush(<file*>) -> clean file buffer
----------------------------------------------------------------*/

void zad_0()
{
    FILE *fp = fopen("myfile.bin", "wb");
    if (fp == NULL)
        exit(1);
    int num = 1024;
    if (fwrite(&num, sizeof(int), 1, fp) != 1)
    {
        printf("write error");
        exit(1);
    }
    else
    {
        fclose(fp);
    }

    fp = fopen("myfile.bin", "rb");
    if (fp == NULL)
        exit(1);
    int newnum;
    if (fread(&newnum, sizeof(int), 1, fp) != 1)
    {
        printf("Error reading");
        exit(1);
    }
    else
    {
        printf("%d", newnum);
        fclose(fp);
    }
}

// zad 1 => fprintf, fscanf in txt file int float strinf
void zad_1_file()
{
    FILE *fp = fopen("zad_1.txt", "w");
    if (fp == NULL)
        exit(1);
    int num = 5;
    float num2 = 1.23;
    char str[20] = "Hello";
    fprintf(fp, "%d, %f, %s", num, num2, str);
    fclose(fp);

    fp = fopen("zad_1.txt", "r");
    if (fp == NULL)
        exit(1);
    int out_num;
    float out_float;
    char out_str[20];
    fscanf(fp, "%d, %f, %s", &out_num, &out_float, out_str);
    printf("%d, %f, %s", out_num, out_float, out_str);
}

// float arr[10] - init => write to bin file, read nth num;
void zad_2()
{
    float arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i + 1;
    }
    FILE *fp = fopen("zad_2.bin", "wb");
    IF_FILE_NULL(fp);
    fwrite(arr, sizeof(float), 10, fp);
    fclose(fp);
    fp = fopen("zad_2.bin", "rb");
    IF_FILE_NULL(fp);
    int n = 3;
    float output;
    fseek(fp, (n - 1) * sizeof(float), SEEK_SET);
    if (fread(&output, sizeof(float), 1, fp) != 1)
        exit(1);
    else
        printf("%f\n", output);
}

#endif