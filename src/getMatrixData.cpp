double getMatrixData(double** matrix,int i,int j) {
	int row=i<j?i:j;
	int col=i>j?i:j;
	col-=row;
	return *(*(matrix+row)+col);
}
