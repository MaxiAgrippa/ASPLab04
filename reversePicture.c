//
// Created by Maix on 7/6/20.
//
#include "stdio.h"
#include "stdlib.h"
#include "sys/fcntl.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "unistd.h"

// reverse the picture.
void reversePicture(int file_1, int file_2, int columns, int rows, long int fileSize);

/**
 * reverse the target .pgm picture and store to another file.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    // file size
    long int fileSize;
    // serve for reading source file head information
    char *temp = (char *) calloc(100, sizeof(char));
    // picture columns and rows
    int columns, rows;
    // open source file
    int file_1 = open(argv[1], O_RDONLY);
    // if failed, show error and exit
    if (file_1 == -1)
    {
        fprintf(stderr, "Can not open file %s.\n", argv[1]);
        exit(0);
    }
    // open target file
    int file_2 = open(argv[2], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    // if failed, show error and exit
    if (file_2 == -1)
    {
        fprintf(stderr, "Can not open file %s.\n", argv[1]);
        exit(0);
    }

    // put the stream beginning to the end of the source file, and get file size.
    fileSize = lseek(file_1, 0, SEEK_END);
    // set to the beginning of the stream
    lseek(file_1, 0, SEEK_SET);

    // get source file type
    read(file_1, temp, 3);
    // put file type to target file.
    write(file_2, temp, 3);

    // reset temp;
    free(temp);
    temp = (char *) calloc(100, sizeof(char));

    // get source file picture columns and rows.
    FILE *file = fopen(argv[1], "r");
    fseek(file, 3, SEEK_SET);
    fscanf(file, "%d %d\n", &columns, &rows);
    // put picture max grey into target file.
    sprintf(temp, "%d %d\n", columns, rows);
    write(file_2, temp, 8);
    // reset stream position to the correct position.
    lseek(file_1, 8, SEEK_CUR);

    // reset temp;
    free(temp);
    temp = (char *) calloc(100, sizeof(char));

    // get source file picture max grey.
    read(file_1, temp, 4);
    // put picture max grey into target file.
    write(file_2, temp, 4);

    // reverse the picture.
    reversePicture(file_1, file_2, columns, rows, fileSize);

    // close file
    close(file_1);
    close(file_2);
}

// reverse the picture.
void reversePicture(int file_1, int file_2, int columns, int rows, long int fileSize)
{
    // store one row of pixels.
    char oneRowOfPicture[columns];
    // set the stream beginner to the end of the file.
    lseek(file_2, fileSize, SEEK_SET);

    // for every rows
    for (int i = 0; i < rows; i++)
    {
        // read one row of pixels, each pixel is 1 byte.
        read(file_1, oneRowOfPicture, columns);
        // set the stream beginner to columns a head of current stream position.
        lseek(file_2, -columns, SEEK_CUR);
        // write one row of picture at the end row of the target file.
        // it's reversed since it go through buffer which is a first in last out.
        write(file_2, oneRowOfPicture, columns);
        // reset the stream beginner to columns a head of current stream position,
        // since fwrite() will move the position behind.
        lseek(file_2, -columns, SEEK_CUR);
    }
}