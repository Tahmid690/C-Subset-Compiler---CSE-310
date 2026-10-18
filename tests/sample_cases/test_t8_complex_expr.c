int g;

int main() {
    int a, b, c;
    g = 100;
    a = 3;
    b = a * a + g;
    println(b);
    c = (a + 2) * (a - 1);
    println(c);
    g = g / (a * a);
    println(g);
    a = (b - c) % 7;
    println(a);
    return 0;
}
