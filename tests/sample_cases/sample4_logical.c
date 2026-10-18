int main(){
    int t;
    int f;
    int r1;
    int r2;
    int r3;
    int r4;
    t = 1;
    f = 0;

    r1 = t && f;
    r2 = t || f;
    r3 = !t;
    r4 = !f;

    println(r1);
    println(r2);
    println(r3);
    println(r4);

    return 0;
}
