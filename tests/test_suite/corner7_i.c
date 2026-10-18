int main(){
	int a,b,c;
	a = 5;
	b = a++;
	println(a);
	println(b);

	a = 5;
	b = a--;
	println(a);
	println(b);

	a = 3;
	b = 4;
	c = a++ + b--;
	println(c);
	println(a);
	println(b);

	return 0;
}
