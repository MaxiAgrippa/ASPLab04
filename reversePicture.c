//
// Created by Maix on 7/6/20.
//
#include "stdio.h"
#include "stdlib.h"

// flip the picture
void reversePicture(FILE *filePointer_1, FILE *filePointer_2, int columns, int rows, long int fileSize);

/**
 * reverse the target .pgm picture and store to another file.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    // two file pointer, one for source, one for write
    FILE *filePointer_1, *filePointer_2;
    // file size
    long int fileSize;
    // serve for reading source file head information
    char temp[100];
    // picture columns and rows
    int columns, rows;
    // open the source file to read
    filePointer_1 = fopen(argv[2], 'r');
    // if failed, show error and exit
    if (filePointer_1 == NULL)
    {
        perror("Can not open file!");
        exit(0);
    }
    // open the target file to write
    filePointer_2 = fopen(argv[3], 'w');
    // if failed, show error and exit
    if (filePointer_2 == NULL)
    {
        perror("Can not write file!");
        exit(0);
    }
    // put the stream beginning to the end of the source file
    fseek(filePointer_1, 0, SEEK_END);
    // get file size.
    fileSize = ftell(filePointer_1);
    // set to the beginning of the stream
    rewind(filePointer_1);

    // get source file type
    fgets(temp, 100, filePointer_1);
    // put file type to target file.
    fputs(temp, filePointer_2);

    // get source file picture columns and rows.
    fscanf(filePointer_1, "%d %d\n", &columns, &rows);
    // put picture columns and rows into the target file.
    fprintf(filePointer_2, "%d %d\n", &columns, &rows);

    // get source file picture max grey.
    fgets(temp, 100, filePointer_1);
    // put picture max grey into target file.
    fputs(temp, filePointer_2);

    // reverse the picture.
    reversePicture(filePointer_1, filePointer_2, columns, rows, fileSize);

    // close file pointers
    fclose(filePointer_1);
    fclose(filePointer_2);
}

// reverse the picture.
void reversePicture(FILE *filePointer_1, FILE *filePointer_2, int columns, int rows, long int fileSize)
{
    // store one row of pixels.
    char oneRowOfPicture[columns];
    // set the stream beginner to the end of the file.
    fseek(filePointer_2, fileSize, SEEK_SET);

    // for every rows
    for (int i = 0; i < rows; i++)
    {
        // read one row of pixels, each pixel is 1 byte.
        fread(oneRowOfPicture, 1, columns, filePointer_1);
        // set the stream beginner to columns a head of current stream position.
        fseek(filePointer_2, -columns, SEEK_CUR);
        // write one row of picture at the end row of the target file.
        // it's reversed since it go through buffer which is a first in last out.
        fwrite(oneRowOfPicture, 1, columns, filePointer_2);
        // reset the stream beginner to columns a head of current stream position,
        // since fwrite() will move the position behind.
        fseek(filePointer_2, -columns, SEEK_CUR);
    }
}