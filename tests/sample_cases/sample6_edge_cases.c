int g1;
int g2;

int main() {
    int a;
    int b;
    int c;
    int d;
    g1 = 17;
    g2 = 5;
    a = -10;
    b = 3;
    
    c = g1 % g2 + a;
    println(c);
    
    d = !(g1 <= g2);
    println(d);
    
    return 0;
}
