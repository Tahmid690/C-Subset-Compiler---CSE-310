int double_it(int x){
	return 2 * x;
}

int sum2(int a, int b){
	return a + b;
}

int main(){
	int r,t;
	t = double_it(3);
	r = sum2(t, double_it(4));
	println(r);

	t = sum2(1, 2);
	r = double_it(t);
	println(r);

	t = sum2(1, 1);
	r = sum2(double_it(t), 1);
	println(r);

	return 0;
}
