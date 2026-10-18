int main(){
	int i,s;
	s = 0;

	for(i = 1; i <= 10; i++){
		s = s + i;
	}
	println(s);

	i = 10;
	while(0){
		i = 999;
	}
	println(i);

	s = 0;
	i = 0;
	while(i < 3){
		int j;
		j = 0;
		while(j < 3){
			s = s + 1;
			j++;
		}
		i++;
	}
	println(s);

	return 0;
}
