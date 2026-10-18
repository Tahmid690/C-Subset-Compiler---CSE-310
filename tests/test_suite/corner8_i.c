int main(){
	int x[4];
	int i,j,t;

	x[0] = 10;
	x[1] = 20;
	x[2] = 30;
	t = x[0] + x[1] + x[2];
	x[3] = t;

	t = x[3];
	println(t);

	i = 1;
	j = 2;
	x[i+j-2] = 99;
	t = x[1];
	println(t);

	x[0]++;
	t = x[0];
	println(t);

	return 0;
}
