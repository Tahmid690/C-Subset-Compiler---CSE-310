int bigger(int a, int b){
	if(a > b){
		return a;
	}
	return b;
}

int clamp3(int v, int lo, int hi){
	if(v < lo) return lo;
	if(v > hi) return hi;
	return v;
}

int main(){
	int r,t;
	r = bigger(3, 7);
	println(r);
	r = bigger(10, 4);
	println(r);

	r = clamp3(5, 1, 10);
	println(r);
	r = clamp3(-3, 1, 10);
	println(r);
	r = clamp3(15, 1, 10);
	println(r);

	t = clamp3(8, 2, 6);
	r = bigger(t, 4);
	println(r);

	return 0;
}
