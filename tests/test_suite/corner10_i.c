int is_even(int n);
int is_odd(int n);

int is_even(int n){
	if(n == 0) return 1;
	int m;
	m = n - 1;
	return is_odd(m);
}

int is_odd(int n){
	if(n == 0) return 0;
	int m;
	m = n - 1;
	return is_even(m);
}

int fib(int n){
	if(n <= 1) return n;
	int a,b;
	a = n - 1;
	b = n - 2;
	int fa,fb;
	fa = fib(a);
	fb = fib(b);
	return fa + fb;
}

int main(){
	int r;
	r = is_even(4);
	println(r);
	r = is_odd(4);
	println(r);
	r = is_even(7);
	println(r);
	r = is_odd(7);
	println(r);
	r = fib(8);
	println(r);

	return 0;
}
