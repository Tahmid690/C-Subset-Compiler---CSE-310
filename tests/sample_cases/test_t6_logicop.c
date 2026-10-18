int main() {
    int a, b, c, d, e;
    a = 1;
    b = 0;
    c = a && b;
    println(c);
    c = a || b;
    println(c);
    c = b && b;
    println(c);
    c = a || a;
    println(c);
    d = !a;
    println(d);
    e = !b;
    println(e);
    c = !a && b;
    println(c);
    c = !b || a;
    println(c);
    return 0;
}
