#ifndef ASPIRADORA_H
#define  ASPIRADORA_H

class Aspiradora {
private:
    const unsigned char N;
public:
    Aspiradora ();
    ~Aspiradora ();
    void aspirar(char *area[], int n, int x, int y);
};

#endif
