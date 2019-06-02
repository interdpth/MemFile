#pragma once
#include <stdio.h>
#include <iostream>
class MemFile
{
public:

	//Singleton reference
	static MemFile* currentFile;
    
	//Takes in a FILE pointer, and currents a copy of the file in memory.
	MemFile(FILE* fp);

	//Makes a blank mem file of the expected size
	MemFile(int size);

	//Creates a memfile from a given file name, fails if below expected size.
	MemFile(char* file, int expectedMinSize);

	//Returns the memfile size
	int FileSize();
	//Saves current file
	void save();

	//Saves to file.
	void save(char* file);

	//Seek an offset for opertations in memfile
	void seek(unsigned long offset);

	//Reads in size * count to destation from memfile
	void fread(void* dst, int count, int size);	

	//gets a char from current memfile
	unsigned char fgetc();
	//puts a char from current memfile
	unsigned char fputc(unsigned char val);
	//Writes in size * count to destation from memfile
	void fwrite(void* dst, int count, int size);

	//Checks filesize validity.
	bool ValidFileSize();

	//Returns memfile as a byte array.
	unsigned char* GetFile();
	
	//Returns current file index
	int ftell();

	//Cleanup
	~MemFile();
private: 
	unsigned char* _theFile; 
	long fileIndex; 
	char* fileName;
	FILE* inuseFile;
	int _expectedFileSize;
	int _fileSize;
};

