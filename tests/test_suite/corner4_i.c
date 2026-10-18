int main(){
	int a,b;
	a = 10;
	b = 0;

	if(a > 5){
		if(a > 8){
			if(a > 12){
				b = 1;
			}
			b = b + 2;
		}
		b = b + 4;
	}
	println(b);

	a = 0;
	if(a){
		b = 99;
	}
	println(b);

	return 0;
}
