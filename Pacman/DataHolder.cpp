#include "DataHolder.h"

DataHolder::DataHolder(int rows, int cols) : nrows(rows), ncols(cols) 
{
	data = new char* [nrows];
	for (int i = 0; i < nrows; i++)
		data[i] = new char[ncols];
}

DataHolder::~DataHolder()
{
	for (int i = 0; i < nrows; i++)
		delete[] data[i];
	delete[] data;
}

char DataHolder::GetData(int row, int col)
{
	return data[row][col];
}

void DataHolder::SetData(int row, int col, char value)
{
	data[row][col] = value;
}
