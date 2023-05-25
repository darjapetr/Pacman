#pragma once

class DataHolder 
{
private:
	char** data;
	int nrows, ncols;
public:
	DataHolder(int rows, int cols);
	~DataHolder();
	char GetData(int row, int col);
	void SetData(int row, int col, char value);
};