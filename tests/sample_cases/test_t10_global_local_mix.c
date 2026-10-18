int g1, g2;

int main() {
    int a, b, c, d;
    g1 = 10;
    g2 = 20;
    a = g1 + g2;
    println(a);
    b = g1 * g2;
    println(b);
    g1 = g2 - g1;
    println(g1);
    a = g1 < g2;
    println(a);
    b = g1 == g2;
    println(b);
    c = g1 && g2;
    println(c);
    d = !g1;
    println(d);
    return 0;
}
