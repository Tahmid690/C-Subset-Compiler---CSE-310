int arr[5];

int main(){
	int i,s;
	for(i = 0; i < 5; i++){
		arr[i] = i * i;
	}

	i = arr[0];
	println(i);
	i = arr[2];
	println(i);
	i = arr[4];
	println(i);

	s = arr[0] + arr[2] + arr[4];
	println(s);

	return 0;
}
