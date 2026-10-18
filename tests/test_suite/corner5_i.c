int x;

int f(int x){
	x = x + 10;
	return x;
}

int main(){
	int a,b,c,d,e;
	x = 5;
	a = f(x);
	println(a);
	println(x);

	b = 3;
	c = 4;
	d = b * c;
	e = d - b + c;
	println(d);
	println(e);

	return 0;
}
