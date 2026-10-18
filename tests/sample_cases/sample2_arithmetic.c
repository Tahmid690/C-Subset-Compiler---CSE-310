int x, y;

int main() {
    int a, b, c, d, e;
    x = 50;
    y = 7;
    a = 12;
    b = 5;
    
    c = a + b * 4 - (x / y);
    println(c);
    
    d = (x % y) * (a - b);
    println(d);
    
    e = -a + (-b);
    println(e);
    
    return 0;
}
