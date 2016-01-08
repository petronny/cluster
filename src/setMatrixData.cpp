void setMatrixData(double** matrix,int i,int j,double val) {
	int row=i<j?i:j;
	int col=i>j?i:j;
	col-=row;
	*(*(matrix+row)+col)=val;
}
